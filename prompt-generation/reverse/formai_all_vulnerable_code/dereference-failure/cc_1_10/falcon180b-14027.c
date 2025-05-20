//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitize_input(char *input) {
    int i = 0;
    int j = 0;
    char sanitized_input[MAX_INPUT_LENGTH];

    // Remove leading and trailing whitespace
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[strlen(input) - 1 - i])) {
        i--;
    }

    // Remove any non-alphanumeric characters
    while (i < strlen(input)) {
        if (!isalnum(input[i])) {
            i++;
            continue;
        }
        sanitized_input[j] = tolower(input[i]);
        j++;
        i++;
    }
    sanitized_input[j] = '\0';

    // Copy sanitized input back to original input
    strcpy(input, sanitized_input);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter some input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}