#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

void sanitize_input(char *input) {
    int i = 0;
    while (input[i] != '\0') {
        if (!isalnum(input[i]) && !isspace(input[i])) {
            input[i] = '_';
        }
        i++;
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter your command: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    sanitize_input(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}
