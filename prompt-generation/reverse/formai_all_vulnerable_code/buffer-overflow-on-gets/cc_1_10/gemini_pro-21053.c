//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to ASCII art
char *char_to_ascii(char c) {
    // Define the ASCII art for each character
    char *ascii_art[] = {
        "  ___  ",
        " |__ \\ ",
        "    ) |",
        "   / / ",
        "  / /_ ",
        " |____|",
        " _   _ ",
        "| | | |",
        "| |_| |",
        " \\___/ ",
        "       ",
        "  ___  ",
        " |__ \\ ",
        "   ) |",
        "  / / ",
        " / /_ ",
        "|____|",
        " _   _ ",
        "| | | |",
        "| |_| |",
        " \\___/ ",
        "       ",
        "  ___  ",
        " |__ \\ ",
        "   ) |",
        "  / / ",
        " / /_ ",
        "|____|",
        " _   _ ",
        "| | | |",
        "| |_| |",
        " \\___/ ",
        "       ",
        "  ___  ",
        " |__ \\ ",
        "   ) |",
        "  / / ",
        " / /_ ",
        "|____|",
        " _   _ ",
        "| | | |",
        "| |_| |",
        " \\___/ ",
        "       ",
        "  ___  ",
        " |__ \\ ",
        "   ) |",
        "  / / ",
        " / /_ ",
        "|____|",
        " _   _ ",
        "| | | |",
        "| |_| |",
        " \\___/ ",
        "       ",
        "  ___  ",
        " |__ \\ ",
        "   ) |",
        "  / / ",
        " / /_ ",
        "|____|",
        " _   _ ",
        "| | | |",
        "| |_| |",
        " \\___/ ",
        "       ",
        "  ___  ",
        " |__ \\ ",
        "   ) |",
        "  / / ",
        " / /_ ",
        "|____|",
        " _   _ ",
        "| | | |",
        "| |_| |",
        " \\___/ ",
        "       ",
        "  ___  ",
        " |__ \\ ",
        "   ) |",
        "  / / ",
        " / /_ ",
        "|____|",
        " _   _ ",
        "| | | |",
        "| |_| |",
        " \\___/ ",
        "       ",
        "  ___  ",
        " |__ \\ ",
        "   ) |",
        "  / / ",
        " / /_ ",
        "|____|",
        " _   _ ",
        "| | | |",
        "| |_| |",
        " \\___/ ",
        "       ",
        "  ___  ",
        " |__ \\ ",
        "   ) |",
        "  / / ",
        " / /_ ",
        "|____|",
        " _   _ ",
        "| | | |",
        "| |_| |",
        " \\___/ ",
        "       ",
        "  ___  ",
        " |__ \\ ",
        "   ) |",
        "  / / ",
        " / /_ ",
        "|____|",
        " _   _ ",
        "| | | |",
        "| |_| |",
        " \\___/ "
    };

    // Return the ASCII art for the given character
    return ascii_art[c - 'A'];
}

// Function to convert a string to ASCII art
char *string_to_ascii(char *string) {
    // Allocate memory for the ASCII art
    char *ascii_art = malloc(strlen(string) * 7);

    // Convert each character in the string to ASCII art
    for (int i = 0; i < strlen(string); i++) {
        strcat(ascii_art, char_to_ascii(string[i]));
    }

    // Return the ASCII art
    return ascii_art;
}

// Main function
int main() {
    // Get the string to convert to ASCII art from the user
    char string[100];
    printf("Enter a string to convert to ASCII art: ");
    gets(string);

    // Convert the string to ASCII art
    char *ascii_art = string_to_ascii(string);

    // Print the ASCII art
    printf("%s", ascii_art);

    // Free the memory allocated for the ASCII art
    free(ascii_art);

    return 0;
}