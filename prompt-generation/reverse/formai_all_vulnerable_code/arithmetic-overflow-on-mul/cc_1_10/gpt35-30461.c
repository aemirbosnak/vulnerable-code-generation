//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define ASCII_SCALE_FACTOR 10

void convert_to_ascii(char *input_path, char *output_path);

int main(void)
{
    convert_to_ascii("input_image.bmp", "output_ascii.txt");
    return 0;
}

void convert_to_ascii(char *input_path, char *output_path)
{
    // Open input file
    FILE *input_file = fopen(input_path, "rb");
    if (!input_file)
    {
        printf("Error: Could not open input file %s\n", input_path);
        return;
    }

    // Read header data
    unsigned short magic_number;
    fread(&magic_number, sizeof(magic_number), 1, input_file);

    unsigned int file_size;
    fread(&file_size, sizeof(file_size), 1, input_file);

    fseek(input_file, 4, SEEK_CUR);

    unsigned int data_offset;
    fread(&data_offset, sizeof(data_offset), 1, input_file);

    unsigned int header_size;
    fread(&header_size, sizeof(header_size), 1, input_file);

    int width, height;
    fseek(input_file, 4, SEEK_CUR);
    fread(&width, sizeof(width), 1, input_file);
    fseek(input_file, 4, SEEK_CUR);
    fread(&height, sizeof(height), 1, input_file);

    fseek(input_file, data_offset, SEEK_SET);

    // Open output file
    FILE *output_file = fopen(output_path, "w");
    if (!output_file)
    {
        printf("Error: Could not open output file %s\n", output_path);
        fclose(input_file);
        return;
    }

    // Read pixel data
    unsigned int padding = 0;
    if ((width * 3) % 4 != 0)
    {
        padding = 4 - ((width * 3) % 4);
    }

    unsigned char image[MAX_HEIGHT][MAX_WIDTH][3];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fread(image[i][j], sizeof(char), 3, input_file);
        }
        fseek(input_file, padding, SEEK_CUR);
    }

    // Write ASCII art to output file
    int ascii_width = width * ASCII_SCALE_FACTOR;
    int ascii_height = height * ASCII_SCALE_FACTOR;

    char ascii_image[MAX_HEIGHT * ASCII_SCALE_FACTOR][MAX_WIDTH * ASCII_SCALE_FACTOR];
    memset(ascii_image, ' ', sizeof(char) * MAX_HEIGHT * ASCII_SCALE_FACTOR * MAX_WIDTH * ASCII_SCALE_FACTOR);

    char ascii_char[] = "@#&%*+=-:. "; // Charaters used for ASCII art, from dark to light

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int pixel_value = (image[i][j][0] + image[i][j][1] + image[i][j][2]) / 3;
            int ascii_index = ((float)pixel_value / 255) * (strlen(ascii_char) - 1);
            for (int k = 0; k < ASCII_SCALE_FACTOR; k++)
            {
                for (int l = 0; l < ASCII_SCALE_FACTOR; l++)
                {
                    ascii_image[i * ASCII_SCALE_FACTOR + k][j * ASCII_SCALE_FACTOR + l] = ascii_char[ascii_index];
                }
            }
        }
    }

    for (int i = 0; i < ascii_height; i++)
    {
        for (int j = 0; j < ascii_width; j++)
        {
            fprintf(output_file, "%c", ascii_image[i][j]);
        }
        fprintf(output_file, "\n");
    }

    // Close files
    fclose(input_file);
    fclose(output_file);
}