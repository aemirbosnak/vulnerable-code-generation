//FormAI DATASET v1.0 Category: Image compression ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the cheerful C image compression program!\n");
    printf("Let's compress an image!\n");

    //read the image file and fetch pixel data
    FILE *input_image = fopen("input_image.ppm", "rb");
    if (!input_image)
    {
        printf("Error! Could not open input image file.\n");
        return 1;
    }

    //read the first three bytes of the input file to check the file type is P6 or not
    char magic_number[3];
    magic_number[2] = '\0';
    if(fread(magic_number, sizeof(char), 2, input_image) != 2 || magic_number[0] != 'P' || magic_number[1] != '6')
    {
        printf("Error! The input image file is not of type P6.\n");
        return 1;
    }

    //fetch image dimensions
    int width, height, max_value;
    fscanf(input_image, "%d %d %d", &width, &height, &max_value);
    fgetc(input_image);

    //allocate memory to load the image data
    unsigned char *buffer = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 3);
    if(!buffer)
    {
        printf("Error! Could not allocate memory to load image data.\n");
        return 1;
    }

    //read the pixel data
    if(fread(buffer, sizeof(unsigned char), width * height * 3, input_image) != width * height * 3)
    {
        printf("Error! Could not read the entire image data.\n");
        return 1;
    }

    //create a new buffer for compressed data
    int compressed_length = (int)(width * height * 3 * 0.5);
    unsigned char *compressed_buffer = (unsigned char*)malloc(sizeof(unsigned char) * compressed_length);
    if(!compressed_buffer)
    {
        printf("Error! Could not allocate memory for compressed data.\n");
        return 1;
    }

    //compress the image data
    int current_pixel_index = 0, current_compressed_index = 0;
    while(current_pixel_index < width * height * 3)
    {
        //calculate the average of the RGB components of the current pixel
        int average = (buffer[current_pixel_index] + buffer[current_pixel_index + 1] + buffer[current_pixel_index + 2]) / 3;

        //store the average RGB value in the compressed buffer
        compressed_buffer[current_compressed_index] = (unsigned char)average;

        //increment the current indexes
        current_pixel_index += 3;
        current_compressed_index += 1;
    }

    //write the compressed data to a new file
    FILE *output_image = fopen("output_image.ppm", "wb");
    if(!output_image)
    {
        printf("Error! Could not create output image file.\n");
        return 1;
    }

    //write the P5 magic number and the image dimensions to the output file
    fprintf(output_image, "P5\n%d %d\n%d\n", width, height, max_value);

    //write the compressed data to the output file
    if(fwrite(compressed_buffer, sizeof(unsigned char), current_compressed_index, output_image) != current_compressed_index)
    {
        printf("Error! Could not write compressed data to output file.\n");
        return 1;
    }

    //cleanup
    fclose(input_image);
    fclose(output_image);
    free(buffer);
    free(compressed_buffer);

    printf("Image compression complete! Thanks for using this program!");

    return 0;
}