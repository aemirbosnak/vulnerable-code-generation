//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256

// Function to sanitize input by removing unwanted characters
void sanitize_input(char *input) {
    int i, j = 0; // Initialize index variables for input and sanitized input

    // Loop through each character of the input string
    for (i = 0; i < strlen(input); i++) {
        // Check if the character is alphanumeric or a space
        if (isalnum(input[i]) || isspace(input[i])) {
            input[j++] = input[i]; // If it is, keep it in the sanitized input
        }
    }
    input[j] = '\0'; // Null-terminate the sanitized string
}

// Function to show a peaceful message
void display_greeting() {
    printf("Welcome to the Peaceful Input Sanitizer!\n");
    printf("Ensure your words are calm and peaceful. Let's begin...\n");
}

// Function to handle user input
void handle_user_input() {
    char input[MAX_INPUT_SIZE];

    printf("Please enter your words: ");
    fgets(input, MAX_INPUT_SIZE, stdin); // Read user input

    // Remove the trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Sanitize the input
    sanitize_input(input);
    printf("Sanitized input: \"%s\"\n", input);
}

int main() {
    // Display greeting message
    display_greeting();

    // Main loop to handle user input
    while (1) {
        handle_user_input(); // Prompt user for input
        
        // Ask if the user wants to input more data
        char choice;
        printf("Would you like to enter another phrase? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Clean the newline character from input buffer

        // If the user chooses 'n', exit the loop
        if (choice != 'y') {
            printf("Thank you for using the Peaceful Input Sanitizer. Be calm and carry on.\n");
            break;
        }
    }

    return 0; // Exit program successfully
}