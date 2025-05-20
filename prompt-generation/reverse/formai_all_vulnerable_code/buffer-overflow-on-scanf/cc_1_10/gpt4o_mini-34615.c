//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to convert decimal number to binary string
void decimalToBinary(int num, char *binaryString) {
    for (int i = 31; i >= 0; i--) {
        binaryString[i] = (num & (1 << i)) ? '1' : '0';
    }
    binaryString[32] = '\0'; // Null-terminate the string
}

// Function to calculate bitwise AND
int bitwiseAnd(int a, int b) {
    return a & b;
}

// Function to calculate bitwise OR
int bitwiseOr(int a, int b) {
    return a | b;
}

// Function to calculate bitwise XOR
int bitwiseXor(int a, int b) {
    return a ^ b;
}

// Function to calculate bitwise NOT
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

void printMenu() {
    printf("\nBitwise Operations Menu:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Exit\n");
    printf("Choose an operation (1-7): ");
}

int main() {
    int choice;
    int num1, num2;
    char binary1[33], binary2[33], resultBinary[33];
    
    while (1) {
        printMenu();
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting... \n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two integers: ");
                scanf("%d %d", &num1, &num2);
                printf("Bitwise AND of %d and %d is %d\n", num1, num2, bitwiseAnd(num1, num2));
                break;
            case 2:
                printf("Enter two integers: ");
                scanf("%d %d", &num1, &num2);
                printf("Bitwise OR of %d and %d is %d\n", num1, num2, bitwiseOr(num1, num2));
                break;
            case 3:
                printf("Enter two integers: ");
                scanf("%d %d", &num1, &num2);
                printf("Bitwise XOR of %d and %d is %d\n", num1, num2, bitwiseXor(num1, num2));
                break;
            case 4:
                printf("Enter an integer: ");
                scanf("%d", &num1);
                printf("Bitwise NOT of %d is %d\n", num1, bitwiseNot(num1));
                break;
            case 5:
                printf("Enter an integer and number of positions to shift: ");
                scanf("%d %d", &num1, &num2);
                printf("%d left shifted by %d is %d\n", num1, num2, leftShift(num1, num2));
                break;
            case 6:
                printf("Enter an integer and number of positions to shift: ");
                scanf("%d %d", &num1, &num2);
                printf("%d right shifted by %d is %d\n", num1, num2, rightShift(num1, num2));
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                continue;
        }

        // Display binary representations
        decimalToBinary(num1, binary1);
        decimalToBinary(num2, binary2);
        if (choice < 4) {
            decimalToBinary(bitwiseAnd(num1, num2), resultBinary);
            printf("Binary representation of %d: %s\n", num1, binary1);
            printf("Binary representation of %d: %s\n", num2, binary2);
            printf("Resulting Binary: %s\n", resultBinary);
        } else if (choice == 4) {
            decimalToBinary(bitwiseNot(num1), resultBinary);
            printf("Binary representation of %d: %s\n", num1, binary1);
            printf("Resulting Binary: %s\n", resultBinary);
        }
    }

    return 0;
}