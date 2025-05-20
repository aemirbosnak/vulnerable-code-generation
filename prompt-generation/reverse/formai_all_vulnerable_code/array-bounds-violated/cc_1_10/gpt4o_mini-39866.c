//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printASCIIArt(char *input) {
    const char *asciiArt[] = {
        "             ___       ",
        "            |  _ \\      ",
        "            | |_) |     ",
        "            |  __/      ",
        "            |_|         ",
        "   _   _     ___    _   ",
        "  | | | |   / _ \\  | |  ",
        "  | |_| |  | | | | | |  ",
        "  |  _  |  | | | | | |  ",
        "  |_| |_|   \\___/  |_|  ",
        "   _           _        ",
        "  (_)         | |       ",
        "   _  __ _  __| |__     ",
        "  | |/ _` |/ _` '_ \\    ",
        "  | | (_| | (_| | | |   ",
        "  | |\\__,_|\\__,_| |_|   "
    };

    printf("Your input in ASCII Art:\n");
    int input_length = strlen(input);
    
    for (int i = 0; i < input_length; i++) {
        // Print each character in the input string using ASCII art
        if (input[i] >= 'A' && input[i] <= 'Z') {
            // Adjust for capital letters (A-Z)
            int index = input[i] - 'A';
            for (int j = 0; j < 6; j++) {
                printf("%s", asciiArt[j * 6 + index]);
            }
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            // Adjust for lowercase letters (a-z)
            int index = input[i] - 'a';
            for (int j = 0; j < 6; j++) {
                printf("%s", asciiArt[j * 6 + index]);
            }
        } else if (input[i] == ' ') {
            // Print space in ASCII Art
            for (int j = 0; j < 6; j++) {
                printf("                  \n");
            }
        }
    }
    printf("\n");
}

void getInput(char *buffer, int length) {
    printf("Please enter a string to convert to ASCII Art: ");
    fgets(buffer, length, stdin);

    // Remove the newline character from fgets
    size_t input_len = strlen(buffer);
    if (input_len > 0 && buffer[input_len - 1] == '\n') {
        buffer[input_len - 1] = '\0';
    }
}

int main() {
    char input[100];

    getInput(input, sizeof(input));
    printASCIIArt(input);

    printf("Thank you for using the ASCII Art Generator! Have a great day!\n");
    return 0;
}