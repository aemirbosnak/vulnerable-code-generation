//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to ASCII art
char *char_to_ascii(char ch) {
    // Array of ASCII art characters
    char *ascii_chars[] = {
        "  .----------------.  ",
        " | .--------------. | ",
        " | |    _______   | | ",
        " | |   /  ___  \  | | ",
        " | |  |  (__ \_|  | | ",
        " | |   '.___`----'  | | ",
        " | |       |.      | | ",
        " | |       | |      | | ",
        " | |       | |      | | ",
        " | |       | |      | | ",
        " | |       | |      | | ",
        " | |       | |      | | ",
        " | |       | |      | | ",
        " | |       '-;______.-' | ",
        " | |_________________| | ",
        " |_____________________| ",
        "  '-----------------'  "
    };

    // Get the index of the character in the ASCII art array
    int index = ch - 'a';

    // Return the ASCII art representation of the character
    return ascii_chars[index];
}

// Function to convert a string to ASCII art
char *string_to_ascii(char *str) {
    // Allocate memory for the ASCII art representation of the string
    char *ascii_art = malloc(strlen(str) * 18);

    // Convert each character in the string to ASCII art
    for (int i = 0; i < strlen(str); i++) {
        char *ch_ascii = char_to_ascii(str[i]);

        // Append the ASCII art representation of the character to the string
        strcat(ascii_art, ch_ascii);
    }

    // Return the ASCII art representation of the string
    return ascii_art;
}

// Main function
int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string to ASCII art
    char *ascii_art = string_to_ascii(str);

    // Print the ASCII art representation of the string
    printf("%s\n", ascii_art);

    // Free the memory allocated for the ASCII art representation of the string
    free(ascii_art);

    return 0;
}