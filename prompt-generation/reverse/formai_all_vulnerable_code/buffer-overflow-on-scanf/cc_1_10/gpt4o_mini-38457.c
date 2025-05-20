//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

#define MAX_NUM 256    // Set a maximum number for operations
#define BIT_COUNT 8    // We will use 8 bits for our example

// Function to display the binary representation of a number
void displayBinary(unsigned char num) {
    for(int i = BIT_COUNT - 1; i >= 0; i--) {
        putchar((num & (1 << i)) ? '1' : '0');
    }
    putchar('\n');
}

// Function to perform bitwise AND operation
unsigned char bitwiseAND(unsigned char a, unsigned char b) {
    return a & b;
}

// Function to perform bitwise OR operation
unsigned char bitwiseOR(unsigned char a, unsigned char b) {
    return a | b;
}

// Function to perform bitwise XOR operation
unsigned char bitwiseXOR(unsigned char a, unsigned char b) {
    return a ^ b;
}

// Function to perform bitwise NOT operation
unsigned char bitwiseNOT(unsigned char a) {
    return ~a;
}

// Function to shift bits to the left
unsigned char leftShift(unsigned char a, int shift) {
    return a << shift;
}

// Function to shift bits to the right
unsigned char rightShift(unsigned char a, int shift) {
    return a >> shift;
}

int main() {
    unsigned char num1, num2;

    printf("Enter two numbers between 0 and %d: \n", MAX_NUM - 1);
    scanf("%hhu %hhu", &num1, &num2);

    if(num1 >= MAX_NUM || num2 >= MAX_NUM) {
        printf("Please enter numbers within range 0 to %d\n", MAX_NUM - 1);
        return 1; // Exit the program if numbers are out of range
    }

    printf("Number 1: %d (Binary: ", num1);
    displayBinary(num1);
    printf("Number 2: %d (Binary: ", num2);
    displayBinary(num2);

    // Bitwise AND
    unsigned char andResult = bitwiseAND(num1, num2);
    printf("Bitwise AND: %d (Binary: ", andResult);
    displayBinary(andResult);

    // Bitwise OR
    unsigned char orResult = bitwiseOR(num1, num2);
    printf("Bitwise OR: %d (Binary: ", orResult);
    displayBinary(orResult);

    // Bitwise XOR
    unsigned char xorResult = bitwiseXOR(num1, num2);
    printf("Bitwise XOR: %d (Binary: ", xorResult);
    displayBinary(xorResult);

    // Bitwise NOT
    unsigned char notResult1 = bitwiseNOT(num1);
    unsigned char notResult2 = bitwiseNOT(num2);
    printf("Bitwise NOT on Number 1: %d (Binary: ", notResult1);
    displayBinary(notResult1);
    printf("Bitwise NOT on Number 2: %d (Binary: ", notResult2);
    displayBinary(notResult2);

    // Left Shift
    int shift;
    printf("Enter the number of positions to shift left: ");
    scanf("%d", &shift);
    unsigned char leftShiftResult = leftShift(num1, shift);
    printf("Left Shift of Number 1: %d (Binary: ", leftShiftResult);
    displayBinary(leftShiftResult);

    // Right Shift
    printf("Enter the number of positions to shift right: ");
    scanf("%d", &shift);
    unsigned char rightShiftResult = rightShift(num1, shift);
    printf("Right Shift of Number 1: %d (Binary: ", rightShiftResult);
    displayBinary(rightShiftResult);

    printf("\nFancy operations complete! Experiment with more numbers next time!\n");
    return 0;
}