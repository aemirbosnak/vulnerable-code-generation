//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>

#define IMAGE_WIDTH 256
#define IMAGE_HEIGHT 256
#define MAX_SIZE 1000000
#define PIXEL_VALUE 128

// Function to read image file and store pixel values in a 2D array
void readImage(char* filename, int image[IMAGE_WIDTH][IMAGE_HEIGHT]) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    int count = 0;
    while (fgetc(fp)!= EOF) {
        if (count >= MAX_SIZE) {
            printf("Error: Image file is too large\n");
            exit(1);
        }
        int pixelValue = fgetc(fp);
        if (pixelValue == EOF) {
            printf("Error: Image file is corrupted\n");
            exit(1);
        }
        image[count / IMAGE_WIDTH][count % IMAGE_WIDTH] = pixelValue;
        count++;
    }
    fclose(fp);
}

// Function to hide message in image using steganography
void hideMessage(char* message, int messageLength, int image[IMAGE_WIDTH][IMAGE_HEIGHT]) {
    int i = 0, j = 0, k = 0;
    while (i < IMAGE_HEIGHT && j < IMAGE_WIDTH) {
        if (image[i][j] == PIXEL_VALUE) {
            int bit = message[k] - 'a';
            if (bit < 0 || bit > 1) {
                printf("Error: Invalid message\n");
                exit(1);
            }
            image[i][j] += bit;
            k++;
        }
        j++;
    }
}

// Function to extract hidden message from image using steganography
void extractMessage(int image[IMAGE_WIDTH][IMAGE_HEIGHT], char* message) {
    int i = 0, j = 0, k = 0;
    while (i < IMAGE_HEIGHT && j < IMAGE_WIDTH) {
        if (image[i][j]!= PIXEL_VALUE) {
            int bit = image[i][j] - PIXEL_VALUE;
            if (bit < 0 || bit > 1) {
                printf("Error: Invalid image\n");
                exit(1);
            }
            message[k] = bit + 'a';
            k++;
        }
        j++;
    }
    message[k] = '\0';
}

// Function to display image as ASCII art
void displayImage(int image[IMAGE_WIDTH][IMAGE_HEIGHT]) {
    int i = 0, j = 0;
    while (i < IMAGE_HEIGHT) {
        while (j < IMAGE_WIDTH) {
            printf("%c", image[i][j] + 'a');
            j++;
        }
        printf("\n");
        i++;
    }
}

int main() {
    char message[100];
    printf("Enter message to hide: ");
    scanf("%s", message);
    int messageLength = strlen(message);
    if (messageLength > IMAGE_WIDTH * IMAGE_HEIGHT / 2) {
        printf("Error: Message is too long\n");
        exit(1);
    }
    char imageFilename[100];
    printf("Enter image filename: ");
    scanf("%s", imageFilename);
    int image[IMAGE_WIDTH][IMAGE_HEIGHT];
    readImage(imageFilename, image);
    hideMessage(message, messageLength, image);
    displayImage(image);
    char extractedMessage[100];
    extractMessage(image, extractedMessage);
    printf("\nExtracted message: %s\n", extractedMessage);
    return 0;
}