//FormAI DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} pixel;

int main(int argc, char** argv) {
    if(argc != 3) {
        printf("USAGE: image_editor [input_image_file] [output_image_file]\n");
        return 1;
    }

    FILE *in_fp, *out_fp;
    in_fp = fopen(argv[1], "rb");
    out_fp = fopen(argv[2], "wb");

    if(in_fp == NULL) {
        printf("ERROR: Could not open input image file.\n");
        return 1;
    }

    if(out_fp == NULL) {
        printf("ERROR: Could not open output image file.\n");
        return 1;
    }

    //Read in the header of the input file
    unsigned char header_info[54];
    fread(header_info, sizeof(unsigned char), 54, in_fp);

    //Read in the dimensions of the image
    int width = *(int*)&header_info[18];
    int height = *(int*)&header_info[22];

    int padding = 0;
    while((width * 3 + padding) % 4 != 0) {
        padding++;
    }

    int total_size = width * height * 3 + padding * height;
    unsigned char *img_data = (unsigned char*)malloc(sizeof(unsigned char) * total_size);

    fread(img_data, sizeof(unsigned char), total_size, in_fp);

    //Create a new pixel array using the input image dimensions
    pixel **pixels;
    pixels = (pixel**)malloc(sizeof(pixel*) * height);
    for(int i = 0; i < height; i++) {
        pixels[i] = (pixel*)malloc(sizeof(pixel) * width);
    }

    //Fill in the pixel array with the values from the input image
    int index = 0;
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            pixels[row][col].blue = img_data[index];
            pixels[row][col].green = img_data[index + 1];
            pixels[row][col].red = img_data[index + 2];
            index += 3;
        }
        index += padding;
    }

    //Image editing code goes here
    //Example: convert image to grayscale
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            unsigned char gray_value = (unsigned char)((pixels[row][col].blue + pixels[row][col].green + pixels[row][col].red) / 3);
            pixels[row][col].blue = gray_value;
            pixels[row][col].green = gray_value;
            pixels[row][col].red = gray_value;
        }
    }

    //Write the modified pixel data to the output file
    fwrite(header_info, sizeof(unsigned char), 54, out_fp);
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            fwrite(&pixels[row][col], sizeof(pixel), 1, out_fp);
        }
        for(int i = 0; i < padding; i++) {
            fputc(0x00, out_fp);
        }
    }

    fclose(in_fp);
    fclose(out_fp);

    //Free up dynamically allocated memory
    for(int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);
    free(img_data);

    return 0;
}