//Code Llama-13B DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
// text_to_ascii_art.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

// ASCII art characters
const char *characters[] = {
    "  ___ ",
    " / _ \\",
    "/_/ \\_\\",
    "\\   /",
    " \\_/ ",
};

// Function to generate ASCII art from a given text
void generate_ascii_art(const char *text) {
    int text_length = strlen(text);
    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;

    // Initialize 2D array to store ASCII art
    char art[height][width];

    // Loop through each character in the text
    for (int i = 0; i < text_length; i++) {
        // Get the index of the character in the characters array
        int char_index = text[i] - 'A';

        // Get the ASCII art character for the current character
        const char *ascii_char = characters[char_index];

        // Add the ASCII art character to the art array
        for (int j = 0; j < height; j++) {
            art[j][i] = ascii_char[j];
        }
    }

    // Print the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Get input text from the user
    char text[MAX_WIDTH];
    printf("Enter text: ");
    scanf("%s", text);

    // Generate ASCII art from the input text
    generate_ascii_art(text);

    return 0;
}