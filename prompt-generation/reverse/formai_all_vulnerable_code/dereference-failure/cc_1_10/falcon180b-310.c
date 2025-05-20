//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define WATERMARK_SIZE 64 // size of watermark
#define IMAGE_SIZE 512 // size of image
#define KEY_SIZE 16 // size of key

// function to generate watermark
void generate_watermark(unsigned char *watermark, unsigned char *key) {
    int i, j;
    for (i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = rand() % 256; // generate random watermark
    }
    for (i = 0; i < WATERMARK_SIZE; i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            watermark[i] ^= key[j]; // XOR watermark with key
        }
    }
}

// function to embed watermark in image
void embed_watermark(unsigned char *image, unsigned char *watermark) {
    int i, j;
    for (i = 0; i < IMAGE_SIZE; i++) {
        for (j = 0; j < IMAGE_SIZE; j++) {
            image[i*IMAGE_SIZE + j] ^= watermark[i*WATERMARK_SIZE + j]; // XOR image with watermark
        }
    }
}

// function to extract watermark from image
void extract_watermark(unsigned char *image, unsigned char *watermark, unsigned char *key) {
    int i, j;
    for (i = 0; i < IMAGE_SIZE; i++) {
        for (j = 0; j < IMAGE_SIZE; j++) {
            watermark[i*WATERMARK_SIZE + j] = image[i*IMAGE_SIZE + j] ^ key[i*KEY_SIZE + j]; // XOR image with key to extract watermark
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s image_file watermark_file key_file\n", argv[0]);
        return 1;
    }

    unsigned char *image = (unsigned char *) malloc(IMAGE_SIZE);
    unsigned char *watermark = (unsigned char *) malloc(WATERMARK_SIZE);
    unsigned char *key = (unsigned char *) malloc(KEY_SIZE);

    FILE *image_file = fopen(argv[1], "rb");
    FILE *watermark_file = fopen(argv[2], "rb");
    FILE *key_file = fopen(argv[3], "rb");

    if (image_file == NULL || watermark_file == NULL || key_file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    fread(image, IMAGE_SIZE, 1, image_file);
    fread(watermark, WATERMARK_SIZE, 1, watermark_file);
    fread(key, KEY_SIZE, 1, key_file);

    fclose(image_file);
    fclose(watermark_file);
    fclose(key_file);

    generate_watermark(watermark, key);

    embed_watermark(image, watermark);

    FILE *output_file = fopen("watermarked_image.bmp", "wb");
    fwrite(image, IMAGE_SIZE, 1, output_file);
    fclose(output_file);

    return 0;
}