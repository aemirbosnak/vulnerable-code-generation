//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 1024

// Function to check if a character is alphanumeric
bool is_alphanumeric(char c) {
    return (isalnum(c) || c == '_');
}

// Function to sanitize input
void sanitize_input(char *input_string) {
    int i = 0;
    while (i < strlen(input_string)) {
        if (!is_alphanumeric(input_string[i])) {
            input_string[i] = '_';
        }
        i++;
    }
}

// Function to prompt the user for input
char *prompt_user_for_input(const char *prompt_message) {
    char input_string[MAX_INPUT_LENGTH];
    printf("%s", prompt_message);
    fgets(input_string, MAX_INPUT_LENGTH, stdin);
    input_string[strcspn(input_string, "\n")] = '\0';
    return strdup(input_string);
}

// Function to print the sanitized input
void print_sanitized_input(const char *input_string) {
    printf("Sanitized input: %s\n", input_string);
}

int main() {
    char *input_string;

    // Prompt the user for input
    input_string = prompt_user_for_input("Enter some text: ");

    // Sanitize the input
    sanitize_input(input_string);

    // Print the sanitized input
    print_sanitized_input(input_string);

    // Free the memory allocated for the input string
    free(input_string);

    return 0;
}