//FormAI DATASET v1.0 Category: Image Steganography ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// Function to set the least significant bit of a given byte
unsigned char setLSB(unsigned char byte, unsigned char bit) {
    return (byte & 0xFE) | bit;
}

// Function to get the least significant bit of a given byte
unsigned char getLSB(unsigned char byte) {
    return byte & 0x01;
}

// Function to hide a message in an image using LSB steganography
void hideMessage(char *message, FILE *imageFile) {
    // Read the header of the image file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);

    // Create a new image file to write the modified data
    FILE *outFile = fopen("stego_image.bmp", "wb");
    fwrite(header, sizeof(unsigned char), 54, outFile);

    // Get the size of the message in bytes
    int messageSize = strlen(message);

    // Write the size of the message at the beginning of the image data
    fwrite(&messageSize, sizeof(int), 1, outFile);

    // Loop through each byte of the image data, hiding one bit of the message in each byte
    unsigned char byte;
    unsigned char bit;
    int i = 0;
    while (fread(&byte, sizeof(unsigned char), 1, imageFile) == 1) {
        // Get the next bit of the message
        if (i < messageSize) {
            bit = getLSB((unsigned char)message[i]);
        } else {
            bit = 0;
        }

        // Set the least significant bit of the byte to the message bit
        byte = setLSB(byte, bit);

        // Write the modified byte to the output file
        fwrite(&byte, sizeof(unsigned char), 1, outFile);

        // Increment the message bit index
        i++;
    }

    // Close both files
    fclose(imageFile);
    fclose(outFile);
}

// Function to retrieve a message hidden in an image using LSB steganography
char *retrieveMessage(FILE *imageFile) {
    // Read the first 54 bytes of the image file (the header)
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);

    // Get the size of the message from the image data
    int messageSize;
    fread(&messageSize, sizeof(int), 1, imageFile);

    // Allocate memory for the message
    char *message = (char *)malloc((messageSize + 1) * sizeof(char));
    message[messageSize] = '\0';

    // Loop through the image data, retrieving one bit of the message from each byte
    unsigned char byte;
    unsigned char bit;
    int i = 0;
    while (fread(&byte, sizeof(unsigned char), 1, imageFile) == 1) {
        // Get the least significant bit of the byte
        bit = getLSB(byte);

        // Set the corresponding bit of the message
        if (i < messageSize) {
            message[i] = (char)(bit + '0');
        }

        // Increment the message bit index
        i++;
    }

    // Close the file and return the retrieved message
    fclose(imageFile);
    return message;
}

// Main function for testing steganography functions
int main() {
    // Hide a message in an image file
    FILE *imageFile = fopen("test_image.bmp", "rb");
    char *message = "This is a secret message!";
    hideMessage(message, imageFile);

    // Retrieve the message from the modified image file
    imageFile = fopen("stego_image.bmp", "rb");
    char *retrievedMessage = retrieveMessage(imageFile);

    // Print the retrieved message and free the allocated memory
    printf("Retrieved message: %s\n", retrievedMessage);
    free(retrievedMessage);

    return 0;
}