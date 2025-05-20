//FormAI DATASET v1.0 Category: Fractal Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

void display(char **fractal, int size);

void draw_fractal(char **fractal, int x, int y, int size, int level);

char **initialize_fractal(int size);

void free_fractal(char **fractal, int size);

int main()
{
    srand(time(NULL));

    int size, level;

    printf("Enter the size of the fractal: ");
    scanf("%d", &size);

    char **fractal = initialize_fractal(size);

    level = log2(size);

    draw_fractal(fractal, size / 2, size / 2, size / 2, level);

    display(fractal, size);

    free_fractal(fractal, size);

    return 0;
}

void display(char **fractal, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%c", fractal[i][j]);
        }
        printf("\n");
    }
}

void draw_fractal(char **fractal, int x, int y, int size, int level)
{
    if (level == 0)
    {
        fractal[x][y] = '*';
        return;
    }

    draw_fractal(fractal, x - size / 2, y - size / 2, size / 2, level - 1);
    draw_fractal(fractal, x + size / 2, y - size / 2, size / 2, level - 1);
    draw_fractal(fractal, x - size / 2, y + size / 2, size / 2, level - 1);
    draw_fractal(fractal, x + size / 2, y + size / 2, size / 2, level - 1);
}

char **initialize_fractal(int size)
{
    char **fractal = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++)
    {
        fractal[i] = (char *)malloc(size * sizeof(char));
        for (int j = 0; j < size; j++)
        {
            fractal[i][j] = ' ';
        }
    }

    return fractal;
}

void free_fractal(char **fractal, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(fractal[i]);
    }
    free(fractal);
}