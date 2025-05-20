//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing image details
typedef struct {
    unsigned char r, g, b;  // RGB channels
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;  // Pointer to pixel data
} Image;

// Function to read a PPM image file
Image* readPPM(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%2s", format);
    if (strcmp(format, "P6") != 0) {
        fclose(file);
        fprintf(stderr, "Unsupported file format\n");
        return NULL;
    }

    Image *img = (Image*)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file);  // Read the newline after maxval

    img->data = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

// Function to write a PPM image file
void writePPM(const char* filename, Image* img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Function to encode secret message into the least significant bits of pixels
void encodeMessage(Image* img, const char* message) {
    int messageLength = strlen(message);
    if (messageLength == 0) return;

    // Encode message length in the first pixel's least significant bit
    img->data[0].r = (img->data[0].r & 0xFE) | ((messageLength >> 7) & 0x01);
    img->data[0].g = (img->data[0].g & 0xFE) | ((messageLength >> 6) & 0x01);
    img->data[0].b = (img->data[0].b & 0xFE) | ((messageLength >> 5) & 0x01);

    int pixelIndex = 1;  // Start encoding from second pixel
    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            if (pixelIndex >= img->width * img->height) {
                fprintf(stderr, "Image not large enough to hold the message\n");
                return;
            }
            img->data[pixelIndex].r = (img->data[pixelIndex].r & 0xFE) | ((message[i] >> (7 - j)) & 0x01);
            pixelIndex++;
        }
    }
}

// Function to decode the secret message from the image
char* decodeMessage(Image* img) {
    int messageLength = 0;

    // Get message length from the first pixel's least significant bits
    messageLength |= (img->data[0].r & 0x01) << 7;
    messageLength |= (img->data[0].g & 0x01) << 6;
    messageLength |= (img->data[0].b & 0x01) << 5;

    char *message = (char*)malloc(messageLength + 1);
    if (!message) return NULL;
    message[messageLength] = '\0';

    int pixelIndex = 1;
    for (int i = 0; i < messageLength; i++) {
        char byte = 0;
        for (int j = 0; j < 8; j++) {
            if (pixelIndex >= img->width * img->height) {
                free(message);
                return NULL;
            }
            byte |= (img->data[pixelIndex].r & 0x01) << (7 - j);
            pixelIndex++;
        }
        message[i] = byte;
    }
    return message;
}

// Main function for execution
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encode|decode> <image.ppm> <message/output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = readPPM(argv[2]);
    if (!img) return EXIT_FAILURE;

    if (strcmp(argv[1], "encode") == 0) {
        encodeMessage(img, argv[3]);
        writePPM(argv[3], img);
        printf("Message encoded in %s\n", argv[3]);
    } else if (strcmp(argv[1], "decode") == 0) {
        char *message = decodeMessage(img);
        if (message) {
            printf("Decoded message: %s\n", message);
            free(message);
        } else {
            fprintf(stderr, "Failed to decode message\n");
        }
    } else {
        fprintf(stderr, "Invalid command. Use 'encode' or 'decode'.\n");
    }

    free(img->data);
    free(img);
    return EXIT_SUCCESS;
}