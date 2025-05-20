//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

void setPixel(char pixels[HEIGHT][WIDTH], int x, int y, char color)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        pixels[y][x] = color;
    }
}

void drawRectangle(char pixels[HEIGHT][WIDTH], int x, int y, int w, int h, char color)
{
    for (int i = x; i < x + w; i++)
    {
        for (int j = y; j < y + h; j++)
        {
            setPixel(pixels, i, j, color);
        }
    }
}

void drawLine(char pixels[HEIGHT][WIDTH], int x1, int y1, int x2, int y2, char color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
 
    int sx = x2 >= x1 ? 1 : -1;
    int sy = y2 >= y1 ? 1 : -1;

    int err = dx - dy;

    while (x1 != x2 || y1 != y2)
    {
        setPixel(pixels, x1, y1, color);

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }

    setPixel(pixels, x2, y2, color);
}

int main()
{
    srand(time(NULL));

    char pixels[HEIGHT][WIDTH];

    printf(" -----Pixel Art Generator-----\n");
    printf("|                             |\n");
    printf("| Choose your art style:      |\n");
    printf("| 1. Random                   |\n");
    printf("| 2. Rectangle                |\n");
    printf("| 3. Line                     |\n");
    printf("|                             |\n");
    printf(" ------------------------------\n");

    int choice;
    scanf("%d", &choice);

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            pixels[i][j] = '.';
        }
    }

    switch (choice)
    {
        case 1:
        {
            for (int i = 0; i < HEIGHT; i++)
            {
                for (int j = 0; j < WIDTH; j++)
                {
                    int colorIndex = rand() % 3;
                    char color = colorIndex == 0 ? 'R' : colorIndex == 1 ? 'G' : 'B';
                    setPixel(pixels, j, i, color);
                }
            }

            break;
        }

        case 2:
        {
            int x, y, w, h;
            printf("Enter x, y, width, and height: ");
            scanf("%d %d %d %d", &x, &y, &w, &h);

            int colorIndex;
            char color;
            printf("Choose your color:\n");
            printf("1. Red\n");
            printf("2. Green\n");
            printf("3. Blue\n");
            scanf("%d", &colorIndex);
            color = colorIndex == 1 ? 'R' : colorIndex == 2 ? 'G' : 'B';

            drawRectangle(pixels, x, y, w, h, color);

            break;
        }

        case 3:
        {
            int x1, y1, x2, y2;
            printf("Enter x1, y1, x2, and y2: ");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            int colorIndex;
            char color;
            printf("Choose your color:\n");
            printf("1. Red\n");
            printf("2. Green\n");
            printf("3. Blue\n");
            scanf("%d", &colorIndex);
            color = colorIndex == 1 ? 'R' : colorIndex == 2 ? 'G' : 'B';

            drawLine(pixels, x1, y1, x2, y2, color);

            break;
        }

        default:
        {
            printf("Invalid choice.\n");
        }
    }

    printf("\n");

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%c ", pixels[i][j]);
        }

        printf("\n");
    }

    return 0;
}