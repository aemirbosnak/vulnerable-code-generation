//FormAI DATASET v1.0 Category: Image Steganography ; Style: happy
// Welcome to my happy Image Steganography program!
// This program allows you to hide a secret message within an image.
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[100];
    printf("Please enter the message you want to hide: ");
    gets(message);

    FILE *image_file = fopen("image.bmp", "rb"); // open image file

    if (image_file == NULL) {
        printf("Failed to open image file. Please make sure it exists.");
        exit(1);
    }

    // read BMP file header and information header

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);
    
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    
    printf("Image size: %d x %d\n", width, height);

    // allocate memory for image data

    int image_size = width * height * 3;
    unsigned char *image_data = (unsigned char*)malloc(sizeof(unsigned char) * image_size);

    // read image data

    fread(image_data, sizeof(unsigned char), image_size, image_file);

    // hide message within image

    int message_len = strlen(message);
    int i, j, k;

    for (i = 0; i < message_len; i++) {
        char c = message[i];
        for (j = 0; j < 8; j++) {
            int bit = (c >> j) & 1;
            for (k = 0; k < 3; k++) {
                image_data[(i * 8 + j) * 3 + k] = (image_data[(i * 8 + j) * 3 + k] & 0xFE) | bit;
            }
        }
    }

    // write hidden message image to file

    FILE *output_file = fopen("hidden_image.bmp", "wb"); // create new file for hidden image

    fwrite(header, sizeof(unsigned char), 54, output_file);
    fwrite(image_data, sizeof(unsigned char), image_size, output_file);

    fclose(image_file);
    fclose(output_file);

    printf("Your message has been successfully hidden within the image!\n");
    printf("You can find the hidden image in 'hidden_image.bmp'.\n");

    free(image_data);

    return 0;
}