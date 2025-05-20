//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000

int sanitize_input(char* input) {
    int i = 0;
    int j = 0;
    char buffer[MAX_INPUT_LENGTH];

    // Remove leading/trailing whitespace
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[strlen(input)-1-i])) {
        i--;
    }

    // Copy input to buffer, ignoring non-printable characters
    while (i < strlen(input)) {
        if (isprint(input[i])) {
            buffer[j++] = input[i++];
        } else {
            i++;
        }
    }
    buffer[j] = '\0';

    // Remove consecutive non-printable characters
    char* nonprintable = "!@#$%^&*()_+-=[]{}\\|;':\",.<>/?";
    char* output = buffer;
    while (*output) {
        if (strchr(nonprintable, *output)) {
            memmove(output, output+1, strlen(output)-1);
        } else {
            output++;
        }
    }

    // Add null terminator
    output[strlen(output)-1] = '\0';

    // Copy output to input
    strcpy(input, output);

    return 1;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter some input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}