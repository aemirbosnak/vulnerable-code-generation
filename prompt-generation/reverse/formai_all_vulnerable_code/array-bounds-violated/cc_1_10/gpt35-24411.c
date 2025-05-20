//FormAI DATASET v1.0 Category: Image Steganography ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

unsigned char image[MAX_SIZE];

void encryptData(char *data, char *key) {
    unsigned char encryptedData[strlen(data)];
    int count = 0;
    for (int i = 0; i < strlen(data); i++) {
        if (count == strlen(key)) {
            count = 0;
        }
        encryptedData[i] = (data[i] + key[count]) % 256;
        count++;
    }
    strcpy(data, encryptedData);
}

void decryptData(char *data, char *key) {
    unsigned char decryptedData[strlen(data)];
    int count = 0;
    for (int i = 0; i < strlen(data); i++) {
        if (count == strlen(key)) {
            count = 0;
        }
        decryptedData[i] = (data[i] - key[count]) % 256;
        count++;
    }
    strcpy(data, decryptedData);
}

void hideDataInImage(char *message, char *key) {
    int dataLen = strlen(message);
    char encryptedData[dataLen];
    char tempData[dataLen];

    strcpy(tempData, message);
    encryptData(tempData, key);

    int byteCount = 0;
    for (int i = 0; i < strlen(tempData); i++) {
        unsigned char byte = tempData[i];
        for (int bitCount = 7; bitCount >= 0; bitCount--) {
            unsigned char bit = (byte >> bitCount) & 1;
            if (bit == 1) {
                image[byteCount] = image[byteCount] | 1;
            } else {
                image[byteCount] = image[byteCount] & 254;
            }
            byteCount++;
        }
    }
}

void extractDataFromImage(char *key) {
    char decryptedData[MAX_SIZE];
    int byteCount = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        char byte = 0;
        for (int bitCount = 0; bitCount < 8; bitCount++) {
            byte = byte << 1;
            if (image[byteCount] & 1) {
                byte = byte | 1;
            } else {
                byte = byte | 0;
            }
            byteCount++;
        }
        decryptedData[i] = byte;
    }

    decryptData(decryptedData, key);
    printf("\n\nExtracted Data: %s\n", decryptedData);
}

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];

    printf("Enter a message to hide in the image (less than %d characters):\n", MAX_SIZE / 8);
    fgets(message, MAX_SIZE, stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter a key to encrypt the message:\n");
    fgets(key, MAX_SIZE, stdin);
    key[strcspn(key, "\n")] = 0;

    FILE *fp;
    fp = fopen("paranoid_image.bmp", "rb");
    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    int bytesRead = fread(image, 1, MAX_SIZE, fp);
    fclose(fp);
    if (bytesRead <= 0) {
        printf("Error reading image\n");
        return 1;
    }

    hideDataInImage(message, key);

    fp = fopen("paranoid_image.bmp", "wb");
    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    fwrite(image, 1, MAX_SIZE, fp);
    fclose(fp);

    printf("\nData successfully hidden in the image\n");

    fp = fopen("paranoid_image.bmp", "rb");
    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    bytesRead = fread(image, 1, MAX_SIZE, fp);
    fclose(fp);
    if (bytesRead <= 0) {
        printf("Error reading image\n");
        return 1;
    }

    extractDataFromImage(key);

    return 0;
}