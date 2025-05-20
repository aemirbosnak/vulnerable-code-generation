//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define the watermark data structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Watermark;

// Read a watermark from a file
Watermark *read_watermark(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening watermark file: %s\n", filename);
        return NULL;
    }

    // Read the watermark header
    Watermark *watermark = malloc(sizeof(Watermark));
    fread(&watermark->width, sizeof(int), 1, fp);
    fread(&watermark->height, sizeof(int), 1, fp);

    // Read the watermark data
    watermark->data = malloc(watermark->width * watermark->height);
    fread(watermark->data, sizeof(unsigned char), watermark->width * watermark->height, fp);

    fclose(fp);

    return watermark;
}

// Embed the watermark in an image
void embed_watermark(unsigned char *image, int width, int height, Watermark *watermark) {
    // Convert the watermark to a binary string
    int watermark_size = watermark->width * watermark->height;
    char *watermark_binary = malloc(watermark_size + 1);
    for (int i = 0; i < watermark_size; i++) {
        watermark_binary[i] = watermark->data[i] ? '1' : '0';
    }
    watermark_binary[watermark_size] = '\0';

    // Embed the watermark in the image
    int image_size = width * height;
    int watermark_index = 0;
    for (int i = 0; i < image_size; i++) {
        if (watermark_index < watermark_size) {
            // Embed the watermark bit in the least significant bit of the image pixel
            image[i] &= 0xFE;
            image[i] |= (watermark_binary[watermark_index] - '0');
            watermark_index++;
        }
    }

    free(watermark_binary);
}

// Extract the watermark from an image
Watermark *extract_watermark(unsigned char *image, int width, int height) {
    // Create a new watermark
    Watermark *watermark = malloc(sizeof(Watermark));
    watermark->width = width;
    watermark->height = height;
    watermark->data = malloc(watermark->width * watermark->height);

    // Extract the watermark from the image
    int watermark_size = watermark->width * watermark->height;
    int watermark_index = 0;
    for (int i = 0; i < watermark_size; i++) {
        // Extract the watermark bit from the least significant bit of the image pixel
        watermark->data[i] = (image[i] & 1) ? 1 : 0;
        watermark_index++;
    }

    return watermark;
}

// Save the watermark to a file
void save_watermark(const char *filename, Watermark *watermark) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening watermark file: %s\n", filename);
        return;
    }

    // Write the watermark header
    fwrite(&watermark->width, sizeof(int), 1, fp);
    fwrite(&watermark->height, sizeof(int), 1, fp);

    // Write the watermark data
    fwrite(watermark->data, sizeof(unsigned char), watermark->width * watermark->height, fp);

    fclose(fp);
}

// Main function
int main() {
    // Read the input image
    unsigned char *image = malloc(sizeof(unsigned char) * 1024 * 1024);
    int width, height;
    FILE *fp = fopen("image.bmp", "rb");
    if (!fp) {
        fprintf(stderr, "Error opening input image: image.bmp\n");
        return -1;
    }
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    // Read the watermark
    Watermark *watermark = read_watermark("watermark.bmp");
    if (!watermark) {
        return -1;
    }

    // Embed the watermark in the image
    embed_watermark(image, width, height, watermark);

    // Save the watermarked image
    fp = fopen("watermarked_image.bmp", "wb");
    if (!fp) {
        fprintf(stderr, "Error opening watermarked image: watermarked_image.bmp\n");
        return -1;
    }
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    // Extract the watermark from the watermarked image
    Watermark *extracted_watermark = extract_watermark(image, width, height);

    // Save the extracted watermark
    save_watermark("extracted_watermark.bmp", extracted_watermark);

    // Free the allocated memory
    free(image);
    free(watermark->data);
    free(watermark);
    free(extracted_watermark->data);
    free(extracted_watermark);

    return 0;
}