//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Define variables
double num1, num2, result;
char operation;

// Define functions
void display() {
    printf("%.2f %c %.2f = ", num1, operation, num2);
    if (operation == '+') {
        result = num1 + num2;
    } else if (operation == '-') {
        result = num1 - num2;
    } else if (operation == '*') {
        result = num1 * num2;
    } else if (operation == '/') {
        result = num1 / num2;
    }
    printf("%.2f\n", result);
}

void clear() {
    printf("\n");
    num1 = 0;
    num2 = 0;
    result = 0;
    operation = '\0';
}

// Define main function
int main() {
    printf("Welcome to the Scientific Calculator!\n\n");
    while (1) {
        printf("Enter a number: ");
        if (!scanf("%lf", &num1)) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        printf("Enter an operator (+, -, *, /): ");
        scanf(" %c", &operation);
        printf("Enter another number: ");
        if (!scanf("%lf", &num2)) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        switch (operation) {
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
                    printf("Error: Division by zero.\n");
                    continue;
                }
                result = num1 / num2;
                break;
            default:
                printf("Invalid operator. Please try again.\n");
                continue;
        }
        display();
    }
    return 0;
}