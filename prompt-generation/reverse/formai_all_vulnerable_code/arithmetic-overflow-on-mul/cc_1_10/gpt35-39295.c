//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

//Declaring function for flipping image
void flipImage(int width, int height, unsigned char *imageData) {
    int i, j, k;
    unsigned char temp;
    for (k = 0; k < 3; k++) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width / 2; j++) {
                temp = imageData[i * width * 3 + j * 3 + k];
                imageData[i * width * 3 + j * 3 + k] = imageData[i * width * 3 + (width - j - 1) * 3 + k];
                imageData[i * width * 3 + (width - j - 1) * 3 + k] = temp;
            }
        }
    }
}

//Declaring function for changing brightness and contrast of image
void changeBrightnessContrast(int width, int height, unsigned char *imageData, float brightness, float contrast) {
    int i, j, k;
    float pixelValue;
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (k = 0; k < 3; k++) {
                pixelValue = imageData[i * width * 3 + j * 3 + k];
                pixelValue = factor * (pixelValue - 128.0) + 128.0 + brightness;
                if (pixelValue < 0) pixelValue = 0;
                if (pixelValue > 255) pixelValue = 255;
                imageData[i * width * 3 + j * 3 + k] = (unsigned char) pixelValue;
            }
        }
    }
}

int main() {
    FILE *inputFile;
    FILE *outputFile;
    int fileType, fileSize, reserved, dataOffset, width, height, bitCount, compression, imageSize, i, j, k;
    unsigned char *bmpHeader;
    unsigned char *imageData;
    float brightness, contrast;
    int brightnessFlag = 0, contrastFlag = 0;
 
    //Reading input file
    inputFile = fopen("input.bmp", "rb");
    if(inputFile == NULL) {
        printf("Error reading file\n");
        return 0;
    }
    fseek(inputFile, 0, SEEK_END);
    fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);
    bmpHeader = (unsigned char*) malloc(sizeof(unsigned char) * 54);
    fread(bmpHeader, sizeof(unsigned char), 54, inputFile);

    //Parsing bmp header
    fileSize = *(int*)&bmpHeader[2];
    reserved = *(int*)&bmpHeader[6];
    dataOffset = *(int*)&bmpHeader[10];
    width = *(int*)&bmpHeader[18];
    height = *(int*)&bmpHeader[22];
    bitCount = *(int*)&bmpHeader[28];
    compression = *(int*)&bmpHeader[30];
    imageSize = *(int*)&bmpHeader[34];

    //Reading image data
    imageData = (unsigned char *) malloc(sizeof(unsigned char) * width * height * 3);
    fread(imageData, sizeof(unsigned char), width * height * 3, inputFile);
    fclose(inputFile);

    //Asking user for processing options
    printf("Select the processing options you want to apply:\n");
    printf("1. Flip image horizontally\n");
    printf("2. Change brightness\n");
    printf("3. Change contrast\n");
    printf("Enter your choice(s) separated by a space: ");
    int option;
    while (scanf("%d", &option)) {
        if(option == 1) {
            flipImage(width, height, imageData);
            printf("Image flipped successfully\n");
        } else if(option == 2) {
            printf("Enter the brightness value (-255 to 255): ");
            scanf("%f", &brightness);
            brightnessFlag = 1;
        } else if(option == 3) {
            printf("Enter the contrast value (-255 to 255): ");
            scanf("%f", &contrast);
            contrastFlag = 1;
        } else {
            break;
        }
    }

    //Processing image according to selected options
    if(brightnessFlag || contrastFlag) {
        changeBrightnessContrast(width, height, imageData, brightness, contrast);
        printf("Image brightness/contrast changed successfully\n");
    }

    //Writing output file
    outputFile = fopen("output.bmp", "wb");
    if(outputFile == NULL) {
        printf("Error writing file\n");
        return 0;
    }
    fwrite(bmpHeader, sizeof(unsigned char), 54, outputFile);
    fwrite(imageData, sizeof(unsigned char), width * height * 3, outputFile);
    fclose(outputFile);

    printf("Output file generated successfully\n");

    //Freeing memory
    free(bmpHeader);
    free(imageData);

    return 0;
}