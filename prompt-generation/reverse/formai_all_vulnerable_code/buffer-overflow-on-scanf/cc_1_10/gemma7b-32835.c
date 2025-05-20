//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w, h, i, j;
    char **img;

    printf("Enter image width: ");
    scanf("%d", &w);

    printf("Enter image height: ");
    scanf("%d", &h);

    img = malloc(h * w * sizeof(char *));
    for (i = 0; i < h; i++)
    {
        img[i] = malloc(w * sizeof(char));
    }

    printf("Enter image data: ");
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            scanf("%c", &img[i][j]);
        }
    }

    printf("ASCII art:\n");
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            switch (img[i][j])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("#");
                    break;
                default:
                    printf("!");
                    break;
            }
        }
        printf("\n");
    }

    free(img);

    return 0;
}