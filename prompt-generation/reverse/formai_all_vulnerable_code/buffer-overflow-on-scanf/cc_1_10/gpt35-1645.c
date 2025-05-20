//FormAI DATASET v1.0 Category: Sorting ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // the maximum size of the array

/* function to swap two elements in an array */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* function to perform bubble sort */
void bubble_sort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

/* function to perform selection sort */
void selection_sort(int arr[], int n) {
    int min_idx;
    for(int i=0;i<n-1;i++) {
        min_idx = i;
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

/* function to perform insertion sort */
void insertion_sort(int arr[], int n) {
    int key, j;
    for(int i=1;i<n;i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[MAX_SIZE], n, choice;
    printf("Enter the size of the array (maximum 10): ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter your choice of sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            bubble_sort(arr, n);
            printf("Sorted array using Bubble Sort: ");
            break;
        case 2:
            selection_sort(arr, n);
            printf("Sorted array using Selection Sort: ");
            break;
        case 3:
            insertion_sort(arr, n);
            printf("Sorted array using Insertion Sort: ");
            break;
        default:
            printf("Invalid choice.\n");
            exit(0);
    }
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}