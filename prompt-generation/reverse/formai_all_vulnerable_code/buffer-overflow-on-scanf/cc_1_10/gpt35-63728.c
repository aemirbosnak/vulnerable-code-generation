//FormAI DATASET v1.0 Category: Image Steganography ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000000

// Function to convert a decimal number to binary
void decimalToBinary(int decimalNum, int *binaryArr) {
    int i = 0;
    while(decimalNum > 0) {
        binaryArr[i] = decimalNum % 2;
        decimalNum /= 2;
        i++;
    }
}

// Function to convert a binary number to decimal
int binaryToDecimal(int *binaryArr, int size) {
    int decimalNum = 0;
    for(int i = 0; i < size; i++) {
        decimalNum += binaryArr[i] * pow(2, i);
    }
    return decimalNum;
}

// Function to encode the message into the pixels of the image
void encode(int *pixelsArr, int *binaryArr, int messageSize) {
    int index = 0;
    for(int i = 0; i < messageSize; i++) {
        int pixelIndex = i * 3;
        for(int j = 0; j < 8; j++) {
            pixelsArr[pixelIndex + j] = pixelsArr[pixelIndex + j] & binaryArr[index];
            index++;
            if(index >= messageSize * 8) {
                return;
            }
        }
    }
}

// Function to decode the message from the pixels of the image
void decode(int *pixelsArr, int messageSize) {
    int index = 0;
    int *binaryArr = (int*) malloc(messageSize * 8 * sizeof(int));
    for(int i = 0; i < messageSize; i++) {
        int pixelIndex = i * 3;
        for(int j = 0; j < 8; j++) {
            binaryArr[index] = pixelsArr[pixelIndex + j] & 1;
            index++;
        }
    }

    printf("Decoded message: ");
    for(int i = 0; i < messageSize * 8; i+=8) {
        int decimalNum = binaryToDecimal(binaryArr + i, 8);
        printf("%c", decimalNum);
    }
    printf("\n");

    free(binaryArr);
}

int main() {
    FILE *imageFile;
    char imagePath[MAX_SIZE];
    printf("Enter the path of the image file: ");
    scanf("%s", imagePath);
    imageFile = fopen(imagePath, "rb");

    if(imageFile == NULL) {
        printf("Error in opening the image file");
        return 0;
    }

    int imageHeaderSize = 54;
    int pixelsSize;

    fseek(imageFile, 0L, SEEK_END);
    int fileSize = ftell(imageFile) - imageHeaderSize;
    fseek(imageFile, imageHeaderSize, SEEK_SET);

    int *pixelsArr = (int*) malloc(fileSize * sizeof(int));
    int bytesRead = fread((void*) pixelsArr, sizeof(int), fileSize, imageFile);

    printf("Enter the secret message to hide: ");
    char message[MAX_SIZE];
    scanf(" %[^\n]s", message);

    int messageSize = strlen(message);
    int binarySize = messageSize * 8;

    int *binaryArr = (int*) malloc(binarySize * sizeof(int));
    for(int i = 0; i < messageSize; i++) {
        decimalToBinary(message[i], binaryArr + i * 8);
    }

    encode(pixelsArr, binaryArr, messageSize);

    rewind(imageFile);
    int *imageHeaderArr = (int*) malloc(imageHeaderSize * sizeof(int));
    fread((void*) imageHeaderArr, sizeof(int), imageHeaderSize, imageFile);

    char outputImagePath[MAX_SIZE] = "stego_image.bmp";
    FILE *outputImageFile = fopen(outputImagePath, "wb");

    if(outputImageFile == NULL) {
        printf("Error in creating the output image file");
        return 0;
    }

    fwrite((void*) imageHeaderArr, sizeof(int), imageHeaderSize, outputImageFile);
    fwrite((void*) pixelsArr, sizeof(int), fileSize, outputImageFile);

    fclose(imageFile);
    fclose(outputImageFile);
    printf("Image successfully encoded\n");

    imageFile = fopen(outputImagePath, "rb");

    if(imageFile == NULL) {
        printf("Error in opening the image file");
        return 0;
    }

    fseek(imageFile, 0L, SEEK_END);
    pixelsSize = ftell(imageFile) - imageHeaderSize;
    fseek(imageFile, imageHeaderSize, SEEK_SET);

    int *pixelsArr2 = (int*) malloc(pixelsSize * sizeof(int));
    fread((void*) pixelsArr2, sizeof(int), pixelsSize, imageFile);

    decode(pixelsArr2, messageSize);

    fclose(imageFile);
    free(pixelsArr);
    free(pixelsArr2);
    free(imageHeaderArr);
    free(binaryArr);

    return 0;
}