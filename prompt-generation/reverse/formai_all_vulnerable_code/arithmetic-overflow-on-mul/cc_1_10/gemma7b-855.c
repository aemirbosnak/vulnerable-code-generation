//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **ascii_art = NULL;
    int rows = 0;
    int cols = 0;

    // Allocate memory for the ASCII art
    ascii_art = malloc(rows * sizeof(char *) + 1);
    for (int r = 0; r < rows; r++)
    {
        ascii_art[r] = malloc(cols * sizeof(char) + 1);
    }

    // Get the ASCII art from the user
    printf("Enter the number of rows for your ASCII art: ");
    scanf("%d", &rows);

    printf("Enter the number of columns for your ASCII art: ");
    scanf("%d", &cols);

    // Fill the ASCII art with characters
    printf("Enter the ASCII characters for your art (separate them with spaces): ");
    char *art_text = malloc(rows * cols * sizeof(char) + 1);
    scanf("%s", art_text);

    // Convert the ASCII text into an ASCII art
    int i = 0;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            ascii_art[r][c] = art_text[i];
            i++;
        }
    }

    // Print the ASCII art
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%c ", ascii_art[r][c]);
        }
        printf("\n");
    }

    // Free the memory allocated for the ASCII art
    for (int r = 0; r < rows; r++)
    {
        free(ascii_art[r]);
    }
    free(ascii_art);
    free(art_text);

    return 0;
}