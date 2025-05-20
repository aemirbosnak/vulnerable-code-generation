//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define BIT_SIZE 8

// Function to print the binary representation of a number
void print_binary(int num) {
    for (int i = BIT_SIZE - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

// Function to perform bitwise AND operation
int bitwise_and(int num1, int num2) {
    return num1 & num2;
}

// Function to perform bitwise OR operation
int bitwise_or(int num1, int num2) {
    return num1 | num2;
}

// Function to perform bitwise XOR operation
int bitwise_xor(int num1, int num2) {
    return num1 ^ num2;
}

// Function to perform bitwise NOT operation
int bitwise_not(int num) {
    return ~num;
}

// Function to perform left shift operation
int left_shift(int num, int shift) {
    return num << shift;
}

// Function to perform right shift operation
int right_shift(int num, int shift) {
    return num >> shift;
}

int main() {
    int num1, num2, choice;

    // Input two numbers from user
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Perform bitwise operations based on user choice
    printf("Select operation:\n1. Bitwise AND\n2. Bitwise OR\n3. Bitwise XOR\n4. Bitwise NOT\n5. Left Shift\n6. Right Shift\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Bitwise AND: ");
            printf("%d\n", bitwise_and(num1, num2));
            break;
        case 2:
            printf("Bitwise OR: ");
            printf("%d\n", bitwise_or(num1, num2));
            break;
        case 3:
            printf("Bitwise XOR: ");
            printf("%d\n", bitwise_xor(num1, num2));
            break;
        case 4:
            printf("Bitwise NOT: ");
            printf("%d\n", bitwise_not(num1));
            break;
        case 5:
            printf("Left Shift: ");
            printf("%d\n", left_shift(num1, 2));
            break;
        case 6:
            printf("Right Shift: ");
            printf("%d\n", right_shift(num1, 2));
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}