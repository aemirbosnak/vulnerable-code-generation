//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];
    int size1, size2, i, j, k, bitwise_result;

    // Get the size of the first array
    printf("Enter the size of the first array (max %d): ", MAX_SIZE);
    scanf("%d", &size1);

    // Get the elements of the first array
    printf("Enter the elements of the first array:\n");
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Get the size of the second array
    printf("Enter the size of the second array (max %d): ", MAX_SIZE);
    scanf("%d", &size2);

    // Get the elements of the second array
    printf("Enter the elements of the second array:\n");
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Perform bitwise operations on the arrays
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            // Bitwise AND
            bitwise_result = arr1[i] & arr2[j];
            printf("Bitwise AND of %d and %d is %d\n", arr1[i], arr2[j], bitwise_result);

            // Bitwise OR
            bitwise_result = arr1[i] | arr2[j];
            printf("Bitwise OR of %d and %d is %d\n", arr1[i], arr2[j], bitwise_result);

            // Bitwise XOR
            bitwise_result = arr1[i] ^ arr2[j];
            printf("Bitwise XOR of %d and %d is %d\n", arr1[i], arr2[j], bitwise_result);

            // Left shift
            bitwise_result = arr1[i] << 2;
            printf("Left shift of %d by 2 is %d\n", arr1[i], bitwise_result);

            // Right shift
            bitwise_result = arr1[i] >> 2;
            printf("Right shift of %d by 2 is %d\n", arr1[i], bitwise_result);
        }
    }

    return 0;
}