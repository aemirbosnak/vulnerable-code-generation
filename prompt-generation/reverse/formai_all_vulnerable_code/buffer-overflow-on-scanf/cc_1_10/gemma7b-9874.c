//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int img_width, img_height;
    printf("Enter image width: ");
    scanf("%d", &img_width);

    printf("Enter image height: ");
    scanf("%d", &img_height);

    int **img_data = malloc(img_height * sizeof(int *));
    for (int h = 0; h < img_height; h++)
    {
        img_data[h] = malloc(img_width * sizeof(int));
    }

    printf("Enter image data (separated by commas): ");
    char input[1024];
    fgets(input, 1024, stdin);

    char *token = strtok(input, ",");
    int i = 0;
    while (token)
    {
        img_data[i / img_width][i % img_width] = atoi(token);
        token = strtok(NULL, ",");
        i++;
    }

    int pixel_max = 0;
    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            pixel_max = fmax(pixel_max, img_data[h][w]);
        }
    }

    int ascii_max = pixel_max * 2 + 1;
    char **ascii_art = malloc(ascii_max * sizeof(char *));
    for (int h = 0; h < ascii_max; h++)
    {
        ascii_art[h] = malloc(ascii_max * sizeof(char));
    }

    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            ascii_art[h][w] = (char)('a' + img_data[h][w] * 2);
        }
    }

    printf("ASCII Art:\n");
    for (int h = 0; h < ascii_max; h++)
    {
        for (int w = 0; w < ascii_max; w++)
        {
            printf("%c ", ascii_art[h][w]);
        }
        printf("\n");
    }

    free(img_data);
    free(ascii_art);

    return 0;
}