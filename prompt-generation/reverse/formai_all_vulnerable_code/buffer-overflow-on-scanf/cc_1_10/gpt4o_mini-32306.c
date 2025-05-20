//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

// Function to sanitize user input by removing unwanted characters 
void sanitize_input(char *input, const char *allowed_chars) {
    char *ptr = input;
    while (*ptr) {
        // Check if the character is in the allowed characters list
        if (strchr(allowed_chars, *ptr) == NULL) {
            // If it's not allowed, shift the remaining part of the string left
            char *next_char = ptr + 1;
            while (*next_char) {
                *ptr++ = *next_char++;
            }
            *ptr = '\0'; // Null terminate the sanitized string
        } else {
            ptr++;
        }
    }
}

// Function to display user input
void display_input(const char *input) {
    printf("Sanitized Input: %s\n", input);
}

// Main function
int main() {
    char user_input[MAX_INPUT_LENGTH];
    const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@_.-"; // Define allowed characters
    char *custom_msg = "Please enter a username (alphanumeric with @, _, . and - allowed):";

    printf("%s\n", custom_msg);
    // Reading user input
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
        // Remove newline character from input if it exists
        user_input[strcspn(user_input, "\n")] = 0;

        // Sanitize the user input
        sanitize_input(user_input, allowed_chars);
        
        // Display the sanitized input
        display_input(user_input);
    } else {
        fprintf(stderr, "Error reading input!\n");
        return EXIT_FAILURE;
    }

    // Example of allowing user to enter a password
    printf("Please enter a password (alphanumeric, and special characters !@#$%^&*):\n");
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
        user_input[strcspn(user_input, "\n")] = 0;

        // Allow all characters just for this example
        // In a real implementation, you'd want to define strict rules for passwords
        sanitize_input(user_input, "");

        // Display the sanitized password length
        printf("Sanitized Password Length: %zu\n", strlen(user_input));
    } else {
        fprintf(stderr, "Error reading input!\n");
        return EXIT_FAILURE;
    }

    // Implementing a simple menu to allow repeated entries
    int continue_input = 1;
    while (continue_input) {
        printf("\nWould you like to enter another username? (1: Yes, 0: No): ");
        int choice;
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Exiting.\n");
            break;
        }
        if (choice == 1) {
            // Clear the input buffer before reading again
            while (getchar() != '\n'); // Clear input buffer

            printf("Please enter a username again:\n");
            if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
                user_input[strcspn(user_input, "\n")] = 0;

                // Sanitize and display again
                sanitize_input(user_input, allowed_chars);
                display_input(user_input);
            }
        } else {
            continue_input = 0; // Exit the loop
        }
    }

    printf("Thank you for using the input sanitizer program!\n");
    return EXIT_SUCCESS;
}