//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define futuristic function prototypes
void bitwise_operations(unsigned char a, unsigned char b, char operation);
void print_binary(unsigned char num);

// Main function
int main() {
    unsigned char num1, num2;
    char operation;

    // Get user input
    printf("Enter two numbers in binary format separated by space: ");
    scanf("%c%c", &num1, &num2);
    printf("Enter the operation you want to perform (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform bitwise operations
    bitwise_operations(num1, num2, operation);

    return 0;
}

// Bitwise operations function
void bitwise_operations(unsigned char a, unsigned char b, char operation) {
    switch(operation) {
        case '+':
            // Bitwise OR
            printf("The result of OR operation is: ");
            print_binary(a | b);
            break;
        case '-':
            // Bitwise AND
            printf("The result of AND operation is: ");
            print_binary(a & b);
            break;
        case '*':
            // Bitwise XOR
            printf("The result of XOR operation is: ");
            print_binary(a ^ b);
            break;
        case '/':
            // Bitwise NOT
            printf("The result of NOT operation on first number is: ");
            print_binary(~a);
            break;
        default:
            printf("Invalid operation. Please enter a valid operation.\n");
            break;
    }
}

// Function to print binary representation of a number
void print_binary(unsigned char num) {
    int i = 7;
    while(num > 0) {
        if(num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
        i--;
    }
}