//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned char uchar;

int main(void) {
    // Open the image and message files
    FILE *image = fopen("image.bmp", "rb");
    if (!image) {
        perror("Error opening image file");
        return 1;
    }
    FILE *message = fopen("message.txt", "rb");
    if (!message) {
        perror("Error opening message file");
        return 1;
    }

    // Read the BMP header
    uchar header[54];
    fread(header, 54, 1, image);

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Calculate the number of pixels in the image
    int num_pixels = width * height;

    // Read the message
    char *message_text;
    long message_size = 0;
    fseek(message, 0L, SEEK_END);
    message_size = ftell(message);
    rewind(message);
    message_text = malloc(message_size);
    fread(message_text, message_size, 1, message);

    // Encode the message into the image data
    int message_index = 0;
    for (int i = 54; i < num_pixels * 3; i++) {
        uchar pixel = header[i];
        // Replace the least significant bit of the pixel with a bit from the message
        pixel &= 0xFE;
        pixel |= (message_text[message_index] >> 7) & 0x01;
        header[i] = pixel;
        message_index++;
        if (message_index == message_size) {
            break;
        }
    }

    // Write the modified BMP header to the file
    fwrite(header, 54, 1, image);

    // Write the rest of the image data to the file
    fseek(image, 54, SEEK_SET);
    uchar data[num_pixels * 3];
    fread(data, num_pixels * 3, 1, image);
    fwrite(data, num_pixels * 3, 1, image);

    // Close the image and message files
    fclose(image);
    fclose(message);

    printf("Message successfully encoded into image.\n");
    return 0;
}