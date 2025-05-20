//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: energetic
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define ASCII_HEIGHT 8
#define ASCII_MAP_SIZE 94

const char* asciiMap[ASCII_MAP_SIZE][ASCII_HEIGHT] = {
    // ASCII characters from space (32) to tilde (126)
    // You can modify these patterns to create new designs
    {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}, // Space
    {" *", "**", " *", " *", " *", " *", " *", "***"}, // !
    {"   ", "   ", "   ", "  *", " * ", "   ", "   ", "   "}, // "
    {"* ", "* ", "***", "* ", "***", "  ", "  ", "  "}, // #
    {"   ", "  *", "***", "  *", "   ", "  ", "   ", "   "}, // $
    {"*  ", " * ", "  *", "   ", "  *", "   ", " * ", "***"}, // %
    {"* ", "**", "* ", "**", "* *", "   ", "***", "   "}, // &
    {" *", "**", " *", "   ", "   ", "   ", "   ", "   "}, // '
    {"   ", "  *", " * ", " * ", "   ", "   ", "   ", "   "}, // (
    {"   ", " * ", "  *", "  *", "   ", "   ", "   ", "   "}, // )
    {"  *", " **", " * ", "***", " * ", "   ", "   ", "   "}, // *
    {"   ", "   ", "***", "   ", "***", "   ", "   ", "   "}, // +
    {"   ", "   ", "   ", "   ", "   ", "   ", "   ", " **"}, // ,
    {"   ", "   ", "***", "   ", "   ", "   ", "   ", "   "}, // -
    {"   ", "   ", "   ", "   ", "  *", "   ", "   ", "   "}, // .
    {"   ", "   ", "  *", " * ", "   ", "   ", "   ", "   "}, // /
    // continue to add ASCII patterns for each character...
    {"***", "* *", "* *", "* *", "***", "   ", "   ", "   "}, // A
    {"** ", "* *", "** ", "* *", "** ", "   ", "   ", "   "}, // B
    // Add more patterns for the remaining characters...

};

void printAsciiArt(char* text) {
    int length = strlen(text);
    for (int line = 0; line < ASCII_HEIGHT; line++) {
        for (int i = 0; i < length; i++) {
            char ch = text[i];
            if (ch >= 32 && ch <= 126) {
                // Find corresponding ASCII art
                int index = ch - 32; // Shift characters to map with 0 index
                printf("%s", asciiMap[index][line]);
            } else {
                // If character is outside printable range, print a space
                printf("     ");
            }
        }
        printf("\n");
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];

    printf("Welcome to the Energetic Text to ASCII Art Generator!\n");
    printf("Enter a text (Max %d characters): ", MAX_TEXT_LENGTH - 1);
    fgets(text, sizeof(text), stdin);
    
    // Remove trailing newline if necessary
    text[strcspn(text, "\n")] = 0;

    printf("\nHere is your ASCII Art:\n");
    printAsciiArt(text);
    
    return 0;
}