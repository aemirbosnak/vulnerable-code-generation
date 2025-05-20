#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

void sanitize_input(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '!' || input[i] == '@' || input[i] == '#') {
            input[i] = ' ';
        } else if (input[i] == '$' || input[i] == '%' || input[i] == '^') {
            input[i] = '_';
        }
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter first line: ");
    fgets(input, sizeof(input), stdin);
    sanitize_input(input);

    printf("Enter second line: ");
    fgets(input, sizeof(input), stdin);
    sanitize_input(input);

    printf("Enter third line: ");
    fgets(input, sizeof(input), stdin);
    sanitize_input(input);

    printf("Sanitized input:\n%s", input);

    return 0;
}
