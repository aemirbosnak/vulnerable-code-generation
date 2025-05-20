//FormAI DATASET v1.0 Category: Sorting ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n){
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++){
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int i, n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    int arr[n];

    // Generate random array
    srand(time(NULL));
    for (i = 0; i < n; i++){
        arr[i] = rand() % 1000;
    }

    // Print unsorted array
    printf("Unsorted Array:\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    // Sort array
    selectionSort(arr, n);

    // Print sorted array
    printf("\n\nSorted Array:\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}