//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100
#define ASCII_ART_HEIGHT 8
#define ASCII_ART_WIDTH 6

// ASCII representations of characters from space ( ) to tilde (~)
const char *asciiArt[][ASCII_ART_HEIGHT] = {
    {' ', ' ', ' ', ' ', ' ', ' '}, // Space
    {' ', ' ', ' ', ' ', ' ', ' '}, // Exclamation
    {' ', ' ', ' ', ' ', ' ', ' '}, // Quotation
    {' ', 'X', 'X', 'X', ' ', ' '}, // Hash
    {' ', 'X', 'X', 'X', 'X', ' '}, // Dollar
    {' ', ' ', ' ', ' ', ' ', ' '}, // Percent
    {' ', ' ', ' ', ' ', ' ', ' '}, // Ampersand
    {' ', ' ', ' ', 'X', ' ', ' '}, // Apostrophe
    {' ', ' ', ' ', 'X', ' ', ' '}, // Parenthesis Left
    {' ', ' ', ' ', 'X', ' ', ' '}, // Parenthesis Right
    {' ', ' ', ' ', ' ', ' ', ' '}, // Asterisk
    {' ', 'X', 'X', 'X', 'X', ' '}, // Plus
    {' ', ' ', ' ', ' ', ' ', ' '}, // Comma
    {' ', 'X', 'X', 'X', ' ', ' '}, // Hyphen
    {' ', ' ', ' ', ' ', ' ', ' '}, // Period
    {' ', ' ', ' ', ' ', ' ', ' '}, // Slash
    {'X', 'X', 'X', 'X', ' ', ' '}, // 0
    {' ', ' ', ' ', 'X', ' ', ' '}, // 1
    {'X', 'X', ' ', 'X', 'X', ' '}, // 2
    {' ', ' ', ' ', 'X', ' ', ' '}, // 3
    {' ', 'X', 'X', ' ', ' ', ' '}, // 4
    {'X', 'X', ' ', ' ', 'X', ' '}, // 5
    {'X', 'X', 'X', 'X', ' ', ' '}, // 6
    {' ', ' ', ' ', 'X', ' ', ' '}, // 7
    {'X', 'X', 'X', 'X', 'X', ' '}, // 8
    {'X', 'X', 'X', 'X', ' ', ' '}, // 9
    {' ', 'X', ' ', ' ', ' ', ' '}, // Colon
    {' ', ' ', 'X', ' ', ' ', ' '}, // Semicolon
    {' ', ' ', ' ', 'X', ' ', ' '}, // Less than
    {'O', 'O', ' ', ' ', ' ', 'O'}, // Equal
    {' ', ' ', ' ', 'X', ' ', ' '}, // Greater than
    {' ', ' ', 'X', ' ', ' ', ' '}, // Question
    {' ', ' ', ' ', ' ', ' ', ' '}, // At
    {'X', 'X', 'X', ' ', 'X', 'X'}, // A
    {'X', 'X', 'X', 'X', ' ', ' '}, // B
    {' ', 'X', 'X', 'X', ' ', ' '}, // C
    {' ', 'X', 'X', 'X', 'X', ' '}, // D
    {'X', 'X', ' ', 'X', 'X', ' '}, // E
    {'X', 'X', 'X', ' ', ' ', ' '}, // F
    {' ', 'X', 'X', 'X', 'X', ' '}, // G
    {'X', 'X', 'X', ' ', 'X', 'X'}, // H
    {' ', ' ', 'X', ' ', ' ', ' '}, // I
    {' ', ' ', ' ', 'X', ' ', ' '}, // J
    {' ', 'X', ' ', ' ', ' ', ' '}, // K
    {' ', ' ', 'X', ' ', ' ', ' '}, // L
    {'X', ' ', ' ', ' ', ' ', ' '}, // M
    {' ', 'X', ' ', ' ', ' ', ' '}, // N
    {'X', 'X', 'X', 'X', 'X', ' '}, // O
    {'X', 'X', 'X', ' ', ' ', ' '}, // P
    {'X', 'X', 'X', 'X', ' ', ' '}, // Q
    {'X', 'X', ' ', ' ', ' ', ' '}, // R
    {' ', ' ', ' ', 'X', ' ', ' '}, // S
    {'X', ' ', ' ', ' ', ' ', ' '}, // T
    {' ', ' ', 'X', ' ', ' ', ' '}, // U
    {' ', 'X', ' ', ' ', ' ', ' '}, // V
    {'X', 'X', 'X', 'X', 'X', ' '}, // W
    {' ', ' ', ' ', ' ', ' ', ' '}, // X
    {'X', ' ', ' ', ' ', ' ', ' '}, // Y
    {'X', ' ', ' ', ' ', 'X', ' '}, // Z
    // Additional characters as needed...
};

void printAsciiArt(char c) {
    // Handle range of printable ASCII characters
    if (c >= 32 && c <= 126) {
        int index = c - 32; // Map character to corresponding ASCII position
        for (int i = 0; i < ASCII_ART_HEIGHT; i++) {
            printf("%s\n", asciiArt[index][i]);
        }
    } else {
        printf("Character '%c' is not supported for ASCII art.\n", c);
    }
}

void convertToAsciiArt(char *input) {
    for (int i = 0; i < strlen(input); i++) {
        printAsciiArt(input[i]);
        printf("\n"); // Separate characters visually
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter text to convert to ASCII art (max %d characters): ", MAX_INPUT_LENGTH - 1);
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove trailing newline character from input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    printf("\nASCII Art Representation:\n\n");
    convertToAsciiArt(input);

    return 0;
}