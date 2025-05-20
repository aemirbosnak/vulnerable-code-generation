//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Define variables
    int num1, num2, operator;
    char choice;

    // Prompt user for input
    printf("Welcome to the Arithmetic Calculator!\n");
    printf("Please choose an operation:\n");
    printf("A - Addition\n");
    printf("S - Subtraction\n");
    printf("M - Multiplication\n");
    printf("D - Division\n");
    scanf("%c", &choice);

    // Generate random numbers based on user input
    switch (choice) {
        case 'A':
        case 'a':
            num1 = rand() % 100;
            num2 = rand() % 100;
            operator = '+';
            break;
        case 'S':
        case's':
            num1 = rand() % 100;
            num2 = rand() % 100;
            operator = '-';
            break;
        case 'M':
        case'm':
            num1 = rand() % 100;
            num2 = rand() % 100;
            operator = '*';
            break;
        case 'D':
        case 'd':
            num1 = rand() % 100;
            num2 = rand() % 100;
            while (num2 == 0) {
                num2 = rand() % 100;
            }
            operator = '/';
            break;
        default:
            printf("Invalid input. Please choose a valid operation.\n");
            return 1;
    }

    // Perform arithmetic operation and display result
    switch (operator) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", num1 / 100.0, num2 / 100.0, num1 / 100.0 + num2 / 100.0);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", num1 / 100.0, num2 / 100.0, num1 / 100.0 - num2 / 100.0);
            break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", num1 / 100.0, num2 / 100.0, num1 / 100.0 * num2 / 100.0);
            break;
        case '/':
            printf("%.2f / %.2f = %.2f\n", num1 / 100.0, num2 / 100.0, num1 / 100.0 / num2 / 100.0);
            break;
    }

    return 0;
}