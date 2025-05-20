//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

// Function prototypes
int generateRandomNumber();
void displayBinary(int n);
int bitwiseAND(int a, int b);
int bitwiseOR(int a, int b);
int bitwiseXOR(int a, int b);
int bitwiseNOT(int a);
int leftShift(int a, int positions);
int rightShift(int a, int positions);

int main() {
    srand(time(0)); // Seed for random number generation

    int num1 = generateRandomNumber();
    int num2 = generateRandomNumber();

    printf("Randomly generated numbers: %d and %d\n\n", num1, num2);
    
    // Display the binary representations of the numbers
    printf("Binary representation of %d: ", num1);
    displayBinary(num1);
    
    printf("Binary representation of %d: ", num2);
    displayBinary(num2);
    
    // Bitwise operations
    printf("\nPerforming Bitwise Operations:\n");

    int andResult = bitwiseAND(num1, num2);
    printf("%d AND %d = ", num1, num2);
    displayBinary(andResult);

    int orResult = bitwiseOR(num1, num2);
    printf("%d OR %d = ", num1, num2);
    displayBinary(orResult);

    int xorResult = bitwiseXOR(num1, num2);
    printf("%d XOR %d = ", num1, num2);
    displayBinary(xorResult);

    int notResult = bitwiseNOT(num1);
    printf("NOT %d = ", num1);
    displayBinary(notResult);

    // Left Shift
    int shiftLeftResult = leftShift(num1, 2);
    printf("%d << 2 = ", num1);
    displayBinary(shiftLeftResult);

    // Right Shift
    int shiftRightResult = rightShift(num2, 2);
    printf("%d >> 2 = ", num2);
    displayBinary(shiftRightResult);

    printf("\nThanks for exploring Bitwise Operations!\n");
    return 0;
}

// Function to generate a random number between 0 and MAX_NUM
int generateRandomNumber() {
    return rand() % (MAX_NUM + 1);
}

// Function to display the binary representation of a number
void displayBinary(int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        putchar((n & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}

// Function for bitwise AND
int bitwiseAND(int a, int b) {
    return a & b;
}

// Function for bitwise OR
int bitwiseOR(int a, int b) {
    return a | b;
}

// Function for bitwise XOR
int bitwiseXOR(int a, int b) {
    return a ^ b;
}

// Function for bitwise NOT
int bitwiseNOT(int a) {
    return ~a;
}

// Function for left shift
int leftShift(int a, int positions) {
    return a << positions;
}

// Function for right shift
int rightShift(int a, int positions) {
    return a >> positions;
}