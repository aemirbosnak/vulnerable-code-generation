//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 512

typedef struct {
    unsigned char r, g, b;
} pixel;

int main() {
    FILE *image, *message;
    int i, j, k, size, msg_len, bit;
    pixel img[MAX_SIZE][MAX_SIZE];

    // Open the image and message files
    image = fopen("image.bmp", "rb");
    message = fopen("message.txt", "rb");

    // Check if the files were opened successfully
    if (image == NULL || message == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    // Get the size of the image
    fseek(image, 18, SEEK_SET);
    fread(&size, sizeof(int), 1, image);

    // Get the length of the message
    fseek(message, 0, SEEK_END);
    msg_len = ftell(message);

    // Check if the message is too long to fit in the image
    if (msg_len > size * size * 3 - 54) {
        printf("Error: Message is too long\n");
        return 1;
    }

    // Read the image data into the array
    fseek(image, 54, SEEK_SET);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            fread(&img[i][j], sizeof(pixel), 1, image);
        }
    }

    // Read the message data into a buffer
    char *msg = malloc(msg_len);
    fseek(message, 0, SEEK_SET);
    fread(msg, 1, msg_len, message);

    // Embed the message in the image data
    k = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            for (bit = 0; bit < 3; bit++) {
                if (k < msg_len) {
                    img[i][j].b &= ~1;
                    img[i][j].b |= (msg[k] >> bit) & 1;
                    k++;
                }
            }
        }
    }

    // Write the modified image data back to the file
    fseek(image, 54, SEEK_SET);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            fwrite(&img[i][j], sizeof(pixel), 1, image);
        }
    }

    // Close the files
    fclose(image);
    fclose(message);

    return 0;
}