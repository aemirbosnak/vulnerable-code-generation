//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
/*
Welcome to my Digital Watermarking example program! 

The main objective of this program is to embed the message "Hello, World!" into an image file.

We will be using the Least Significant Bit (LSB) method of digital watermarking.

First, we will read in the image file and convert it into a pixel array.

Then, we will convert the message into a bit array.

Next, we will iterate through each pixel in the image array and replace the LSB of each pixel with a bit from the message array.

Once we have embedded the entire message into the image, we will save the image as a new file.

Let's get started!
*/

#include <stdio.h>
#include <stdlib.h>

#define MESSAGE "Hello, World!"

int main()
{
    // Open the input image file
    FILE* infile = fopen("input_image.jpg", "rb");
    if(infile == NULL) {
        printf("Error: could not open input file!");
        exit(1);
    }

    // Open the output image file
    FILE* outfile = fopen("output_image.jpg", "wb");
    if(outfile == NULL) {
        fclose(infile);
        printf("Error: could not open output file!");
        exit(1);
    }

    // Read the image header and pixel data
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, infile);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bpp = *(int*)&header[28];

    int padding = 0;
    if ((width*bpp) % 4 != 0) {
        padding = 4 - ((width*bpp) % 4);
    }

    int size = width * height * bpp / 8;
    unsigned char* data = (unsigned char*) malloc(size * sizeof(unsigned char));
    fread(data, sizeof(unsigned char), size, infile);

    // Embed the message into the image
    int message_length = sizeof(MESSAGE) / sizeof(char) - 1;
    int message_bits[message_length*8];
    int index = 0;
    for(int i = 0; i < message_length; i++) {
        for(int j = 7; j >= 0; j--) {
            message_bits[index] = (MESSAGE[i] >> j) & 1;
            index++;
        }
    }

    index = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            for(int k = 0; k < 3; k++) {
                if(index < message_length*8) {
                    int pixel = i*width*3 + j*3 + k;
                    data[pixel] = (data[pixel] & 0xFE) | message_bits[index];
                    index++;
                }
            }
        }
    }

    // Write the output image to file
    fwrite(header, sizeof(unsigned char), 54, outfile);
    fwrite(data, sizeof(unsigned char), size, outfile);

    // Free memory and close files
    free(data);
    fclose(infile);
    fclose(outfile);

    printf("Digital watermarking completed successfully! Check output_image.jpg for the result.");

    return 0;
}