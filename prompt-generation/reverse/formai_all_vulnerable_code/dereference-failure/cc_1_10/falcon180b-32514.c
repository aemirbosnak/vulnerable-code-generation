//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 500

// Function to sanitize user input
void sanitizeInput(char* input) {
    // Remove leading and trailing whitespace
    int i = 0;
    while (isspace(input[i])) {
        i++;
    }
    int j = strlen(input) - 1;
    while (isspace(input[j])) {
        j--;
        input[j] = '\0';
    }

    // Remove non-alphanumeric characters
    j = 0;
    for (i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
}

// Function to get user input
char* getInput(char* prompt) {
    char input[MAX_INPUT_SIZE];
    printf("%s", prompt);
    fgets(input, MAX_INPUT_SIZE, stdin);
    return strdup(input);
}

int main() {
    char* name;
    char* message;

    // Get user's name
    name = getInput("What is your name? ");
    sanitizeInput(name);
    printf("Hello, %s! \n", name);

    // Get user's message
    message = getInput("What message would you like to send? ");
    sanitizeInput(message);
    printf("Your message is: %s\n", message);

    free(name);
    free(message);

    return 0;
}