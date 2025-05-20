//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024
#define MAX_MSG_SIZE 256

// Function to convert a message to a binary string
char *msgToBinary(char *msg) {
    int len = strlen(msg);
    char *binary = (char *)malloc(len * 8 + 1);
    for (int i = 0; i < len; i++) {
        int c = msg[i];
        for (int j = 0; j < 8; j++) {
            binary[i * 8 + j] = (c & (1 << (7 - j))) ? '1' : '0';
        }
    }
    binary[len * 8] = '\0';
    return binary;
}

// Function to embed a message in an image
void embedMessage(char *image, char *msg) {
    // Convert the message to a binary string
    char *binary = msgToBinary(msg);

    // Get the length of the message
    int len = strlen(binary);

    // Iterate over the pixels of the image
    for (int i = 0; i < len; i++) {
        // Get the pixel value
        int pixel = image[i];

        // Modify the least significant bit of the pixel to match the message bit
        image[i] = (pixel & ~1) | (binary[i] - '0');
    }

    // Free the binary string
    free(binary);
}

// Function to extract a message from an image
char *extractMessage(char *image) {
    // Get the length of the image
    int len = strlen(image);

    // Create a buffer to store the extracted message
    char *msg = (char *)malloc(len / 8 + 1);

    // Iterate over the pixels of the image
    for (int i = 0; i < len; i++) {
        // Get the pixel value
        int pixel = image[i];

        // Extract the least significant bit of the pixel
        msg[i / 8] |= (pixel & 1) << (7 - (i % 8));
    }

    // Null-terminate the message
    msg[len / 8] = '\0';

    // Return the extracted message
    return msg;
}

// Main function
int main() {
    // Get the input image
    char *image = (char *)malloc(MAX_SIZE);
    printf("Enter the input image: ");
    scanf("%s", image);

    // Get the message to be embedded
    char *msg = (char *)malloc(MAX_MSG_SIZE);
    printf("Enter the message to be embedded: ");
    scanf("%s", msg);

    // Embed the message in the image
    embedMessage(image, msg);

    // Save the watermarked image
    printf("Saving the watermarked image as \"watermarked.bmp\"...\n");
    FILE *fp = fopen("watermarked.bmp", "wb");
    fwrite(image, 1, strlen(image), fp);
    fclose(fp);

    // Extract the message from the watermarked image
    char *extractedMsg = extractMessage(image);

    // Print the extracted message
    printf("Extracted message: %s\n", extractedMsg);

    // Free the allocated memory
    free(image);
    free(msg);
    free(extractedMsg);

    return 0;
}