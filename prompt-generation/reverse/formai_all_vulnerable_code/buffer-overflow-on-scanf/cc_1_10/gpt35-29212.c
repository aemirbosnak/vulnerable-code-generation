//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 80    // Maximum length of ASCII art lines
#define MAX_ASCII_VALUE 126   // Maximum ASCIII value for printable characters
#define MIN_ASCII_VALUE 32    // Minimum ASCII value for printable characters

// Function to convert a character to its corresponding ASCII value
int charToAscii(char c) {
    return (int) c;
}

// Function to print the ASCII art
void printAsciiArt(char* text) {
    // Get the length of the input text
    int textLength = strlen(text);

    // Create an array of characters to store the ASCII art
    char asciiArt[textLength][MAX_LINE_LENGTH + 1];

    // Initialize the array with spaces
    for (int i = 0; i < textLength; i++) {
        for (int j = 0; j < MAX_LINE_LENGTH; j++) {
            asciiArt[i][j] = ' ';
        }
        asciiArt[i][MAX_LINE_LENGTH] = '\0';
    }

    // Calculate the ASCII art for each character in the input text
    for (int i = 0; i < textLength; i++) {
        int asciiValue = charToAscii(text[i]);
        
        // Make sure the ASCII value is within the printable range
        if (asciiValue < MIN_ASCII_VALUE || asciiValue > MAX_ASCII_VALUE) {
            asciiValue = MIN_ASCII_VALUE + (i % (MAX_ASCII_VALUE - MIN_ASCII_VALUE));
        }
        
        // Calculate the ASCII art for the current character
        for (int j = 0; j < MAX_LINE_LENGTH; j++) {
            int asciiArtValue = (int) ((1 - (j % 2)) * asciiValue + (j % 2) * (MAX_ASCII_VALUE - asciiValue));
            asciiArt[i][j] = (char) asciiArtValue;
        }
    }

    // Print the ASCII art
    for (int i = 0; i < MAX_LINE_LENGTH; i++) {
        for (int j = 0; j < textLength; j++) {
            printf("%c", asciiArt[j][i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Get the input text from the user
    char text[100];
    printf("Enter a text to convert to ASCII art: ");
    scanf("%s", text);

    // Print the ASCII art for the input text
    printAsciiArt(text);

    return 0;
}