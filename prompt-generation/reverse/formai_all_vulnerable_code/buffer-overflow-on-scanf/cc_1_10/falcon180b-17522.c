//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int main() {
    int i, j, n, result, mask;
    int arr[SIZE] = {0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111};
    int arr2[SIZE] = {0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111};

    printf("Bitwise Operations Example\n\n");
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nBitwise AND Operation:\n");
    for (i = 0; i < n; i++) {
        result = arr[i] & arr2[i];
        printf("%d ", result);
    }

    printf("\n\nBitwise OR Operation:\n");
    for (i = 0; i < n; i++) {
        result = arr[i] | arr2[i];
        printf("%d ", result);
    }

    printf("\n\nBitwise XOR Operation:\n");
    for (i = 0; i < n; i++) {
        result = arr[i] ^ arr2[i];
        printf("%d ", result);
    }

    printf("\n\nBitwise NOT Operation:\n");
    for (i = 0; i < n; i++) {
        result = ~arr[i];
        printf("%d ", result);
    }

    printf("\n\nBitwise Left Shift Operation:\n");
    for (i = 0; i < n; i++) {
        result = arr[i] << 2;
        printf("%d ", result);
    }

    printf("\n\nBitwise Right Shift Operation:\n");
    for (i = 0; i < n; i++) {
        result = arr[i] >> 2;
        printf("%d ", result);
    }

    return 0;
}