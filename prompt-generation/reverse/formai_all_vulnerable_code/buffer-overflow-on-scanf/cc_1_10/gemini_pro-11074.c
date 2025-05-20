//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digits(char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if a string is within a specific range of values
int is_in_range(char *str, int min, int max) {
    int num = atoi(str);
    return num >= min && num <= max;
}

// Function to sanitize user input
char *sanitize_input(char *input, int min, int max) {
    // Check if the input is a valid number
    if (!is_digits(input)) {
        return "Invalid input. Please enter a valid number.";
    }

    // Check if the number is within the specified range
    if (!is_in_range(input, min, max)) {
        return "Invalid input. Please enter a number within the specified range.";
    }

    // Otherwise, return the original input
    return input;
}

int main() {
    // Prompt the user for input
    printf("Enter a number between 1 and 10: ");

    // Get the user input
    char input[100];
    scanf("%s", input);

    // Sanitize the user input
    char *sanitized_input = sanitize_input(input, 1, 10);

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    return 0;
}