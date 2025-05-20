//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bitwise AND operation
    printf("\nBitwise AND operation:\n");
    int result = arr[0] & arr[1];
    printf("Result: %d\n", result);

    // Bitwise OR operation
    printf("\nBitwise OR operation:\n");
    result = arr[0] | arr[1];
    printf("Result: %d\n", result);

    // Bitwise XOR operation
    printf("\nBitwise XOR operation:\n");
    result = arr[0] ^ arr[1];
    printf("Result: %d\n", result);

    // Bitwise NOT operation
    printf("\nBitwise NOT operation:\n");
    result = ~arr[0];
    printf("Result: %d\n", result);

    // Bitwise Left Shift operation
    printf("\nBitwise Left Shift operation:\n");
    result = arr[0] << 2;
    printf("Result: %d\n", result);

    // Bitwise Right Shift operation
    printf("\nBitwise Right Shift operation:\n");
    result = arr[0] >> 2;
    printf("Result: %d\n", result);

    return 0;
}