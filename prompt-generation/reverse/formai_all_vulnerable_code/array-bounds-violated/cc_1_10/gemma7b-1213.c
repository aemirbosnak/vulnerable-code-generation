//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char image[] = "C Image to ASCII Art Converter";
    int i, j, height, width;

    height = 20;
    width = 50;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (image[j] != '\0')
            {
                switch (image[j])
                {
                    case 'C':
                        printf("%c ", 219);
                        break;
                    case 'I':
                        printf("%c ", 247);
                        break;
                    case 'M':
                        printf("%c ", 230);
                        break;
                    case 'A':
                        printf("%c ", 173);
                        break;
                    case 'R':
                        printf("%c ", 235);
                        break;
                    default:
                        printf("%c ", 32);
                        break;
                }
            }
            else
            {
                printf("%c ", 32);
            }
        }

        printf("\n");
    }

    return 0;
}