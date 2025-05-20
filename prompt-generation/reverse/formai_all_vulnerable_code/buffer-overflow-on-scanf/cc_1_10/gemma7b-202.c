//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void image_to_ascii(char **img, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int pixel_value = (int)img[y][x];
            switch (pixel_value)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf(".. ");
                    break;
                case 3:
                    printf("... ");
                    break;
                case 4:
                    printf(".... ");
                    break;
                case 5:
                    printf("..... ");
                    break;
                case 6:
                    printf("...... ");
                    break;
                case 7:
                    printf("------- ");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    char **img = NULL;
    int w, h;

    printf("Enter the width of the image: ");
    scanf("%d", &w);

    printf("Enter the height of the image: ");
    scanf("%d", &h);

    img = (char **)malloc(h * sizeof(char *) + 1);
    for (int i = 0; i < h; i++)
    {
        img[i] = (char *)malloc(w * sizeof(char) + 1);
    }

    printf("Enter the pixels of the image (separated by spaces): ");
    scanf("%s", img[0]);

    image_to_ascii(img, w, h);

    free(img);

    return 0;
}