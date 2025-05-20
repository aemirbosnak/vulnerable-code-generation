//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_ART_HEIGHT 10

/* Function declaration */
char** generateAsciiArt(char* inputString, int artHeight);

int main()
{
    char inputString[MAX_LINE_LENGTH];
    int artHeight;

    printf("Enter your text (max 80 characters): ");
    fgets(inputString, MAX_LINE_LENGTH, stdin);

    printf("Enter the height of the ASCII art (max 10): ");
    scanf("%d", &artHeight);

    char** asciiArt = generateAsciiArt(inputString, artHeight);

    printf("Here's the ASCII art:\n");

    int i, j;
    for (i = 0; i < artHeight; i++) {
        for (j = 0; j < strlen(inputString); j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (i = 0; i < artHeight; i++) {
        free(asciiArt[i]);
    }
    free(asciiArt);

    return 0;
}

/**
 * Generate ASCII art for the input string.
 * @param inputString The string to generate ASCII art for.
 * @param artHeight The height of the ASCII art.
 * @return A 2D character array (string array) representing the ASCII art.
 */
char** generateAsciiArt(char* inputString, int artHeight)
{
    char** asciiArt = (char**) malloc(artHeight * sizeof(char*));
    int i, j, k;

    for (i = 0; i < artHeight; i++) {
        asciiArt[i] = (char*) malloc(strlen(inputString) * sizeof(char));
    }

    for (i = 0; i < artHeight; i++) {
        for (j = 0; j < strlen(inputString); j++) {
            if (inputString[j] != '\n' && inputString[j] != '\r') {
                // Set the character according to a pattern
                k = ((i + j) % 5) + 1;
                asciiArt[i][j] = (char) (k + '0');
            }
        }
    }

    return asciiArt;
}