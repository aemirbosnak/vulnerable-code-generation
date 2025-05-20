//FormAI DATASET v1.0 Category: Image compression ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
    char file_name[MAX_SIZE], out_file_name[MAX_SIZE];

    printf("Enter image filename: ");
    scanf("%s", file_name);

    FILE *in_file = fopen(file_name, "rb");

    if (!in_file)
    {
        printf("Error: could not open %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    printf("Enter output filename: ");
    scanf("%s", out_file_name);

    FILE *out_file = fopen(out_file_name, "wb");

    if (!out_file)
    {
        printf("Error: could not open %s\n", out_file_name);
        exit(EXIT_FAILURE);
    }

    unsigned char header[54];
    int read = fread(header, sizeof(unsigned char), 54, in_file);

    if (read != 54)
    {
        printf("Error: Invalid BMP file.\n");
        exit(EXIT_FAILURE);
    }

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bpp = *(int*)&header[28];

    printf("Width: %d\n", width);
    printf("Height: %d\n", height);
    printf("Bits per pixel: %d\n", bpp);

    int row_size = (width * bpp + 31) / 32 * 4;

    unsigned char *image_data = (unsigned char*) malloc(row_size * height);
    unsigned char *new_image_data = (unsigned char*) malloc(row_size * height);

    fread(image_data, sizeof(unsigned char), row_size * height, in_file);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < row_size; j++)
        {
            new_image_data[i * row_size + j] = image_data[i * row_size + j] / 4;
        }
    }

    fwrite(header, sizeof(unsigned char), 54, out_file);
    fwrite(new_image_data, sizeof(unsigned char), row_size * height, out_file);

    fclose(in_file);
    fclose(out_file);

    return 0;
}