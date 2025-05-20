//FormAI DATASET v1.0 Category: Image Steganography ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum image size and maximum message size
#define MAX_IMG_SIZE 1000
#define MAX_MSG_SIZE 500

// Struct for holding image data and metadata
typedef struct {
    int width; // Width of image in pixels
    int height; // Height of image in pixels
    int pixels[MAX_IMG_SIZE][MAX_IMG_SIZE]; // Image pixel data
} Image;

// Function to read image from file
Image readImage(char* fileName) {
    Image img;
    FILE* file = fopen(fileName, "r");
    if (file != NULL) {
        // Read image width and height from file
        fscanf(file, "%d %d", &img.width, &img.height);
        // Read pixel data from file
        for (int i = 0; i < img.height; i++) {
            for (int j = 0; j < img.width; j++) {
                fscanf(file, "%d", &img.pixels[i][j]);
            }
        }
        fclose(file);
    }
    return img;
}

// Function to write image to file
void writeImage(char* fileName, Image img) {
    FILE* file = fopen(fileName, "w");
    if (file != NULL) {
        // Write image width and height to file
        fprintf(file, "%d %d\n", img.width, img.height);
        // Write pixel data to file
        for (int i = 0; i < img.height; i++) {
            for (int j = 0; j < img.width; j++) {
                fprintf(file, "%d ", img.pixels[i][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
}

// Function to hide message in image using decentralized steganography
void hideMessage(Image* img, char* message) {
    int len = strlen(message);
    // Check if message will fit in image
    if ((len * 8) > (img->width * img->height)) {
        printf("Error: message too large for image\n");
    }
    else {
        // Convert message to bit string and pad with zeroes
        char bitString[MAX_MSG_SIZE * 8];
        memset(bitString, 0, sizeof(bitString));
        for (int i = 0; i < len; i++) {
            int asciiCode = (int) message[i];
            // Convert ascii code to binary and append to bit string
            for (int j = 0; j < 8; j++) {
                int bit = (asciiCode >> (7 - j)) & 1;
                bitString[(i * 8) + j] = bit + '0';
            }
        }
        // Embed bit string in image by modifying LSB of each pixel
        int bitIndex = 0;
        for (int i = 0; i < img->height; i++) {
            for (int j = 0; j < img->width; j++) {
                int bit = bitString[bitIndex] - '0'; // Get bit to embed
                if (bit == 1) {
                    // Set LSB of pixel to 1
                    img->pixels[i][j] |= 1;
                }
                else {
                    // Set LSB of pixel to 0
                    img->pixels[i][j] &= 254;
                }
                bitIndex++;
                if (bitIndex >= (len * 8)) {
                    // Message embedded, return from function
                    return;
                }
            }
        }
    }
}

// Function to extract message from image using decentralized steganography
char* extractMessage(Image img) {
    char* message = (char*) malloc(MAX_MSG_SIZE);
    memset(message, 0, sizeof(message));
    int bitIndex = 0;
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            int lsb = img.pixels[i][j] & 1; // Get LSB of pixel
            if (lsb == 1) {
                // Set corresponding bit in message to 1
                message[bitIndex / 8] |= (1 << (7 - (bitIndex % 8)));
            }
            bitIndex++;
            if (bitIndex >= (MAX_MSG_SIZE * 8)) {
                // Message extracted, return from function
                return message;
            }
        }
    }
    return message;
}

int main() {
    Image img = readImage("image.txt");
    char message[] = "Hello, this is a secret message!";
    hideMessage(&img, message);
    writeImage("encoded_image.txt", img);
    Image encodedImg = readImage("encoded_image.txt");
    char* extractedMsg = extractMessage(encodedImg);
    printf("Extracted message: %s\n", extractedMsg);
    free(extractedMsg);
    return 0;
}