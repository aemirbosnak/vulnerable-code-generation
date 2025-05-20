//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to embed a watermark into an image
void embedWatermark(const char *inputImagePath, const char *outputImagePath, const char *watermarkText) {
    FILE *input = fopen(inputImagePath, "rb");
    if (!input) {
        perror("Failed to open the input image");
        return;
    }

    FILE *output = fopen(outputImagePath, "wb");
    if (!output) {
        perror("Failed to open the output image");
        fclose(input);
        return;
    }

    // Reading the header of the BMP file
    uint8_t header[54];
    fread(header, sizeof(uint8_t), 54, input);
    fwrite(header, sizeof(uint8_t), 54, output);

    // Get image dimensions
    int width = *((int*)&header[18]);
    int height = *((int*)&header[22]);
    int padding = (4 - (width * 3) % 4) % 4;

    // Calculate the embedding position
    int waterMarkLength = strlen(watermarkText);
    int waterMarkPosX = width - waterMarkLength * 10 - 10; // Leave some margin
    int waterMarkPosY = height - 20; // Leave some margin

    // Write image data to output and embed the watermark
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Read pixel
            uint8_t pixel[3];
            fread(pixel, sizeof(uint8_t), 3, input);

            // Check if within watermark position
            if (y >= waterMarkPosY && y < waterMarkPosY + 20 &&
                x >= waterMarkPosX && x < waterMarkPosX + waterMarkLength * 10) {
                // Change the pixel value to embed watermark (very simplistic way)
                if ((x - waterMarkPosX) % 10 == 0 && (y - waterMarkPosY) % 10 == 0) {
                    pixel[0] = (pixel[0] & 0xFE) | ((watermarkText[(x - waterMarkPosX) / 10] & 1) ? 1 : 0);
                }
            }

            // Write the modified pixel to output
            fwrite(pixel, sizeof(uint8_t), 3, output);
        }
        // Write padding
        for (int p = 0; p < padding; p++) {
            fputc(0, output);
        }
    }

    // Close files
    fclose(input);
    fclose(output);
    printf("Watermark embedded successfully!\n");
}

// Function to detect a watermark in an image
void detectWatermark(const char *imagePath, const char *expectedWatermark) {
    FILE *input = fopen(imagePath, "rb");
    if (!input) {
        perror("Failed to open the image file");
        return;
    }

    uint8_t header[54];
    fread(header, sizeof(uint8_t), 54, input);

    int width = *((int*)&header[18]);
    int height = *((int*)&header[22]);
    int padding = (4 - (width * 3) % 4) % 4;

    char detectedWatermark[100] = {0};
    int idx = 0;

    // Scan for watermark
    for (int y = height - 20; y < height; y++) {
        for (int x = width - strlen(expectedWatermark) * 10 - 10; x < width; x++) {
            uint8_t pixel[3];
            fread(pixel, sizeof(uint8_t), 3, input);
            
            if ((x - (width - strlen(expectedWatermark) * 10 - 10)) % 10 == 0 &&
                (y - (height - 20)) % 10 == 0) {
                detectedWatermark[idx++] = (pixel[0] & 1) ? '1' : '0'; // Naive binary reading
            }
        }
        // Skip padding
        fseek(input, padding, SEEK_CUR);
    }

    detectedWatermark[idx] = '\0';
    fclose(input);

    // Print results
    printf("Detected watermark: %s\n", detectedWatermark);
    if (strcmp(detectedWatermark, expectedWatermark) == 0) {
        printf("Watermark matches expected watermark!\n");
    } else {
        printf("Watermark does not match!\n");
    }
}

int main() {
    const char *inputImage = "input.bmp";
    const char *outputImage = "output_watermarked.bmp";
    const char *watermark = "Watermark";

    embedWatermark(inputImage, outputImage, watermark);
    detectWatermark(outputImage, watermark);

    return 0;
}