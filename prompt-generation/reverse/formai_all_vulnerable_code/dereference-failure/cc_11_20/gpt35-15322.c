//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complete
#include <stdio.h>

int main()
{
    // Open the input file
    FILE *input = fopen("input.bmp", "rb");
    if (input == NULL)
    {
        printf("Error opening input file\n");
        return 1;
    }
    
    // Read the BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input);
    
    // Get the image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    
    // Calculate the row padding
    int padding = 0;
    while ((width * 3 + padding) % 4 != 0)
    {
        padding++;
    }
    
    // Allocate memory for the image
    unsigned char* image = (unsigned char*) malloc(width * height * 3);
    
    // Read the image data
    fread(image, sizeof(unsigned char), width * height * 3, input);

    // Close the input file
    fclose(input);

    // Flip the image horizontally
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                unsigned char temp = image[i * (width * 3 + padding) + j * 3 + k];
                image[i * (width * 3 + padding) + j * 3 + k] = image[i * (width * 3 + padding) + (width - 1 - j) * 3 + k];
                image[i * (width * 3 + padding) + (width - 1 - j) * 3 + k] = temp;
            }
        }
    }

    // Change the brightness of the image
    float brightness = 1.5;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                unsigned char pixel = image[i * (width * 3 + padding) + j * 3 + k];
                pixel *= brightness;
                if (pixel > 255) pixel = 255;
                image[i * (width * 3 + padding) + j * 3 + k] = pixel;
            }
        }
    }

    // Change the contrast of the image
    float contrast = 1.2;
    float pivot = 128.0;
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259 - contrast));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                unsigned char pixel = image[i * (width * 3 + padding) + j * 3 + k];
                pixel = factor * (pixel - pivot) + pivot;
                if (pixel < 0) pixel = 0;
                if (pixel > 255) pixel = 255;
                image[i * (width * 3 + padding) + j * 3 + k] = pixel;
            }
        }
    }

    // Open the output file
    FILE *output = fopen("output.bmp", "wb");
    if (output == NULL)
    {
        printf("Error opening output file\n");
        return 1;
    }
    
    // Write the BMP header
    fwrite(header, sizeof(unsigned char), 54, output);
    
    // Write the image data
    fwrite(image, sizeof(unsigned char), width * height * 3, output);

    // Close the output file
    fclose(output);

    // Free the memory
    free(image);

    return 0;
}