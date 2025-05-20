//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_PER_LINE 80

// Declare the function prototypes
void print_ascii_art(char *text);
int main() {
    // Get the input text from the user
    char text[MAX_CHAR_PER_LINE];
    printf("Enter the text you want to convert to ASCII art: ");
    gets(text);

    // Print the ASCII art of the text
    print_ascii_art(text);

    return 0;
}

void print_ascii_art(char *text) {
    // Create a 2D array to store the ASCII art of the text
    char ascii_art[MAX_CHAR_PER_LINE][MAX_CHAR_PER_LINE];

    // Initialize the ASCII art array with spaces
    for (int i = 0; i < MAX_CHAR_PER_LINE; i++) {
        for (int j = 0; j < MAX_CHAR_PER_LINE; j++) {
            ascii_art[i][j] = ' ';
        }
    }

    // Convert the text to ASCII art
    int char_index = 0;
    int row = 0;
    int col = 0;
    while (text[char_index] != '\0') {
        // Get the ASCII code of the character
        int ascii_code = text[char_index];

        // Convert the ASCII code to a 5x7 binary representation
        int binary_representation[5][7];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 7; j++) {
                binary_representation[i][j] = (ascii_code >> (i * 7 + j)) & 1;
            }
        }

        // Draw the character in the ASCII art array
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 7; j++) {
                if (binary_representation[i][j] == 1) {
                    ascii_art[row + i][col + j] = '#';
                }
            }
        }

        // Increment the character index, row, and column
        char_index++;
        col += 7;
        if (col >= MAX_CHAR_PER_LINE) {
            col = 0;
            row += 5;
        }
    }

    // Print the ASCII art
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < MAX_CHAR_PER_LINE; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}