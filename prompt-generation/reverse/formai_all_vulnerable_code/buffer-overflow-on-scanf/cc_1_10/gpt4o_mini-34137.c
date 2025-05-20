//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

void sanitize_input(const char *input, char *output, size_t max_size) {
    size_t j = 0;
    for (size_t i = 0; input[i] != '\0' && j < max_size - 1; i++) {
        if (isalnum(input[i]) || isspace(input[i])) { // Allowalphanumeric and spaces
            output[j++] = input[i];
        }
    }
    output[j] = '\0'; // Null terminate the sanitized string
}

void get_safe_input(char *buffer, size_t size) {
    char temp[MAX_INPUT_SIZE];
    printf("Enter your input (max %zu characters): ", size - 1);
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = 0; // Remove newline character

    sanitize_input(temp, buffer, size);
}

void display_info(const char *input) {
    printf("Sanitized Output: %s\n", input);
}

int main() {
    char sanitized_input[MAX_INPUT_SIZE];

    get_safe_input(sanitized_input, sizeof(sanitized_input));
    display_info(sanitized_input);

    // A simple check to demonstrate further input handling
    if (strlen(sanitized_input) == 0) {
        printf("No valid input was provided.\n");
    } else {
        printf("You entered a valid string with length: %zu\n", strlen(sanitized_input));
    }

    // Loop for multiple entries
    char choice;
    do {
        printf("Would you like to enter another string? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume newline

        if (tolower(choice) == 'y') {
            get_safe_input(sanitized_input, sizeof(sanitized_input));
            display_info(sanitized_input);
            printf("You entered a valid string with length: %zu\n", strlen(sanitized_input));
        } else if (tolower(choice) != 'n') {
            printf("Invalid choice! Please enter 'y' or 'n'.\n");
        }
    } while (tolower(choice) != 'n');

    printf("Thank you for using the input sanitizer. Goodbye!\n");

    return 0;
}