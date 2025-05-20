//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_SANITIZED_LENGTH (MAX_INPUT_LENGTH * 2)

void sanitize_input(char *input) {
    char sanitized_input[MAX_SANITIZED_LENGTH];
    int sanitized_length = 0;
    int input_length = strlen(input);

    // Remove leading/trailing whitespace
    while (isspace(input[0])) {
        input++;
    }
    while (isspace(input[input_length - 1])) {
        input_length--;
    }

    // Convert all characters to lowercase
    for (int i = 0; i < input_length; i++) {
        sanitized_input[sanitized_length++] = tolower(input[i]);
    }

    // Remove non-alphanumeric characters
    for (int i = 0; i < sanitized_length; i++) {
        if (!isalnum(sanitized_input[i])) {
            sanitized_input[i] = '\0';
        }
    }

    // Remove consecutive dots
    int consecutive_dots = 0;
    for (int i = 0; i < sanitized_length; i++) {
        if (sanitized_input[i] == '.') {
            consecutive_dots++;
        } else {
            consecutive_dots = 0;
        }
        if (consecutive_dots > 1) {
            sanitized_input[i] = '\0';
        }
    }

    // Truncate sanitized input if it exceeds the maximum length
    if (sanitized_length > MAX_SANITIZED_LENGTH) {
        sanitized_input[MAX_SANITIZED_LENGTH - 1] = '\0';
    }

    // Copy sanitized input to original input buffer
    strcpy(input, sanitized_input);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter some text:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sanitize_input(input);

    printf("Sanitized input: %s\n", input);

    return 0;
}