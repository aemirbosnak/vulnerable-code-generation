//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_BITS 32
#define NUM_BYTES 4

void print_binary(int num) {
    char binary[NUM_BITS + 1];
    int i, j;
    for (i = 0; i < NUM_BYTES; i++) {
        for (j = 0; j < 8; j++) {
            if ((num >> (i * 8 + j)) & 0x01) {
                binary[NUM_BYTES * 8 - 1 - i * 8 - j] = '1';
            } else {
                binary[NUM_BYTES * 8 - 1 - i * 8 - j] = '0';
            }
        }
    }
    binary[NUM_BITS] = '\0';
    printf("Binary: %s\n", binary);
}

int main() {
    int num1, num2, result;
    char choice;
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Enter another number: ");
    scanf("%d", &num2);
    printf("Enter an operation (+, -, *, /): ");
    scanf(" %c", &choice);

    switch (choice) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
                exit(1);
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operation\n");
            exit(1);
    }

    printf("Result: %d\n", result);

    print_binary(num1);
    print_binary(num2);
    print_binary(result);

    return 0;
}