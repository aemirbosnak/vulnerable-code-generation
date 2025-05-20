//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to ASCII Art
void charToAsciiArt(char ch, int width, char* art) {
    const char *asciiArt[][5] = {
        {"  _  ", " | | ", " | | ", " |_| ", "     "}, // A
        {" _   ", "| |  ", "| |_ ", "|_ _|", "     "}, // B
        {"  _  ", " | | ", " | | ", " |_| ", "     "}, // C
        // Add other characters as needed ...
    };

    if(ch >= 'A' && ch <= 'Z') {
        int index = ch - 'A';
        for(int i = 0; i < 5; i++) {
            strcat(art, asciiArt[index][i]);
            strcat(art, "\n");
        }
    }
}

// Main function to convert the input string to ASCII Art
void textToAsciiArt(char *input) {
    char art[1024] = ""; // Buffer to hold ASCII art

    for(int i = 0; i < strlen(input); i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            charToAsciiArt(input[i], 5, art);
        } else if(input[i] == ' ') {
            strcat(art, "\n\n"); // Space between words
        }
    }

    printf("%s\n", art);
}

int main() {
    char input[256];

    // Prompt the user for input
    printf("Enter a string (A-Z only): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    // Run conversion and show ASCII art
    printf("Generating ASCII art...\n");
    textToAsciiArt(input);

    return 0;
}