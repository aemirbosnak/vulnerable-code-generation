//FormAI DATASET v1.0 Category: Image compression ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data numbers
#define NUM_ROWS 10
#define NUM_COLS 10

// Compression constants
#define COMPRESSED_ROWS 5
#define BITS_PER_NUM 3

// Some happy messages
#define HAPPY_MSG_1 "Yay! We're compressing some images!\n"
#define HAPPY_MSG_2 "Woohoo, let's see some magic!\n"
#define HAPPY_MSG_3 "Aren't you glad we're doing this together?\n"
#define HAPPY_MSG_4 "Ready, set, go! Let's make those images smaller!\n"

// The actual image data
int imageData[NUM_ROWS][NUM_COLS] = {
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
    {255, 0, 0, 0, 255, 255, 255, 255, 255, 255},
    {255, 0, 0, 0, 0, 0, 255, 255, 255, 255},
    {255, 0, 0, 0, 0, 0, 0, 0, 255, 255},
    {255, 0, 0, 0, 0, 0, 0, 0, 0, 255},
    {255, 255, 0, 0, 0, 0, 0, 0, 0, 255},
    {255, 255, 255, 0, 0, 0, 0, 0, 0, 255},
    {255, 255, 255, 255, 0, 0, 0, 0, 0, 255},
    {255, 255, 255, 255, 255, 0, 0, 0, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255}
};

// The compressed image data
unsigned char compressedData[COMPRESSED_ROWS * NUM_COLS * BITS_PER_NUM / 8];

// The actual compression function
void compressImage() {
    printf(HAPPY_MSG_1);
    printf(HAPPY_MSG_2);
    printf(HAPPY_MSG_3);
    printf(HAPPY_MSG_4);
    // Let's loop through the rows that we need to compress
    for (int i = 0; i < COMPRESSED_ROWS; i++) {
        // Let's loop through each column and compress the data
        for (int j = 0; j < NUM_COLS; j += (8 / BITS_PER_NUM)) {
            // Let's extract the bits we need and combine them into one byte
            unsigned char compressedByte = 0;
            for (int k = 0; k < 8 / BITS_PER_NUM; k++) {
                compressedByte <<= BITS_PER_NUM;
                compressedByte |= imageData[i][j + k] & ((1 << BITS_PER_NUM) - 1);
            }
            // Let's store the compressed byte in our compressed data array
            compressedData[i * NUM_COLS * BITS_PER_NUM / 8 + j * BITS_PER_NUM / 8] = compressedByte;
        }
    }
}

// The actual decompression function
void decompressImage() {
    // Let's create a new array to store the decompressed data
    int decompressedData[NUM_ROWS][NUM_COLS];
    memset(decompressedData, 0, NUM_ROWS * NUM_COLS * sizeof(int));
    // Let's loop through the rows that we need to decompress
    for (int i = 0; i < COMPRESSED_ROWS; i++) {
        // Let's loop through each column and decompress the data
        for (int j = 0; j < NUM_COLS; j += (8 / BITS_PER_NUM)) {
            // Let's extract the compressed byte from our compressed data array
            unsigned char compressedByte = compressedData[i * NUM_COLS * BITS_PER_NUM / 8 + j * BITS_PER_NUM / 8];
            // Let's loop through each bit and decompress the data
            for (int k = 8 / BITS_PER_NUM - 1; k >= 0; k--) {
                decompressedData[i][j + k] = compressedByte & ((1 << BITS_PER_NUM) - 1);
                compressedByte >>= BITS_PER_NUM;
            }
        }
    }
    // Let's print out the decompressed image data
    printf("Decompressed image data:\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", decompressedData[i][j]);
        }
        printf("\n");
    }
}

// The main function
int main() {
    // Let's print out the original image data
    printf("Original image data:\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", imageData[i][j]);
        }
        printf("\n");
    }
    // Let's compress the image data
    compressImage();
    // Let's decompress the image data
    decompressImage();
    // Let's exit the program
    return 0;
}