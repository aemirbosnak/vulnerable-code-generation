//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 1000
#define MAX_OPERATIONS 10

// Global variables
int num1 = 0, num2 = 0, result = 0;
char operations[MAX_OPERATIONS][20];

// Function declarations
void get_numbers(void);
void get_operations(void);
void perform_operations(void);
void display_result(void);

int main(void)
{
    // Initialize the program
    srand(time(NULL));

    // Get the numbers
    get_numbers();

    // Get the operations
    get_operations();

    // Perform the operations
    perform_operations();

    // Display the result
    display_result();

    return 0;
}

// Function to get the numbers
void get_numbers(void)
{
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
}

// Function to get the operations
void get_operations(void)
{
    int i;

    for (i = 0; i < MAX_OPERATIONS; i++) {
        printf("Enter an operation (+, -, *, /): ");
        fgets(operations[i], 20, stdin);
    }
}

// Function to perform the operations
void perform_operations(void)
{
    int i, j;

    for (i = 0; i < MAX_OPERATIONS; i++) {
        for (j = 0; j < MAX_OPERATIONS; j++) {
            if (operations[i][0] == '+') {
                num1 += atoi(operations[j]);
            } else if (operations[i][0] == '-') {
                num1 -= atoi(operations[j]);
            } else if (operations[i][0] == '*') {
                num1 *= atoi(operations[j]);
            } else if (operations[i][0] == '/') {
                num1 /= atoi(operations[j]);
            }
        }
    }
}

// Function to display the result
void display_result(void)
{
    printf("Result: %d\n", num1);
}