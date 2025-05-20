//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to ASCII art
char* charToASCII(char c) {
    // Array of ASCII art characters
    char* ASCII_chars[] = {
        "  ____ ",
        " | __ )",
        " |  _ \\",
        " | |_) |",
        " |____/ ",
        "       ",
        "  ___  ",
        " |__ \\ ",
        "    ) |",
        "   / / ",
        "  / /_ ",
        " |____|",
        "   ___  ",
        "  / _ \\ ",
        " | | | |",
        " | |_| |",
        "  \\___/ ",
        "       ",
        "  _____ ",
        " |  ___|",
        " | |_   ",
        " |  _|  ",
        " |_|    ",
        "       ",
        "   ___  ",
        "  / _ \\ ",
        " | | | |",
        " | |_| |",
        "  \\___/ ",
        "       ",
        "   ___  ",
        "  / _ \\ ",
        " | | | |",
        " | |_| |",
        "  \\___/ ",
        "       ",
        "  _____ ",
        " |__  / ",
        "   / /  ",
        "  / /_  ",
        " /____| ",
        "       ",
        "  _____  ",
        " |  __ \\ ",
        " | |__) |",
        " |  ___/ ",
        " |_|     ",
        "        ",
        "  ___  ",
        " |__ \\ ",
        "   ) |",
        "  / / ",
        " / /_ ",
        " |____|",
        "   ___  ",
        "  / _ \\ ",
        " | | | |",
        " | |_| |",
        "  \\___/ ",
        "       ",
        "  _____  ",
        " |_   _| ",
        "   | |   ",
        "   | |   ",
        "   |_|   ",
        "        ",
        "   ___  ",
        "  / _ \\ ",
        " | | | |",
        " | |_| |",
        "  \\___/ ",
        "       ",
        "  _____  ",
        " |_   _| ",
        "   | |   ",
        "   | |   ",
        "   |_|   ",
        "        ",
        "  _____  ",
        " |_   _| ",
        "   | |   ",
        "   | |   ",
        "   |_|   ",
        "        ",
        "   ___  ",
        "  / _ \\ ",
        " | | | |",
        " | |_| |",
        "  \\___/ ",
        "       ",
        "  _____  ",
        " |__  / ",
        "   / /  ",
        "  / /_  ",
        " /____| ",
        "       ",
        "  _____ ",
        " |  ___|",
        " | |_   ",
        " |  _|  ",
        " |_|    ",
        "       ",
        "  ___   ",
        " |__ \\  ",
        "   ) | ",
        "  / /  ",
        " / /_  ",
        " |____|",
        "        ",
        "  __  __ ",
        " |  \\/  |",
        " | |\/| |",
        " | |  | |",
        " |_|  |_|",
        "        ",
        "  _____ ",
        " |_   _| ",
        "   | |   ",
        "   | |   ",
        "   |_|   ",
        "        ",
        "  _____  ",
        " |_   _| ",
        "   | |   ",
        "   | |   ",
        "   |_|   ",
        "        ",
        "  _____  ",
        " |_   _| ",
        "   | |   ",
        "   | |   ",
        "   |_|   ",
        "        ",
        "   ___   ",
        "  / _ \\  ",
        " | | | |",
        " | |_| |",
        "  \\___/ ",
        "       ",
        "  _   _ ",
        " | | | |",
        " | | | |",
        " | |_| |",
        "  \\___/ ",
        "       ",
        "  _____ ",
        " |_   _| ",
        "   | |   ",
        "   | |   ",
        "   |_|   ",
        "        ",
        "   ___  ",
        "  / _ \\ ",
        " | (_) |",
        "  \\__, |",
        "   |___/ ",
        "       ",
        "  _____ ",
        " |_   _| ",
        "   | |   ",
        "   | |   ",
        "   |_|   ",
        "        ",
        "   _   _ ",
        "  | | | |",
        "  | | | |",
        "  | |_| |",
        "   \\___/ ",
        "       ",
        "  _____  ",
        " |_   _| ",
        "   | |   ",
        "   | |   ",
        "   |_|   ",
        "        ",
        "  _____ ",
        " |_   _| ",
        "   | |   ",
        "   | |   ",
        "   |_|   ",
        "        ",
        "   ___   ",
        "  / _ \\  ",
        " | | | |",
        " | |_| |",
        "  \\___/ ",
        "       ",
        "  _____  ",
        " |__  /  ",
        "   / /   ",
        "  / /_  ",
        " /____| ",
        "       ",
        "   ___  ",
        "  / _ \\ ",
        " | | | |",
        " | |_| |",
        "  \\___/ ",
        "       ",
        "  _____  ",
        " |_   _| ",
        "   | |   ",
        "   | |   ",
        "   |_|   ",
        "        "
    };

    // Check if the character is valid
    if (c < 'A' || c > 'Z') {
        return NULL;
    }

    // Return the ASCII art character for the given character
    return ASCII_chars[c - 'A'];
}

// Function to convert a string to ASCII art
char* stringToASCII(char* str) {
    // Allocate memory for the ASCII art string
    char* ASCII_str = malloc(strlen(str) * 7);

    // Convert each character in the string to ASCII art
    for (int i = 0; i < strlen(str); i++) {
        char* ASCII_char = charToASCII(str[i]);
        strcat(ASCII_str, ASCII_char);
        strcat(ASCII_str, "\n");
    }

    // Return the ASCII art string
    return ASCII_str;
}

// Main function
int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    gets(str);

    // Convert the string to ASCII art
    char* ASCII_str = stringToASCII(str);

    // Print the ASCII art string
    printf("%s", ASCII_str);

    // Free the memory allocated for the ASCII art string
    free(ASCII_str);

    return 0;
}