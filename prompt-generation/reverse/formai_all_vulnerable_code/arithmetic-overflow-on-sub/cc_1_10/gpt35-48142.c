//FormAI DATASET v1.0 Category: Sorting ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

// Function to swap two elements in an array
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quick sort function
void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivot = arr[high]; // pivot element
        int i = low - 1; // index of smaller element

        for(int j=low; j<high; j++){
            // If current element is smaller than or equal to pivot
            if(arr[j] <= pivot){
                i++;
                swap(&arr[i], &arr[j]); // swap arr[i] and arr[j]
            }
        }

        swap(&arr[i+1], &arr[high]); // swap arr[i+1] and arr[high]

        // Recursively sort elements before partition and after partition
        quickSort(arr, low, i);
        quickSort(arr, i+2, high);
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n-1);

    printf("Sorted array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}