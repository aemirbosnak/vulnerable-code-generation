//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

void itoa(int num, char *str)
{
    int i = 0;
    char n[11];
    if (num < 0)
    {
        n[0] = '-';
        num = -num;
    }
    else
    {
        n[0] = '+';
    }
    while (num)
    {
        int digit = num % 10;
        num /= 10;
        n[i++] = digit + '0';
    }
    n[i] = '\0';
    strcpy(str, n);
}

int main()
{
    char image[] = "C Image to ASCII Art Converter!";
    int width = 60;
    int height = 5;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (image[x] == 'C')
            {
                printf("%c", 248);
            }
            else if (image[x] == 'I')
            {
                printf("%c", 242);
            }
            else if (image[x] == 'M')
            {
                printf("%c", 236);
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