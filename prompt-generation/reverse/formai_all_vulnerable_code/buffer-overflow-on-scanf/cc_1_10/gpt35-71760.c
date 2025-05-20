//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertCode(char code[], int length);

int main()
{
    int numPlayers;
    char colorCode[7]; // Accepts hex color code as user input

    printf("Welcome to the Color Code Converter Game!\n");
    printf("How many players will be playing?\n");
    scanf("%d", &numPlayers);
    printf("Enter a hex color code: ");
    scanf("%s", colorCode);

    printf("Original color code: %s\n", colorCode);

    // Call the function to convert the hex color code to RGB
    convertCode(colorCode, strlen(colorCode));

    printf("Color code converted to RGB successfully!\n");

    // Invite other players to guess the RGB values
    for (int i = 2; i <= numPlayers; i++)
    {
        printf("Player %d, guess the RGB values in this format: r g b\n", i);
        
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);

        // Check if the guess is correct
        if (r == colorCode[0] && g == colorCode[2] && b == colorCode[4])
        {
            printf("Congratulations! You guessed the correct RGB values!\n");
        }
        else
        {
            printf("Incorrect guess. Please try again\n");
        }
    }

    return 0;
}

// Function to convert hex color code to RGB values
void convertCode(char code[], int length)
{
    int r, g, b;
    r = strtol(strncpy((char[3]){code[0], code[1], 0}, &code[0], 2), NULL, 16);
    g = strtol(strncpy((char[3]){code[2], code[3], 0}, &code[2], 2), NULL, 16);
    b = strtol(strncpy((char[3]){code[4], code[5], 0}, &code[4], 2), NULL, 16);

    printf("RGB values: (%d, %d, %d)\n", r, g, b);
}