//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE], result[MAX_SIZE];
    int size1, size2;

    printf("Enter the size of first array (max %d): ", MAX_SIZE);
    scanf("%d", &size1);

    printf("Enter the elements of first array:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of second array (max %d): ", MAX_SIZE);
    scanf("%d", &size2);

    printf("Enter the elements of second array:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("Bitwise operations:\n");
    printf("AND: ");
    for (int i = 0; i < size1 && i < size2; i++) {
        result[i] = arr1[i] & arr2[i];
        printf("%d ", result[i]);
    }
    printf("\n");

    printf("OR: ");
    for (int i = 0; i < size1 && i < size2; i++) {
        result[i] = arr1[i] | arr2[i];
        printf("%d ", result[i]);
    }
    printf("\n");

    printf("XOR: ");
    for (int i = 0; i < size1 && i < size2; i++) {
        result[i] = arr1[i] ^ arr2[i];
        printf("%d ", result[i]);
    }
    printf("\n");

    printf("Left shift: ");
    for (int i = 0; i < size1 && i < size2; i++) {
        result[i] = arr1[i] << 2;
        printf("%d ", result[i]);
    }
    printf("\n");

    printf("Right shift: ");
    for (int i = 0; i < size1 && i < size2; i++) {
        result[i] = arr1[i] >> 2;
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}