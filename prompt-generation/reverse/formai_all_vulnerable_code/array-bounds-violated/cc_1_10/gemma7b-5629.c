//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char *s)
{
    int i = 0;
    char num[11];

    if (n < 0)
    {
        s[0] = '-';
        n = -n;
    }

    do
    {
        num[i++] = n % 10 + '0';
        n /= 10;
    } while (n);

    num[i] = '\0';
    strcpy(s, num);
}

int main()
{
    char image[] = "           /\n"
                     "\\/|\\/\n"
                     "\___)_\n";

    int w = 12;
    int h = 3;

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            char pixel = image[y * w + x];

            switch (pixel)
            {
                case '.':
                    printf(" ");
                    break;
                case '-':
                    printf(" ");
                    break;
                case '|':
                    printf("|");
                    break;
                case ')':
                    printf(")");
                    break;
                default:
                    printf(" ");
                    break;
            }
        }

        printf("\n");
    }

    return 0;
}