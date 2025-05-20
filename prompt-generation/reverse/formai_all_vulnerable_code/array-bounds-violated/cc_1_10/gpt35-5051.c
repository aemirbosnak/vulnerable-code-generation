//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024

int main() {

    char input[MAX_INPUT_SIZE];
    printf("Please enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove newline character from input
    int len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Remove leading and trailing spaces
    int i = 0;
    while (isspace(input[i])) {
        i++;
    }

    int j = strlen(input) - 1;
    while (j > i && isspace(input[j])) {
        j--;
    }

    input[j+1] = '\0';
    char* sanitized_input = (char*)malloc((strlen(input) + 1) * sizeof(char));

    if (sanitized_input == NULL) {
        printf("Error: Unable to allocate memory for sanitized input.\n");
        exit(EXIT_FAILURE);
    }

    memset(sanitized_input, 0, strlen(input) + 1);

    // Loop through input to sanitize it
    int k = 0;
    for (i; i <= j; i++) {
        if (isalnum(input[i])) {
            sanitized_input[k++] = input[i];
        }
    }

    printf("Sanitized input: %s\n", sanitized_input);

    // Free memory
    free(sanitized_input);

    return 0;

}