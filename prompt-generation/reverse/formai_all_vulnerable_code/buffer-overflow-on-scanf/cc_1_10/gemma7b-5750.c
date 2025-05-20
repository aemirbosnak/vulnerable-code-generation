//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void draw_ascii_art(int w, int h, char ***arr)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%c ", arr[i][j]);
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
            arr[i][j] = (char *)malloc(1 * sizeof(char));
        }
    }

    printf("Enter the ASCII art: ");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            scanf("%c", arr[i][j]);
        }
    }

    draw_ascii_art(w, h, arr);

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