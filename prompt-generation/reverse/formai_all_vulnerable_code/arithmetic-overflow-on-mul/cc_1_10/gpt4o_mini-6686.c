//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readPGM(const char *filename, unsigned char **image, int *width, int *height);
void writePGM(const char *filename, unsigned char *image, int width, int height);
void embedWatermark(unsigned char *original, unsigned char *watermark, unsigned char *output, int width, int height, int wm_width, int wm_height);
void extractWatermark(unsigned char *output, unsigned char *extracted, int width, int height, int wm_width, int wm_height);
void displayImage(const char *filename);

int main() {
    const char *originalImageFile = "original.pgm";
    const char *watermarkImageFile = "watermark.pgm";
    const char *outputImageFile = "output.pgm";
    const char *extractedImageFile = "extracted.pgm";

    unsigned char *originalImage = NULL;
    unsigned char *watermarkImage = NULL;
    unsigned char *outputImage = NULL;
    unsigned char *extractedImage = NULL;
    
    int originalWidth, originalHeight;
    int watermarkWidth, watermarkHeight;

    // Read the original image
    readPGM(originalImageFile, &originalImage, &originalWidth, &originalHeight);
    
    // Read the watermark image
    readPGM(watermarkImageFile, &watermarkImage, &watermarkWidth, &watermarkHeight);

    // Allocate memory for the output image
    outputImage = (unsigned char *)malloc(originalWidth * originalHeight);
    if (outputImage == NULL) {
        fprintf(stderr, "Failed to allocate memory for output image\n");
        return 1;
    }

    // Embed the watermark into the original image
    embedWatermark(originalImage, watermarkImage, outputImage, originalWidth, originalHeight, watermarkWidth, watermarkHeight);
    
    // Write the watermarked image to file
    writePGM(outputImageFile, outputImage, originalWidth, originalHeight);

    // Allocate memory for the extracted watermark image
    extractedImage = (unsigned char *)malloc(watermarkWidth * watermarkHeight);
    if (extractedImage == NULL) {
        fprintf(stderr, "Failed to allocate memory for extracted watermark image\n");
        free(originalImage);
        free(watermarkImage);
        free(outputImage);
        return 1;
    }

    // Extract the watermark from the output image
    extractWatermark(outputImage, extractedImage, originalWidth, originalHeight, watermarkWidth, watermarkHeight);

    // Write the extracted watermark to file
    writePGM(extractedImageFile, extractedImage, watermarkWidth, watermarkHeight);

    // Display the images (optional)
    displayImage(outputImageFile);
    displayImage(extractedImageFile);

    // Cleanup
    free(originalImage);
    free(watermarkImage);
    free(outputImage);
    free(extractedImage);

    return 0;
}

void readPGM(const char *filename, unsigned char **image, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    char header[3];
    fscanf(file, "%s", header);
    
    if (strcmp(header, "P5") != 0) {
        fprintf(stderr, "Unsupported PGM format: %s\n", header);
        fclose(file);
        return;
    }
    
    // Read image dimensions
    fscanf(file, "%d %d", width, height);
    fgetc(file); // Read the newline after the dimensions
    fgetc(file); // Read the max pixel value (not used)

    // Allocate memory for the image
    *image = (unsigned char *)malloc((*width) * (*height));
    fread(*image, sizeof(unsigned char), (*width) * (*height), file);
    fclose(file);
}

void writePGM(const char *filename, unsigned char *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    fprintf(file, "P5\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height, file);
    fclose(file);
}

void embedWatermark(unsigned char *original, unsigned char *watermark, unsigned char *output, int width, int height, int wm_width, int wm_height) {
    memcpy(output, original, width * height); // Copy original image to output
    for (int y = 0; y < wm_height; y++) {
        for (int x = 0; x < wm_width; x++) {
            int index = (y * width) + x; // Calculate the index in the output
            output[index] = (original[index] + watermark[y * wm_width + x]) / 2; // Simple average for embedding
        }
    }
}

void extractWatermark(unsigned char *output, unsigned char *extracted, int width, int height, int wm_width, int wm_height) {
    memset(extracted, 0, wm_width * wm_height); // Clear extracted image
    for (int y = 0; y < wm_height; y++) {
        for (int x = 0; x < wm_width; x++) {
            int index = (y * width) + x; // Calculate the index in the output
            extracted[y * wm_width + x] = output[index]; // Direct extraction for simplicity
        }
    }
}

void displayImage(const char *filename) {
    char command[256];
    snprintf(command, sizeof(command), "display %s", filename); // Use ImageMagick's display command
    system(command);
}