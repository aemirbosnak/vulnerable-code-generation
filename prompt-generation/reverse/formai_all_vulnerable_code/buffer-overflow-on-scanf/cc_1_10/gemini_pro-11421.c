//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input size
#define MAX_INPUT_SIZE 1024

// Function to sanitize user input
int sanitize_input(char *input, int max_size) {
    // Check if the input is valid
    if (input == NULL || strlen(input) == 0) {
        return -1;
    }

    // Check if the input is too long
    if (strlen(input) > max_size) {
        return -1;
    }

    // Check if the input contains any invalid characters
    for (int i = 0; i < strlen(input); i++) {
        if (!((input[i] >= 'a' && input[i] <= 'z') ||
              (input[i] >= 'A' && input[i] <= 'Z') ||
              (input[i] >= '0' && input[i] <= '9') ||
              input[i] == ' ' || input[i] == '.' || input[i] == ',')) {
            return -1;
        }
    }

    // The input is valid
    return 0;
}

// Main function
int main() {
    // Get user input
    char input[MAX_INPUT_SIZE];
    printf("Enter your input: ");
    scanf("%s", input);

    // Sanitize the user input
    int result = sanitize_input(input, MAX_INPUT_SIZE);

    // Print the result
    if (result == -1) {
        printf("Invalid input\n");
    } else {
        printf("Valid input: %s\n", input);
    }

    return 0;
}