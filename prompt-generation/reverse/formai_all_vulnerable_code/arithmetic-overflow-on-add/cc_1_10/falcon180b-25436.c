//Falcon-180B DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void my_error_handler(int error_code, const char* message);
bool is_valid_integer(const char* str);
int get_integer_input(const char* prompt);

int main() {
    int num1, num2, result;

    // Get input from user
    printf("Enter the first integer: ");
    num1 = get_integer_input("Invalid input. Please enter a valid integer. ");

    printf("Enter the second integer: ");
    num2 = get_integer_input("Invalid input. Please enter a valid integer. ");

    // Calculate the sum of two integers
    result = num1 + num2;

    // Display the result
    printf("The sum of %d and %d is %d.\n", num1, num2, result);

    return 0;
}

// Function to handle errors
void my_error_handler(int error_code, const char* message) {
    printf("Error: %s\n", message);
    exit(error_code);
}

// Function to check if a string is a valid integer
bool is_valid_integer(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Function to get integer input from user
int get_integer_input(const char* prompt) {
    char input[100];
    int num;

    printf("%s", prompt);
    fgets(input, 100, stdin);

    if (!is_valid_integer(input)) {
        my_error_handler(1, "Invalid input. Please enter a valid integer. ");
    }

    num = atoi(input);
    return num;
}