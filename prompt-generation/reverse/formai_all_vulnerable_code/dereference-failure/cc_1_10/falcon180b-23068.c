//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void print_array(int arr[], int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE];
    srand(time(NULL));

    // Fill array with random values
    int i;
    for(i=0; i<SIZE; i++) {
        arr[i] = rand() % 256;
    }

    // Print original array
    printf("Original array:\n");
    print_array(arr, SIZE);

    // Bitwise AND operation
    int result_and = 0;
    int mask = 0b11111111;
    for(i=0; i<SIZE; i++) {
        result_and |= (arr[i] & mask);
    }
    printf("Result of bitwise AND operation:\n");
    print_array(result_and, SIZE);

    // Bitwise OR operation
    int result_or = 0;
    for(i=0; i<SIZE; i++) {
        result_or |= (arr[i] | 0b11111111);
    }
    printf("Result of bitwise OR operation:\n");
    print_array(result_or, SIZE);

    // Bitwise XOR operation
    int result_xor = 0;
    for(i=0; i<SIZE; i++) {
        result_xor ^= (arr[i] ^ 0b11111111);
    }
    printf("Result of bitwise XOR operation:\n");
    print_array(result_xor, SIZE);

    // Bitwise NOT operation
    int result_not = 0;
    for(i=0; i<SIZE; i++) {
        result_not |= (~arr[i]);
    }
    printf("Result of bitwise NOT operation:\n");
    print_array(result_not, SIZE);

    // Bitwise left shift operation
    int result_left_shift = 0;
    int shift_amount = 4;
    for(i=0; i<SIZE; i++) {
        result_left_shift |= (arr[i] << shift_amount);
    }
    printf("Result of bitwise left shift operation:\n");
    print_array(result_left_shift, SIZE);

    // Bitwise right shift operation
    int result_right_shift = 0;
    for(i=0; i<SIZE; i++) {
        result_right_shift |= (arr[i] >> 4);
    }
    printf("Result of bitwise right shift operation:\n");
    print_array(result_right_shift, SIZE);

    return 0;
}