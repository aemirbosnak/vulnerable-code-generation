//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char *s)
{
    int i = 0;
    char num[11];

    if (n < 0)
    {
        num[0] = '-';
        n = -n;
    }

    while (n)
    {
        int digit = n % 10;
        num[i++] = digit + '0';
        n /= 10;
    }

    num[i] = '\0';
    strcpy(s, num);
}

int main()
{
    char image[] = "R";
    int width = 5;
    int height = 3;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (image[x] == 'R')
            {
                printf("%c", 247);
            }
            else
            {
                printf("%c", 32);
            }
        }

        printf("\n");
    }

    return 0;
}