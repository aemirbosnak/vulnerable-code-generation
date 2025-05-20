//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 500

void sanitizeInput(char* input) {
    //Create a copy of the original input
    char sanitizedInput[MAX_INPUT_LENGTH];
    strcpy(sanitizedInput, input);

    //Replace all non-alphanumeric characters with a space
    for (int i = 0; i < strlen(sanitizedInput); i++) {
        if (!isalnum(sanitizedInput[i])) {
            sanitizedInput[i] = ' ';
        }
    }

    //Remove multiple spaces in a row
    int i, j;
    for (i = 0; sanitizedInput[i] == ' '; i++);
    if (i > 0) {
        for (j = i; j <= strlen(sanitizedInput); j++) {
            sanitizedInput[j - i] = sanitizedInput[j];
        }
    }
    for (i = 0; i < strlen(sanitizedInput); i++) {
        if (sanitizedInput[i] == ' ' && sanitizedInput[i + 1] == ' ') {
            for (j = i; j < strlen(sanitizedInput); j++) {
                sanitizedInput[j] = sanitizedInput[j + 1];
            }
            i--;
        }
    }

    //Remove leading and trailing spaces
    for (i = strlen(sanitizedInput) - 1; sanitizedInput[i] == ' '; i--);
    sanitizedInput[i + 1] = '\0';
    for (i = 0; sanitizedInput[i] == ' '; i++);
    if (i > 0) {
        for (j = i; j <= strlen(sanitizedInput); j++) {
            sanitizedInput[j - i] = sanitizedInput[j];
        }
    }

    //Return the sanitized input
    strcpy(input, sanitizedInput);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter your input:\n");
    fgets(input, sizeof(input), stdin);
    sanitizeInput(input);
    printf("\nSanitized Input:\n%s", input);
    return 0;
}