//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void draw_ascii_art(int width, int height, char ***arr)
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            printf("%c ", arr[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    char ***arr = NULL;
    int w, h;

    printf("Enter the width of the ASCII art: ");
    scanf("%d", &w);

    printf("Enter the height of the ASCII art: ");
    scanf("%d", &h);

    arr = (char ***)malloc(h * sizeof(char **));
    for (int i = 0; i < h; i++)
    {
        arr[i] = (char **)malloc(w * sizeof(char *));
        for (int j = 0; j < w; j++)
        {
            arr[i][j] = (char *)malloc(MAX_SIZE * sizeof(char));
        }
    }

    // Get the ASCII art data from the user
    printf("Enter the ASCII art data (line by line):\n");
    for (int r = 0; r < h; r++)
    {
        char line[MAX_SIZE];
        scanf("%s", line);
        strcpy(arr[r], line);
    }

    // Draw the ASCII art
    draw_ascii_art(w, h, arr);

    // Free the memory
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);

    return 0;
}