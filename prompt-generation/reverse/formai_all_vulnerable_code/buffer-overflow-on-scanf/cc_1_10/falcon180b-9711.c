//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("Enter the number of bits: ");
    scanf("%d", &n);

    int arr[n];

    // Generating random numbers for the array
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 2;
    }

    // Displaying the array
    printf("Array of bits: ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");

    // Bitwise operations
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Sum of bits: %d\n", sum);

    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= arr[i];
    }
    printf("Product of bits: %d\n", product);

    int or_result = 0;
    for (int i = 0; i < n; i++) {
        or_result |= arr[i];
    }
    printf("OR of bits: %d\n", or_result);

    int and_result = 0;
    for (int i = 0; i < n; i++) {
        and_result &= arr[i];
    }
    printf("AND of bits: %d\n", and_result);

    int xor_result = 0;
    for (int i = 0; i < n; i++) {
        xor_result ^= arr[i];
    }
    printf("XOR of bits: %d\n", xor_result);

    int shift_result = 0;
    for (int i = 0; i < n; i++) {
        shift_result <<= 1;
        if (arr[i] == 1) {
            shift_result |= 1;
        }
    }
    printf("Shift of bits: %d\n", shift_result);

    return 0;
}