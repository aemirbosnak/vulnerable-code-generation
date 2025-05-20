//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 256

// Function to sanitize input
void sanitize_input(const char *input, char *sanitized) {
    int j = 0; // Index for sanitized array

    // Loop through each character in user input
    for (int i = 0; input[i] != '\0' && i < MAX_INPUT; i++) {
        // Validate character: accept alphanumeric and some special characters
        if (isalnum(input[i]) || input[i] == ' ' || input[i] == '.' || input[i] == ',' || input[i] == '-') {
            sanitized[j++] = input[i]; // Append to sanitized if it is acceptable
        }
    }
    sanitized[j] = '\0'; // Null-terminate the sanitized string
}

// Main function to drive the program
int main() {
    char user_input[MAX_INPUT];
    char sanitized_output[MAX_INPUT];

    printf("Welcome to the User Input Sanitizer!\n");
    printf("Please enter a string (up to %d characters):\n", MAX_INPUT - 1);
    
    // Get user input
    fgets(user_input, sizeof(user_input), stdin);
    
    // Remove the newline character from fgets
    user_input[strcspn(user_input, "\n")] = 0;

    printf("Sanitizing your input...\n");

    // Sanitize the input
    sanitize_input(user_input, sanitized_output);
    
    // Output the sanitized string
    printf("Original input was: %s\n", user_input);
    printf("Sanitized output is: %s\n", sanitized_output);

    // Additional functionality: repeat if user wishes
    char repeat;
    do {
        printf("Would you like to sanitize another input? (y/n): ");
        scanf(" %c", &repeat);
        getchar(); // Clear the newline in the input buffer
        if (repeat == 'y' || repeat == 'Y') {
            printf("Please enter a new string:\n");
            fgets(user_input, sizeof(user_input), stdin);
            user_input[strcspn(user_input, "\n")] = 0; // Remove newline
            printf("Sanitizing your new input...\n");
            sanitize_input(user_input, sanitized_output);
            printf("Original input was: %s\n", user_input);
            printf("Sanitized output is: %s\n", sanitized_output);
        }
    } while (repeat == 'y' || repeat == 'Y');

    printf("Thank you for using the User Input Sanitizer! Goodbye!\n");
    return 0;
}