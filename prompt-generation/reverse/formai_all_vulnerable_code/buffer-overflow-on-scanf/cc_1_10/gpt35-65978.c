//FormAI DATASET v1.0 Category: Sorting ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// function declaration
void insertion_sort(int arr[], int n);

int main() {
    int n, i;

    // input size of array
    printf("Enter size of array: ");
    scanf("%d", &n);

    // dynamically allocate memory for array
    int *arr = (int *) malloc(n * sizeof(int));

    // input array elements
    printf("Enter array elements: ");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // call insertion sort function
    insertion_sort(arr, n);

    // print sorted array
    printf("Sorted array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    // free dynamically allocated memory
    free(arr);

    return 0;
}

// function to perform insertion sort
void insertion_sort(int arr[], int n) {
    int i, j, temp;

    for(i=1; i<n; i++) {
        temp = arr[i];
        j = i - 1;

        while(j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
    }
}