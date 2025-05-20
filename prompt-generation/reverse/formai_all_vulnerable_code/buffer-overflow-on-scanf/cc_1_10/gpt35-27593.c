//FormAI DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

// function to search for a key
int search(int *arr, int key, int n) {
    // initialize starting and ending indices of the array
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        // calculate the middle index
        int mid = (start + end) / 2;
   
        // check if the key is present at the middle index
        if (*(arr + mid) == key) {
            return mid;
        }
    
        // if key is greater than the middle element, ignore left half
        else if (*(arr + mid) < key) {
            start = mid + 1;
        }
        
        // if key is smaller than the middle element, ignore right half
        else {
            end = mid - 1;
        }
    }

    // if key is not present in the array
    return -1;
}

void main() {
    // allocate memory for the array dynamically
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    // populate the array with random integers
    for (int i = 0; i < n; i++) {
        *(arr + i) = rand() % 100;
    }

    // sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + j) < *(arr + i)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }

    // print the sorted array
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }

    // search for a key
    int key;
    printf("\nEnter the key to search for: ");
    scanf("%d", &key);
    int index = search(arr, key, n);

    // print the result of the search
    if (index == -1) {
        printf("\nKey not found.\n");
    }
    else {
        printf("\nKey found at index %d.\n", index);
    }

    // free the allocated memory
    free(arr);
}