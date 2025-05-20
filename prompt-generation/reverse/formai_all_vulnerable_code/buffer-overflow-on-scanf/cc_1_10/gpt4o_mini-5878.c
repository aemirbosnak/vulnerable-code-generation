//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h>

// Function prototypes
void displayBits(unsigned int n);
unsigned int bitwiseAND(unsigned int a, unsigned int b);
unsigned int bitwiseOR(unsigned int a, unsigned int b);
unsigned int bitwiseXOR(unsigned int a, unsigned int b);
unsigned int bitwiseNOT(unsigned int a);
unsigned int leftShift(unsigned int n, unsigned int pos);
unsigned int rightShift(unsigned int n, unsigned int pos);

int main() {
    unsigned int num1, num2;
    printf("Enter two unsigned integers:\n");
    printf("Num1: ");
    scanf("%u", &num1);
    printf("Num2: ");
    scanf("%u", &num2);

    printf("\nYou entered:\n");
    printf("Num1: ");
    displayBits(num1);
    printf("Num2: ");
    displayBits(num2);

    printf("\nBitwise Operations Results:\n");
    printf("A (AND) B: ");
    displayBits(bitwiseAND(num1, num2));
    printf("A (OR) B: ");
    displayBits(bitwiseOR(num1, num2));
    printf("A (XOR) B: ");
    displayBits(bitwiseXOR(num1, num2));
    printf("A (NOT) B: ");
    displayBits(bitwiseNOT(num1));
    printf("B (NOT) A: ");
    displayBits(bitwiseNOT(num2));

    unsigned int shift_pos;
    printf("\nEnter the number of positions to shift left/right: ");
    scanf("%u", &shift_pos);
    
    printf("\nLeft Shift A by %u: ", shift_pos);
    displayBits(leftShift(num1, shift_pos));
    printf("Right Shift A by %u: ", shift_pos);
    displayBits(rightShift(num1, shift_pos));

    return 0;
}

unsigned int bitwiseAND(unsigned int a, unsigned int b) {
    return a & b;
}

unsigned int bitwiseOR(unsigned int a, unsigned int b) {
    return a | b;
}

unsigned int bitwiseXOR(unsigned int a, unsigned int b) {
    return a ^ b;
}

unsigned int bitwiseNOT(unsigned int a) {
    return ~a;
}

unsigned int leftShift(unsigned int n, unsigned int pos) {
    return n << pos;
}

unsigned int rightShift(unsigned int n, unsigned int pos) {
    return n >> pos;
}

void displayBits(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%u", (n >> i) & 1);
        if (i % 4 == 0) {
            printf(" "); // Adding space for clarity
        }
    }
    printf("\n");
}