//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 100

// Function to sanitize user input
void sanitizeInput(char *input)
{
    char *ptr = input;
    
    // Remove leading and trailing whitespaces
    while (*ptr && isspace(*ptr)) ptr++; 
    if (*ptr == 0) { 
        *input = 0; 
        return; 
    }

    char *end = ptr + strlen(ptr) - 1;
    while (end > ptr && isspace(*end)) end--;
    *(end + 1) = 0;

    // Remove non-alphanumeric characters
    int i = 0, j = 0;
    while (ptr[j]) {
        if (isalnum(ptr[j])) {
            input[i++] = ptr[j];
        }
        j++;
    }
    input[i] = 0;

    // Convert input to lowercase
    for (i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }
}

int main()
{
    char userInput[MAX_INPUT_LENGTH];
    bool isValidInput = false;

    while (!isValidInput) {
        printf("Enter your input: ");
        fflush(stdout);
        fgets(userInput, MAX_INPUT_LENGTH, stdin);

        // Remove newline character from user input
        size_t lastIndex = strlen(userInput) - 1;
        if (userInput[lastIndex] == '\n') {
            userInput[lastIndex] = '\0';
        }

        sanitizeInput(userInput);

        // Check if sanitized input is empty
        if (strlen(userInput) == 0) {
            printf("Invalid input. Please try again.\n\n");
        } else {
            printf("Sanitized input: %s\n", userInput);
            isValidInput = true;
        }
    }

    return 0;
}