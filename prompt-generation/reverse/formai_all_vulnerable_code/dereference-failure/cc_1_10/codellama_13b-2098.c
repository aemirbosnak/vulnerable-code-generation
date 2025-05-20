//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: active
// Image Steganography Example Program in Active Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to hide message in an image
void hideMessage(char *imagePath, char *message) {
    // Open the image file
    FILE *imageFile = fopen(imagePath, "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open image file.\n");
        return;
    }

    // Get the image size
    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);

    // Read the image data
    char *imageData = (char *)malloc(imageSize);
    fread(imageData, 1, imageSize, imageFile);
    fclose(imageFile);

    // Get the message size
    int messageSize = strlen(message);

    // Hide the message in the image
    for (int i = 0; i < messageSize; i++) {
        // Hide the message bit by bit
        int bit = message[i] & 0x01;
        int index = (i * 8) % imageSize;
        imageData[index] ^= bit;
    }

    // Write the modified image data back to the file
    FILE *outputFile = fopen("modified_image.jpg", "wb");
    fwrite(imageData, 1, imageSize, outputFile);
    fclose(outputFile);

    // Free the memory
    free(imageData);
}

// Function to extract message from an image
void extractMessage(char *imagePath) {
    // Open the image file
    FILE *imageFile = fopen(imagePath, "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open image file.\n");
        return;
    }

    // Get the image size
    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);

    // Read the image data
    char *imageData = (char *)malloc(imageSize);
    fread(imageData, 1, imageSize, imageFile);
    fclose(imageFile);

    // Extract the message from the image
    char *message = (char *)malloc(imageSize / 8);
    for (int i = 0; i < imageSize / 8; i++) {
        // Extract the message bit by bit
        int bit = imageData[i * 8] & 0x01;
        message[i] = bit;
    }

    // Write the message to the console
    printf("Message: %s\n", message);

    // Free the memory
    free(imageData);
    free(message);
}

int main() {
    // Hide a message in an image
    char *imagePath = "image.jpg";
    char *message = "This is a hidden message.";
    hideMessage(imagePath, message);

    // Extract the message from the image
    imagePath = "modified_image.jpg";
    extractMessage(imagePath);

    return 0;
}