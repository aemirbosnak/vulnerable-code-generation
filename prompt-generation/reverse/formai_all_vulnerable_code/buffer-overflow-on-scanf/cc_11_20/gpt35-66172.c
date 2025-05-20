//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program will encrypt a message into an image using a digital watermarking algorithm.

int main()
{
    FILE *image_file, *watermarked_file;
    char image_name[40];
    unsigned char image_data[54], pixel_data[3];
    int image_width, image_height, i, j, k;
    char message[] = "Hello, World!"; // message to be hidden
    int message_length = strlen(message);
    int message_index = 0; // variable to keep track of the current index of the message

    printf("Enter the name of the image file (with extension): ");
    scanf("%s", image_name);

    image_file = fopen(image_name, "rb");

    if(image_file == NULL)
    {
        printf("Unable to open image file.\n");
        exit(1);
    }

    // read the header data of the image file
    for(i = 0; i < 54; i++)
    {
        image_data[i] = getc(image_file);
    }

    // extract the pixel data from the image file
    image_width = *(int*)&image_data[18];
    image_height = *(int*)&image_data[22];

    printf("Image Size: %d x %d\n", image_width, image_height);

    // allocate memory for the pixel data
    unsigned char **image_pixels = (unsigned char **)malloc(sizeof(unsigned char *) * image_height);
    for(i = 0; i < image_height; i++)
    {
        image_pixels[i] = (unsigned char *)malloc(sizeof(unsigned char) * image_width * 3);
    }

    for(i = 0; i < image_height; i++)
    {
        for(j = 0; j < image_width; j++)
        {
            // read a pixel from the image file
            for(k = 0; k < 3; k++)
            {
                pixel_data[k] = getc(image_file);
            }

            // store the pixel data in the array
            for(k = 0; k < 3; k++)
            {
                image_pixels[i][j*3+k] = pixel_data[k];
            }
        }
    }

    fclose(image_file);

    // embed the message into the pixel data
    for(i = 0; i < message_length; i++)
    {
        // convert the character to binary and store it in an array
        int binary[8] = {0};
        int char_value = (int)message[i];

        for(j = 7; j >= 0; j--)
        {
            binary[j] = char_value % 2;
            char_value = char_value / 2;
        }

        // embed the binary data into the least significant bit of each pixel
        for(j = 0; j < 8; j++)
        {
            // get the current pixel data
            int pixel_value = (int)image_pixels[i/message_length][(i%message_length)*24+(j*3)];

            // set the least significant bit to the current binary digit
            pixel_value = (pixel_value & 0xFE) | binary[j];

            // store the modified pixel data back into the array
            image_pixels[i/message_length][(i%message_length)*24+(j*3)] = (unsigned char)pixel_value;
        }
    }

    // write the watermarked image to a new file
    char watermarked_image_name[50];
    printf("Enter the name for the watermarked image file (with extension): ");
    scanf("%s", watermarked_image_name);

    watermarked_file = fopen(watermarked_image_name, "wb");

    for(i = 0; i < 54; i++)
    {
        putc(image_data[i], watermarked_file);
    }

    for(i = 0; i < image_height; i++)
    {
        for(j = 0; j < image_width; j++)
        {
            // retrieve the pixel data from the array
            for(k = 0; k < 3; k++)
            {
                pixel_data[k] = image_pixels[i][j*3+k];
            }

            // write the pixel data to the watermarked image file
            for(k = 0; k < 3; k++)
            {
                putc(pixel_data[k], watermarked_file);
            }
        }
    }

    fclose(watermarked_file);

    // free the allocated memory
    for(i = 0; i < image_height; i++)
    {
        free(image_pixels[i]);
    }
    free(image_pixels);

    printf("Message embedded successfully!\n");
    return 0;
}