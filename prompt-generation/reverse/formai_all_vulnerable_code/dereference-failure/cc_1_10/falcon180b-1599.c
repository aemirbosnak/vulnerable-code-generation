//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000

// Function to sanitize user input
void sanitize_input(char *input) {
    int i = 0, j = 0;

    // Remove leading/trailing whitespaces
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[strlen(input) - 1 - j])) {
        j++;
    }
    input[j] = '\0';

    // Remove non-alphanumeric characters
    char *sanitized_input = malloc(strlen(input) + 1);
    for (i = 0, j = 0; input[i]; i++) {
        if (isalnum(input[i])) {
            sanitized_input[j++] = input[i];
        }
    }
    sanitized_input[j] = '\0';
    strcpy(input, sanitized_input);
    free(sanitized_input);
}

// Function to check if input is empty
int is_empty(char *input) {
    return strlen(input) == 0;
}

// Function to check if input is a valid integer
int is_integer(char *input) {
    for (int i = 0; input[i]; i++) {
        if (!isdigit(input[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if input is a valid float
int is_float(char *input) {
    for (int i = 0; input[i]; i++) {
        if (!isdigit(input[i]) && input[i]!= '.') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitize_input(input);
    printf("Sanitized input: %s\n", input);

    if (is_empty(input)) {
        printf("Input is empty.\n");
    } else if (is_integer(input)) {
        printf("Input is a valid integer.\n");
    } else if (is_float(input)) {
        printf("Input is a valid float.\n");
    } else {
        printf("Input is not a valid integer or float.\n");
    }

    return 0;
}