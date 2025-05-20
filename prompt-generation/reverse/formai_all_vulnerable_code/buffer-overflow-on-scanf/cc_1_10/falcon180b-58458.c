//Falcon-180B DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Function to check if a string is a valid integer
int is_valid_integer(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0; // Not a valid integer
        }
    }
    return 1; // Valid integer
}

// Function to check if a string is a valid floating point number
int is_valid_float(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i]) && str[i]!= '.') {
            return 0; // Not a valid float
        }
    }
    return 1; // Valid float
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the Fibonacci sequence up to a given number
int fibonacci(int n) {
    int sequence[n];
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }
    return sequence[n-1];
}

int main() {
    char input_string[MAX_STRING_LENGTH];
    int input_int;
    float input_float;
    int choice;

    // Prompt user for input
    printf("Enter a number: ");
    scanf("%s", input_string);

    // Check if input is a valid integer
    if (is_valid_integer(input_string)) {
        input_int = atoi(input_string);
        printf("Factorial of %d is %d\n", input_int, factorial(input_int));
    } else if (is_valid_float(input_string)) {
        input_float = atof(input_string);
        printf("Fibonacci sequence up to %.2f is %d\n", input_float, fibonacci(input_float));
    } else {
        printf("Invalid input\n");
    }

    return 0;
}