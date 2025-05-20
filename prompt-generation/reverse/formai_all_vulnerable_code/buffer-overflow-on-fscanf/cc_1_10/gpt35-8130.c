//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768
#define MAX_PIXEL_VALUE 255
#define ASCII_RANGE 95

char ASCII_CHARS[ASCII_RANGE] = {' ', '.', '\'', ':', '_', '*', '=', '@', '(', '%', '/', 'C', '?', '+', '1', '7', 'i', '>', '<', 'h', 'a', 'k', 'b', 'r', 'd', 'X', 'O', '0', 'K', 'N', 'M'};

char pixel_to_ascii(int pixel_value, int ascii_range)
{
    int range = (MAX_PIXEL_VALUE+1) / ascii_range;
    for (int i = 0; i < ascii_range; i++)
    {
        if (pixel_value <= ((i+1)*range))
            return ASCII_CHARS[i];
    }
    return ' ';
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL)
    {
        printf("Error: Unable to open '%s' for reading\n", argv[1]);
        return 1;
    }

    // parse header
    char magic_number[3];
    int width, height, pixel_value;
    fscanf(input_file, "%s", magic_number);
    if (strcmp(magic_number, "P5") != 0)
    {
        printf("Error: Unsupported file format '%s'\n", magic_number);
        fclose(input_file);
        return 1;
    }
    fscanf(input_file, "%d %d %d", &width, &height, &pixel_value);
    if (width > MAX_WIDTH || height > MAX_HEIGHT || pixel_value > MAX_PIXEL_VALUE)
    {
        printf("Error: Invalid image size\n");
        fclose(input_file);
        return 1;
    }

    // read data
    unsigned char pixels[MAX_HEIGHT][MAX_WIDTH];
    fread(pixels, sizeof(unsigned char), width*height, input_file);
    fclose(input_file);

    // generate ascii art
    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL)
    {
        printf("Error: Unable to open '%s' for writing\n", argv[2]);
        return 1;
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            fprintf(output_file, "%c", pixel_to_ascii(pixels[y][x], ASCII_RANGE));
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);

    printf("ASCII art conversion complete!\n");

    return 0;
}