//Code Llama-13B DATASET v1.0 Category: Text to ASCII art generator ; Style: active
// C Text to ASCII Art Generator Example Program

#include <stdio.h>
#include <string.h>

// Function to convert a character to its ASCII art representation
void char_to_ascii_art(char c, int size) {
    // Define the ASCII art characters for each letter
    char letters[26][5][5] = {
        // A
        {
            " _ ",
            "| |",
            "|_|",
            "   ",
            "   "
        },
        // B
        {
            " _ ",
            "|_|",
            " _|",
            "   ",
            "   "
        },
        // C
        {
            " _ ",
            " _|",
            " _|",
            "   ",
            "   "
        },
        // D
        {
            " _ ",
            "|_|",
            "  |",
            "   ",
            "   "
        },
        // E
        {
            " _ ",
            "| |",
            "|_|",
            "   ",
            "   "
        },
        // F
        {
            " _ ",
            "| |",
            " _|",
            "   ",
            "   "
        },
        // G
        {
            " _ ",
            "|_|",
            "|_|",
            "   ",
            "   "
        },
        // H
        {
            " _ ",
            "| |",
            "| |",
            "   ",
            "   "
        },
        // I
        {
            " _ ",
            "  |",
            "  |",
            "   ",
            "   "
        },
        // J
        {
            " _ ",
            "|_|",
            "  |",
            "   ",
            "   "
        },
        // K
        {
            " _ ",
            "| |",
            " _|",
            "   ",
            "   "
        },
        // L
        {
            " _ ",
            "|_|",
            "   ",
            "   ",
            "   "
        },
        // M
        {
            " _ ",
            "|_|",
            "|_|",
            "   ",
            "   "
        },
        // N
        {
            " _ ",
            "|_|",
            "| |",
            "   ",
            "   "
        },
        // O
        {
            " _ ",
            "| |",
            "|_|",
            "   ",
            "   "
        },
        // P
        {
            " _ ",
            "|_|",
            "|_|",
            "   ",
            "   "
        },
        // Q
        {
            " _ ",
            "| |",
            "|_|",
            "  |",
            "   "
        },
        // R
        {
            " _ ",
            "|_|",
            "| |",
            "   ",
            "   "
        },
        // S
        {
            " _ ",
            "| |",
            " _|",
            "   ",
            "   "
        },
        // T
        {
            " _ ",
            "| |",
            "   ",
            "   ",
            "   "
        },
        // U
        {
            " _ ",
            "|_|",
            "|_|",
            "   ",
            "   "
        },
        // V
        {
            " _ ",
            "| |",
            "| |",
            "   ",
            "   "
        },
        // W
        {
            " _ ",
            "|_|",
            " _|",
            "   ",
            "   "
        },
        // X
        {
            " _ ",
            "|_|",
            "|_|",
            "   ",
            "   "
        },
        // Y
        {
            " _ ",
            "|_|",
            "|_|",
            "  |",
            "   "
        },
        // Z
        {
            " _ ",
            "|_|",
            " _|",
            "   ",
            "   "
        }
    };

    // Check if the character is a letter
    if (c >= 'a' && c <= 'z') {
        // Convert the character to uppercase
        c = toupper(c);
        // Get the index of the letter in the letters array
        int index = c - 'A';
        // Print the ASCII art representation of the letter
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%c", letters[index][i][j]);
            }
            printf("\n");
        }
    } else {
        // Print a space if the character is not a letter
        printf(" ");
    }
}

// Main function to test the ASCII art generator
int main() {
    // Get the user input
    char text[100];
    printf("Enter a text: ");
    scanf("%s", text);

    // Convert the text to uppercase
    for (int i = 0; i < strlen(text); i++) {
        text[i] = toupper(text[i]);
    }

    // Print the ASCII art representation of the text
    for (int i = 0; i < strlen(text); i++) {
        char_to_ascii_art(text[i], 5);
    }

    return 0;
}