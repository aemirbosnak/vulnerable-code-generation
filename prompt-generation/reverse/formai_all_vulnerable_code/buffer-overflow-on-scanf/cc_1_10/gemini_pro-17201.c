//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Ask the user for the image file and message to hide
    char image_file[100], message[100];
    printf("Enter the name of the image file: ");
    scanf("%s", image_file);
    printf("Enter the message to hide: ");
    scanf("%s", message);

    // Open the image file and read the image data
    FILE *image = fopen(image_file, "rb");
    if (image == NULL) {
        fprintf(stderr, "Error opening image file\n");
        return 1;
    }

    // Get the file size
    fseek(image, 0, SEEK_END);
    long file_size = ftell(image);
    fseek(image, 0, SEEK_SET);

    // Check if the message is too large to fit in the image
    if (strlen(message) > file_size) {
        fprintf(stderr, "Error: Message is too large to fit in the image\n");
        return 1;
    }

    // Hide the message in the image
    int i, j, k;
    for (i = 0, j = 0; i < file_size && j < strlen(message); i++) {
        // Get the pixel value
        unsigned char pixel[3];
        fread(pixel, 1, 3, image);

        // Hide the message bit by bit
        for (k = 0; k < 3 && j < strlen(message); k++) {
            if (message[j] == '0') {
                pixel[k] &= ~1;
            } else {
                pixel[k] |= 1;
            }
            j++;
        }

        // Write the modified pixel value back to the image
        fseek(image, i * 3, SEEK_SET);
        fwrite(pixel, 1, 3, image);
    }

    // Close the image file
    fclose(image);

    // Ask the user for the output file name
    char output_file[100];
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // Open the output file and write the modified image data
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file\n");
        return 1;
    }

    // Get the file size
    fseek(image, 0, SEEK_END);
    long output_file_size = ftell(image);
    fseek(image, 0, SEEK_SET);

    // Write the modified image data to the output file
    for (i = 0; i < output_file_size; i++) {
        unsigned char byte;
        fread(&byte, 1, 1, image);
        fwrite(&byte, 1, 1, output);
    }

    // Close the output file
    fclose(output);

    // Tell the user that the message has been hidden
    printf("Message successfully hidden in the image!\n");

    return 0;
}