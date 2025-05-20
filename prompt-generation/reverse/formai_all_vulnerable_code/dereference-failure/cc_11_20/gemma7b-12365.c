//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w, h, i, j;
    char **img;

    printf("Enter width and height of image: ");
    scanf("%d %d", &w, &h);

    img = (char **)malloc(h * sizeof(char *) + h);
    for (i = 0; i < h; i++)
    {
        img[i] = (char *)malloc(w * sizeof(char) + w);
    }

    printf("Enter image data (each pixel as a number, separated by spaces): ");
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            scanf("%d ", &img[i][j]);
        }
    }

    printf("Image in ASCII art:\n");
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
                    printf(". ");
                    break;
                case 2:
                    printf("* ");
                    break;
                case 3:
                    printf("o ");
                    break;
                case 4:
                    printf("# ");
                    break;
            }
        }
        printf("\n");
    }

    free(img);

    return 0;
}