//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100000
#define MIN_NUM 1

// Function to check if the input is a valid number
int is_valid_number(const char *str) {
    int num;
    if (sscanf(str, "%d", &num) == 1) {
        return num >= MIN_NUM && num <= MAX_NUM;
    } else {
        return 0;
    }
}

// Function to perform arithmetic operations
void perform_arithmetic_op(int num1, int num2, char op) {
    int result;
    switch (op) {
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
            result = num1 / num2;
            break;
        default:
            result = -1;
            break;
    }
    printf("%d\n", result);
}

int main() {
    int num1, num2, op;
    char input[100];

    // Get the first number from the user
    printf("Enter the first number: ");
    fgets(input, 100, stdin);
    num1 = is_valid_number(input);
    if (num1 == 0) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    // Get the second number from the user
    printf("Enter the second number: ");
    fgets(input, 100, stdin);
    num2 = is_valid_number(input);
    if (num2 == 0) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    // Get the arithmetic operator from the user
    printf("Enter the arithmetic operator (+, -, *, /): ");
    fgets(input, 100, stdin);
    op = input[0];

    // Perform the arithmetic operation
    perform_arithmetic_op(num1, num2, op);

    return 0;
}