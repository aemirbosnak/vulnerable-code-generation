//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024 // Maximum size of the image
#define WATERMARK_SIZE 64 // Size of the watermark
#define WATERMARK_VALUE 128 // Value of the watermark

// Function to read the image from a file
void read_image(char* filename, int* image, int size) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error reading file\n");
        exit(1);
    }
    fread(image, sizeof(int), size, fp);
    fclose(fp);
}

// Function to write the watermarked image to a file
void write_watermarked_image(char* filename, int* watermarked_image, int size) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error writing file\n");
        exit(1);
    }
    fwrite(watermarked_image, sizeof(int), size, fp);
    fclose(fp);
}

// Function to add the watermark to the image
void add_watermark(int* image, int* watermarked_image, int size) {
    for (int i = 0; i < size; i++) {
        if (i % WATERMARK_SIZE == 0 && i < size - WATERMARK_SIZE) {
            int watermark_value = (int)round((double)WATERMARK_VALUE * (double)image[i] / 255.0);
            for (int j = 0; j < WATERMARK_SIZE; j++) {
                watermarked_image[i + j] += watermark_value;
            }
        } else {
            watermarked_image[i] = image[i];
        }
    }
}

int main() {
    int image[MAX_SIZE];
    int watermarked_image[MAX_SIZE];

    // Read the image from a file
    read_image("image.bmp", image, MAX_SIZE);

    // Add the watermark to the image
    add_watermark(image, watermarked_image, MAX_SIZE);

    // Write the watermarked image to a file
    write_watermarked_image("watermarked_image.bmp", watermarked_image, MAX_SIZE);

    return 0;
}