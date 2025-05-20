//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    char input[100];
    int i, j, k, length, num_digits;
    bool is_valid = true;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(input, 100, stdin);

    // Remove any leading/trailing whitespace
    length = strlen(input);
    if (input[0] == '\n') {
        input[0] = '\0';
        length--;
    }
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
        length--;
    }

    // Check for valid characters
    for (i = 0; i < length; i++) {
        if (!isalpha(input[i])) {
            is_valid = false;
            break;
        }
    }

    // Check for minimum length
    if (length < 5) {
        is_valid = false;
    }

    // Check for maximum length
    if (length > 20) {
        is_valid = false;
    }

    // Check for special characters
    if (strchr(input, '!') || strchr(input, '@') || strchr(input, '#') || strchr(input, '$') || strchr(input, '%') || strchr(input, '&')) {
        is_valid = false;
    }

    // Check for numbers
    num_digits = 0;
    for (i = 0; i < length; i++) {
        if (isdigit(input[i])) {
            num_digits++;
        }
    }
    if (num_digits > 2) {
        is_valid = false;
    }

    // Check for consecutive characters
    for (i = 0; i < length - 1; i++) {
        if (input[i] == input[i + 1]) {
            is_valid = false;
            break;
        }
    }

    // Output the result
    if (is_valid) {
        printf("Input is valid.\n");
    } else {
        printf("Input is NOT valid.\n");
    }

    return 0;
}