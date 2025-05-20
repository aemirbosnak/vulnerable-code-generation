//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BITS 32

void print_binary(unsigned int num) {
    int i;
    for (i = NUM_BITS - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    unsigned int num1, num2;
    char operation;

    printf("Enter two numbers:\n");
    scanf("%u %u", &num1, &num2);

    printf("Enter the operation (+, -, *, &, |, ^, <<, >>):\n");
    scanf(" %c", &operation);

    switch (operation) {
        case '+':
            printf("Result: %u\n", num1 + num2);
            break;
        case '-':
            printf("Result: %u\n", num1 - num2);
            break;
        case '*':
            printf("Result: %u\n", num1 * num2);
            break;
        case '&':
            printf("Result: ");
            print_binary(num1 & num2);
            printf("\n");
            break;
        case '|':
            printf("Result: ");
            print_binary(num1 | num2);
            printf("\n");
            break;
        case '^':
            printf("Result: ");
            print_binary(num1 ^ num2);
            printf("\n");
            break;
        case '<<':
            printf("Result: ");
            print_binary(num1 << num2);
            printf("\n");
            break;
        case '>>':
            printf("Result: ");
            print_binary(num1 >> num2);
            printf("\n");
            break;
        default:
            printf("Invalid operation.\n");
    }

    return 0;
}