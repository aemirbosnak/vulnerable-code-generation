//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

/* Define some macros for easier bit manipulation */

#define SET_BIT(var, bit) (var |= (1 << bit))
#define CLEAR_BIT(var, bit) (var &= ~(1 << bit))
#define CHECK_BIT(var, bit) (var & (1 << bit))

/* Function to print binary representation of a number */

void print_binary(unsigned int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

/* Function to perform bitwise operations on two numbers */

int bitwise_operations(int num1, int num2, int operation) {
    switch (operation) {
        case 1: /* Bitwise AND */
            return num1 & num2;
        case 2: /* Bitwise OR */
            return num1 | num2;
        case 3: /* Bitwise XOR */
            return num1 ^ num2;
        case 4: /* Bitwise NOT */
            return ~num1;
        case 5: /* Left shift */
            return num1 << num2;
        case 6: /* Right shift */
            return num1 >> num2;
        default:
            printf("Invalid operation!\n");
            exit(1);
    }
}

int main() {
    int num1, num2, operation, result;

    /* Get user input for two numbers and operation */

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Select operation:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left shift\n");
    printf("6. Right shift\n");
    scanf("%d", &operation);

    /* Perform selected operation and print result */

    switch (operation) {
        case 1:
            result = num1 & num2;
            printf("Result: %d\n", result);
            break;
        case 2:
            result = num1 | num2;
            printf("Result: %d\n", result);
            break;
        case 3:
            result = num1 ^ num2;
            printf("Result: %d\n", result);
            break;
        case 4:
            result = ~num1;
            printf("Result: %d\n", result);
            break;
        case 5:
            result = num1 << num2;
            printf("Result: %d\n", result);
            break;
        case 6:
            result = num1 >> num2;
            printf("Result: %d\n", result);
            break;
        default:
            printf("Invalid operation!\n");
            exit(1);
    }

    return 0;
}