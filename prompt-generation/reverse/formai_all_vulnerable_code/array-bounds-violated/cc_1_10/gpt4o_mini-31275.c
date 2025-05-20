//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256
#define CHAR_WIDTH 5
#define CHAR_HEIGHT 7

// ASCII art representation for lowercase alphabets
const char* asciiArt[][CHAR_HEIGHT] = {
    // a-z
    {
        "  _  ",
        " / \ ",
        "/ _ \\",
        "| (_) |",
        " \\___/ ",
        "       ",
        "       "
    },
    {
        " _    ",
        "| |   ",
        "| |__ ",
        "| '_ \\",
        "| |_) |",
        "|_.__/ ",
        "       "
    },
    {
        "  __  ",
        " / _| ",
        "| |__ ",
        "|  __|",
        "| |   ",
        "|_|   ",
        "      "
    },
    {
        " _  __",
        "| |/ /",
        "| ' / ",
        "| . \\ ",
        "|_|\\_\\",
        "      ",
        "      "
    },
    {
        "  _  ",
        " / | ",
        "/  | ",
        "|   |",
        "|_|_|",
        "     ",
        "     "
    },
    {
        "   __",
        "  |_ |",
        "   _|/",
        "  |  ",
        "  |  ",
        "  |__",
        "     "
    },
    {
        "  __  ",
        " |  \\ ",
        " |   |",
        " |   |",
        " | _ |",
        "    _|",
        "     "
    },
    {
        "  __   ",
        " |  |  ",
        " |  |  ",
        " |  |  ",
        " |  |__",
        " |_____\\",
        "        "
    },
    {
        "   __ ",
        "  |__|",
        "   __ ",
        "  |  |",
        "  |  |",
        "  |__|",
        "      "
    },
    {
        "   __  ",
        "  |  | ",
        "  |  | ",
        "  |  | ",
        "  |__| ",
        "   __| ",
        "        "
    },
    {
        "  __   ",
        " |  |  ",
        " |  |  ",
        " |  |__|",
        " |____  ",
        "      | ",
        "      |_ "
    },
    {
        "       ",
        "   /\\  ",
        "  /  \\ ",
        " /____\\",
        "       ",
        "       ",
        "       "
    },
    {
        "      ",
        "   /\\ ",
        "  /__\\",
        "      ",
        "      ",
        "      ",
        "      "
    },
    {
        "      ",
        "   /\\ ",
        "  /__\\",
        " /|  |\\",
        "/_|__|_\\",
        "        ",
        "        "
    },
    {
        "      ",
        "   __ ",
        "  |__|",
        "   __|",
        "  |__|",
        "      ",
        "      "
    },
    {
        "    __",
        "   |  |",
        "   |__|",
        "   |__|",
        "   |  |",
        "   |__|",
        "       "
    },
    {
        "      ",
        "  _ * ",
        " | |  |",
        " | |__|",
        " |__ | ",
        "      ",
        "      "
    },
    {
        "  _  ",
        " / \\ ",
        "/ _ \\",
        "| (_) |",
        " \\___/ ",
        "        ",
        "        "
    },
    {
        "   _  ",
        "  | |_|",
        "  | | |  ",
        "  | | |  ",
        "  |_|_|  ",
        "         ",
        "         "
    },
    {
        "      ",
        "   _  ",
        "  | | ",
        "  | | ",
        "  |_| ",
        "      ",
        "      "
    },
    {
        "      ",
        "      ",
        "       ",
        "   _ _ ",
        "  | | |",
        "  | | |",
        "  |_|_|"
    }
};

// Function to generate ASCII art for a given input string
void generateAsciiArt(const char* str) {
    size_t len = strlen(str);
    for (int row = 0; row < CHAR_HEIGHT; row++) {
        for (size_t i = 0; i < len; i++) {
            char ch = tolower(str[i]);
            if (ch >= 'a' && ch <= 'z') {
                printf("%s", asciiArt[ch - 'a'][row]);
            } else {
                // Print empty space for unsupported characters
                printf("       ");
            }
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_INPUT];

    printf("Enter a string (a-z): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    generateAsciiArt(input);

    return 0;
}