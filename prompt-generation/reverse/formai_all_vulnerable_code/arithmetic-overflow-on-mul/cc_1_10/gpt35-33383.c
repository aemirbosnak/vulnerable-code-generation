//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *file_name = "image.bmp"; // Change to your image file name
    FILE *image_file;
    unsigned char header[54];
    unsigned char *image_data = NULL;
    int width, height, bit_depth, image_size; 
    
    image_file = fopen(file_name, "rb");
    if (!image_file)
    {
        printf("Failed to open file %s\n", file_name);
        return 1;
    }

    fread(header, sizeof(unsigned char), 54, image_file);
    width = *(int*)&header[18];
    height = *(int*)&header[22];
    bit_depth = *(int*)&header[28];

    if (bit_depth <= 8)
    {
        printf("Not a valid image format\n");
        return 1;
    }

    image_size = width * height * bit_depth / 8;
    image_data = (unsigned char*)malloc(image_size);
    fread(image_data, sizeof(unsigned char), image_size, image_file);
    fclose(image_file);

    // Change brightness
    int brightness = 20;
    for (int i = 0; i < image_size; i++)
    {
        image_data[i] = image_data[i] + brightness > 255 ? 255 : image_data[i] + brightness;
    }

    // Change contrast
    float contrast = 1.2;
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int i = 0; i < image_size; i++)
    {
        image_data[i] = (unsigned char)(factor * (image_data[i] - 128) + 128);
    }

    // Flip image horizontally
    unsigned char tmp;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width / 2; col++)
        {
            tmp = image_data[row * width + col];
            image_data[row * width + col] = image_data[row * width + (width - col - 1)];
            image_data[row * width + (width - col - 1)] = tmp;
        }
    }

    // Write new image
    char *new_file_name = "modified_image.bmp";
    image_file = fopen(new_file_name, "wb");
    if (!image_file)
    {
        printf("Failed to create file %s\n", new_file_name);
        return 1;
    }

    fwrite(header, sizeof(unsigned char), 54, image_file);
    fwrite(image_data, sizeof(unsigned char), image_size, image_file);
    fclose(image_file);

    free(image_data);
    printf("Processing completed successfully! Modified image saved as %s\n", new_file_name);
    return 0;
}