//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of the array
#define MAX_ELEMENTS 1000 // maximum number of elements in the array
#define MAX_CHARS 50 // maximum length of an element

// function to compare two strings
int compare(const void* a, const void* b) {
    char* str1 = *(char**)a;
    char* str2 = *(char**)b;
    return strcmp(str1, str2);
}

// function to search for an element in the array
int search(char* arr[], int size, char* element) {
    // sort the array
    qsort(arr, size, sizeof(char*), compare);

    // binary search for the element
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid], element);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // element not found
    return -1;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // initialize the array
    char* arr[MAX_SIZE];
    for (int i = 0; i < size; i++) {
        arr[i] = malloc(MAX_CHARS * sizeof(char));
        printf("Enter element %d: ", i + 1);
        scanf("%s", arr[i]);
    }

    // search for an element
    char* element;
    printf("Enter the element to search for: ");
    scanf("%s", element);
    int result = search(arr, size, element);

    // print the result
    if (result!= -1) {
        printf("Element found at index %d\n", result + 1);
    } else {
        printf("Element not found\n");
    }

    // free the memory
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    return 0;
}