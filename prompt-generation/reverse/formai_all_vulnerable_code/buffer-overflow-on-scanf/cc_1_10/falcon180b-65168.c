//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to print the binary representation of a number
void print_binary(unsigned int num) {
    int i = 0;
    while (num > 0) {
        printf("%d", num & 1);
        num >>= 1;
        i++;
        if (i == 8) {
            printf("\n");
            i = 0;
        }
    }
}

// Function to perform bitwise operations on two numbers
void bitwise_operations(unsigned int num1, unsigned int num2, char operation) {
    unsigned int result = 0;

    switch (operation) {
        case '&': // Bitwise AND
            result = num1 & num2;
            printf("Bitwise AND: ");
            print_binary(result);
            break;

        case '|': // Bitwise OR
            result = num1 | num2;
            printf("Bitwise OR: ");
            print_binary(result);
            break;

        case '^': // Bitwise XOR
            result = num1 ^ num2;
            printf("Bitwise XOR: ");
            print_binary(result);
            break;

        case '~': // Bitwise NOT
            result = ~num1;
            printf("Bitwise NOT: ");
            print_binary(result);
            break;

        case '<<': // Left shift
            result = num1 << num2;
            printf("Left shift by %d: ", num2);
            print_binary(result);
            break;

        case '>>': // Right shift
            result = num1 >> num2;
            printf("Right shift by %d: ", num2);
            print_binary(result);
            break;

        default:
            printf("Invalid operation!\n");
            break;
    }
}

int main() {
    unsigned int num1, num2;
    char operation;

    printf("Enter two numbers:\n");
    scanf("%u %u", &num1, &num2);

    printf("Enter the operation (+, -, *, /, &, |, ^, ~, <<, >>):\n");
    scanf(" %c", &operation);

    bitwise_operations(num1, num2, operation);

    return 0;
}