//FormAI DATASET v1.0 Category: Image Steganography ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BYTE_SIZE 8

/* Function prototypes */
void hideData(char* message, char* imageFilename, char* outputImageFilename);
char* convertToBits(char character);
char* convertMessageToBits(char* message);
void writePixel(FILE* file, char* pixel, char* bit);
int isEndOfMessage(char* message);

/* Function to hide the data */
void hideData(char* message, char* imageFilename, char* outputImageFilename) {
    FILE* image = fopen(imageFilename, "rb");
    FILE* outputImage = fopen(outputImageFilename, "wb");
    char pixel[3], bit[BYTE_SIZE];
    int bitIndex = 0, messageIndex = 0, endOfMessage = 0;

    while (!endOfMessage && fread(pixel, 1, 3, image) == 3) {
        for (int i = 0; i < 3; i++) {
            if (!endOfMessage) {
                writePixel(outputImage, &pixel[i], &bit[bitIndex]);
                bit[bitIndex++] = pixel[i] & 1;

                if (bitIndex == BYTE_SIZE) {
                    char letter = strtol(bit, NULL, 2);
                    endOfMessage = isEndOfMessage(&message[messageIndex]);
                    messageIndex++;

                    if (!endOfMessage) {
                        bitIndex = 0;
                        letter = message[messageIndex];
                    }
                    sprintf(bit, "%s", convertToBits(letter));
                }
            } else {
                fwrite(&pixel[i], 1, 1, outputImage);
            }
        }
    }

    fclose(image);
    fclose(outputImage);
    printf("Data successfully hidden in image!\n");
}

/* Function to convert character to bits */
char* convertToBits(char character) {
    char* bit = (char*)malloc(sizeof(char) * (BYTE_SIZE + 1));
    int index = 0;

    for (int i = BYTE_SIZE - 1; i >= 0; i--) {
        bit[index++] = ((1 << i) & character) ? '1' : '0';
    }

    bit[index] = '\0';
    return bit;
}

/* Function to convert message to bits */
char* convertMessageToBits(char* message) {
    char* bits = (char*)malloc(sizeof(char) * (strlen(message) * BYTE_SIZE + 1));
    bits[0] = '\0';

    for (int i = 0; i < strlen(message); i++) {
        strcat(bits, convertToBits(message[i]));
    }

    return bits;
}

/* Function to write pixel */
void writePixel(FILE* file, char* pixel, char* bit) {
    char newPixel[3];

    for (int i = 0; i < BYTE_SIZE; i++) {
        newPixel[i] = (*pixel & ~(1 << i)) | (bit[i] - '0');
    }

    fwrite(newPixel, 1, 3, file);
}

/* Function to check if end of message reached */
int isEndOfMessage(char* message) {
    return message[0] == '\0';
}

/* Main function */
int main() {
    char* message = "This is a secret message!";
    char* imageFilename = "image.bmp";
    char* outputImageFilename = "output_image.bmp";
    hideData(message, imageFilename, outputImageFilename);
    return 0;
}