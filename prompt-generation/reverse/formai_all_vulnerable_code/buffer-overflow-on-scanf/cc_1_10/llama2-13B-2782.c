//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERATIONS 10
#define MAX_NUMBERS 10

// Global variables
int num1, num2, result;
char operation[10];

// Functions
void get_operations(void);
void get_numbers(void);
void perform_operation(void);
void display_result(void);

int main(void)
{
    // Initialize variables
    num1 = 0;
    num2 = 0;
    result = 0;
    operation[0] = '\0';

    // Get operations
    get_operations();

    // Get numbers
    get_numbers();

    // Perform operation
    perform_operation();

    // Display result
    display_result();

    return 0;
}

// Function to get operations
void get_operations(void)
{
    int i;

    printf("Enter an operation (+, -, x, /, *): ");
    scanf("%s", operation);

    // Check for invalid input
    if (operation[0] == '\0' || strlen(operation) > 10)
    {
        printf("Invalid input. Please enter a valid operation.\n");
        get_operations();
    }

    // Store operation in global variable
    strcpy(operation, scanf("%s", operation));
}

// Function to get numbers
void get_numbers(void)
{
    int i;

    for (i = 0; i < MAX_NUMBERS; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &num1);

        // Check for invalid input
        if (num1 < 0)
        {
            printf("Invalid input. Please enter a valid number.\n");
            get_numbers();
        }

        // Store number in global variable
        num2 = num1;
    }
}

// Function to perform operation
void perform_operation(void)
{
    if (strcmp(operation, "+") == 0)
    {
        result = num1 + num2;
    }
    else if (strcmp(operation, "-") == 0)
    {
        result = num1 - num2;
    }
    else if (strcmp(operation, "*") == 0)
    {
        result = num1 * num2;
    }
    else if (strcmp(operation, "/") == 0)
    {
        result = num1 / num2;
    }
    else
    {
        printf("Invalid operation. Please enter a valid operation.\n");
        get_operations();
    }
}

// Function to display result
void display_result(void)
{
    printf("Result: %d\n", result);
}