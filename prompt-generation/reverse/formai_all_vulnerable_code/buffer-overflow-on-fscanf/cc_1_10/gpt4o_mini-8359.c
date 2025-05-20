//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024 * 1024 * 3  // Max size for the PPM image (RGB)
#define MAX_MSG_SIZE 255                 // Max size for the embedding message

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

// Function prototypes
Image* loadPPM(const char *filename);
void savePPM(const char *filename, Image *image);
void embedWatermark(Image *image, const char *message);
char* extractWatermark(Image *image);

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <input_image.ppm> <output_image.ppm> <watermark_message>\n", argv[0]);
        return 1;
    }

    // Load the image
    Image *image = loadPPM(argv[1]);
    if (!image) {
        fprintf(stderr, "Failed to load image %s\n", argv[1]);
        return 1;
    }

    // Embed the watermark
    embedWatermark(image, argv[3]);

    // Save the watermarked image
    savePPM(argv[2], image);

    // Extract the watermark
    char *extractedMessage = extractWatermark(image);
    printf("Extracted Watermark: %s\n", extractedMessage);

    // Clean up
    free(image->pixels);
    free(image);
    free(extractedMessage);
    return 0;
}

Image* loadPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("File opening failed");
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Invalid PPM file format.\n");
        fclose(file);
        return NULL;
    }

    Image *image = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &image->width, &image->height);
    int maxColor;
    fscanf(file, "%d", &maxColor);
    fgetc(file); // Consume the newline character

    image->pixels = (Pixel *)malloc(image->width * image->height * sizeof(Pixel));
    fread(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);

    return image;
}

void savePPM(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("File opening failed");
        return;
    }

    fprintf(file, "P6\n");
    fprintf(file, "%d %d\n", image->width, image->height);
    fprintf(file, "255\n");

    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void embedWatermark(Image *image, const char *message) {
    int msgLen = strlen(message);
    if (msgLen > MAX_MSG_SIZE) {
        fprintf(stderr, "Message too long to embed.\n");
        return;
    }

    // Embed length of message in the first pixel
    image->pixels[0].r = msgLen;

    // Embed the message into the least significant bits
    for (int i = 0; i < msgLen; i++) {
        Pixel *pixel = &image->pixels[i + 1]; // Skip the first pixel
        pixel->r = (pixel->r & 0xFE) | ((message[i] >> 7) & 0x01);
        pixel->g = (pixel->g & 0xFE) | ((message[i] >> 6) & 0x01);
        pixel->b = (pixel->b & 0xFE) | ((message[i] >> 5) & 0x01);
    }
}

char* extractWatermark(Image *image) {
    int msgLen = image->pixels[0].r;
    if (msgLen > MAX_MSG_SIZE) {
        fprintf(stderr, "Invalid message length in watermark extraction.\n");
        return NULL;
    }

    char *message = (char *)malloc((msgLen + 1) * sizeof(char));
    message[msgLen] = '\0'; // Null-terminate the string  

    // Extract the message from the least significant bits
    for (int i = 0; i < msgLen; i++) {
        Pixel *pixel = &image->pixels[i + 1]; // Skip the first pixel
        message[i] = 0;
        message[i] |= ((pixel->r & 0x01) << 7);
        message[i] |= ((pixel->g & 0x01) << 6);
        message[i] |= ((pixel->b & 0x01) << 5);
    }

    return message;
}