//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: high level of detail
#include <stdio.h>

// Function to perform AND operation
int bitwise_and(int a, int b) {
    return a & b;
}

// Function to perform OR operation
int bitwise_or(int a, int b) {
    return a | b;
}

// Function to perform XOR operation
int bitwise_xor(int a, int b) {
    return a ^ b;
}

// Function to perform NOT operation
int bitwise_not(int a) {
    return ~a;
}

// Function to perform left shift
int left_shift(int a, int shift) {
    return a << shift;
}

// Function to perform right shift
int right_shift(int a, int shift) {
    return a >> shift;
}

// Function to display binary representation of an integer
void display_binary(int a) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (a >> i) & 1);
        if (i % 4 == 0) {
            printf(" "); // Adding space for better readability
        }
    }
    printf("\n");
}

// Main function
int main() {
    int num1, num2, shift;
    // User instructions
    printf("Welcome to the Bitwise Operations Program!\n");
    printf("This program allows you to perform various bitwise operations on two integers.\n");

    // User input for two integers
    printf("Please enter the first integer: ");
    scanf("%d", &num1);
    printf("Please enter the second integer: ");
    scanf("%d", &num2);

    // Displaying the binary representation of the numbers
    printf("\nBinary representation of %d: ", num1);
    display_binary(num1);
    printf("Binary representation of %d: ", num2);
    display_binary(num2);

    // Performing bitwise operations
    printf("\nBitwise Operations:\n");
    printf("-------------------------------\n");
    printf("A (AND) B: %d\n", bitwise_and(num1, num2));
    printf("A (OR) B: %d\n", bitwise_or(num1, num2));
    printf("A (XOR) B: %d\n", bitwise_xor(num1, num2));
    printf("NOT A: %d\n", bitwise_not(num1));
    printf("NOT B: %d\n", bitwise_not(num2));

    // Shift Operations
    printf("\nEnter number of positions to shift (should be non-negative): ");
    scanf("%d", &shift);
    printf("A << %d: %d\n", shift, left_shift(num1, shift));
    printf("A >> %d: %d\n", shift, right_shift(num1, shift));
    printf("B << %d: %d\n", shift, left_shift(num2, shift));
    printf("B >> %d: %d\n", shift, right_shift(num2, shift));

    // Final message
    printf("\nThank you for using the Bitwise Operations Program!\n");
    return 0;
}