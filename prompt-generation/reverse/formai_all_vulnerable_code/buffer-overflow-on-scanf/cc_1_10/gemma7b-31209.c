//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("clear");
    printf("Enter the image file path: ");
    char image_path[256];
    scanf("%s", image_path);

    FILE *fp = fopen(image_path, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char image_data[10000];
    fread(image_data, 1, 10000, fp);
    fclose(fp);

    int image_width = 256;
    int image_height = 256;
    int pixel_size = 4;
    int num_pixels = image_width * image_height * pixel_size;

    char ascii_data[num_pixels];
    for (int i = 0; i < num_pixels; i++)
    {
        ascii_data[i] = image_data[i] / 2;
    }

    printf("Enter the output file path: ");
    char output_path[256];
    scanf("%s", output_path);

    fp = fopen(output_path, "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < num_pixels; i++)
    {
        fprintf(fp, "%c ", ascii_data[i]);
    }

    fclose(fp);

    return 0;
}