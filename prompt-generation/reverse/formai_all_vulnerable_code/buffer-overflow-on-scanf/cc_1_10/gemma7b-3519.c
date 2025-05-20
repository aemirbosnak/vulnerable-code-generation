//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char image[1024];
    printf("Enter the image file name: ");
    scanf("%s", image);

    FILE *fp = fopen(image, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the image file
    fread(image, 1024, 1, fp);

    // Convert the image to ASCII art
    for (int i = 0; image[i] != '\0'; i++)
    {
        switch (image[i])
        {
            case 0:
                printf(". ");
                break;
            case 1:
                printf("o ");
                break;
            case 2:
                printf("O ");
                break;
            case 3:
                printf("* ");
                break;
            case 4:
                printf("# ");
                break;
            default:
                printf(" ");
                break;
        }
    }

    // Close the file
    fclose(fp);

    return 0;
}