//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// CAT Translator Function
void catTranslate(char *input) {
    int i, j;
    char output[100];

    for (i = 0; input[i] != '\0'; i++) {
        if (isspace(input[i])) {
            output[i] = 'M'; // Meow for space
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = input[i] + 3; // Purr for capital letters
            if (output[i] > 'Z') output[i] -= 26;
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = input[i] + 3; // Hiss for small letters
            if (output[i] > 'z') output[i] -= 26;
        } else {
            output[i] = input[i]; // Keep special characters as is
        }
    }

    // Add null terminator to output string
    output[i] = '\0';

    // Print translated string
    printf("Input: %s\n", input);
    printf("Output: %s\n", output);
}

int main() {
    char input[100];

    printf("Welcome to the CAT Language Translator!\n");
    printf("Translate English text into CAT language!\n\n");

    printf("Enter text to translate: ");
    scanf("%s", input);

    catTranslate(input);

    return 0;
}

// CAT Language Translator Functions
// Meow for spaces
// Purr for capital letters (shifted 3 positions)
// Hiss for small letters (shifted 3 positions)
// Keep special characters as is