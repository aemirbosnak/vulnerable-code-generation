//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void embedWatermark(char* imageFile, char* watermarkText) {
    FILE* image = fopen(imageFile, "r+b");
    fseek(image, 0, SEEK_END);
    int imageSize = ftell(image);
    rewind(image);

    char* fileData = malloc(sizeof(char) * imageSize);
    fread(fileData, sizeof(char), imageSize, image);

    srand(time(NULL));
    int watermarkLength = strlen(watermarkText);
    int insertionIndex = rand() % (imageSize - watermarkLength);

    fseek(image, insertionIndex, SEEK_SET);
    fwrite(watermarkText, sizeof(char), watermarkLength, image);

    free(fileData);
    fclose(image);

    printf("Watermark successfully embedded.\n");
}

void extractWatermark(char* imageFile, int watermarkLength) {
    FILE* image = fopen(imageFile, "rb");
    fseek(image, 0, SEEK_END);
    int imageSize = ftell(image);
    rewind(image);

    char* fileData = malloc(sizeof(char) * imageSize);
    fread(fileData, sizeof(char), imageSize, image);

    int extractionIndex = rand() % (imageSize - watermarkLength);

    char* extractedWatermark = malloc(sizeof(char) * watermarkLength);
    memcpy(extractedWatermark, &fileData[extractionIndex], watermarkLength);

    printf("Extracted watermark: %s\n", extractedWatermark);

    free(extractedWatermark);
    free(fileData);
    fclose(image);
}

int main() {
    char* imageFile = "test.jpg";
    char* watermarkText = "This is a test watermark.";
    int watermarkLength = strlen(watermarkText);

    embedWatermark(imageFile, watermarkText);
    printf("Attempting to extract watermark...\n");
    extractWatermark(imageFile, watermarkLength);

    return 0;
}