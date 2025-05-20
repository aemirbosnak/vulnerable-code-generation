//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isNumber(const char *str) {
    // Validate if the input is a number
    while (*str) {
        if (!(*str >= '0' && *str <= '9')) {
            return false;
        }
        str++;
    }
    return true;
}

void clearBuffer() {
    // Clearing the input buffer for safety
    while (getchar() != '\n');
}

int main() {
    char num1_str[20], num2_str[20];
    int num1, num2;
    char operation;
    bool validInput = false;

    printf("Welcome to the Paranoia Arithmetic Program! \n");
    printf("We take input safety seriously! Let's avoid errors.\n");

    // Input first number
    while (!validInput) {
        printf("Please enter the first number (whole number only): ");
        fgets(num1_str, sizeof(num1_str), stdin);
        
        // Remove newline character
        size_t len = strlen(num1_str);
        if (len > 0 && num1_str[len - 1] == '\n') {
            num1_str[len - 1] = '\0';
        }

        // Check if input is a number
        if (isNumber(num1_str)) {
            num1 = atoi(num1_str);
            validInput = true;
        } else {
            printf("That doesn't look like a valid number! Please try again.\n");
        }
    }

    validInput = false;

    // Input second number
    while (!validInput) {
        printf("Please enter the second number (whole number only): ");
        fgets(num2_str, sizeof(num2_str), stdin);
        
        // Remove newline character
        size_t len = strlen(num2_str);
        if (len > 0 && num2_str[len - 1] == '\n') {
            num2_str[len - 1] = '\0';
        }

        // Check if input is a number
        if (isNumber(num2_str)) {
            num2 = atoi(num2_str);
            validInput = true;
        } else {
            printf("That doesn't look like a valid number! Please try again.\n");
        }
    }

    // Clear the input buffer to dispose of any leftovers
    clearBuffer();

    // Asking for operation
    printf("Now, choose an operation (+, -, *, /, %%): ");
    scanf(" %c", &operation);

    // Validation of operation
    while (operation != '+' && operation != '-' && operation != '*' &&
           operation != '/' && operation != '%') {
        printf("That's not a valid operation! Pick +, -, *, /, or %%: ");
        clearBuffer();
        scanf(" %c", &operation);
    }

    // Performing the operation
    printf("Calculating, just checking everything... \n");
    
    switch (operation) {
        case '+':
            printf("The result of %d + %d is %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("The result of %d - %d is %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("The result of %d * %d is %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Danger! Division by zero is not allowed! Please check your numbers!\n");
            } else {
                printf("The result of %d / %d is %d\n", num1, num2, num1 / num2);
            }
            break;
        case '%':
            if (num2 == 0) {
                printf("Caution! Modulo by zero could lead to catastrophic failure! Exit in peace.\n");
            } else {
                printf("The result of %d %% %d is %d\n", num1, num2, num1 % num2);
            }
            break;
        default:
            printf("That's strange... How did you get here?\n");
            break;
    }

    printf("Operation completed. It's safe to exit!\n");
    return 0;
}