//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 50

int main()
{
    int width, height;
    char **ascii_art;

    // Get the dimensions of the ASCII art
    printf("Enter the width of the ASCII art: ");
    scanf("%d", &width);

    printf("Enter the height of the ASCII art: ");
    scanf("%d", &height);

    // Allocate memory for the ASCII art
    ascii_art = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++)
    {
        ascii_art[i] = (char*)malloc(width * sizeof(char));
    }

    // Get the ASCII art
    printf("Enter the ASCII art: ");
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            scanf("%c", &ascii_art[h][w]);
        }
    }

    // Print the ASCII art
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            printf("%c ", ascii_art[h][w]);
        }
        printf("\n");
    }

    // Free the memory for the ASCII art
    for (int i = 0; i < height; i++)
    {
        free(ascii_art[i]);
    }
    free(ascii_art);

    return 0;
}