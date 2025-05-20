//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to print the binary representation of a number
void printBinary(unsigned int num) {
    printf("Binary representation: ");
    for (int i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

// Function to perform bitwise operations on two numbers
void bitwiseOperations(unsigned int num1, unsigned int num2, char operation) {
    switch (operation) {
        case '&':
            printf("Bitwise AND: ");
            printf("%u\n", num1 & num2);
            break;
        case '|':
            printf("Bitwise OR: ");
            printf("%u\n", num1 | num2);
            break;
        case '^':
            printf("Bitwise XOR: ");
            printf("%u\n", num1 ^ num2);
            break;
        case '~':
            printf("Bitwise NOT: ");
            printf("%u\n", ~num1);
            break;
        case 'L':
            printf("Left shift: ");
            printf("%u\n", num1 << num2);
            break;
        case 'R':
            printf("Right shift: ");
            printf("%u\n", num1 >> num2);
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }
}

int main() {
    int choice, num1, num2;
    char operation;

    // Take input from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operation (+, -, *, /, &, |, ^, ~, L, R): ");
    scanf(" %c", &operation);

    // Perform bitwise operations on the two numbers
    bitwiseOperations(num1, num2, operation);

    // Print the binary representation of the two numbers
    printf("Binary representation of %d: ", num1);
    printBinary(num1);
    printf("Binary representation of %d: ", num2);
    printBinary(num2);

    return 0;
}