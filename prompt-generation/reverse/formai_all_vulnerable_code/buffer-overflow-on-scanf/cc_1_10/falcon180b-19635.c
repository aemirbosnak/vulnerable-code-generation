//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is alphabetic
int is_alpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Function to check if a character is numeric
int is_numeric(char c) {
    return c >= '0' && c <= '9';
}

// Function to sanitize user input
void sanitize_input(char* input) {
    int i, j;

    // Remove leading/trailing spaces
    while (isspace(input[0])) {
        strcpy(input, input + 1);
    }
    while (isspace(input[strlen(input) - 1])) {
        input[strlen(input) - 1] = '\0';
    }

    // Remove non-alphanumeric characters
    for (i = 0, j = 0; input[i]!= '\0'; i++) {
        if (is_alpha(input[i]) || is_numeric(input[i])) {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
}

int main() {
    char input[100];

    // Prompt user for input
    printf("Please enter your input:\n");
    scanf("%s", input);

    // Sanitize input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}