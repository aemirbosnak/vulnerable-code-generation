//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 10

typedef struct Calculator {
    int number1;
    int number2;
    char operator;
} Calculator;

int main() {
    Calculator calculator;
    int choice;

    printf("Welcome to the Grand Calculator of the Middle Ages!\n");
    printf("Please select an option:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            calculator.number1 = read_number("Enter the first number: ");
            calculator.number2 = read_number("Enter the second number: ");
            calculator.operator = '+';
            break;
        case 2:
            calculator.number1 = read_number("Enter the first number: ");
            calculator.number2 = read_number("Enter the second number: ");
            calculator.operator = '-';
            break;
        case 3:
            calculator.number1 = read_number("Enter the first number: ");
            calculator.number2 = read_number("Enter the second number: ");
            calculator.operator = '*';
            break;
        case 4:
            calculator.number1 = read_number("Enter the first number: ");
            calculator.number2 = read_number("Enter the second number: ");
            calculator.operator = '/';
            break;
        default:
            printf("Invalid input.\n");
    }

    if (calculator.operator != '\0') {
        int result = calculate(calculator);
        printf("The result is: %d\n", result);
    }

    return 0;
}

int read_number(char *message) {
    int number;

    printf("%s", message);
    scanf("%d", &number);

    return number;
}

int calculate(Calculator calculator) {
    switch (calculator.operator) {
        case '+':
            return calculator.number1 + calculator.number2;
        case '-':
            return calculator.number1 - calculator.number2;
        case '*':
            return calculator.number1 * calculator.number2;
        case '/':
            if (calculator.number2 == 0) {
                printf("Cannot divide by zero.\n");
                return -1;
            }
            return calculator.number1 / calculator.number2;
        default:
            return -1;
    }
}