//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_INPUT_LENGTH 1000

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove leading and trailing whitespace
    int i = 0;
    while (isspace(input[i])) {
        i++;
    }
    int j = strlen(input) - 1;
    while (isspace(input[j])) {
        input[j] = '\0';
        j--;
    }

    // Check for null characters
    if (strchr(input, '\0')!= NULL) {
        printf("Error: Input contains null character.\n");
        return 1;
    }

    // Check for maximum length
    if (strlen(input) >= MAX_INPUT_LENGTH) {
        printf("Error: Input exceeds maximum length of %d characters.\n", MAX_INPUT_LENGTH);
        return 1;
    }

    // Remove non-ASCII characters
    for (i = 0; i < strlen(input); i++) {
        if (!isascii(input[i])) {
            input[i] = '\0';
        }
    }

    // Check for empty input
    if (strlen(input) == 0) {
        printf("Error: Input is empty.\n");
        return 1;
    }

    // Check for special characters
    char special_chars[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    int special_chars_length = strlen(special_chars);
    for (i = 0; i < strlen(input); i++) {
        if (strchr(special_chars, input[i])!= NULL) {
            printf("Error: Input contains special characters.\n");
            return 1;
        }
    }

    // Check for numbers
    if (strspn(input, "0123456789")!= strlen(input)) {
        printf("Error: Input contains non-numeric characters.\n");
        return 1;
    }

    // Check for alphabetic characters
    if (strspn(input, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz")!= strlen(input)) {
        printf("Error: Input contains non-alphabetic characters.\n");
        return 1;
    }

    printf("Input is valid.\n");
    return 0;
}