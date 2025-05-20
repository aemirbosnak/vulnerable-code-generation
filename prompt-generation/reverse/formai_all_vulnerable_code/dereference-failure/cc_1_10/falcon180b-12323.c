//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function to sanitize user input
void sanitize_input(char *input) {
    int length = strlen(input);
    char sanitized_input[MAX_INPUT_LENGTH];
    int i = 0;

    // Remove any leading/trailing whitespace
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[length - 1])) {
        length--;
    }

    // Convert input to lowercase
    for (int j = 0; j < length; j++) {
        sanitized_input[j] = tolower(input[j]);
    }

    // Remove any non-alphanumeric characters
    for (int j = 0; j < length; j++) {
        if (!isalnum(sanitized_input[j])) {
            sanitized_input[j] = '\0';
        }
    }

    // Copy sanitized input to original input
    strncpy(input, sanitized_input, MAX_INPUT_LENGTH);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Get user input
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}