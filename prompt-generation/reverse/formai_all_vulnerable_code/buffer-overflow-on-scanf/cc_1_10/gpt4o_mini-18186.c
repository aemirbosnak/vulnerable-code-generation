//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: paranoid
#include <stdio.h>

// Function prototypes for various bitwise operations
void displayBits(unsigned int n);
unsigned int bitwiseAnd(unsigned int a, unsigned int b);
unsigned int bitwiseOr(unsigned int a, unsigned int b);
unsigned int bitwiseXor(unsigned int a, unsigned int b);
unsigned int bitwiseNot(unsigned int a);
unsigned int leftShift(unsigned int a, int shift);
unsigned int rightShift(unsigned int a, int shift);
void paranoidCheck(unsigned int val);

int main() {
    unsigned int a, b;
    
    // The paranoia begins
    printf("Welcome to the Bitwise Operation Paranoia Simulator!\n");
    
    printf("Enter a non-negative integer (a): ");
    scanf("%u", &a);
    
    printf("Enter another non-negative integer (b): ");
    scanf("%u", &b);
    
    // Displaying binary representations
    printf("\nBinary representation of a (%.8X): ", a);
    displayBits(a);
    
    printf("\nBinary representation of b (%.8X): ", b);
    displayBits(b);
    
    // Exploring the dangers of bitwise operations
    paranoidCheck(a);
    paranoidCheck(b);
    
    // Perform bitwise operations
    unsigned int andResult = bitwiseAnd(a, b);
    unsigned int orResult = bitwiseOr(a, b);
    unsigned int xorResult = bitwiseXor(a, b);
    unsigned int notA = bitwiseNot(a);
    unsigned int notB = bitwiseNot(b);
    
    unsigned int leftShiftResult = leftShift(a, 2); // shift left by 2
    unsigned int rightShiftResult = rightShift(b, 2); // shift right by 2
    
    printf("\nResults of Bitwise Operations:\n");
    printf("A AND B = %.8X -> ", andResult);
    displayBits(andResult);
    
    printf("A OR B = %.8X -> ", orResult);
    displayBits(orResult);
    
    printf("A XOR B = %.8X -> ", xorResult);
    displayBits(xorResult);
    
    printf("NOT A = %.8X -> ", notA);
    displayBits(notA);
    
    printf("NOT B = %.8X -> ", notB);
    displayBits(notB);
    
    printf("A << 2 = %.8X -> ", leftShiftResult);
    displayBits(leftShiftResult);
    
    printf("B >> 2 = %.8X -> ", rightShiftResult);
    displayBits(rightShiftResult);
    
    printf("\nEnd of paranoid simulation.\n");
    return 0;
}

// Function to display bits of an integer
void displayBits(unsigned int n) {
    for(int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%u", (n >> i) & 1);
        if (i % 4 == 0) {
            printf(" "); // Space for better readability
        }
    }
}

// Function to perform bitwise AND
unsigned int bitwiseAnd(unsigned int a, unsigned int b) {
    return a & b;
}

// Function to perform bitwise OR
unsigned int bitwiseOr(unsigned int a, unsigned int b) {
    return a | b;
}

// Function to perform bitwise XOR
unsigned int bitwiseXor(unsigned int a, unsigned int b) {
    return a ^ b;
}

// Function to perform bitwise NOT
unsigned int bitwiseNot(unsigned int a) {
    return ~a;
}

// Function to perform left shift
unsigned int leftShift(unsigned int a, int shift) {
    return a << shift;
}

// Function to perform right shift
unsigned int rightShift(unsigned int a, int shift) {
    return a >> shift;
}

// Function to conduct a paranoia check on the value
void paranoidCheck(unsigned int val) {
    if (val == 0) {
        printf("Warning: You entered zero! It's an unsafe value! \n");
    } else if (val > 1000) {
        printf("Caution: High value detected (value: %u)! Are you sure? \n", val);
    } else {
        printf("Value %u seems safe. Proceeding with caution...\n", val);
    }
}