//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char img[1000];
    int i, j, r, h;
    printf("Enter the image data (separated by spaces): ");
    scanf("%s", img);

    printf("Enter the height of the image: ");
    scanf("%d", &h);

    printf("Enter the width of the image: ");
    scanf("%d", &r);

    int img_data[h][r];
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < r; j++)
        {
            img_data[i][j] = img[i * r + j] - 48;
        }
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < r; j++)
        {
            switch (img_data[i][j])
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
                default:
                    printf("Error!");
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}