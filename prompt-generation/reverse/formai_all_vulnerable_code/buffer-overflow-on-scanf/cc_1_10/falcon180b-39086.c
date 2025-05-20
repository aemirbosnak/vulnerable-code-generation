//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_ALLOWED_CHARS 100

int main() {
    char input[MAX_INPUT_LENGTH];
    char allowed_chars[MAX_ALLOWED_CHARS];
    int allowed_chars_count = 0;
    int input_length;

    // Prompt user to enter allowed characters
    printf("Enter allowed characters (up to 100): ");
    scanf("%s", allowed_chars);

    // Convert allowed characters to lowercase
    for (int i = 0; i < strlen(allowed_chars); i++) {
        allowed_chars[i] = tolower(allowed_chars[i]);
    }

    // Prompt user to enter input
    printf("Enter input: ");
    scanf("%s", input);

    // Sanitize input
    input_length = strlen(input);
    for (int i = 0; i < input_length; i++) {
        if (!isalnum(input[i])) {
            input[i] = '_';
        }
    }

    // Count number of allowed characters in input
    for (int i = 0; i < strlen(allowed_chars); i++) {
        for (int j = 0; j < input_length; j++) {
            if (allowed_chars[i] == input[j]) {
                allowed_chars_count++;
                break;
            }
        }
    }

    // Print sanitized input and number of allowed characters
    printf("Sanitized input: %s\n", input);
    printf("Number of allowed characters: %d\n", allowed_chars_count);

    return 0;
}