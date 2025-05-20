//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a valid identifier
int isIdentifier(char c) {
    // All characters in the range of a-z and A-Z are valid identifier characters
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    // All other characters are not valid identifier characters
    return 0;
}

// Function to check if a string is a valid identifier
int isValidIdentifier(char *str) {
    // Check if the string contains any invalid characters
    for (int i = 0; i < strlen(str); i++) {
        if (!isIdentifier(str[i])) {
            return 0;
        }
    }
    // If the string contains only valid identifier characters, it is a valid identifier
    return 1;
}

// Function to parse a syntax
void parseSyntax(char *syntax) {
    // Print the syntax
    printf("%s\n", syntax);

    // Check if the syntax is a valid identifier
    if (isValidIdentifier(syntax)) {
        printf("The syntax '%s' is a valid identifier.\n", syntax);
    } else {
        printf("The syntax '%s' is not a valid identifier.\n", syntax);
    }
}

// Function to generate a random syntax
char *generateSyntax(int length) {
    char *syntax = (char *)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        syntax[i] = 'a' + rand() % 26;
    }
    syntax[length] = '\0';
    return syntax;
}

int main() {
    int length;
    printf("Enter the length of the syntax: ");
    scanf("%d", &length);

    // Generate a random syntax
    char *syntax = generateSyntax(length);

    // Parse the syntax
    parseSyntax(syntax);

    // Free the memory
    free(syntax);

    return 0;
}