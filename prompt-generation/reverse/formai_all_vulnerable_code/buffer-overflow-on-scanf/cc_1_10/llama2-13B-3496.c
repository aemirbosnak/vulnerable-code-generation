//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_OPERATIONS 10
#define MAX_NUMBERS 5

// Protected variables and functions
int num1, num2, result;
void perform_operation(char op);
void get_numbers(void);
void display_result(void);

// Global variables
char operation;

int main(void)
{
    // Initialize variables and set operation to addition
    operation = '+';
    num1 = 0;
    num2 = 0;
    result = 0;

    // Get numbers from user
    get_numbers();

    // Perform operation
    perform_operation(operation);

    // Display result
    display_result();

    return 0;
}

void get_numbers(void)
{
    int i;

    // Ask user for numbers
    printf("Enter two numbers: ");

    // Read numbers
    for (i = 0; i < MAX_NUMBERS; i++) {
        scanf("%d", &num1);
        num2 = num1;
    }
}

void perform_operation(char op)
{
    int temp;

    // Perform operation based on op
    switch (op) {
        case '+':
            temp = num1 + num2;
            break;
        case '-':
            temp = num1 - num2;
            break;
        case '*':
            temp = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: division by zero\n");
                return;
            }
            temp = num1 / num2;
            break;
        default:
            printf("Invalid operation\n");
            return;
    }

    // Store result
    result = temp;
}

void display_result(void)
{
    printf("Result: %d\n", result);
}