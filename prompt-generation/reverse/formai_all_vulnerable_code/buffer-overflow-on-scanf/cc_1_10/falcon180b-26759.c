//Falcon-180B DATASET v1.0 Category: Recursive ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

//Function to print array
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//Function to merge two sorted arrays
void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i=0; i<n1; i++){
        L[i] = arr[left + i];
    }
    for(int j=0; j<n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }

    while(i < n1){
        arr[k++] = L[i++];
    }

    while(j < n2){
        arr[k++] = R[j++];
    }
}

//Function to merge sort
void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

//Function to perform quick sort
void quickSort(int arr[], int left, int right){
    int pivot = arr[right];
    int i = left - 1;

    for(int j=left; j<right; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;

    quickSort(arr, left, i);
    quickSort(arr, i+2, right);
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    //Performing Merge Sort
    mergeSort(arr, 0, size-1);
    printf("Sorted array using Merge Sort: ");
    printArray(arr, size);

    //Performing Quick Sort
    quickSort(arr, 0, size-1);
    printf("\nSorted array using Quick Sort: ");
    printArray(arr, size);

    return 0;
}