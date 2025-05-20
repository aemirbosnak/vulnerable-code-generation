//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 255
#define MAX_WATERMARK_LEN 255
#define MAX_IMAGE_NAME_LEN 100

typedef struct {
    unsigned char r, g, b;
} Pixel;

void embed_watermark(const char* image_path, const char* watermark, const char* output_path) {
    FILE *image = fopen(image_path, "rb");
    if (!image) {
        perror("Error opening image file");
        return;
    }

    FILE *output = fopen(output_path, "wb");
    if (!output) {
        perror("Error creating output file");
        fclose(image);
        return;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);
    fwrite(header, sizeof(unsigned char), 54, output);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int size = width * height;

    Pixel *pixels = (Pixel*)malloc(size * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), size, image);
    
    int wm_len = strlen(watermark);
    for (int i = 0; i < wm_len; i++) {
        int pixel_index = i % size;
        pixels[pixel_index].r = (pixels[pixel_index].r & 0xFE) | ((watermark[i] >> 7) & 0x01);
        pixels[pixel_index].g = (pixels[pixel_index].g & 0xFE) | ((watermark[i] >> 6) & 0x01);
        pixels[pixel_index].b = (pixels[pixel_index].b & 0xFE) | ((watermark[i] >> 5) & 0x01);
    }

    fwrite(pixels, sizeof(Pixel), size, output);
    
    free(pixels);
    fclose(image);
    fclose(output);
}

void extract_watermark(const char* image_path, char* watermark, int wm_len) {
    FILE *image = fopen(image_path, "rb");
    if (!image) {
        perror("Error opening image file");
        return;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);
    
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int size = width * height;

    Pixel *pixels = (Pixel*)malloc(size * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), size, image);
    
    for (int i = 0; i < wm_len; i++) {
        int pixel_index = i % size;
        watermark[i] = 0;
        watermark[i] |= ((pixels[pixel_index].r & 0x01) << 7);
        watermark[i] |= ((pixels[pixel_index].g & 0x01) << 6);
        watermark[i] |= ((pixels[pixel_index].b & 0x01) << 5);
    }
    watermark[wm_len] = '\0';

    free(pixels);
    fclose(image);
}

int main() {
    char image[MAX_IMAGE_NAME_LEN];
    char output[MAX_IMAGE_NAME_LEN];
    char watermark[MAX_WATERMARK_LEN];
    
    printf("Enter image path: ");
    fgets(image, MAX_IMAGE_NAME_LEN, stdin);
    strtok(image, "\n");
    
    printf("Enter watermark (max %d chars): ", MAX_WATERMARK_LEN - 1);
    fgets(watermark, MAX_WATERMARK_LEN, stdin);
    strtok(watermark, "\n");
    
    printf("Enter output image path: ");
    fgets(output, MAX_IMAGE_NAME_LEN, stdin);
    strtok(output, "\n");
    
    embed_watermark(image, watermark, output);
    
    char extracted_watermark[MAX_WATERMARK_LEN];
    extract_watermark(output, extracted_watermark, strlen(watermark));
    
    printf("Extracted Watermark: %s\n", extracted_watermark);
    
    return 0;
}