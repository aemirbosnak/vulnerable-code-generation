//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char image[1024];
    int width, height;

    printf("Enter the image file name: ");
    scanf("%s", image);

    FILE *file = fopen(image, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(file, "%d %d", &width, &height);

    printf("Image dimensions: %dx%d\n", width, height);

    fgets(image, 1024, file);

    fclose(file);

    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            char pixel = image[i * width + j];

            switch (pixel)
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
                    printf("# ");
                    break;
            }
        }

        printf("\n");
    }

    return 0;
}