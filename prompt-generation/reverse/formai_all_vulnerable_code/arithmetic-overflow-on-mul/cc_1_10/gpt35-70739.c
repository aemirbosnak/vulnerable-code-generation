//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to insert watermark in the image
void insertWatermark(char* inputImageFile, char* outputImageFile, char* watermarkString) {

    FILE *fIN, *fOUT;

    fIN = fopen(inputImageFile, "rb");
    fOUT = fopen(outputImageFile, "wb");

    if (fIN == NULL || fOUT == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }

    unsigned char imageHeader[54];
    fread(imageHeader, sizeof(unsigned char), 54, fIN);
    fwrite(imageHeader, sizeof(unsigned char), 54, fOUT);

    //Finding the height and width of the image
    int height = *(int*)&imageHeader[18];
    int width = *(int*)&imageHeader[22];

    int imageSize = height * width * 3; // 3 bytes per pixel

    //Creating a buffer to read the image data
    unsigned char *imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, sizeof(unsigned char), imageSize, fIN);

    //Converting the watermark message into binary
    unsigned char watermarkBinary[sizeof(watermarkString) * 8 + 1];
    int watermarkLength = strlen(watermarkString);

    for (int i = 0; i < watermarkLength; i++) {
        int asciiValue = (int)watermarkString[i];
        for (int j = 7; j >= 0; j--) {
            *(watermarkBinary + i * 8 + (7 - j)) = (asciiValue % 2 == 0 ? '0' : '1');
            asciiValue /= 2;
        }
    }

    *(watermarkBinary + watermarkLength * 8) = '\0';

    //Inserting the watermark in the image
    int watermarkIndex = 0;

    for (int i = 0; i < imageSize; i++) {
        if (i % 3 == 0) {
            int pixelValue = *(imageData + i);
            if (watermarkIndex < strlen(watermarkBinary)) {
                pixelValue = (pixelValue & 0xFE) + (int)(watermarkBinary[watermarkIndex++] - '0');
            }
            *(imageData + i) = pixelValue;
        }
    }

    fwrite(imageData, sizeof(unsigned char), imageSize, fOUT);

    fclose(fIN);
    fclose(fOUT);

    free(imageData);

}

//Function to extract watermark from the image
void extractWatermark(char* inputImageFile) {

    FILE* fIN;

    fIN = fopen(inputImageFile, "rb");

    if (fIN == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }

    unsigned char imageHeader[54];
    fread(imageHeader, sizeof(unsigned char), 54, fIN);

    //Finding the height and width of the image
    int height = *(int*)&imageHeader[18];
    int width = *(int*)&imageHeader[22];

    int imageSize = height * width * 3; // 3 bytes per pixel

    //Creating a buffer to read the image data
    unsigned char *imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, sizeof(unsigned char), imageSize, fIN);

    //Extracting the watermark from the image
    char watermarkMessage[100];
    int watermarkIndex = 0;
    char watermarkChar = '\0';

    for (int i = 0; i < imageSize; i++) {
        if (i % 3 == 0) {
            int pixelValue = *(imageData + i);
            int watermarkBit = pixelValue & 0x01;
            watermarkChar += (watermarkBit << (7 - watermarkIndex));
            watermarkIndex++;
            if (watermarkIndex == 8) {
                if (watermarkChar == '\0') break;
                strncat(watermarkMessage, &watermarkChar, 1);
                watermarkChar = '\0';
                watermarkIndex = 0;
            }
        }
    }

    printf("Extracted Watermark Message: %s\n", watermarkMessage);

    fclose(fIN);

    free(imageData);

}

int main() {

    char inputImageFile[100] = "input_image.bmp";
    char outputImageFile[100] = "output_image.bmp";
    char watermarkString[100] = "Digital Watermarking";

    printf("Inserting watermark into the image...\n");
    insertWatermark(inputImageFile, outputImageFile, watermarkString);

    printf("Extracting watermark from the image...\n");
    extractWatermark(outputImageFile);

    return 0;
}