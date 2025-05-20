//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char *s)
{
    int i = 0;
    char *p = s;

    if (n < 0)
    {
        *p++ = '-';
        n = -n;
    }

    while (n)
    {
        int digit = n % 10;
        *p++ = digit + '0';
        n /= 10;
    }

    *p = '\0';
}

int main()
{
    char img[] = "C Image to ASCII Art Converter";
    int w = 40;
    int h = 20;

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            char pixel = img[y * w + x];

            switch (pixel)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("*");
                    break;
                case 3:
                    printf("#");
                    break;
            }
        }

        printf("\n");
    }

    return 0;
}