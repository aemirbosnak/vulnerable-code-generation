//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: standalone
/*
 * Image Steganography
 *
 * This program implements a basic image steganography algorithm using
 * the Least Significant Bit (LSB) method.
 *
 * Usage:
 *      ./steganography <input_image> <message>
 *
 * The input image must be a 24-bit BMP file, and the message must be
 * a string of characters.
 *
 * The output image will be created in the same directory as the input
 * image, and its name will be the same as the input image with a
 * ".out" extension.
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structures
typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    unsigned int width, height;
    Pixel **pixels;
} Image;

// Function prototypes
void read_image(const char *filename, Image *img);
void write_image(const char *filename, Image *img);
void encode_message(Image *img, const char *message);
void decode_message(Image *img, char *message);

// Function definitions
void read_image(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: unable to open input file.\n");
        exit(1);
    }

    fread(&img->width, sizeof(unsigned int), 1, fp);
    fread(&img->height, sizeof(unsigned int), 1, fp);

    img->pixels = (Pixel **)malloc(img->width * sizeof(Pixel *));
    for (int i = 0; i < img->width; i++) {
        img->pixels[i] = (Pixel *)malloc(img->height * sizeof(Pixel));
        for (int j = 0; j < img->height; j++) {
            fread(&img->pixels[i][j].r, sizeof(unsigned char), 1, fp);
            fread(&img->pixels[i][j].g, sizeof(unsigned char), 1, fp);
            fread(&img->pixels[i][j].b, sizeof(unsigned char), 1, fp);
        }
    }

    fclose(fp);
}

void write_image(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: unable to open output file.\n");
        exit(1);
    }

    fwrite(&img->width, sizeof(unsigned int), 1, fp);
    fwrite(&img->height, sizeof(unsigned int), 1, fp);

    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            fwrite(&img->pixels[i][j].r, sizeof(unsigned char), 1, fp);
            fwrite(&img->pixels[i][j].g, sizeof(unsigned char), 1, fp);
            fwrite(&img->pixels[i][j].b, sizeof(unsigned char), 1, fp);
        }
    }

    fclose(fp);
}

void encode_message(Image *img, const char *message) {
    int msg_len = strlen(message);
    int pixel_count = img->width * img->height;
    int pixel_index = 0;

    for (int i = 0; i < msg_len; i++) {
        int shift_amount = 7 - (i % 8);
        Pixel *pixel = &img->pixels[pixel_index / img->width][pixel_index % img->height];

        if (message[i] == '1') {
            pixel->r = pixel->r | (1 << shift_amount);
        } else {
            pixel->r = pixel->r & ~(1 << shift_amount);
        }

        pixel_index++;
        if (pixel_index == pixel_count) {
            break;
        }
    }
}

void decode_message(Image *img, char *message) {
    int msg_len = 0;
    int pixel_count = img->width * img->height;
    int pixel_index = 0;

    while (pixel_index < pixel_count) {
        Pixel *pixel = &img->pixels[pixel_index / img->width][pixel_index % img->height];
        int shift_amount = 7 - (msg_len % 8);
        char bit = (pixel->r >> shift_amount) & 1;

        message[msg_len] = bit + '0';
        msg_len++;

        pixel_index++;
    }

    message[msg_len] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <message>\n", argv[0]);
        exit(1);
    }

    Image img;
    read_image(argv[1], &img);
    encode_message(&img, argv[2]);
    write_image("output.bmp", &img);

    return 0;
}