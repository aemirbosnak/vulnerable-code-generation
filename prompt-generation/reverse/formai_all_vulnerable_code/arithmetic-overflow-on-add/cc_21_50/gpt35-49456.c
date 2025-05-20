//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    FILE *input_file, *output_file;
    unsigned char header[54], *input_image, *output_image;
    int width, height, padding, brightness, contrast, choice;
    unsigned int size;

    // Open input and output files
    input_file = fopen("input.bmp", "rb");
    output_file = fopen("output.bmp", "wb");

    if(input_file == NULL || output_file == NULL)
    {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read header of input file
    fread(header, sizeof(unsigned char), 54, input_file);

    // Extract width and height from header
    width = *(int*)&header[18];
    height = *(int*)&header[22];

    // Calculate size and padding of input file
    size = width * height * 3;
    padding = (4 - (size % 4)) % 4;

    // Allocate memory for input and output images
    input_image = (unsigned char*)malloc(size);
    output_image = (unsigned char*)malloc(size);

    if(input_image == NULL || output_image == NULL)
    {
        printf("Error: could not allocate memory.\n");
        return 1;
    }

    // Read input image
    fread(input_image, sizeof(unsigned char), size, input_file);

    // Ask user for brightness and contrast values
    printf("Please enter brightness value (-255 to 255): ");
    scanf("%d", &brightness);
    printf("Please enter contrast value (-100 to 100): ");
    scanf("%d", &contrast);

    // Apply brightness and contrast to input image
    for(int i = 0; i < size; i += 3)
    {
        for(int j = 0; j < 3; j++)
        {
            int value = (int)input_image[i + j] + brightness;
            value = (int)(((value - 128) * (100 + contrast)) / 100 + 128);
            if(value > 255) value = 255;
            if(value < 0) value = 0;
            output_image[i + j] = (unsigned char)value;
        }
    }

    // Ask user for flipping choice
    printf("Do you want to flip the image? (1 for horizontal, 2 for vertical, 3 for both, 0 for none): ");
    scanf("%d", &choice);

    // Flip the image based on user choice
    switch(choice)
    {
        case 1: // Horizontal flip
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width/2; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {
                        unsigned char temp = output_image[i*(width*3+padding)+j*3+k];
                        output_image[i*(width*3+padding)+j*3+k] = output_image[i*(width*3+padding)+(width-j-1)*3+k];
                        output_image[i*(width*3+padding)+(width-j-1)*3+k] = temp;
                    }
                }
            }
            break;
        case 2: // Vertical flip
            for(int i = 0; i < height/2; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {
                        unsigned char temp = output_image[i*(width*3+padding)+j*3+k];
                        output_image[i*(width*3+padding)+j*3+k] = output_image[(height-i-1)*(width*3+padding)+j*3+k];
                        output_image[(height-i-1)*(width*3+padding)+j*3+k] = temp;
                    }
                }
            }
            break;
        case 3: // Both flips
            for(int i = 0; i < height/2; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {
                        unsigned char temp = output_image[i*(width*3+padding)+j*3+k];
                        output_image[i*(width*3+padding)+j*3+k] = output_image[(height-i-1)*(width*3+padding)+j*3+k];
                        output_image[(height-i-1)*(width*3+padding)+j*3+k] = temp;
                    }
                }
            }
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width/2; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {
                        unsigned char temp = output_image[i*(width*3+padding)+j*3+k];
                        output_image[i*(width*3+padding)+j*3+k] = output_image[i*(width*3+padding)+(width-j-1)*3+k];
                        output_image[i*(width*3+padding)+(width-j-1)*3+k] = temp;
                    }
                }
            }
            break;
        case 0: // No flip
        default:
            break;
    }

    // Write header and output image to output file
    fwrite(header, sizeof(unsigned char), 54, output_file);
    fwrite(output_image, sizeof(unsigned char), size, output_file);

    // Close files and free memory
    fclose(input_file);
    fclose(output_file);
    free(input_image);
    free(output_image);

    printf("Image processing complete.\n");

    return 0;
}