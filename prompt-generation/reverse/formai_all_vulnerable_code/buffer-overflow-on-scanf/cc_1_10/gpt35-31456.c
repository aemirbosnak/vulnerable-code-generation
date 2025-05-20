//FormAI DATASET v1.0 Category: Image Steganography ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global constants
#define MAX_IMAGE_SIZE 1000000
#define FILENAME_SIZE 256
#define MAX_MESSAGE_SIZE 10000

// Function to read image file
int readImage(char filename[], char image[]) {
    FILE *file = fopen(filename, "rb");

    // Check if file exists
    if (file == NULL) {
        printf("Error: Could not open file %s", filename);
        return -1;
    }

    // Get file size
    fseek(file, 0L, SEEK_END);
    long int filesize = ftell(file);
    rewind(file);

    // Check if file is too big
    if (filesize > MAX_IMAGE_SIZE) {
        printf("Error: Image file is too big");
        fclose(file);
        return -1;
    }

    // Read file into memory
    size_t result = fread(image, 1, filesize, file);
    if (result != filesize) {
        printf("Error: Could not read image file");
        fclose(file);
        return -1;
    }

    fclose(file);
    return (int)filesize;
}

// Function to write image file
int writeImage(char filename[], char image[], int filesize) {
    FILE *file = fopen(filename, "wb");

    // Check if file exists
    if (file == NULL) {
        printf("Error: Could not open file %s", filename);
        return -1;
    }

    // Write image to file
    size_t result = fwrite(image, 1, filesize, file);
    if (result != filesize) {
        printf("Error: Could not write image file");
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}

// Function to encode message into image
int encode(char message[], char image[], int imageSize) {
    // Check if message is too big
    int messageSize = strlen(message);
    if (messageSize > MAX_MESSAGE_SIZE) {
        printf("Error: Message is too big");
        return -1;
    }

    // Loop through message and encode each character
    for (int i = 0; i < messageSize; i++) {
        char c = message[i];

        // Get LSB of current byte in image
        char lsb = image[i] & 1;

        // If LSB is different from bit in message, flip LSB
        if (((c >> 7) & 1) != lsb) {
            image[i] ^= 1;
        }

        // If last character in message, add null terminator
        if (i == messageSize - 1) {
            image[i + 1] = '\0';
            return 0;
        }
    }

    return -1;
}

// Function to decode message from image
int decode(char message[], char image[], int imageSize) {
    // Loop through image and decode each character
    for (int i = 0; i < MAX_MESSAGE_SIZE; i++) {
        // Get LSB of current byte in image
        char lsb = image[i] & 1;

        // Shift current bit into message
        message[i >> 3] |= lsb << (7 - (i & 7));

        // If null terminator found, end decoding
        if (message[i >> 3] == '\0') {
            return 0;
        }
    }

    return -1;
}

int main() {
    char filename[FILENAME_SIZE];
    char message[MAX_MESSAGE_SIZE];
    char image[MAX_IMAGE_SIZE];
    int imageSize;

    printf("Enter filename of image to modify: ");
    scanf("%s", filename);

    // Read image file into memory
    imageSize = readImage(filename, image);
    if (imageSize == -1) {
        return -1;
    }

    printf("Enter message to hide in image: ");
    scanf(" %[^\n]", message);

    // Encode message into image
    int result = encode(message, image, imageSize);
    if (result == -1) {
        return -1;
    }

    printf("Enter filename to save modified image as: ");
    scanf("%s", filename);

    // Write modified image to file
    result = writeImage(filename, image, imageSize);
    if (result == -1) {
        return -1;
    }

    printf("Message encoded successfully!\n");

    // Decode message from image
    printf("Do you want to decode the message from the image? (y/n): ");
    char option;
    scanf(" %c", &option);

    if (option == 'y' || option == 'Y') {
        char decodedMessage[MAX_MESSAGE_SIZE] = {0};

        result = decode(decodedMessage, image, imageSize);
        if (result == -1) {
            return -1;
        }

        printf("Decoded message: %s\n", decodedMessage);
    }

    return 0;
}