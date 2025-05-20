//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_IMG_SIZE 1024

// Function to read an image from a file
unsigned char* read_image(char* filename, int* width, int* height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the header
    unsigned char header[14];
    fread(header, sizeof(unsigned char), 14, fp);

    // Check if the file is a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: File is not a BMP file\n");
        fclose(fp);
        return NULL;
    }

    // Read the width and height of the image
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    // Read the image data
    unsigned char* data = malloc(*width * *height * 3);
    fread(data, sizeof(unsigned char), *width * *height * 3, fp);

    fclose(fp);

    return data;
}

// Function to write an image to a file
void write_image(char* filename, unsigned char* data, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the header
    unsigned char header[14];
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = sizeof(header) + width * height * 3;
    *(int*)&header[10] = sizeof(header);
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;

    fwrite(header, sizeof(unsigned char), 14, fp);

    // Write the image data
    fwrite(data, sizeof(unsigned char), width * height * 3, fp);

    fclose(fp);
}

// Function to embed a watermark in an image
unsigned char* embed_watermark(unsigned char* data, int width, int height, unsigned char* watermark, int watermark_width, int watermark_height) {
    // Convert the watermark to a binary array
    unsigned char* watermark_bits = malloc(watermark_width * watermark_height);
    for (int i = 0; i < watermark_width * watermark_height; i++) {
        watermark_bits[i] = watermark[i] > 128 ? 1 : 0;
    }

    // Embed the watermark in the image
    for (int i = 0; i < watermark_width * watermark_height; i++) {
        int x = i % watermark_width;
        int y = i / watermark_width;
        data[width * (y + height / 2) + x + width / 2] = (data[width * (y + height / 2) + x + width / 2] & 0xFE) | watermark_bits[i];
    }

    return data;
}

// Function to extract a watermark from an image
unsigned char* extract_watermark(unsigned char* data, int width, int height, int watermark_width, int watermark_height) {
    // Extract the watermark bits from the image
    unsigned char* watermark_bits = malloc(watermark_width * watermark_height);
    for (int i = 0; i < watermark_width * watermark_height; i++) {
        int x = i % watermark_width;
        int y = i / watermark_width;
        watermark_bits[i] = (data[width * (y + height / 2) + x + width / 2] & 1) << 7;
    }

    // Convert the watermark bits to a binary image
    unsigned char* watermark = malloc(watermark_width * watermark_height);
    for (int i = 0; i < watermark_width * watermark_height; i++) {
        watermark[i] = watermark_bits[i] ? 255 : 0;
    }

    return watermark;
}

int main() {
    // Read the original image
    int width, height;
    unsigned char* data = read_image("original.bmp", &width, &height);
    if (data == NULL) {
        return 1;
    }

    // Read the watermark
    int watermark_width, watermark_height;
    unsigned char* watermark = read_image("watermark.bmp", &watermark_width, &watermark_height);
    if (watermark == NULL) {
        return 1;
    }

    // Embed the watermark in the image
    unsigned char* watermarked_data = embed_watermark(data, width, height, watermark, watermark_width, watermark_height);

    // Write the watermarked image to a file
    write_image("watermarked.bmp", watermarked_data, width, height);

    // Extract the watermark from the watermarked image
    unsigned char* extracted_watermark = extract_watermark(watermarked_data, width, height, watermark_width, watermark_height);

    // Write the extracted watermark to a file
    write_image("extracted_watermark.bmp", extracted_watermark, watermark_width, watermark_height);

    // Free the memory allocated for the images
    free(data);
    free(watermark);
    free(watermarked_data);
    free(extracted_watermark);

    return 0;
}