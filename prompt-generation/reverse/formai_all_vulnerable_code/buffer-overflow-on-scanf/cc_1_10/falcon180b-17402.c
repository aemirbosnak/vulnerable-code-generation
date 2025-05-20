//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of a number
void print_binary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    char binary[33]; // Maximum 32 bits + null terminator
    int i = 31;
    binary[i] = '\0';

    while (n > 0) {
        if (n & 1) {
            binary[i] = '1';
        } else {
            binary[i] = '0';
        }
        n >>= 1;
        i--;
    }

    printf("%s", binary);
}

// Function to perform bitwise operations on two numbers
void bitwise_operations(int num1, int num2, char operation) {
    int result;

    switch (operation) {
        case '+':
            result = num1 | num2;
            printf("OR: ");
            print_binary(result);
            break;

        case '-':
            result = num1 & ~num2;
            printf("AND NOT: ");
            print_binary(result);
            break;

        case '*':
            result = num1 & num2;
            printf("AND: ");
            print_binary(result);
            break;

        case '/':
            result = num1 ^ num2;
            printf("XOR: ");
            print_binary(result);
            break;

        case '%':
            result = num1 >> 1;
            printf("Right shift by 1: ");
            print_binary(result);
            break;

        case '&':
            result = num1 << 1;
            printf("Left shift by 1: ");
            print_binary(result);
            break;

        default:
            printf("Invalid operation.\n");
            return;
    }
}

int main() {
    int num1, num2, operation;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Enter operation (+, -, *, /, %, &, |): ");
    scanf("%c", &operation);

    bitwise_operations(num1, num2, operation);

    return 0;
}