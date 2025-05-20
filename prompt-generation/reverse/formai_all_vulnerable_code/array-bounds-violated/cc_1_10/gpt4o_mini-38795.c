//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_CHAR_COUNT 128
#define ASCII_WIDTH 5
#define ASCII_HEIGHT 7

// Define a structure for Font
typedef struct {
    char character; // ASCII character representation
    char bitmap[ASCII_HEIGHT][ASCII_WIDTH + 1]; // Bitmap for the character
} Font;

// Declare ASCII art font characters
Font fonts[ASCII_CHAR_COUNT];

// Function to initialize ASCII art characters
void initializeFonts() {
    // Example bitmap for characters 'A', 'B', 'C', and space
    // Each character is defined using a 5x7 pixel block
    // 1 represents a pixel, 0 represents no pixel
    Font sampleFonts[] = {
        {'A', {
            "  1  ",
            " 1 1 ",
            "1   1",
            "11111",
            "1   1",
            "1   1",
            "     "}},
        {'B', {
            "1111 ",
            "1   1",
            "1111 ",
            "1   1",
            "1111 ",
            "     ",
            "     "}},
        {'C', {
            " 111 ",
            "1   1",
            "1    ",
            "1   1",
            " 111 ",
            "     ",
            "     "}},
        {' ', {
            "     ",
            "     ",
            "     ",
            "     ",
            "     ",
            "     ",
            "     "}}
    };

    // Copy the sample fonts to the global fonts array
    for (int i = 0; i < sizeof(sampleFonts) / sizeof(sampleFonts[0]); i++) {
        fonts[(int)sampleFonts[i].character] = sampleFonts[i];
    }
}

// Function to convert text to ASCII art
void textToAsciiArt(const char* text) {
    // Get length of text
    int len = strlen(text);

    // Loop through each character in the text
    for (int row = 0; row < ASCII_HEIGHT; row++) {
        for (int i = 0; i < len; i++) {
            char ch = text[i];
            // Print the corresponding ASCII art row of the character
            for (int col = 0; col < ASCII_WIDTH; col++) {
                if (fonts[(int)ch].bitmap[row][col] == '1') {
                    printf("##"); // Print "#" for pixel
                } else {
                    printf("  "); // Print space for no pixel
                }
            }
            // Print a space between characters
            printf("  ");
        }
        printf("\n"); // Move to the next row after printing all characters
    }
}

// Main function
int main() {
    char inputText[256];

    // Initialize fonts
    initializeFonts();

    // Welcome message
    printf("Welcome to the Text to ASCII Art Generator!\n");
    printf("Enter text to convert (max 255 characters): ");

    // Read input text from user
    fgets(inputText, sizeof(inputText), stdin);
    
    // Remove trailing newline character
    inputText[strcspn(inputText, "\n")] = 0;

    // Generate ASCII art
    printf("\nASCII Art Representation:\n\n");
    textToAsciiArt(inputText);

    return 0;
}