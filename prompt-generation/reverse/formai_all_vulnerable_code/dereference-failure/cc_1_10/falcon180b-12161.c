//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only alphabets
int isAlphabet(char *str) {
    int i = 0;
    while(str[i]!= '\0') {
        if(!isalpha(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to sanitize user input
void sanitizeInput(char *input) {
    int i = 0, j = 0;
    char sanitized[1000]; // assuming maximum input length is 1000 characters

    // remove leading and trailing whitespaces
    while(isspace(input[i])) {
        i++;
    }
    while(isspace(input[strlen(input)-1])) {
        input[strlen(input)-1] = '\0';
        input[strlen(input)-2] = '\0';
        input[strlen(input)-3] = '\0';
    }

    // remove non-alphabetic characters
    while(isAlphabet(input)) {
        sanitized[j] = input[i];
        i++;
        j++;
    }
    sanitized[j] = '\0';

    // copy sanitized input to original input
    strcpy(input, sanitized);
}

// Example usage
int main() {
    char input[1000];
    printf("Enter some text: ");
    fgets(input, 1000, stdin);
    sanitizeInput(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}