//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[MAX_SIZE];
    printf("Enter the elements of the array: ");
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    // Bitwise Operations
    int sum = 0;
    for(int i=0; i<size; i++) {
        sum |= arr[i];
    }
    printf("Sum of all elements: %d\n", sum);

    int product = 1;
    for(int i=0; i<size; i++) {
        product &= arr[i];
    }
    printf("Product of all elements: %d\n", product);

    int difference = 0;
    for(int i=0; i<size; i++) {
        difference ^= arr[i];
    }
    printf("Difference of all elements: %d\n", difference);

    int bitwise_and = 0;
    for(int i=0; i<size; i++) {
        bitwise_and &= arr[i];
    }
    printf("Bitwise AND of all elements: %d\n", bitwise_and);

    int bitwise_or = 0;
    for(int i=0; i<size; i++) {
        bitwise_or |= arr[i];
    }
    printf("Bitwise OR of all elements: %d\n", bitwise_or);

    int bitwise_xor = 0;
    for(int i=0; i<size; i++) {
        bitwise_xor ^= arr[i];
    }
    printf("Bitwise XOR of all elements: %d\n", bitwise_xor);

    int bitwise_not = 0;
    for(int i=0; i<size; i++) {
        bitwise_not ^= arr[i];
    }
    printf("Bitwise NOT of all elements: %d\n", bitwise_not);

    int bitwise_left_shift = 0;
    for(int i=0; i<size; i++) {
        bitwise_left_shift <<= arr[i];
    }
    printf("Bitwise left shift of all elements: %d\n", bitwise_left_shift);

    int bitwise_right_shift = 0;
    for(int i=0; i<size; i++) {
        bitwise_right_shift >>= arr[i];
    }
    printf("Bitwise right shift of all elements: %d\n", bitwise_right_shift);

    return 0;
}