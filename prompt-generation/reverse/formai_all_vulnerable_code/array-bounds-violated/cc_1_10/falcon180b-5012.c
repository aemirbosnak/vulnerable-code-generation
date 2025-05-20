//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

int main()
{
    int i, j, x, y, k;
    int image[HEIGHT][WIDTH];
    int flipped_image[HEIGHT][WIDTH];
    int brightness = 0;
    int contrast = 0;
    int max_value = 255;
    int min_value = 0;
    int pixel_value;
    FILE *input_file, *output_file;

    // Read input image
    input_file = fopen("input.bmp", "rb");
    if (input_file == NULL)
    {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read image data from file
    fread(image, sizeof(int), WIDTH * HEIGHT, input_file);

    // Flip image horizontally
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            x = j;
            y = i;
            k = 0;
            while (k < HEIGHT)
            {
                pixel_value = image[k][x];
                flipped_image[k][y] = pixel_value;
                k++;
                x--;
            }
        }
    }

    // Adjust brightness and contrast
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            pixel_value = flipped_image[i][j];
            pixel_value += brightness;
            pixel_value = (pixel_value * contrast) / max_value;
            pixel_value += max_value - min_value;
            if (pixel_value < min_value)
            {
                pixel_value = min_value;
            }
            else if (pixel_value > max_value)
            {
                pixel_value = max_value;
            }
            flipped_image[i][j] = pixel_value;
        }
    }

    // Write flipped and adjusted image to output file
    output_file = fopen("output.bmp", "wb");
    if (output_file == NULL)
    {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    fwrite(flipped_image, sizeof(int), WIDTH * HEIGHT, output_file);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}