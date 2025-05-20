//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void generate_ascii_art(int width, int height, char **arr)
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            arr[r][c] = rand() % MAX + 32;
        }
    }
}

int main()
{
    int width, height;
    char **arr;

    printf("Enter the width of the ASCII art: ");
    scanf("%d", &width);

    printf("Enter the height of the ASCII art: ");
    scanf("%d", &height);

    arr = (char **)malloc(height * sizeof(char *) + 1);
    for (int i = 0; i < height; i++)
    {
        arr[i] = (char *)malloc(width * sizeof(char) + 1);
    }

    generate_ascii_art(width, height, arr);

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            printf("%c ", arr[r][c]);
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}