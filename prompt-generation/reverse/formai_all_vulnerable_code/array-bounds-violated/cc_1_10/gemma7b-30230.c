//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int num, char *str)
{
    int i = 0;
    char temp;

    str[0] = '\0';

    if (num < 0)
    {
        str[0] = '-';
        num = -num;
    }

    while (num)
    {
        temp = num % 10;
        num /= 10;
        str[i++] = temp + '0';
    }

    str[i] = '\0';
}

int main()
{
    char image[] = ":)";

    int height = 3;
    int width = 5;

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            if (image[c] == ':')
            {
                printf("=");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}