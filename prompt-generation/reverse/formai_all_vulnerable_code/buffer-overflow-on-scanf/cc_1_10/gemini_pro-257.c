//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Cat Language Translator function
char *cat_language_translator(char *input) {
    // Allocate memory for the translated string
    char *translated = malloc(strlen(input) + 1);

    // Translate the input string into Cat Language
    int i;
    for (i = 0; i < strlen(input); i++) {
        switch (input[i]) {
            case 'a':
                translated[i] = 'm';
                break;
            case 'e':
                translated[i] = 'o';
                break;
            case 'i':
                translated[i] = 'u';
                break;
            case 'o':
                translated[i] = 'a';
                break;
            case 'u':
                translated[i] = 'e';
                break;
            default:
                translated[i] = input[i];
        }
    }

    // Add the null-terminator to the translated string
    translated[strlen(input)] = '\0';

    // Return the translated string
    return translated;
}

// Define the main function
int main() {
    // Get the input string from the user
    char input[100];
    printf("Enter a string to be translated into Cat Language: ");
    scanf("%s", input);

    // Translate the input string into Cat Language
    char *translated = cat_language_translator(input);

    // Print the translated string
    printf("The translated string is: %s\n", translated);

    // Free the memory allocated for the translated string
    free(translated);

    return 0;
}