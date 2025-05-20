//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

int main()
{
    // Open image file for reading
    FILE *image_file = fopen("input_image.ppm", "rb");

    if(image_file == NULL)
    {
        printf("Error: Unable to open image file\n");
        exit(EXIT_FAILURE);
    }

    // Read image header information
    char header[3];
    fscanf(image_file, "%s", header);

    int width, height, max_value;
    fscanf(image_file, "%d %d %d", &width, &height, &max_value);

    // Allocate memory for image data
    unsigned char *image_data = (unsigned char*) malloc(sizeof(unsigned char) * width * height * 3);

    if(image_data == NULL)
    {
        printf("Error: Unable to allocate memory for image data\n");
        fclose(image_file);
        exit(EXIT_FAILURE);
    }

    // Read image data from file
    fread(image_data, sizeof(unsigned char), width * height * 3, image_file);

    // Close image file
    fclose(image_file);

    // Flip image upside down
    for(int i = 0; i < height / 2; i++)
    {
        for(int j = 0; j < width * 3; j++)
        {
            unsigned char temp = image_data[i * width * 3 + j];
            image_data[i * width * 3 + j] = image_data[(height - 1 - i) * width * 3 + j];
            image_data[(height - 1 - i) * width * 3 + j] = temp;
        }
    }

    // Increase brightness and contrast
    int brightness = 50;
    float contrast = 1.5;

    for(int i = 0; i < height * width * 3; i++)
    {
        int value = (int) image_data[i] + brightness;
        value = (int) ((value - 128) * contrast + 128);

        if(value < 0)
            value = 0;

        if(value > MAX_PIXEL_VALUE)
            value = MAX_PIXEL_VALUE;

        image_data[i] = (unsigned char) value;
    }

    // Open output image file for writing
    FILE *output_file = fopen("output_image.ppm", "wb");

    if(output_file == NULL)
    {
        printf("Error: Unable to create output image file\n");
        free(image_data);
        exit(EXIT_FAILURE);
    }

    // Write header
    fprintf(output_file, "%s\n%d %d\n%d\n", header, width, height, max_value);

    // Write image data
    fwrite(image_data, sizeof(unsigned char), width * height * 3, output_file);

    // Free memory
    free(image_data);

    // Close output file
    fclose(output_file);

    return 0;
}