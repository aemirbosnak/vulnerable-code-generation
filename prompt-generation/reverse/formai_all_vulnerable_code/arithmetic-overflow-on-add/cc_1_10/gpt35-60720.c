//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

void bucket_sort(int arr[], int n) {
    int i, j;
    int count[ARRAY_SIZE];

    for(i=0; i < n; i++) {
        count[i] = 0;
    }
    for(i=0; i < n; i++) {
        (count[arr[i]])++;
    }
    for(i=0, j=0; i < n; i++) {
        for(; count[i]>0; (count[i])--) {
            arr[j++] = i;
        }
    }
}

int paranoid_bucket_sort(int arr[], int n) {
    if (n <= 0) {
        printf("Error: Array is empty\n");
        return -1;
    }
    if (n > ARRAY_SIZE) {
        printf("Error: Array size exceeds maximum limit of %d\n", ARRAY_SIZE);
        return -1;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0 || arr[i] > ARRAY_SIZE) {
            printf("Error: Array element %d is out of range\n", i);
            return -1;
        }
    }
    printf("Input Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("Bucket Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

int main() {
    int arr1[] = {29, 25, 3, 49, 9, 37, 21, 43, 18, 36};
    paranoid_bucket_sort(arr1, (sizeof(arr1)/sizeof(int)));

    int arr2[] = {55, 76, 12, 100, 23, 9, 8, 106, 57, 68, 73, 88, 99, 5};
    paranoid_bucket_sort(arr2, (sizeof(arr2)/sizeof(int)));

    int arr3[] = {105, 77, 35, 17, 32, 41, 106, 70, 95, 45, 64, 12, 27, 37, 94, 12};
    paranoid_bucket_sort(arr3, (sizeof(arr3)/sizeof(int)));

    return 0;
}