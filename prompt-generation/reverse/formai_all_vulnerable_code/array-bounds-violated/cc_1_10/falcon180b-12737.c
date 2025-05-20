//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1000

int main() {
    char input[MAX_INPUT_SIZE];
    int input_length;

    printf("Enter some input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input_length = strlen(input);

    // Remove leading and trailing whitespace
    while (isspace(input[0])) {
        memmove(input, input + 1, input_length - 1);
        input_length--;
    }
    while (isspace(input[input_length - 1])) {
        input[input_length - 1] = '\0';
        input_length--;
    }

    // Remove any non-alphanumeric characters
    for (int i = 0; i < input_length; i++) {
        if (!isalnum(input[i])) {
            memmove(input + i, input + i + 1, input_length - i - 1);
            input_length--;
        }
    }

    // Remove any consecutive whitespace
    for (int i = 0; i < input_length; i++) {
        if (isspace(input[i])) {
            memmove(input + i, input + i + 1, input_length - i - 1);
            input_length--;
        }
    }

    // Remove any leading or trailing whitespace
    while (isspace(input[0])) {
        memmove(input, input + 1, input_length - 1);
        input_length--;
    }
    while (isspace(input[input_length - 1])) {
        input[input_length - 1] = '\0';
        input_length--;
    }

    printf("Sanitized input: %s\n", input);

    return 0;
}