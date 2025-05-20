//Falcon-180B DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User-defined function to handle errors
void error_handler(char* message, int line_number) {
    printf("Error at line %d: %s\n", line_number, message);
    exit(1);
}

// Function to check if a given string is a valid integer
int is_integer(char* input) {
    for (int i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the sum of two integers
int sum(int num1, int num2) {
    return num1 + num2;
}

int main() {
    char input[100];
    int num1, num2, sum_result;

    // Prompt user to enter two integers
    printf("Enter two integers: ");
    scanf("%s", input);

    // Check if the input is a valid integer
    if (!is_integer(input)) {
        error_handler("Invalid input", __LINE__);
    }

    // Convert the input string to integer
    num1 = atoi(input);

    // Prompt user to enter another integer
    printf("Enter another integer: ");
    scanf("%s", input);

    // Check if the input is a valid integer
    if (!is_integer(input)) {
        error_handler("Invalid input", __LINE__);
    }

    // Convert the input string to integer
    num2 = atoi(input);

    // Calculate the sum of the two integers
    sum_result = sum(num1, num2);

    // Print the result
    printf("The sum of %d and %d is %d\n", num1, num2, sum_result);

    return 0;
}