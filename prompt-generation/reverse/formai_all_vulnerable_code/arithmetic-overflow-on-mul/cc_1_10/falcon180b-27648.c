//Falcon-180B DATASET v1.0 Category: Error handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Custom error handling function
void handle_error(int error_code, char* message) {
    printf("Error: %s\n", message);
    exit(error_code);
}

// Function to check if a string is a valid number
int is_number(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    char input[100];
    int num;

    // Prompt user for input
    printf("Enter a number: ");
    fgets(input, 100, stdin);

    // Convert input string to integer
    num = atoi(input);

    // Check if input is a valid number
    if (!is_number(input)) {
        handle_error(1, "Input is not a valid number");
    }

    // Calculate factorial of input number
    int result = factorial(num);

    // Print result
    printf("Factorial of %d is %d\n", num, result);

    return 0;
}