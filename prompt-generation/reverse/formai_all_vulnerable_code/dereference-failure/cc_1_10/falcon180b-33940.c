//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define INVALID_CHARACTERS "!@#$%^&*()_+-=[]{}|;:,.<>?"

// Function to sanitize user input
void sanitize_input(char *input) {
    int length = strlen(input);
    // Remove leading and trailing spaces
    while (isspace(input[0])) {
        strcpy(input, input+1);
    }
    while (isspace(input[length-1])) {
        input[length-1] = '\0';
    }
    // Remove invalid characters
    for (int i = 0; i < length; i++) {
        if (strchr(INVALID_CHARACTERS, input[i])!= NULL) {
            input[i] = '\0';
        }
    }
}

// Function to check if input is valid
int is_valid_input(char *input) {
    int length = strlen(input);
    if (length == 0) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (!isalpha(input[i]) &&!isdigit(input[i]) && input[i]!= '.' && input[i]!= '-') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Welcome to the Cybernetic Input Sanitizer!\n");
    printf("Please enter your input:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    // Sanitize input
    sanitize_input(input);
    // Check if input is valid
    if (is_valid_input(input)) {
        printf("Your sanitized input is: %s\n", input);
    } else {
        printf("Invalid input detected. Please enter valid input.\n");
    }
    return 0;
}