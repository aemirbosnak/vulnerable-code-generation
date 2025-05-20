//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string contains only alphanumeric characters and underscores
int isValidString(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (!isalnum(str[i]) && str[i]!= '_') {
            return 0;
        }
    }
    return 1;
}

// Function to sanitize user input
void sanitizeInput(char *input) {
    int i, j;
    char sanitizedInput[100];
    sanitizedInput[0] = '\0';

    // Remove leading and trailing whitespace
    while (isspace(input[0])) {
        input++;
    }
    while (isspace(input[strlen(input) - 1])) {
        input[strlen(input) - 1] = '\0';
    }

    // Remove non-alphanumeric characters
    for (i = 0, j = 0; input[i]!= '\0'; i++) {
        if (isalnum(input[i]) || input[i] == '_') {
            sanitizedInput[j++] = input[i];
        }
    }
    sanitizedInput[j] = '\0';

    // Copy sanitized input back to original string
    strcpy(input, sanitizedInput);
}

int main() {
    char input[100];

    // Prompt user for input
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);

    // Sanitize input
    sanitizeInput(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}