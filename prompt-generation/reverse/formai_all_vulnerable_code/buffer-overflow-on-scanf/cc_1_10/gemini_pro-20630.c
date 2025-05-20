//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define SIZE 512

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

void hide(pixel *image, char *message) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (message[k] != '\0') {
        image[i].red = (image[i].red & 0xF8) | ((message[k] >> 3) & 0x07);
        image[i].green = (image[i].green & 0xF8) | ((message[k] >> 0) & 0x07);

        i++;
        k++;

        if (i == SIZE) {
            i = 0;
            j++;
        }
    }
}

void reveal(pixel *image, char *message) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (image[i].red != 0 || image[i].green != 0) {
        message[k] = ((image[i].red & 0x07) << 3) | (image[i].green & 0x07);

        i++;
        k++;

        if (i == SIZE) {
            i = 0;
            j++;
        }
    }

    message[k] = '\0';
}

int main() {
    pixel image[SIZE * SIZE];
    char message[100];

    // Read the image from a file
    FILE *imageFile = fopen("image.bmp", "rb");
    fread(image, sizeof(pixel), SIZE * SIZE, imageFile);
    fclose(imageFile);

    // Read the message from the user
    printf("Enter the message you want to hide: ");
    scanf("%s", message);

    // Hide the message in the image
    hide(image, message);

    // Write the image to a file
    FILE *outputImageFile = fopen("output_image.bmp", "wb");
    fwrite(image, sizeof(pixel), SIZE * SIZE, outputImageFile);
    fclose(outputImageFile);

    // Read the message from the image
    char revealedMessage[100];
    reveal(image, revealedMessage);

    // Print the revealed message
    printf("The revealed message is: %s", revealedMessage);

    return 0;
}