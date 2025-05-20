//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    int w, h, x, y;

    printf("Enter the width of the pixel art: ");
    scanf("%d", &w);

    printf("Enter the height of the pixel art: ");
    scanf("%d", &h);

    int **arr = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++)
    {
        arr[i] = (int *)malloc(w * sizeof(int));
    }

    printf("Enter the pixel art data (separated by commas): ");
    char input[1024];
    fgets(input, 1024, stdin);

    // Convert the input string into an array of integers
    char *token = strtok(input, ",");
    int i = 0;
    while (token)
    {
        arr[i / h][i % w] = atoi(token);
        token = strtok(NULL, ",");
        i++;
    }

    // Print the pixel art
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            printf("%d ", arr[y][x]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < h; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}