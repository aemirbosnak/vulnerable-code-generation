//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void displayBinary(unsigned int n) {
    for(int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%u", (n >> i) & 1);
    }
}

unsigned int flipBits(unsigned int num) {
    return ~num;
}

unsigned int leftRotate(unsigned int num, unsigned int rotations) {
    return (num << rotations) | (num >> (sizeof(num) * 8 - rotations));
}

unsigned int rightRotate(unsigned int num, unsigned int rotations) {
    return (num >> rotations) | (num << (sizeof(num) * 8 - rotations));
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

int main() {
    unsigned int num1, num2;

    printf("Welcome to the Bitwise Operations Surprise Program!\n");
    printf("Enter two unsigned integers:\n");
    
    if(scanf("%u %u", &num1, &num2) != 2) {
        printf("Invalid input. Please enter unsigned integers only.\n");
        return 1;
    }

    printf("\nYou entered:\n");
    printf("Num 1: %u\nNum 2: %u\n", num1, num2);

    printf("\nDisplaying binary representations:\n");
    printf("Num 1 in binary: ");
    displayBinary(num1);
    printf("\nNum 2 in binary: ");
    displayBinary(num2);
    printf("\n");

    printf("Performing bitwise AND...\n");
    unsigned int andResult = bitwiseAND(num1, num2);
    printf("Num 1 & Num 2 = %u\n", andResult);
    printf("Binary: ");
    displayBinary(andResult);
    printf("\n");

    printf("Performing bitwise OR...\n");
    unsigned int orResult = bitwiseOR(num1, num2);
    printf("Num 1 | Num 2 = %u\n", orResult);
    printf("Binary: ");
    displayBinary(orResult);
    printf("\n");

    printf("Performing bitwise XOR...\n");
    unsigned int xorResult = bitwiseXOR(num1, num2);
    printf("Num 1 ^ Num 2 = %u\n", xorResult);
    printf("Binary: ");
    displayBinary(xorResult);
    printf("\n");

    printf("Flipping bits of Num 1...\n");
    unsigned int flippedNum1 = flipBits(num1);
    printf("Flipped Num 1 = %u\n", flippedNum1);
    printf("Binary: ");
    displayBinary(flippedNum1);
    printf("\n");

    printf("Flipping bits of Num 2...\n");
    unsigned int flippedNum2 = flipBits(num2);
    printf("Flipped Num 2 = %u\n", flippedNum2);
    printf("Binary: ");
    displayBinary(flippedNum2);
    printf("\n");

    unsigned int rotations;
    printf("How many bits would you like to rotate? (1 - %zu bits)\n", sizeof(unsigned int) * 8);
    if(scanf("%u", &rotations) != 1 || rotations > sizeof(unsigned int) * 8) {
        printf("Invalid rotation number.\n");
        return 1;
    }

    printf("\nLeft rotating Num 1 by %u bits...\n", rotations);
    unsigned int leftRotatedNum1 = leftRotate(num1, rotations);
    printf("Left Rotated Num 1 = %u\n", leftRotatedNum1);
    printf("Binary: ");
    displayBinary(leftRotatedNum1);
    printf("\n");

    printf("Right rotating Num 1 by %u bits...\n", rotations);
    unsigned int rightRotatedNum1 = rightRotate(num1, rotations);
    printf("Right Rotated Num 1 = %u\n", rightRotatedNum1);
    printf("Binary: ");
    displayBinary(rightRotatedNum1);
    printf("\n");

    printf("Left rotating Num 2 by %u bits...\n", rotations);
    unsigned int leftRotatedNum2 = leftRotate(num2, rotations);
    printf("Left Rotated Num 2 = %u\n", leftRotatedNum2);
    printf("Binary: ");
    displayBinary(leftRotatedNum2);
    printf("\n");

    printf("Right rotating Num 2 by %u bits...\n", rotations);
    unsigned int rightRotatedNum2 = rightRotate(num2, rotations);
    printf("Right Rotated Num 2 = %u\n", rightRotatedNum2);
    printf("Binary: ");
    displayBinary(rightRotatedNum2);
    printf("\n");

    printf("All operations completed successfully! Thank you for using the Surprise Bitwise Operations Program!\n");

    return 0;
}