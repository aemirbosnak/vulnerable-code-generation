//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a BMP file
unsigned char *readBMP(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open the file %s\n", filename);
        return NULL;
    }

    fseek(file, 18, SEEK_SET);
    fread(width, 4, 1, file);
    fread(height, 4, 1, file);

    int row_padded = (*width * 3 + 3) & (~3);
    unsigned char *data = (unsigned char *)malloc(row_padded * (*height));
    fseek(file, 54, SEEK_SET);
    fread(data, sizeof(unsigned char), row_padded * (*height), file);
    fclose(file);
    return data;
}

// Function to write a BMP file
void writeBMP(const char *filename, unsigned char *data, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open the file %s\n", filename);
        return;
    }

    unsigned char bmpFileHeader[54] = {
        'B', 'M', 54 + (width * height * 3), 0, 0, 0, 0, 0, 54, 0, 0, 0, 1, 0, 24, 0
    };
    fwrite(bmpFileHeader, sizeof(unsigned char), 54, file);
    
    int row_padded = (width * 3 + 3) & (~3);
    fwrite(data, sizeof(unsigned char), row_padded * height, file);
    fclose(file);
}

// Function to hide a message in the least significant bit of the image data
void encodeMessage(unsigned char *data, const char *message, int width, int height) {
    int binaryIndex = 0;
    int messageLength = strlen(message);
    for (int i = 0; i < width * height * 3 && binaryIndex < messageLength; i++) {
        if (binaryIndex < messageLength * 8) {
            data[i] = (data[i] & 0xFE) | ((message[binaryIndex / 8] >> (binaryIndex % 8)) & 1);
            binaryIndex++;
        } else {
            // End the message with a null character if it's not fully used
            break;
        }
    }
}

// Function to extract the hidden message from the image data
void decodeMessage(unsigned char *data, char *message, int width, int height) {
    int binaryIndex = 0;
    for (int i = 0; i < width * height * 3; i++) {
        if (binaryIndex < (256 * 8 - 1)) {
            message[binaryIndex / 8] |= (data[i] & 1) << (binaryIndex % 8);
            binaryIndex++;
        } else {
            break;
        }
    }
    message[binaryIndex / 8] = '\0'; // Null termination
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_image.bmp> <output_image.bmp> <message>\n", argv[0]);
        return 1;
    }

    int width, height;
    unsigned char *imageData = readBMP(argv[1], &width, &height);
    if (imageData == NULL) return 1;

    char *message = argv[3];
    if (strlen(message) > (width * height * 3) / 8) {
        fprintf(stderr, "Message is too long to hide in the image.\n");
        free(imageData);
        return 1;
    }

    encodeMessage(imageData, message, width, height);
    writeBMP(argv[2], imageData, width, height);

    char hiddenMessage[256] = {0};
    decodeMessage(imageData, hiddenMessage, width, height);
    printf("Hidden Message: %s\n", hiddenMessage);

    free(imageData);
    return 0;
}