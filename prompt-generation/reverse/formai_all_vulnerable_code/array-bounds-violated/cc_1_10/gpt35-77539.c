//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: asynchronous
#include <stdio.h> // Standard Input Output Library
#include <stdlib.h> // Standard Library
#include <string.h> // String Library

// ASCII Art Constants
#define ROWS 8
#define COLS 8

// Function Prototypes
void generateAsciiArt(char* text, int length);
void printAsciiArt(char art[][COLS]);

int main()
{
    char text[100]; // Maximum Input Size
    int length; // Length of Input Text

    printf("Enter a Text: ");
    scanf("%[^\n]%*c", text); // Reading input including spaces

    length = strlen(text);

    generateAsciiArt(text, length); // Generate Text ASCII Art

    return 0; // Successful Execution
}

/**
 * Function to generate ASCII Art
 * Input: text (Input Text), length (Length of Input Text)
 * Output: ASCII Art
 **/
void generateAsciiArt(char* text, int length)
{
    int i, j, char_pos, ascii_val;
    char ascii_char;

    char ascii_art[ROWS][COLS]; // ASCII Art Array

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            ascii_art[i][j] = ' '; // Initializing with a space
        }
    }

    for (i = 0; i < length; i++)
    {
        char_pos = text[i] - 32;
        if (char_pos < 0 || char_pos > 94) // Checking if character is valid
            continue;

        ascii_val = ((char_pos % 8) * 8) + (char_pos / 8); // Calculating ASCII value
        ascii_char = (char)ascii_val;

        ascii_art[(i / COLS) * 2][(i % COLS)] = ascii_char; // Saving character in ASCII Art array
    }

    printAsciiArt(ascii_art); // Printing ASCII Art
}

/**
 * Function to print ASCII Art
 * Input: art (ASCII Art Array)
 **/
void printAsciiArt(char art[][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%c ", art[i][j]); // Printing each character in a row
        }
        printf("\n"); // Moving to next row
    }
}