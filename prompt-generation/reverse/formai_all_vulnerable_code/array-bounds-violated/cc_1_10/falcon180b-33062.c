//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];
    int input_size = 0;
    int is_valid_input = 0;

    printf("Enter some text: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input_size = strlen(input);

    // Remove leading/trailing whitespace
    while (isspace(input[0])) {
        memmove(input, input+1, input_size);
        input_size--;
    }
    while (isspace(input[input_size-1])) {
        input[input_size-1] = '\0';
        input_size--;
    }

    // Check for invalid characters
    for (int i = 0; i < input_size; i++) {
        if (!isalnum(input[i])) {
            is_valid_input = 0;
            break;
        }
    }

    // Check for empty input
    if (input_size == 0) {
        is_valid_input = 0;
    }

    // Check for maximum input size
    if (input_size > MAX_INPUT_SIZE) {
        is_valid_input = 0;
    }

    if (is_valid_input) {
        printf("Valid input: %s\n", input);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}