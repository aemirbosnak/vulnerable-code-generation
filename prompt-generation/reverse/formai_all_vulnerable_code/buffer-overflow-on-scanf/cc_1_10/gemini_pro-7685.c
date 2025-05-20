//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int main() {
    // Get the image file name from the user.
    char image_file_name[256];
    printf("Enter the image file name: ");
    scanf("%s", image_file_name);

    // Get the secret message from the user.
    char secret_message[MAX_MESSAGE_LENGTH];
    printf("Enter the secret message: ");
    scanf("%s", secret_message);

    // Open the image file.
    FILE *image_file = fopen(image_file_name, "rb+");
    if (image_file == NULL) {
        printf("Error opening the image file.\n");
        return 1;
    }

    // Get the image dimensions.
    int width, height;
    fread(&width, sizeof(int), 1, image_file);
    fread(&height, sizeof(int), 1, image_file);

    // Get the image data.
    pixel *image_data = malloc(width * height * sizeof(pixel));
    fread(image_data, sizeof(pixel), width * height, image_file);

    // Encode the secret message in the image data.
    int message_index = 0;
    for (int i = 0; i < width * height; i++) {
        // Get the current pixel.
        pixel *pixel = &image_data[i];

        // Get the least significant bit of each color channel.
        unsigned char red_lsb = pixel->red & 1;
        unsigned char green_lsb = pixel->green & 1;
        unsigned char blue_lsb = pixel->blue & 1;

        // Set the least significant bit of each color channel to the next bit of the secret message.
        pixel->red = (pixel->red & ~1) | (secret_message[message_index] & 1);
        pixel->green = (pixel->green & ~1) | ((secret_message[message_index] >> 1) & 1);
        pixel->blue = (pixel->blue & ~1) | ((secret_message[message_index] >> 2) & 1);

        // Increment the message index.
        message_index++;

        // If we have reached the end of the secret message, break out of the loop.
        if (message_index == strlen(secret_message)) {
            break;
        }
    }

    // Write the modified image data to the image file.
    fseek(image_file, sizeof(int) * 2, SEEK_SET);
    fwrite(image_data, sizeof(pixel), width * height, image_file);

    // Close the image file.
    fclose(image_file);

    // Free the image data.
    free(image_data);

    printf("The secret message has been successfully encoded in the image.\n");

    return 0;
}