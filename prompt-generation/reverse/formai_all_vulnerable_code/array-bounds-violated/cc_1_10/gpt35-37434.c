//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: statistical
#include <stdio.h>
#include <string.h>

// Function to print the ASCII art
void printASCIIArt(char *text)
{
    printf("\n");

    // Define the ASCII art, represented as a 2D array
    char asciiArt[][11] = {
        "     __     ",
        " _  |  | _  ",
        "|_| |__||_| ",
        "             ",
        "   _____    ",
        "  |  __ \\   ",
        "  | |__) |  ",
        "  |  ___/   ",
        "  |_|       ",
        "             ",
        "   _____    ",
        "  | ____|   ",
        "  | |__     ",
        "  |___ \\    ",
        "  |____) |  ",
        "             ",
        "  _    _    ",
        " | |  | |   ",
        " | |__| |   ",
        " |____/    ",
        "            ",
        "   ______   ",
        "  | ____ \\  ",
        "  | |__| |  ",
        "  |___   /  ",
        "      |_|   ",
        "            ",
        "  ________  ",
        " |____  __| ",
        "     | |    ",
        "     | |    ",
        "     |_|    ",
        "            ",
        "   ______   ",
        "  |  ____|  ",
        "  | |__     ",
        "  |  __|    ",
        "  | |____   ",
        "  |______|  ",
        "            ",
        "  ______    ",
        " |___  /    ",
        "    / /     ",
        "   / /      ",
        "  / /__     ",
        " /_____|    ",
        "            ",
        "  _     _   ",
        " | |   / /  ",
        " | |__/ /_  ",
        " |____/(_) ",
        "            ",
        "  ____   _  ",
        " |___ \\ / | ",
        "   __) | | |",
        "  |__ <  | |",
        "  ___) |/ / ",
        " |____//_/  ",
        "            ",
        "  _______   ",
        " |__   __|  ",
        "    | |     ",
        "    | |     ",
        "    | |     ",
        "    |_|     "
    };

    // Determine the length of the text and the ASCII art
    int textLength = strlen(text);
    int asciiArtLength = sizeof(asciiArt) / sizeof(asciiArt[0]);

    // Loop through each line of the ASCII art
    for (int i = 0; i < 6; i++) {
        // Loop through each character in the text
        for (int j = 0; j < textLength; j++) {
            // Calculate the index of the corresponding ASCII art line
            // based on the ASCII code of the current character
            int asciiIndex = (int)text[j] - 32;
            // Print the corresponding character in the ASCII art line
            printf("%c", asciiArt[asciiIndex][i]);
        }
        printf("\n");
    }

    printf("\n");
}

int main()
{
    // Test the printASCIIArt() function with some sample text
    char sampleText[] = "Hello, world!";
    printASCIIArt(sampleText);

    return 0;
}