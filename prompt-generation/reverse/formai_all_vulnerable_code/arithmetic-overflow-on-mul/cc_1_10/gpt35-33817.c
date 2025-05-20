//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// function to embed the watermark into the image
void embedWatermark(unsigned char* image, unsigned char* watermark, int imageWidth, int imageHeight, int watermarkWidth, int watermarkHeight) {
    int watermarkRow = 0, watermarkCol = 0;

    // iterate through image and embed the watermark
    for (int i = 0; i < imageWidth * imageHeight; i += 3) {
        if (watermarkCol >= watermarkWidth) {
            watermarkCol = 0;
            watermarkRow++;
            if (watermarkRow >= watermarkHeight) {
                break;  // watermark fully embedded
            }
        }

        // embed watermark into image's least significant bits
        image[i] = (image[i] & 0xFE) | ((watermark[watermarkRow * watermarkWidth + watermarkCol] >> 7) & 1);
        image[i+1] = (image[i+1] & 0xFE) | ((watermark[watermarkRow * watermarkWidth + watermarkCol] >> 6) & 1);
        image[i+2] = (image[i+2] & 0xFE) | ((watermark[watermarkRow * watermarkWidth + watermarkCol] >> 5) & 1);

        watermarkCol++;
    }
}

// function to extract the watermark from the image
void extractWatermark(unsigned char* image, unsigned char* watermark, int imageWidth, int imageHeight, int watermarkWidth, int watermarkHeight) {
    int watermarkRow = 0, watermarkCol = 0;

    // iterate through image and extract the watermark
    for (int i = 0; i < imageWidth * imageHeight; i += 3) {
        if (watermarkCol >= watermarkWidth) {
            watermarkCol = 0;
            watermarkRow++;
            if (watermarkRow >= watermarkHeight) {
                break;  // watermark fully extracted
            }
        }

        // extract watermark from image's least significant bits
        watermark[watermarkRow * watermarkWidth + watermarkCol] |= (image[i] & 1) << 7;
        watermark[watermarkRow * watermarkWidth + watermarkCol] |= (image[i+1] & 1) << 6;
        watermark[watermarkRow * watermarkWidth + watermarkCol] |= (image[i+2] & 1) << 5;

        watermarkCol++;
    }
}

int main() {
    // load image and watermark from files
    FILE* imageFile = fopen("image.raw", "rb");
    FILE* watermarkFile = fopen("watermark.raw", "rb");

    fseek(imageFile, 0, SEEK_END);
    int imageFileSize = ftell(imageFile);
    rewind(imageFile);

    fseek(watermarkFile, 0, SEEK_END);
    int watermarkFileSize = ftell(watermarkFile);
    rewind(watermarkFile);

    if (imageFileSize != watermarkFileSize * 8) {
        printf("Watermark file must be 1/8 the size of the image file.\n");
        return 1;
    }

    unsigned char imageBuffer[imageFileSize];
    unsigned char watermarkBuffer[watermarkFileSize];

    fread(imageBuffer, 1, imageFileSize, imageFile);
    fread(watermarkBuffer, 1, watermarkFileSize, watermarkFile);

    fclose(imageFile);
    fclose(watermarkFile);

    // embed watermark into image
    embedWatermark(imageBuffer, watermarkBuffer, 640, 480, 80, 30);

    // write the watermarked image to file
    FILE* watermarkedFile = fopen("watermarked.raw", "wb");
    fwrite(imageBuffer, 1, imageFileSize, watermarkedFile);
    fclose(watermarkedFile);

    // extract watermark from watermarked image
    unsigned char extractedWatermarkBuffer[watermarkFileSize];
    extractWatermark(imageBuffer, extractedWatermarkBuffer, 640, 480, 80, 30);

    // check if extracted watermark matches original watermark
    if (memcmp(watermarkBuffer, extractedWatermarkBuffer, watermarkFileSize) == 0) {
        printf("Watermark successfully embedded and extracted.\n");
    } else {
        printf("Watermark extraction unsuccessful.\n");
        return 1;
    }

    return 0;
}