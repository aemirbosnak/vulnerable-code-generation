//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

// Function to print a binary number
void print_binary(int num) {
    char binary[MAX_SIZE];
    int i = 0, j = 0;
    while (num > 0) {
        if (num & 1) {
            binary[i++] = '1';
        } else {
            binary[i++] = '0';
        }
        num >>= 1;
    }
    while (i < MAX_SIZE) {
        binary[i++] = '0';
    }
    printf("%s", &binary[MAX_SIZE - j]);
}

// Function to print a decimal number
void print_decimal(int num) {
    printf("%d", num);
}

// Function to perform bitwise operations
void bitwise_operations(int num1, int num2, int operation) {
    switch (operation) {
        case 1: // Bitwise AND
            printf("Bitwise AND: ");
            print_binary(num1 & num2);
            break;
        case 2: // Bitwise OR
            printf("Bitwise OR: ");
            print_binary(num1 | num2);
            break;
        case 3: // Bitwise XOR
            printf("Bitwise XOR: ");
            print_binary(num1 ^ num2);
            break;
        case 4: // Bitwise NOT
            printf("Bitwise NOT: ");
            print_binary(~num1);
            break;
        case 5: // Bitwise Left Shift
            printf("Bitwise Left Shift: ");
            print_binary(num1 << num2);
            break;
        case 6: // Bitwise Right Shift
            printf("Bitwise Right Shift: ");
            print_binary(num1 >> num2);
            break;
        default:
            printf("Invalid operation\n");
    }
}

int main() {
    // Prompt user for input
    int num1, num2, operation;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Enter operation (1-6): ");
    scanf("%d", &operation);

    // Perform bitwise operation
    bitwise_operations(num1, num2, operation);

    return 0;
}