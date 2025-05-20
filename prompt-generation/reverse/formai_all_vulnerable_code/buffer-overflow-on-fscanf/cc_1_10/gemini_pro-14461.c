//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: post-apocalyptic
// Scavenged from the ruins of a forgotten world, this code whispers secrets hidden within images...

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// A relic from the old world, carrying the message
typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Pixel;

// Extract the secrets from the depths of the image
bool extract(const char* filename, char* message) {
    FILE* image = fopen(filename, "rb");
    if (!image) {
        fprintf(stderr, "Image not found or inaccessible\n");
        return false;
    }

    // Parse the image header
    uint32_t width, height, bitdepth;
    if (fscanf(image, "P3\n%u %u\n%u\n", &width, &height, &bitdepth) != 3) {
        fprintf(stderr, "Invalid image header\n");
        fclose(image);
        return false;
    }

    // Read the pixels, one by one
    Pixel* pixels = malloc(width * height * sizeof(Pixel));
    if (!pixels) {
        fprintf(stderr, "Out of memory\n");
        fclose(image);
        return false;
    }
    for (int i = 0; i < width * height; i++) {
        fscanf(image, "%hhu %hhu %hhu\n", &pixels[i].red, &pixels[i].green, &pixels[i].blue);
    }
    fclose(image);

    // Extract the message, one bit at a time
    int message_index = 0;
    for (int i = 0; i < width * height; i++) {
        // Grab the least significant bit from each color channel
        uint8_t bit = (pixels[i].red & 1) | ((pixels[i].green & 1) << 1) | ((pixels[i].blue & 1) << 2);
        // Decode the bit into the message
        message[message_index++] = (bit << 6) | (message[message_index] & 0x3F);
        // Check if we've reached the end of the message
        if (message[message_index - 1] == '\0') {
            break;
        }
    }

    // Success! The message has been extracted
    free(pixels);
    return true;
}

// Hide the message within the image, a secret concealed in plain sight
bool hide(const char* filename, const char* message) {
    FILE* image = fopen(filename, "wb");
    if (!image) {
        fprintf(stderr, "Image not found or inaccessible\n");
        return false;
    }

    // Parse the image header
    uint32_t width, height, bitdepth;
    if (fscanf(image, "P3\n%u %u\n%u\n", &width, &height, &bitdepth) != 3) {
        fprintf(stderr, "Invalid image header\n");
        fclose(image);
        return false;
    }

    // Write the modified image header
    fprintf(image, "P3\n%u %u\n%u\n", width, height, bitdepth);

    // Hide the message, one bit at a time
    int message_index = 0;
    for (int i = 0; i < width * height; i++) {
        // Read the pixel
        Pixel pixel;
        fscanf(image, "%hhu %hhu %hhu\n", &pixel.red, &pixel.green, &pixel.blue);

        // Modify the least significant bit of each color channel
        pixel.red &= 0xFE; pixel.red |= ((message[message_index] >> 6) & 1);
        pixel.green &= 0xFE; pixel.green |= ((message[message_index] >> 5) & 1);
        pixel.blue &= 0xFE; pixel.blue |= ((message[message_index] >> 4) & 1);

        // Write the modified pixel
        fprintf(image, "%hhu %hhu %hhu\n", pixel.red, pixel.green, pixel.blue);

        // Check if we've reached the end of the message
        if (message[message_index++] == '\0') {
            break;
        }
    }

    // Success! The message has been hidden
    fclose(image);
    return true;
}

int main() {
    // A weathered journal found among the ruins
    char filename[] = "apocalyptic_journal.ppm";
    // A whisper from the past, carried by the wind
    char message[] = "Hope survives, even in the darkest of times...";

    // Uncover the secrets hidden within the journal
    char extracted_message[1024];
    if (extract(filename, extracted_message)) {
        printf("Journal Entry Decrypted:\n%s\n", extracted_message);
    } else {
        fprintf(stderr, "Unable to extract message from %s\n", filename);
    }

    // Inscribe a message of hope upon the journal
    if (hide(filename, message)) {
        printf("Message Hidden in %s:\n%s\n", filename, message);
    } else {
        fprintf(stderr, "Unable to hide message in %s\n", filename);
    }

    return 0;
}