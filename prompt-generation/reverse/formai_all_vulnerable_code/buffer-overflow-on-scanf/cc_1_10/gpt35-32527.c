//FormAI DATASET v1.0 Category: Image Steganography ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This program implements a simple example of image steganography in C
// The secret message is taken from the famous play, Romeo and Juliet

// Function to convert decimal to binary
int* decimalToBinary(int decimalNum) {
    static int binaryNum[8];
    for(int i=0; decimalNum > 0; i++) {
        binaryNum[i] = decimalNum % 2;
        decimalNum = decimalNum / 2;
    }
    return binaryNum;
}

// Function to convert binary to decimal
int binaryToDecimal(int* binaryNum) {
    int decimalNum = 0;
    int base = 1;
    for(int i=0; i<8; i++) {
        decimalNum += binaryNum[i] * base;
        base *= 2;
    }
    return decimalNum;
}

int main() {
    char originalImage[100];
    char steganoImage[100];
    char message[] = "Thou art as glorious to this night, being o'er my head, As is a winged messenger of heavenUnto the white, upturned, wond'ring eyes Of mortals that fall back to gaze on him When he bestrides the lazy-puffing clouds And sails upon the bosom of the air.";
    printf("Enter the name of the original image file: ");
    scanf("%s", originalImage);
    printf("Enter the name of the steganography image file: ");
    scanf("%s", steganoImage);

    FILE* originalImg = fopen(originalImage, "rb");
    FILE* steganoImg = fopen(steganoImage, "wb");

    if(originalImg == NULL || steganoImg == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int data, bitCount = 0, i = 0, j = 0, len = strlen(message);
    int* binaryNum;
    unsigned char imageData[512];

    while((data = fgetc(originalImg)) != EOF) {
        imageData[i++] = data;
        if(i % 3 == 0) {
            if(bitCount < len*8) {
                // Convert the character to binary and store in an array
                binaryNum = decimalToBinary((int) message[bitCount/8]);
                // Replace the least significant bit of the image RGB values with the message bit
                imageData[i-3] = (imageData[i-3] & 0b11111110) | binaryNum[7];
                imageData[i-2] = (imageData[i-2] & 0b11111110) | binaryNum[6];
                imageData[i-1] = (imageData[i-1] & 0b11111110) | binaryNum[5];
                imageData[i-2] = (imageData[i-2] & 0b11111110) | binaryNum[4];
                imageData[i-1] = (imageData[i-1] & 0b11111110) | binaryNum[3];
                imageData[i-3] = (imageData[i-3] & 0b11111110) | binaryNum[2];
                imageData[i-1] = (imageData[i-1] & 0b11111110) | binaryNum[1];
                imageData[i-2] = (imageData[i-2] & 0b11111110) | binaryNum[0];
                bitCount++;
            }
        }
    }
    // Write the image data into the stegano image file
    fwrite(imageData, sizeof(imageData), 1, steganoImg);

    fclose(originalImg);
    fclose(steganoImg);

    FILE* steganoImgRead = fopen(steganoImage, "rb");

    if(steganoImgRead == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int byte, binaryValue[8], count = 0, messageIndex = 0;
    char decodedMessage[len+1];

    while((byte = fgetc(steganoImgRead)) != EOF && messageIndex <= len) {
        binaryValue[0] = (byte & 0b00000001);
        binaryValue[1] = (byte & 0b00000010) >> 1;
        binaryValue[2] = (byte & 0b00000100) >> 2;
        binaryValue[3] = (byte & 0b00001000) >> 3;
        binaryValue[4] = (byte & 0b00010000) >> 4;
        binaryValue[5] = (byte & 0b00100000) >> 5;
        binaryValue[6] = (byte & 0b01000000) >> 6;
        binaryValue[7] = (byte & 0b10000000) >> 7;

        for(int k=0; k<8; k++) {
            if(count % 8 == 0) {
                decodedMessage[messageIndex++] = (char) binaryToDecimal(binaryValue);
            } else {
                binaryValue[k] = 0;
            }
            count++;
        }
    }
    decodedMessage[len] = '\0';
    printf("The decoded message is:\n%s\n", decodedMessage);

    fclose(steganoImgRead);

    return 0;
}