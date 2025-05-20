//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of a number
void printBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// Function to perform bitwise AND operation
int bitwiseAND(int a, int b) {
    return a & b;
}

// Function to perform bitwise OR operation
int bitwiseOR(int a, int b) {
    return a | b;
}

// Function to perform bitwise XOR operation
int bitwiseXOR(int a, int b) {
    return a ^ b;
}

// Function to perform bitwise NOT operation
int bitwiseNOT(int a) {
    return ~a;
}

// Function to left shift a number
int leftShift(int a, int shift) {
    return a << shift;
}

// Function to right shift a number
int rightShift(int a, int shift) {
    return a >> shift;
}

int main() {
    int num1, num2, choice, shift;
    
    // Welcome Message
    printf("Welcome to the Curious Bitwise Operations Program!\n");
    printf("---------------------------------------------\n");

    // Input two numbers
    printf("Enter the first integer: ");
    scanf("%d", &num1);
    printf("Enter the second integer: ");
    scanf("%d", &num2);

    // Menu for bitwise operations
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Bitwise AND\n");
        printf("2. Bitwise OR\n");
        printf("3. Bitwise XOR\n");
        printf("4. Bitwise NOT (first number)\n");
        printf("5. Bitwise NOT (second number)\n");
        printf("6. Left Shift (first number)\n");
        printf("7. Right Shift (first number)\n");
        printf("8. Exit\n");
        printf("Your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("You chose Bitwise AND.\n");
                printf("Binary representation of %d: ", num1);
                printBinary(num1);
                printf("Binary representation of %d: ", num2);
                printBinary(num2);
                printf("Result of %d & %d = %d\n", num1, num2, bitwiseAND(num1, num2));
                break;
                
            case 2:
                printf("You chose Bitwise OR.\n");
                printf("Result of %d | %d = %d\n", num1, num2, bitwiseOR(num1, num2));
                break;
                
            case 3:
                printf("You chose Bitwise XOR.\n");
                printf("Result of %d ^ %d = %d\n", num1, num2, bitwiseXOR(num1, num2));
                break;
                
            case 4:
                printf("You chose Bitwise NOT (first number).\n");
                printf("Result of ~%d = %d\n", num1, bitwiseNOT(num1));
                break;
                
            case 5:
                printf("You chose Bitwise NOT (second number).\n");
                printf("Result of ~%d = %d\n", num2, bitwiseNOT(num2));
                break;
                
            case 6:
                printf("You chose Left Shift (first number).\n");
                printf("Enter number of bits to shift: ");
                scanf("%d", &shift);
                printf("Result of %d << %d = %d\n", num1, shift, leftShift(num1, shift));
                break;
                
            case 7:
                printf("You chose Right Shift (first number).\n");
                printf("Enter number of bits to shift: ");
                scanf("%d", &shift);
                printf("Result of %d >> %d = %d\n", num1, shift, rightShift(num1, shift));
                break;

            case 8:
                printf("Thank you for using the Curious Bitwise Operations Program!\n");
                exit(0);

            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }
    
    return 0;
}