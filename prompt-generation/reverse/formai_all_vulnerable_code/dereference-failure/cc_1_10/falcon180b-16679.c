//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

// Function to remove leading and trailing whitespaces from a string
void trim(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;

    while (isspace(*start))
        start++;

    while (isspace(*end))
        end--;

    memmove(str, start, end - start + 1);
    str[end - start + 1] = '\0';
}

// Function to check if a string contains only alphabets and whitespaces
int isAlphabet(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i]) &&!isspace(str[i]))
            return 0;
    }

    return 1;
}

// Function to sanitize user input
void sanitizeInput(char* input) {
    trim(input);
    if (strlen(input) == 0)
        printf("Input cannot be empty.\n");
    else if (!isAlphabet(input))
        printf("Input contains invalid characters.\n");
    else
        printf("Input is valid.\n");
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    sanitizeInput(input);

    return 0;
}