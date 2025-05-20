//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

// Define the pixel structure
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

// Function to hide the message in the image
void hide_message(char *message, Pixel *image, int message_length) {
    int i, j;
    for (i = 0; i < message_length; i++) {
        // Encode the message character into the image
        for (j = 0; j < 8; j++) {
            // Set the least significant bit of the pixel to the jth bit of the message character
            image[i * 8 + j].r = message[i] & (1 << j);
        }
    }
}

// Function to extract the message from the image
void extract_message(Pixel *image, char *message, int message_length) {
    int i, j;
    for (i = 0; i < message_length; i++) {
        // Extract the jth bit of the message from the image
        for (j = 0; j < 8; j++) {
            // Set the jth bit of the message character to the least significant bit of the pixel
            message[i] |= (image[i * 8 + j].r << j);
        }
    }
}

int main() {
    // Load the image
    Pixel *image = (Pixel *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(Pixel));
    if (!image) {
        printf("Failed to allocate memory for the image\n");
        return 1;
    }

    // Read the image from the file
    FILE *fp = fopen("image.bmp", "rb");
    if (!fp) {
        printf("Failed to open the image file\n");
        return 1;
    }
    fread(image, sizeof(Pixel), IMAGE_WIDTH * IMAGE_HEIGHT, fp);
    fclose(fp);

    // Hide the message in the image
    char *message = "Hello, World!";
    int message_length = strlen(message);
    hide_message(message, image, message_length);

    // Save the modified image to a file
    fp = fopen("hidden_image.bmp", "wb");
    if (!fp) {
        printf("Failed to open the output file\n");
        return 1;
    }
    fwrite(image, sizeof(Pixel), IMAGE_WIDTH * IMAGE_HEIGHT, fp);
    fclose(fp);

    // Extract the message from the image
    char *extracted_message = (char *)malloc(message_length + 1);
    if (!extracted_message) {
        printf("Failed to allocate memory for the extracted message\n");
        return 1;
    }
    extract_message(image, extracted_message, message_length);
    extracted_message[message_length] = '\0';

    // Print the extracted message
    printf("Extracted message: %s\n", extracted_message);

    // Free the memory
    free(image);
    free(extracted_message);

    return 0;
}