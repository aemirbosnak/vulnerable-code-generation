//FormAI DATASET v1.0 Category: Bitwise operations ; Style: optimized
#include <stdio.h>

// Function to check if a number is even or odd using bitwise operators
void evenOrOdd(int num) {
    if (num & 1) {
        printf("%d is odd\n", num);
    } else {
        printf("%d is even\n", num);
    }
}

// Function to reverse bits of a number using bitwise operators
unsigned int reverseBits(unsigned int num) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        if (num & (1 << i)) {
            result |= 1;
        }
    }
    return result;
}

// Function to swap two numbers using bitwise operators
void swap(int* x, int* y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

// Function to count number of set bits in a number using bitwise operators
int countSetBits(unsigned int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int num1 = 10;
    int num2 = 20;

    // Check if num1 is even or odd
    evenOrOdd(num1);

    // Swap num1 and num2
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);

    // Reverse bits of num1
    printf("Before reverse: %d\n", num1);
    unsigned int reversed = reverseBits(num1);
    printf("After reverse: %u\n", reversed);

    // Count number of set bits in num2
    printf("Number of set bits in %d: %d\n", num2, countSetBits(num2));

    return 0;
}