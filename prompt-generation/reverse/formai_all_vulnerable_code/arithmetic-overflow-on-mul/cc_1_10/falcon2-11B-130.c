//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: expert-level
#include <stdio.h>
#include <string.h>

// Function to embed the watermark into the image
void embedWatermark(const char* watermark, const char* image, const char* output) {
    // Read the image
    FILE* imageFile = fopen(image, "rb");
    if (!imageFile) {
        printf("Error opening image file\n");
        return;
    }
    
    // Read the watermark
    FILE* watermarkFile = fopen(watermark, "rb");
    if (!watermarkFile) {
        printf("Error opening watermark file\n");
        fclose(imageFile);
        return;
    }
    
    // Read the output file
    FILE* outputFile = fopen(output, "wb");
    if (!outputFile) {
        printf("Error opening output file\n");
        fclose(imageFile);
        fclose(watermarkFile);
        return;
    }
    
    // Extract the width and height of the image
    int width, height;
    fread(&width, sizeof(int), 1, imageFile);
    fread(&height, sizeof(int), 1, imageFile);
    
    // Get the number of bytes per pixel
    int bytesPerPixel = 3 * width;
    
    // Extract the image data
    unsigned char* imageData = (unsigned char*)malloc(bytesPerPixel);
    if (!imageData) {
        printf("Error allocating memory for image data\n");
        fclose(imageFile);
        fclose(watermarkFile);
        fclose(outputFile);
        return;
    }
    fread(imageData, bytesPerPixel, 1, imageFile);
    
    // Extract the watermark data
    unsigned char* watermarkData = (unsigned char*)malloc(strlen(watermark));
    if (!watermarkData) {
        printf("Error allocating memory for watermark data\n");
        free(imageData);
        fclose(imageFile);
        fclose(watermarkFile);
        fclose(outputFile);
        return;
    }
    fread(watermarkData, strlen(watermark), 1, watermarkFile);
    
    // Embed the watermark into the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char* pixel = &imageData[i * width + j * bytesPerPixel];
            unsigned char* watermarkPixel = &watermarkData[i * width + j * bytesPerPixel];
            *pixel += *watermarkPixel;
        }
    }
    
    // Write the modified image data to the output file
    fwrite(imageData, bytesPerPixel, 1, outputFile);
    
    // Free the allocated memory
    free(imageData);
    free(watermarkData);
    
    // Close the files
    fclose(imageFile);
    fclose(watermarkFile);
    fclose(outputFile);
}

// Function to extract the watermark from the image
void extractWatermark(const char* image, const char* output) {
    // Read the image
    FILE* imageFile = fopen(image, "rb");
    if (!imageFile) {
        printf("Error opening image file\n");
        return;
    }
    
    // Read the output file
    FILE* outputFile = fopen(output, "wb");
    if (!outputFile) {
        printf("Error opening output file\n");
        fclose(imageFile);
        return;
    }
    
    // Extract the width and height of the image
    int width, height;
    fread(&width, sizeof(int), 1, imageFile);
    fread(&height, sizeof(int), 1, imageFile);
    
    // Get the number of bytes per pixel
    int bytesPerPixel = 3 * width;
    
    // Extract the image data
    unsigned char* imageData = (unsigned char*)malloc(bytesPerPixel);
    if (!imageData) {
        printf("Error allocating memory for image data\n");
        fclose(imageFile);
        fclose(outputFile);
        return;
    }
    fread(imageData, bytesPerPixel, 1, imageFile);
    
    // Embed the watermark into the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char* pixel = &imageData[i * width + j * bytesPerPixel];
            unsigned char watermarkValue = *pixel;
            *pixel = watermarkValue * 255 / (255 + 1);
        }
    }
    
    // Write the modified image data to the output file
    fwrite(imageData, bytesPerPixel, 1, outputFile);
    
    // Free the allocated memory
    free(imageData);
    
    // Close the files
    fclose(imageFile);
    fclose(outputFile);
}

int main() {
    // Example usage
    const char* image = "example.png";
    const char* watermark = "watermark.png";
    const char* output = "embedded.png";
    embedWatermark(watermark, image, output);
    
    const char* image2 = "embedded.png";
    const char* output2 = "extracted.png";
    extractWatermark(image2, output2);
    
    return 0;
}