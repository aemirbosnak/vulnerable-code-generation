//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate a single character
char translateChar(char c) {
    // Map the character to the corresponding C alien character
    switch (c) {
        case 'a': return 'g';
        case 'b': return 'h';
        case 'c': return 'i';
        case 'd': return 'j';
        case 'e': return 'k';
        case 'f': return 'l';
        case 'g': return 'm';
        case 'h': return 'n';
        case 'i': return 'o';
        case 'j': return 'p';
        case 'k': return 'q';
        case 'l': return 'r';
        case 'm': return 's';
        case 'n': return 't';
        case 'o': return 'u';
        case 'p': return 'v';
        case 'q': return 'w';
        case 'r': return 'x';
        case 's': return 'y';
        case 't': return 'z';
        case 'u': return 'a';
        case 'v': return 'b';
        case 'w': return 'c';
        case 'x': return 'd';
        case 'y': return 'e';
        case 'z': return 'f';
        default: return c;
    }
}

// Function to translate a string
char* translateString(char* str) {
    int len = strlen(str);
    char* res = (char*)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        res[i] = translateChar(str[i]);
    }
    return res;
}

int main() {
    char str[100];
    printf("Enter a string in C Alien Language: ");
    // Read input string
    scanf("%[^\n]s", str);
    char* translated = translateString(str);
    printf("Translated string: %s\n", translated);
    free(translated);  // Free the dynamically allocated memory
    return 0;
}