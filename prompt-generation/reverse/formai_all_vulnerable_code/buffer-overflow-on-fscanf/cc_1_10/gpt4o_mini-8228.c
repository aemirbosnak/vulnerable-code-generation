//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_VALUE 255
#define HEADER_SIZE 3 // PPM header size (P3, width, height)

typedef struct {
    int width;
    int height;
    unsigned char* pixelData;
} Image;

void writePPM(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P3\n%d %d\n%d\n", img->width, img->height, MAX_COLOR_VALUE);
    for (int i = 0; i < img->width * img->height * 3; ++i) {
        fprintf(file, "%d ", img->pixelData[i]);
    }
    fclose(file);
}

Image* readPPM(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P3") != 0) {
        fclose(file);
        fprintf(stderr, "Unsupported file format\n");
        exit(EXIT_FAILURE);
    }

    Image* img = malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    img->pixelData = malloc(img->width * img->height * 3);
    int maxVal;
    fscanf(file, "%d", &maxVal);

    for (int i = 0; i < img->width * img->height * 3; ++i) {
        fscanf(file, "%hhu", &img->pixelData[i]);
    }
    
    fclose(file);
    return img;
}

void hideMessageInImage(const char* message, Image* img) {
    int msgLen = strlen(message);
    int imgSize = img->width * img->height;

    if (msgLen * 8 > imgSize * 3) {
        fprintf(stderr, "Message is too large to fit in the image!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < msgLen; ++i) {
        for (int j = 0; j < 8; ++j) {
            int pixelIndex = (i * 8 + j) / 3;
            int bit = (message[i] >> (7 - j)) & 1;
            img->pixelData[pixelIndex * 3 + 0] = (img->pixelData[pixelIndex * 3 + 0] & 0xFE) | bit; // Modify the red channel
        }
    }
}

void extractMessageFromImage(Image* img, char* output, int outputSize) {
    int msgIndex = 0;
    unsigned char currentChar = 0;

    for (int i = 0; i < img->width * img->height * 3; ++i) {
        currentChar = (currentChar << 1) | (img->pixelData[i] & 1);
        if ((i + 1) % 8 == 0) {
            output[msgIndex++] = currentChar;
            currentChar = 0;
        }

        if (msgIndex >= outputSize - 1) {
            break;
        }
    }
    output[msgIndex] = '\0';
}

int main() {
    printf("Welcome to the Lively Image Steganography Program!\n");

    const char* inputFileName = "input.ppm"; // Input image file
    const char* outputFileName = "output.ppm"; // Output image file
    const char* secretMessage = "Hello, Steganography!"; // The secret message to hide

    Image* img = readPPM(inputFileName);
    printf("Image loaded: %dx%d pixels\n", img->width, img->height);

    hideMessageInImage(secretMessage, img);
    writePPM(outputFileName, img);
    printf("Secret message hidden within the image!\n");

    char extractedMessage[50]; // Buffer for the extracted message
    extractMessageFromImage(img, extractedMessage, sizeof(extractedMessage));
    printf("Extracted message: %s\n", extractedMessage);

    free(img->pixelData);
    free(img);
    printf("Goodbye! Enjoy your steganographic adventures!\n");

    return 0;
}