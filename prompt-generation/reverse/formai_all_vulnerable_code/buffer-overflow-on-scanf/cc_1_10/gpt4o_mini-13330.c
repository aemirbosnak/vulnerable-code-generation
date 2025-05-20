//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: scalable
#include <stdio.h>
#include <stdbool.h>

// Function to get the bits of a number in an array
void getBits(int num, int bits[]) {
    for (int i = 0; i < 32; i++) {
        bits[i] = (num >> (31 - i)) & 1; // Extract each bit from the number
    }
}

// Function to print bits in a readable format
void printBits(int bits[]) {
    for (int i = 0; i < 32; i++) {
        printf("%d", bits[i]);
        if (i % 4 == 3 && i < 31) {
            printf(" "); // Space after every 4 bits
        }
    }
    printf("\n");
}

// Function to perform bitwise AND
int bitwiseAnd(int a, int b) {
    return a & b;
}

// Function to perform bitwise OR
int bitwiseOr(int a, int b) {
    return a | b;
}

// Function to perform bitwise XOR
int bitwiseXor(int a, int b) {
    return a ^ b;
}

// Function to perform bitwise NOT
int bitwiseNot(int a) {
    return ~a;
}

// Function to perform left shift
int leftShift(int a, int positions) {
    return a << positions;
}

// Function to perform right shift
int rightShift(int a, int positions) {
    return a >> positions;
}

// Function to count the number of set bits (1s)
int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1; // Increment if the least significant bit is 1
        num >>= 1;        // Shift right by 1
    }
    return count;
}

// Function to check if a number is a power of two using bitwise operations
bool isPowerOfTwo(int num) {
    return (num > 0) && ((num & (num - 1)) == 0);
}

// Function to toggle bits between two numbers
int toggleBits(int a, int b) {
    return a ^ b;
}

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    // Arrays to store individual bits
    int bitsA[32], bitsB[32];

    // Get bits for both numbers
    getBits(a, bitsA);
    getBits(b, bitsB);

    // Print bits of a
    printf("Bits of %d: ", a);
    printBits(bitsA);

    // Print bits of b
    printf("Bits of %d: ", b);
    printBits(bitsB);
    
    // Perform bitwise operations
    printf("\nBitwise AND: %d\n", bitwiseAnd(a, b));
    printf("Bitwise OR: %d\n", bitwiseOr(a, b));
    printf("Bitwise XOR: %d\n", bitwiseXor(a, b));
    printf("Bitwise NOT of %d: %d\n", a, bitwiseNot(a));
    
    // Shift operations
    printf("Left shift %d by 1: %d\n", a, leftShift(a, 1));
    printf("Right shift %d by 1: %d\n", a, rightShift(a, 1));
    
    // Count set bits
    printf("Number of set bits in %d: %d\n", a, countSetBits(a));
    printf("Number of set bits in %d: %d\n", b, countSetBits(b));

    // Check if numbers are powers of two
    printf("%d is %spower of 2.\n", a, isPowerOfTwo(a) ? "" : "not a ");
    printf("%d is %spower of 2.\n", b, isPowerOfTwo(b) ? "" : "not a ");

    // Toggle bits between two numbers
    printf("Toggle bits between %d and %d gives: %d\n", a, b, toggleBits(a, b));

    return 0;
}