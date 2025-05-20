//FormAI DATASET v1.0 Category: Image Steganography ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

int imageSize(FILE* fp) {
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    return size;
}

void hideMessageInImage(BYTE* imageData, int imageSize, char* message) {
    int messageIndex = 0;
    int bitIndex = 0;
    char bit;
    
    while (message[messageIndex] != '\0') {
        for (int j = 0; j < 8; j++) {
            bit = (message[messageIndex] >> j) & 1;
            imageData[bitIndex] = (imageData[bitIndex] & 0xFE) | bit;
            bitIndex++;
        }
        messageIndex++;
    }
}

void extractSecretMessage(BYTE* imageData, int imageSize) {
    int messageIndex = 0;
    char message[5000];
    char currentChar = 0;
    
    for (int i = 0; i < imageSize; i++) {
        currentChar = (currentChar << 1) | (imageData[i] & 1);
        if ((i+1) % 8 == 0) {
            message[messageIndex] = currentChar;
            messageIndex++;
            currentChar = 0;
            if (message[messageIndex-1] == '\0') {
                break;
            }
        }
    }
    printf("Secret Message: %s\n", message);
}

int main() {
    FILE* fp = fopen("input_image.png", "rb");
    if (fp == NULL) {
        printf("Error opening image file");
        return 0;
    }
    
    int size = imageSize(fp);
    BYTE* imageData = (BYTE*)malloc(sizeof(BYTE) * size);
    fread(imageData, sizeof(BYTE), size, fp);
    
    char message[2000];
    printf("Enter secret message to hide: ");
    scanf("%[^\n]s", message);
    hideMessageInImage(imageData, size, message);
    
    printf("Secret message has been hidden in the image\n");
    
    FILE* out = fopen("output_image.png", "wb");
    fwrite(imageData, sizeof(BYTE), size, out);
    fclose(out);
    
    FILE* fp2 = fopen("output_image.png", "rb");
    int size2 = imageSize(fp2);
    BYTE* imageData2 = (BYTE*)malloc(sizeof(BYTE) * size2);
    fread(imageData2, sizeof(BYTE), size2, fp2);
    
    extractSecretMessage(imageData2, size2);
    
    fclose(fp);
    fclose(fp2);
    free(imageData);
    free(imageData2);
    
    return 0;    
}