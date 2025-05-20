//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 1024

int main() {
    char input[MAX_INPUT_LENGTH];
    char sanitized_input[MAX_INPUT_LENGTH];
    int i, j, k;
    bool is_sanitized = false;

    printf("Welcome to the C User Input Sanitizer!\n");
    printf("Please enter your input:\n");

    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove leading and trailing white spaces
    i = 0;
    while (isspace(input[i])) {
        i++;
    }
    j = strlen(input) - 1;
    while (isspace(input[j])) {
        j--;
    }
    input[j] = '\0';

    // Check for null characters
    if (strchr(input, '\0')!= NULL) {
        printf("Error: Input contains null characters.\n");
        return 1;
    }

    // Check for maximum length
    if (strlen(input) >= MAX_INPUT_LENGTH) {
        printf("Error: Input is too long.\n");
        return 1;
    }

    // Sanitize input by removing non-printable characters and converting to lowercase
    for (i = 0, j = 0; input[i]!= '\0'; i++) {
        if (isprint(input[i])) {
            sanitized_input[j++] = tolower(input[i]);
        }
    }
    sanitized_input[j] = '\0';

    // Compare sanitized input with original input
    if (strcmp(input, sanitized_input) == 0) {
        printf("Input is already sanitized.\n");
    } else {
        printf("Sanitized input: %s\n", sanitized_input);
        is_sanitized = true;
    }

    // Ask user if they want to save the sanitized input to a file
    printf("Do you want to save the sanitized input to a file? (y/n): ");
    scanf(" %c", &k);

    if (k == 'y' || k == 'Y') {
        FILE *fp;
        fp = fopen("sanitized_input.txt", "w");

        if (fp == NULL) {
            printf("Error: Could not open file.\n");
            return 1;
        }

        fprintf(fp, "%s", sanitized_input);

        fclose(fp);
        printf("Sanitized input saved to file.\n");
    }

    return 0;
}