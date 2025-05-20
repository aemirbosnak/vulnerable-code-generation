//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000 // Maximum size of the array

void create_array(int arr[], int size) {
    int i;
    for(i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
}

int binary_search(int arr[], int size, int target) {
    int left = 0, right = size-1, mid;

    while(left <= right) {
        mid = left + (right - left) / 2;

        if(arr[mid] == target)
            return mid;

        if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Target not found in the array
}

int main() {
    int arr[MAX_SIZE], size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if(size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size!\n");
        return 0;
    }

    printf("Enter the elements of the array:\n");
    create_array(arr, size);

    printf("Enter the target element to search for:\n");
    scanf("%d", &target);

    int result = binary_search(arr, size, target);

    if(result == -1)
        printf("Target element not found in the array!\n");
    else
        printf("Target element found at index %d!\n", result);

    return 0;
}