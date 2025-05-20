//Falcon-180B DATASET v1.0 Category: Sorting ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void print_array(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int size) {
    int min_idx;
    for(int i=0; i<size-1; i++) {
        min_idx = i;
        for(int j=i+1; j<size; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void insertion_sort(int arr[], int size) {
    int key, j;
    for(int i=1; i<size; i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge_sort(int arr[], int size) {
    if(size < 2) {
        return;
    }
    int mid = size/2;
    int left[mid], right[size-mid];
    for(int i=0; i<mid; i++) {
        left[i] = arr[i];
    }
    for(int i=mid; i<size; i++) {
        right[i-mid] = arr[i];
    }
    merge_sort(left, mid);
    merge_sort(right, size-mid);
    int i=0, j=0, k=0;
    while(i<mid && j<size-mid) {
        if(left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while(i<mid) {
        arr[k++] = left[i++];
    }
    while(j<size-mid) {
        arr[k++] = right[j++];
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    srand(time(NULL));
    int choice = rand() % 3;
    switch(choice) {
        case 0:
            selection_sort(arr, size);
            printf("Sorted array using selection sort:\n");
            print_array(arr, size);
            break;
        case 1:
            insertion_sort(arr, size);
            printf("Sorted array using insertion sort:\n");
            print_array(arr, size);
            break;
        case 2:
            merge_sort(arr, size);
            printf("Sorted array using merge sort:\n");
            print_array(arr, size);
            break;
    }
    return 0;
}