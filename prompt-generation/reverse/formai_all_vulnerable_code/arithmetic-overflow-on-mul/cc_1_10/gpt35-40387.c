//FormAI DATASET v1.0 Category: Image Editor ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel; // define pixel structure containing RGB values

// function to load a BMP file and return a Pixel array
Pixel* load_bmp(const char* filename, int* width, int* height) { 
    FILE* file = fopen(filename, "rb"); // open file in read binary mode
    if(!file) {
        printf("Unable to open file.\n");
        return NULL;
    }

    unsigned char bmp_header[54]; // BMP header is 54 bytes long
    fread(bmp_header, sizeof(unsigned char), 54, file); // read BMP header
    
    int image_offset = *(int*)&bmp_header[10]; // offset where pixel data starts
    *width = *(int*)&bmp_header[18]; // width of image
    *height = *(int*)&bmp_header[22]; // height of image
    int bits_per_pixel = *(short*)&bmp_header[28]; // bits per pixel
    
    if(bits_per_pixel != 24) { // we only support 24-bit BMP files
        printf("Unsupported file format.\n");
        return NULL;
    }

    Pixel* pixels = (Pixel*)malloc((*width) * (*height) * sizeof(Pixel)); // allocate memory for Pixel array

    fseek(file, image_offset, SEEK_SET); // move file pointer to where pixel data starts

    int row_padding = (*width) % 4; // padding to ensure each row has a multiple of 4 bytes
    for(int row = 0; row < *height; row++) {
        for(int column = 0; column < *width; column++) {
            pixels[row * (*width) + column].b = fgetc(file);
            pixels[row * (*width) + column].g = fgetc(file);
            pixels[row * (*width) + column].r = fgetc(file);
        }
        if(row_padding) { // skip padding bytes if necessary
            fseek(file, 4 - row_padding, SEEK_CUR);
        }
    }

    fclose(file); // close file
    return pixels; // return Pixel array
}

// function to save a Pixel array as a BMP file
void save_bmp(const char* filename, Pixel* pixels, int width, int height) {
    FILE* file = fopen(filename, "wb"); // open file in write binary mode
    if(!file) {
        printf("Unable to open file.\n");
        return;
    }

    int image_size = width * height * sizeof(Pixel); // size of pixel data
    int row_padding = width % 4; // padding to ensure each row has a multiple of 4 bytes

    unsigned char bmp_header[54] = {
        0x42, 0x4D, // BM signature
        0x36, 0x00, 0x0C, 0x00, // size of file = 54 + image_size
        0x00, 0x00, // reserved
        0x00, 0x00, // reserved
        0x36, 0x00, 0x00, 0x00, // offset where pixel data starts
        0x28, 0x00, 0x00, 0x00, // size of InfoHeader
        (unsigned char)(width & 0xFF), (unsigned char)((width >> 8) & 0xFF), (unsigned char)((width >> 16) & 0xFF), (unsigned char)((width >> 24) & 0xFF), // width of image
        (unsigned char)(height & 0xFF), (unsigned char)((height >> 8) & 0xFF), (unsigned char)((height >> 16) & 0xFF), (unsigned char)((height >> 24) & 0xFF), // height of image
        0x01, 0x00, // number of color planes
        0x18, 0x00, // bits per pixel
        0x00, 0x00, 0x00, 0x00, // compression method (none)
        (unsigned char)(image_size & 0xFF), (unsigned char)((image_size >> 8) & 0xFF), (unsigned char)((image_size >> 16) & 0xFF), (unsigned char)((image_size >> 24) & 0xFF), // size of pixel data
        0x13, 0x0B, 0x00, 0x00, // horizontal resolution (2835 pixels/m)
        0x13, 0x0B, 0x00, 0x00, // vertical resolution (2835 pixels/m)
        0x00, 0x00, 0x00, 0x00, // colors used (all)
        0x00, 0x00, 0x00, 0x00 // important colors (all)
    };

    fwrite(bmp_header, sizeof(unsigned char), 54, file); // write BMP header

    for(int row = 0; row < height; row++) {
        for(int column = 0; column < width; column++) {
            fputc(pixels[row * width + column].b, file);
            fputc(pixels[row * width + column].g, file);
            fputc(pixels[row * width + column].r, file);
        }
        if(row_padding) { // add padding bytes if necessary
            for(int i = 0; i < 4 - row_padding; i++) {
                fputc(0, file);
            }
        }
    }

    fclose(file); // close file
}

int main() {
    int width, height;
    Pixel* pixels = load_bmp("image.bmp", &width, &height); // load BMP file into Pixel array
    if(!pixels) {
        printf("Unable to load BMP file.\n");
        return 1;
    }

    // image editing code goes here

    save_bmp("edited_image.bmp", pixels, width, height); // save Pixel array as BMP file
    free(pixels); // deallocate memory used by Pixel array
    return 0;
}