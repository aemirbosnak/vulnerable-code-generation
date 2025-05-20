//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4

int main()
{
    int r, g, b, y;
    char color;

    printf("Enter the color code (R, G, B, Y): ");
    scanf("%c", &color);

    switch (color)
    {
        case 'R':
            r = RED;
            g = 0;
            b = 0;
            y = 0;
            break;
        case 'G':
            r = 0;
            g = GREEN;
            b = 0;
            y = 0;
            break;
        case 'B':
            r = 0;
            g = 0;
            b = BLUE;
            y = 0;
            break;
        case 'Y':
            r = 0;
            g = 0;
            b = 0;
            y = YELLOW;
            break;
        default:
            printf("Invalid color code.\n");
            return 1;
    }

    printf("The color code is: R %d, G %d, B %d, Y %d\n", r, g, b, y);

    return 0;
}