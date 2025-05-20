//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input[1000];
    char *sanitized_input;
    int i, j;

    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin); // get user input with fgets

    for(i = 0; i < strlen(input); i++) {

        // check for alphabets, digits, and common symbols
        if((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122) || (input[i] >= 48 && input[i] <= 57)
         || input[i] == ' ' || input[i] == '.' || input[i] == ',' || input[i] == '!' || input[i] == '?' || input[i] == '@'
         || input[i] == '#' || input[i] == '$' || input[i] == '%' || input[i] == '^' || input[i] == '&' || input[i] == '*'
         || input[i] == '(' || input[i] == ')' || input[i] == '-' || input[i] == '_' || input[i] == '+' || input[i] == '='
         || input[i] == '[' || input[i] == ']' || input[i] == '{' || input[i] == '}' || input[i] == ':' || input[i] == ';'
         || input[i] == '\'' || input[i] == '"' || input[i] == '/' || input[i] == '\\' || input[i] == '|' || input[i] == '<'
         || input[i] == '>' || input[i] == '`' || input[i] == '~') {

            // keep the character

        } else {

            // replace the character with a space
            input[i] = ' ';
        }
    }

    // remove any extra spaces and leading/trailing spaces
    i = 0;
    while(input[i] == ' ') {
        i++;
    }

    j = strlen(input) - 1;
    while(input[j] == ' ' || input[j] == '\n') {
        j--;
    }

    input[j + 1] = '\0'; // add null terminator

    sanitized_input = (char *) malloc((j - i + 2) * sizeof(char)); // allocate memory
    strncpy(sanitized_input, input + i, j - i + 1); // copy sanitized input into new variable
    sanitized_input[j - i + 1] = '\0'; // add null terminator

    printf("Sanitized input: %s\n", sanitized_input); // display sanitized input

    free(sanitized_input); // free memory
    return 0;
}