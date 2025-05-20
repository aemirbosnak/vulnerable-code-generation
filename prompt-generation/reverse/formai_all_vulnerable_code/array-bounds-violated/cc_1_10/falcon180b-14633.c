//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int arr[MAX];
int n;

void generateArray(int size) {
    for(int i=0; i<size; i++) {
        arr[i] = rand() % MAX;
    }
}

void printArray(int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int x) {
    for(int i=0; i<n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int x) {
    int left = 0;
    int right = n-1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == x) {
            return mid;
        } else if(arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int size;

    printf("Enter the size of the array (maximum %d): ", MAX);
    scanf("%d", &size);

    generateArray(size);
    n = size;

    printf("Array: ");
    printArray(n);

    int search;

    printf("\nEnter the element to search: ");
    scanf("%d", &search);

    int result = linearSearch(search);

    if(result == -1) {
        printf("\nElement not found in the array.\n");
    } else {
        printf("\nElement found at position %d.\n", result);
    }

    result = binarySearch(search);

    if(result == -1) {
        printf("\nElement not found in the array.\n");
    } else {
        printf("\nElement found at position %d.\n", result);
    }

    return 0;
}