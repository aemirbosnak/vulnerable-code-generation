//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 32

int main() {
    int arr1[SIZE], arr2[SIZE];
    int choice, i, j;

    printf("Enter the elements of the first array:\n");
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of the second array:\n");
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("\nEnter your choice:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (i = 0; i < SIZE; i++) {
                arr1[i] = arr1[i] & arr2[i];
            }
            printf("\nResult of Bitwise AND:\n");
            for (i = 0; i < SIZE; i++) {
                printf("%d ", arr1[i]);
            }
            break;

        case 2:
            for (i = 0; i < SIZE; i++) {
                arr1[i] = arr1[i] | arr2[i];
            }
            printf("\nResult of Bitwise OR:\n");
            for (i = 0; i < SIZE; i++) {
                printf("%d ", arr1[i]);
            }
            break;

        case 3:
            for (i = 0; i < SIZE; i++) {
                arr1[i] = arr1[i] ^ arr2[i];
            }
            printf("\nResult of Bitwise XOR:\n");
            for (i = 0; i < SIZE; i++) {
                printf("%d ", arr1[i]);
            }
            break;

        default:
            printf("\nInvalid choice!");
    }

    return 0;
}