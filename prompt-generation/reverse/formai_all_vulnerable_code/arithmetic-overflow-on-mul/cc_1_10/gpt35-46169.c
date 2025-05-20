//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54
#define PIXEL_OFFSET 10

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef int Long;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s [input_filename] [output_filename] [brightness/contrast]\n", argv[0]);
        exit(1);
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    int brightness_contrast = atoi(argv[3]);

    // Open input file
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL)
    {
        printf("Failed to open input file: %s", input_filename);
        exit(1);
    }

    // Open output file
    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL)
    {
        printf("Failed to open output file: %s", output_filename);
        exit(1);
    }

    // Read the BMP header
    BYTE bmp_header[BMP_HEADER_SIZE];
    fread(bmp_header, sizeof(BYTE), BMP_HEADER_SIZE, input_file);
    fwrite(bmp_header, sizeof(BYTE), BMP_HEADER_SIZE, output_file);

    // Determine image dimensions
    Long width = *(Long *)&bmp_header[18];
    Long height = *(Long *)&bmp_header[22];

    // Check if the image is 24-bit BMP
    WORD bpp = *(WORD *)&bmp_header[28];
    if (bpp != 24)
    {
        printf("Input file must be a 24-bit BMP");
        exit(1);
    }

    // Calculate row padding
    int row_padding = (4 - ((width * 3) % 4)) % 4;

    // Allocate memory for image pixel data
    BYTE *pixel_data = (BYTE *)malloc(width * height * 3);
    fread(pixel_data, sizeof(BYTE), width * height * 3, input_file);

    // Flip the image
    int row_size = width * 3 + row_padding;
    BYTE *temp_row = (BYTE *)malloc(row_size);
    for (int i = 0, j = height - 1; i < j; i++, j--)
    {
        int offset1 = i * row_size + PIXEL_OFFSET;
        int offset2 = j * row_size + PIXEL_OFFSET;
        for (int k = 0; k < row_size; k++)
        {
            temp_row[k] = pixel_data[offset1 + k];
            pixel_data[offset1 + k] = pixel_data[offset2 + k];
            pixel_data[offset2 + k] = temp_row[k];
        }
    }
    free(temp_row);

    // Adjust the brightness and contrast of the image
    for (int i = 0; i < width * height * 3; i++)
    {
        int value = (int)pixel_data[i] + brightness_contrast;
        if (value < 0)
        {
            value = 0;
        }
        else if (value > 255)
        {
            value = 255;
        }
        pixel_data[i] = (BYTE)value;
    }

    // Write the flipped and adjusted image to output file
    fwrite(pixel_data, sizeof(BYTE), width * height * 3, output_file);

    // Clean up resources
    fclose(input_file);
    fclose(output_file);
    free(pixel_data);

    printf("Image processing complete: %s -> %s\n", input_filename, output_filename);

    return 0;
}