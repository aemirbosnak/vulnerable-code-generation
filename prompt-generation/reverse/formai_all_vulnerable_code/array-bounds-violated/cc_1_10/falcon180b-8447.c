//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];
    char sanitized_input[MAX_INPUT_SIZE];
    int i, j;

    printf("Enter a string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove leading and trailing whitespace
    i = 0;
    while (isspace(input[i])) {
        i++;
    }
    j = strlen(input) - 1;
    while (isspace(input[j])) {
        j--;
    }
    input[j] = '\0';

    // Replace multiple whitespace characters with a single space
    i = 0;
    while (i < strlen(input)) {
        if (isspace(input[i])) {
            j = i + 1;
            while (isspace(input[j]) && j < strlen(input)) {
                j++;
            }
            memmove(input + i, input + j, strlen(input) - j);
            input[strlen(input) - j] = '\0';
        }
        i++;
    }

    // Remove non-alphanumeric characters
    i = 0;
    while (i < strlen(input)) {
        if (!isalnum(input[i])) {
            input[i] = '\0';
        }
        i++;
    }

    // Copy sanitized input to output
    strcpy(sanitized_input, input);

    // Print sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    return 0;
}