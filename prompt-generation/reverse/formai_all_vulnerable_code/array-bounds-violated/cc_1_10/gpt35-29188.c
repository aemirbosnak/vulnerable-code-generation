//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <string.h>

char* translate(char* input) {
    // Dictionary of C Alien Language mappings
    char* dictionary[] = {
        "int",
        "char",
        "float",
        "double",
        "if",
        "else",
        "switch",
        "case",
        "break",
        "while",
        "do",
        "for",
        "return"
    };

    // Corresponding C language mappings
    char* mappings[] = {
        "x",
        "v",
        "y",
        "z",
        "a",
        "b",
        "c",
        "d",
        "e",
        "f",
        "g",
        "h",
        "i"
    };

    // Tokenize input string
    char* token = strtok(input, " ");

    // Output buffer
    char output[1000] = "";
    
    while (token != NULL) {
        // Search for matching word in dictionary
        int match_found = 0;
        for (int i = 0; i < 13; i++) {
            if (strcmp(token, dictionary[i]) == 0) {
                strcat(output, mappings[i]);
                strcat(output, " ");
                match_found = 1;
                break;
            }
        }

        // If no matching word was found, just append the original token
        if (!match_found) {
            strcat(output, token);
            strcat(output, " ");
        }

        // Move on to next token
        token = strtok(NULL, " ");
    }

    // Return the translated output
    return output;
}

int main() {
    // Prompt user for input
    printf("Enter a sentence in C Alien Language: ");
    char input[1000];
    fgets(input, 1000, stdin);

    // Remove trailing newline
    input[strlen(input) - 1] = '\0';

    // Translate and print output
    char* output = translate(input);
    printf("Translated: %s\n", output);

    return 0;
}