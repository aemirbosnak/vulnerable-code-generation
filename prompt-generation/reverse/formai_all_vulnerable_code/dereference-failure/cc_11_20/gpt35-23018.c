//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const int MAX_LENGTH = 100; // Maximum length of input string

bool containsSpecialChar(char c) {
    return c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || 
           c == '^' || c == '&' || c == '*' || c == '(' || c == ')' ||
           c == '-' || c == '+' || c == '=' || c == '[' || c == ']' ||
           c == '{' || c == '}' || c == ';' || c == ':' || c == '"' ||
           c == '\'' || c == '<' || c == '>' || c == ',' || c == '.' ||
           c == '/' || c == '?' || c == '|' || c == '\\' || c == '~' ||
           c == '`';
}

void sanitizeString(char *input, int length) {
    int i, count = 0;
    char *temp = (char *)malloc(length); // create a temporary string

    for (i = 0; i < length; i++) {
        char c = input[i];
        if (isalpha(c)) {
            temp[count++] = c; // if it's alphabetic, add to temp string
        } else if (isdigit(c)) {
            temp[count++] = c; // if it's numeric, add to temp string
        } else if (isspace(c)) {
            temp[count++] = ' '; // if it's a space, add space to temp string
        } else if (containsSpecialChar(c)) {
            temp[count++] = c; // if it's a special character, add to temp string
        } // otherwise, do nothing
    }

    // replace original input string with sanitized string
    strcpy(input, temp);
    free(temp);
}

int main() {
    char input[MAX_LENGTH];

    printf("Welcome to Input Sanitizer 9000!\n");
    printf("Please enter a string (maximum of %d characters):\n", MAX_LENGTH);

    // read user input string
    fgets(input, sizeof(input), stdin);

    // remove newline character from input string
    input[strcspn(input, "\n")] = '\0';

    // sanitize input string
    sanitizeString(input, strlen(input));

    printf("\nYour sanitized string is: %s\n", input);

    return 0;
}