//FormAI DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 512

void print_array(int arr[], int arr_size) {
    printf("[ ");
    for(int i=0; i<arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void bubble_sort(int arr[], int arr_size) {
    for(int i=0; i<arr_size-1; i++) {
        for(int j=0; j<arr_size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int binary_search(int arr[], int arr_size, int search_elem) {
    int left = 0;
    int right = arr_size-1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == search_elem) {
            return mid;
        }
        else if(arr[mid] < search_elem) {
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    return -1;
}

int main() {
    printf("Enter the number of elements in the array: ");
    int arr_size;
    scanf("%d", &arr_size);

    int arr[arr_size];
    printf("Enter the elements of the array:\n");
    for(int i=0; i<arr_size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nBefore sorting:\n");
    print_array(arr, arr_size);

    bubble_sort(arr, arr_size);

    printf("\nAfter sorting:\n");
    print_array(arr, arr_size);

    int search_elem;
    printf("\nEnter the element to search: ");
    scanf("%d", &search_elem);

    int search_index = binary_search(arr, arr_size, search_elem);
    if(search_index == -1) {
        printf("\nElement not found in the array.\n");
    }
    else {
        printf("\nElement found at index %d in the array.\n", search_index);
    }

    return 0;
}