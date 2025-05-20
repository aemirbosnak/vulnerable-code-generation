//Falcon2-11B DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE] = {0};
    int i, j;
    int n = 0;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Array size is too large.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr[j] = arr[j] & arr[i];
        }
    }

    printf("Bitwise AND of each pair of elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr[j] = arr[j] | arr[i];
        }
    }

    printf("Bitwise OR of each pair of elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr[j] = arr[j] ^ arr[i];
        }
    }

    printf("Bitwise XOR of each pair of elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}