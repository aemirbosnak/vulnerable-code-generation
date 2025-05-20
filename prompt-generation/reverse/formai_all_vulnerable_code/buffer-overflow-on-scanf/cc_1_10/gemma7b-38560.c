//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **ascii_art = NULL;
    int height = 0;
    int width = 0;

    printf("Please enter the height of your ASCII art: ");
    scanf("%d", &height);

    printf("Please enter the width of your ASCII art: ");
    scanf("%d", &width);

    ascii_art = malloc(height * sizeof(char *) + height);
    for (int r = 0; r < height; r++)
    {
        ascii_art[r] = malloc(width * sizeof(char) + width);
    }

    // Get the ASCII art from the user
    printf("Enter your ASCII art (line by line):\n");
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            scanf("%c", &ascii_art[r][c]);
        }
    }

    // Print the ASCII art
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            printf("%c ", ascii_art[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < height; r++)
    {
        free(ascii_art[r]);
    }
    free(ascii_art);

    return 0;
}