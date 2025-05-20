//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to embed watermark into image
void embedWatermark(unsigned char *image, unsigned char *watermark, int imageWidth, int imageHeight, int watermarkWidth, int watermarkHeight) {
    // Calculate the size of the watermark in bits
    int watermarkSize = watermarkWidth * watermarkHeight;
    
    // Calculate the number of bits to embed in each pixel
    int bitsPerPixel = (int)ceil((double)watermarkSize / (imageWidth * imageHeight));
    
    // Iterate over the pixels in the image
    for (int i = 0; i < imageWidth * imageHeight; i++) {
        // Extract the least significant bits from the pixel
        int pixelBits = image[i] & ((1 << bitsPerPixel) - 1);
        
        // Replace the least significant bits with the watermark bits
        image[i] = (image[i] & ~((1 << bitsPerPixel) - 1)) | (watermark[i / bitsPerPixel] & ((1 << bitsPerPixel) - 1));
    }
}

// Function to extract watermark from image
void extractWatermark(unsigned char *image, unsigned char *watermark, int imageWidth, int imageHeight, int watermarkWidth, int watermarkHeight) {
    // Calculate the size of the watermark in bits
    int watermarkSize = watermarkWidth * watermarkHeight;
    
    // Calculate the number of bits to extract from each pixel
    int bitsPerPixel = (int)ceil((double)watermarkSize / (imageWidth * imageHeight));
    
    // Iterate over the pixels in the image
    for (int i = 0; i < imageWidth * imageHeight; i++) {
        // Extract the least significant bits from the pixel
        int pixelBits = image[i] & ((1 << bitsPerPixel) - 1);
        
        // Store the watermark bits in the watermark buffer
        watermark[i / bitsPerPixel] = (watermark[i / bitsPerPixel] << bitsPerPixel) | pixelBits;
    }
}

int main() {
    // Load the image from a file
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        perror("Error opening image file");
        return 1;
    }
    
    // Load the watermark from a file
    FILE *watermark_file = fopen("watermark.bmp", "rb");
    if (watermark_file == NULL) {
        perror("Error opening watermark file");
        return 1;
    }
    
    // Read the image header
    unsigned char image_header[54];
    fread(image_header, 1, 54, image_file);
    
    // Read the watermark header
    unsigned char watermark_header[54];
    fread(watermark_header, 1, 54, watermark_file);
    
    // Get the image width and height
    int image_width = *(int *)&image_header[18];
    int image_height = *(int *)&image_header[22];
    
    // Get the watermark width and height
    int watermark_width = *(int *)&watermark_header[18];
    int watermark_height = *(int *)&watermark_header[22];
    
    // Allocate memory for the image data
    unsigned char *image_data = (unsigned char *)malloc(image_width * image_height * 3);
    
    // Read the image data
    fread(image_data, 1, image_width * image_height * 3, image_file);
    
    // Allocate memory for the watermark data
    unsigned char *watermark_data = (unsigned char *)malloc(watermark_width * watermark_height);
    
    // Read the watermark data
    fread(watermark_data, 1, watermark_width * watermark_height, watermark_file);
    
    // Embed the watermark into the image
    embedWatermark(image_data, watermark_data, image_width, image_height, watermark_width, watermark_height);
    
    // Save the watermarked image to a file
    FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
    if (watermarked_image_file == NULL) {
        perror("Error opening watermarked image file");
        return 1;
    }
    
    // Write the image header
    fwrite(image_header, 1, 54, watermarked_image_file);
    
    // Write the image data
    fwrite(image_data, 1, image_width * image_height * 3, watermarked_image_file);
    
    // Close the files
    fclose(image_file);
    fclose(watermark_file);
    fclose(watermarked_image_file);
    
    // Extract the watermark from the watermarked image
    unsigned char *extracted_watermark = (unsigned char *)malloc(watermark_width * watermark_height);
    
    extractWatermark(image_data, extracted_watermark, image_width, image_height, watermark_width, watermark_height);
    
    // Save the extracted watermark to a file
    FILE *extracted_watermark_file = fopen("extracted_watermark.bmp", "wb");
    if (extracted_watermark_file == NULL) {
        perror("Error opening extracted watermark file");
        return 1;
    }
    
    // Write the watermark header
    fwrite(watermark_header, 1, 54, extracted_watermark_file);
    
    // Write the watermark data
    fwrite(extracted_watermark, 1, watermark_width * watermark_height, extracted_watermark_file);
    
    // Close the files
    fclose(extracted_watermark_file);
    
    return 0;
}