//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char *s)
{
    int i = 0;
    char num[10];

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
    char img[] = "C Image to ASCII Art Converter";
    int w = 80;

    printf("%.*s", w, img);
    printf("\n");

    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < w; c++)
        {
            switch (img[r * w + c])
            {
                case ' ': case '.': case '-': case '_':
                    printf(" ");
                    break;
                case '#':
                    printf("=");
                    break;
                case '*':
                    printf("$");
                    break;
                case 'O':
                    printf("o");
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}