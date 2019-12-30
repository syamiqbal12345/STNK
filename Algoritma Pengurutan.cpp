#include<iostream>

using namespace std;

int bubble_sort(int data[], int n) {
    for(int i=0; i<=n-1; i++) {
        for(int kucing=0; kucing<=n-1; kucing++) {
            if(data[kucing+1] < data[kucing]) {
                int tmp = data[kucing];
                data[kucing] = data[kucing+1];
                data[kucing+1] = tmp;
            }
        }
    }
}

void insertion_sort(int data[], int n) {
    int i, j;

    for(i=1; i< n; i++) {
        for(j=i; j>0; j--){
            if(data[j] < data[j-1]) {
                int tmp = data[j-1];
                data[j-1] = data[j];
                data[j] = tmp;
            }
        }
    }
}

int sequential_search(int data[], int cari, int n) {
    for(int i=0; i < n; i++) {
        if(data[i] == cari) {
            return i;
            break;
        }
    }

    return -1;
};

int binary_search1(int data[], int f, int l, int cari) {
    int middle = (f+l)/2;

    if(data[middle] == cari) {
        cout << "Data Ketemu pada Indeks " << middle;
        int middle;
    } else {
        if(data[middle] < cari) {
            binary_search1(data, middle+1, l, cari);
        } else if(data[middle] > cari) {
            binary_search1(data, f,  middle-1, cari);
        }
    }
}
void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

int partition (int arr[], int low, int high) //quick.sort
{
	int tengah = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
	{
		if (arr[j] <= tengah)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void selection_sort(int data[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (data[j] < data[min_idx])
			min_idx = j;
		swap(&data[min_idx], &data[i]);
	}
}

int merges(int arr[], int f, int m, int l)
{
    int i, j, k;
    int n1 = m - f+1;
    int n2 = l - m;


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[f + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i=0;
    j=0;
    k = f;
    while(i < n1 && j < n2) {
        if(L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sisa sebelah kiri
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sisa sebelah kanan
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

};


void mergeSort(int arr[], int f, int l)
{
    if(f < l) {

        int mid = (l+f)/2;
        mergeSort(arr, f, mid);
        mergeSort(arr, mid+1, l);

        merges(arr, f, mid, l);
    }
};

int main() {

    int arr[10] = {6, 1, 7, 3, 8, 11, 5, 9, 10, 19};
   // int i, j, tmp, n = 9;
    int i=0, j=0;

    for(i=0; i<=9; i++) {
    cout << arr[i] << endl;
  }
   cout << "\n----\n";

//  mergeSort(arr,0, 10); //Karena Menggunakan data di ganti dengan array, (data)->(arr)
 // insertion_sort( data, 10);
  //bubble_sort (data, 9);
  //int n = sizeof(arr)/sizeof(arr[0]); //Karena Menggunakan data di ganti dengan array, (data)->(arr)
  // quickSort(arr, 0, n-1);

for(i=0; i<=9; i++) {
    cout << arr[i] << endl;
    }
    cout << "\n----\n";
}

