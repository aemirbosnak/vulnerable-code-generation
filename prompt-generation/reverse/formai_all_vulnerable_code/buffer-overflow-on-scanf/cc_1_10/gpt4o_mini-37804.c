//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Maximum input length
#define MAX_INPUT_LEN 256

// Function to sanitize user input
void sanitize_input(const char *input, char *output) {
    int index = 0;
    
    // Loop through each character in the input
    for (int i = 0; i < strlen(input); i++) {
        // Check if the character is alphanumeric or a space
        if (isalnum(input[i]) || isspace(input[i])) {
            output[index++] = input[i];
        }
    }
    // Null-terminate the output string
    output[index] = '\0';
}

// Function to display the sanitized input
void display_sanitized_input(const char *sanitized) {
    printf("Sanitized Input: '%s'\n", sanitized);
}

int main() {
    char user_input[MAX_INPUT_LEN];
    char sanitized_input[MAX_INPUT_LEN];

    printf("🎉 Welcome to the User Input Sanitizer! 🎉\n");
    printf("Please enter your input (max %d characters):\n", MAX_INPUT_LEN - 1);

    // Get user input
    if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
        printf("Error reading input!\n");
        return 1;
    }

    // Remove the newline character from the input
    size_t length = strlen(user_input);
    if (length > 0 && user_input[length - 1] == '\n') {
        user_input[length - 1] = '\0';
    }

    // Sanitize the input
    sanitize_input(user_input, sanitized_input);

    // Display the result
    display_sanitized_input(sanitized_input);

    printf("🚀 Thank you for using our sanitizer! Stay safe! 🚀\n");

    // A fun little loop to keep the program running after input
    char continue_choice;
    while (1) {
        printf("Would you like to enter another input? (y/n): ");
        scanf(" %c", &continue_choice);  // Whitespace before %c to consume any leftover newline character
        
        if (tolower(continue_choice) == 'y') {
            printf("Please enter your input (max %d characters):\n", MAX_INPUT_LEN - 1);
            getchar(); // Clear the buffer from the previous input
            if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
                printf("Error reading input!\n");
                continue;
            }
            length = strlen(user_input);
            if (length > 0 && user_input[length - 1] == '\n') {
                user_input[length - 1] = '\0';
            }
            sanitize_input(user_input, sanitized_input);
            display_sanitized_input(sanitized_input);
        } else if (tolower(continue_choice) == 'n') {
            printf("🛑 Exiting the sanitizer. Have a great day! 🛑\n");
            break;
        } else {
            printf("❌ Invalid choice! Please enter 'y' or 'n'. ❌\n");
        }
    }

    return 0;
}