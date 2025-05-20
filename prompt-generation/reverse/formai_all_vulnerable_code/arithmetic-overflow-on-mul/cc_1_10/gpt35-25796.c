//FormAI DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

/* Function to set the LSB at given position */
void setLSB(unsigned char* byte, int pos, int bit) {
    if (bit)
        *byte |= (1 << pos); // Turn on the bit
    else
        *byte &= ~(1 << pos); // Turn off the bit
}

/* Function to get the LSB at given position */
int getLSB(unsigned char byte, int pos) {
    return (byte >> pos) & 1;
}

/* Function to hide a message in an image */
void hideMessageInImage(FILE* image, FILE* message, FILE* output) {
    int imageSize, messageSize;
    unsigned char imageByte, messageByte, outputByte;
    int bitPos = 0;

    // Get image and message size
    fseek(image, 0, SEEK_END);
    imageSize = ftell(image);
    rewind(image);
    fseek(message, 0, SEEK_END);
    messageSize = ftell(message);
    rewind(message);

    // Write image size to output file
    fwrite(&imageSize, sizeof(int), 1, output);

    // Write message size to output file
    fwrite(&messageSize, sizeof(int), 1, output);

    // Hide message in image
    for (int i = 0; i < imageSize; i++) {
        // Read image byte
        fread(&imageByte, sizeof(unsigned char), 1, image);

        // Check if we have reached the end of the message
        if (bitPos >= messageSize * 8) {
            // No more message bits to hide, write image byte to output file
            fwrite(&imageByte, sizeof(unsigned char), 1, output);
            continue;
        }

        // Read message byte
        fread(&messageByte, sizeof(unsigned char), 1, message);

        // Hide each bit of message byte in LSB of image byte
        for (int j = 0; j < 8; j++) {
            setLSB(&imageByte, j, getLSB(messageByte, j));
            bitPos++;
        }

        // Write modified image byte to output file
        fwrite(&imageByte, sizeof(unsigned char), 1, output);
    }
}

/* Function to extract a message from an image */
void extractMessageFromImage(FILE* image, FILE* message) {
    int imageSize, messageSize;
    unsigned char imageByte, messageByte;
    int bitPos = 0;

    // Read image size
    fread(&imageSize, sizeof(int), 1, image);

    // Read message size
    fread(&messageSize, sizeof(int), 1, image);

    // Extract message from image
    for (int i = 0; i < imageSize; i++) {
        // Read image byte
        fread(&imageByte, sizeof(unsigned char), 1, image);

        // Extract each bit from LSB of image byte and store it in message byte
        for (int j = 0; j < 8; j++) {
            setLSB(&messageByte, j, getLSB(imageByte, j));
            bitPos++;
            if (bitPos >= messageSize * 8) {
                // We have extracted all message bits, write message to file and exit
                fwrite(&messageByte, sizeof(unsigned char), 1, message);
                return;
            }
        }

        // Write extracted bits to message file
        fwrite(&messageByte, sizeof(unsigned char), 1, message);
    }
}

int main() {
    FILE* image = fopen("image.bmp", "rb");
    FILE* message = fopen("message.txt", "rb");
    FILE* output = fopen("output.bmp", "wb");

    // Hide message in image
    hideMessageInImage(image, message, output);

    fclose(image);
    fclose(message);
    fclose(output);

    // Extract message from image
    FILE* stegoImage = fopen("output.bmp", "rb");
    FILE* extractedMessage = fopen("extracted.txt", "wb");

    extractMessageFromImage(stegoImage, extractedMessage);

    fclose(stegoImage);
    fclose(extractedMessage);

    return 0;
}