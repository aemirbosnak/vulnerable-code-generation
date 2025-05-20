//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert a character to its ASCII art representation
char *char_to_ascii(char c) {
    char *ascii_art[] = {
        " ▄███▄   ▄███▄   ▄███▄     ▄▄▄▄▄        ▄▄▄▄▄   ▄█▄    █▄▄▄▄   ██▄      ▄▄▄▄▄  ",
        "█▀   ▀  █▀   ▀  █▀   ▀    █     ▀▄  ▀▀▀▀▄   █▀▀▀█   █▀▀▀▀▄ █  █     █     ▀▄ ",
        "█    █  █      █    █    █       █    █   █    █  █      █ █    █   █        █ ",
        "█    █  █      █    █    █       █    █   █    █  █    ▄▀ █    █   █        █ ",
        "█    █  █▄▄▄▄█   ▄█████▄    █      ▀▄    █   ▀▄▄█   █    █  ███▄    █        █ ",
        " ▀▄▄▄▀   ▀▄▄▄▀   ▀▒▒▒▒▒▀     ▀▄▄▄▄▄▀     ▀▄▄▄▄▀    ▀▄▄▄▀    ▀▒▒▒▀    ▀▄▄▄▄▄  ",
        "                                                                                 "
    };

    return ascii_art[c - 'a'];
}

// Function to convert a string to its ASCII art representation
char *string_to_ascii(char *str) {
    int len = strlen(str);
    char *ascii_art = malloc(len * 7 + 1); // Each character is 7 characters wide, plus 1 for the null-terminator
    for (int i = 0; i < len; i++) {
        strcat(ascii_art, char_to_ascii(str[i]));
    }
    ascii_art[len * 7] = '\0';
    return ascii_art;
}

// Function to print the ASCII art representation of a string
void print_ascii_art(char *ascii_art) {
    int len = strlen(ascii_art);
    for (int i = 0; i < len; i += 7) {
        printf("%s\n", ascii_art + i);
    }
}

int main() {
    char *str = "Hello, world!";

    // Convert the string to its ASCII art representation
    char *ascii_art = string_to_ascii(str);

    // Print the ASCII art representation of the string
    print_ascii_art(ascii_art);

    // Free the memory allocated for the ASCII art representation
    free(ascii_art);

    return 0;
}