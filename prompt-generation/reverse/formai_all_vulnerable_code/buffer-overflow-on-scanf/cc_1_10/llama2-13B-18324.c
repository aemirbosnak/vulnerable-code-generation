//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ERROR_MESSAGE_SIZE 256

// Structure to hold error information
typedef struct {
    int error_code;
    char error_message[MAX_ERROR_MESSAGE_SIZE];
} error_t;

// Function to handle errors
error_t handle_error(int error_code, const char* error_message) {
    error_t error;
    error.error_code = error_code;
    strncpy(error.error_message, error_message, MAX_ERROR_MESSAGE_SIZE);
    return error;
}

int main() {
    // Variables to store user input
    char input[MAX_INPUT_SIZE];
    int user_choice;

    // Initialize error information
    error_t error;

    // Menu to select user input
    printf("Select an option (1-3):\n");
    printf("1. Enter a string\n");
    printf("2. Enter an integer\n");
    printf("3. Exit\n");

    // Get user input
    scanf("%d", &user_choice);

    // Handle user input
    switch (user_choice) {
        case 1:
            printf("Enter a string: ");
            fgets(input, MAX_INPUT_SIZE, stdin);
            break;

        case 2:
            printf("Enter an integer: ");
            scanf("%d", &user_choice);
            break;

        case 3:
            printf("Exiting...\n");
            return 0;
    }

    // Check for errors
    if (user_choice < 1 || user_choice > 3) {
        error = handle_error(EINVAL, "Invalid user input");
        printf("Error: %d - %s\n", error.error_code, error.error_message);
    }

    // Process user input
    switch (user_choice) {
        case 1:
            printf("You entered: %s\n", input);
            break;

        case 2:
            printf("You entered: %d\n", user_choice);
            break;
    }

    return 0;
}