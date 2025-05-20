//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>

// Function Declarations
void displayBits(unsigned int n);
unsigned int setBit(unsigned int n, int position);
unsigned int clearBit(unsigned int n, int position);
unsigned int toggleBit(unsigned int n, int position);
int checkBit(unsigned int n, int position);
void performBitwiseOperations(unsigned int num);

int main() {
    unsigned int number;

    printf("Enter an unsigned integer: ");
    scanf("%u", &number);
    
    printf("Initial number in binary: ");
    displayBits(number);
    
    performBitwiseOperations(number);

    return 0;
}

// Function Definitions

// Function to display bits of a number
void displayBits(unsigned int n) {
    unsigned int maxBits = sizeof(n) * 8; // Maximum bits based on the size of the number
    for (int i = maxBits - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// Function to set a bit at a specific position
unsigned int setBit(unsigned int n, int position) {
    return n | (1 << position);
}

// Function to clear a bit at a specific position
unsigned int clearBit(unsigned int n, int position) {
    return n & ~(1 << position);
}

// Function to toggle a bit at a specific position
unsigned int toggleBit(unsigned int n, int position) {
    return n ^ (1 << position);
}

// Function to check if a bit at a specific position is set or not
int checkBit(unsigned int n, int position) {
    return (n >> position) & 1;
}

// Function to perform a series of bitwise operations
void performBitwiseOperations(unsigned int num) {
    int position;

    // Set a bit
    printf("Enter the position to set a bit (0 to %lu): ", sizeof(num) * 8 - 1);
    scanf("%d", &position);
    num = setBit(num, position);
    printf("After setting bit at position %d: ", position);
    displayBits(num);

    // Clear a bit
    printf("Enter the position to clear a bit (0 to %lu): ", sizeof(num) * 8 - 1);
    scanf("%d", &position);
    num = clearBit(num, position);
    printf("After clearing bit at position %d: ", position);
    displayBits(num);

    // Toggle a bit
    printf("Enter the position to toggle a bit (0 to %lu): ", sizeof(num) * 8 - 1);
    scanf("%d", &position);
    num = toggleBit(num, position);
    printf("After toggling bit at position %d: ", position);
    displayBits(num);

    // Check a bit
    printf("Enter the position to check a bit (0 to %lu): ", sizeof(num) * 8 - 1);
    scanf("%d", &position);
    if (checkBit(num, position)) {
        printf("Bit at position %d is set.\n", position);
    } else {
        printf("Bit at position %d is not set.\n", position);
    }

    // Final result
    printf("Final number in binary: ");
    displayBits(num);
}