//FormAI DATASET v1.0 Category: Sorting ; Style: modular
#include <stdio.h>
#include <stdlib.h>

/* Function to print the array */
void printArray(int arr[], int n){
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Function to perform quicksort */
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex-1);
        quicksort(arr, pivotIndex+1, high);
    }
}

/* Main Function */
int main(){
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    int* arr = (int*) malloc(n*sizeof(int));

    printf("\n");

    /* Get the array elements from user */
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array:\n");
    printArray(arr, n);

    /* Call the quicksort function */
    quicksort(arr, 0, n-1);

    printf("\nSorted Array:\n");
    printArray(arr, n);

    return 0;
}