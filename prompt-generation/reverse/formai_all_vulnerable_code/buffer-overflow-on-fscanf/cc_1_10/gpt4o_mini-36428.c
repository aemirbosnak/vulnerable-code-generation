//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#define MAX_PAYLOAD_SIZE 256

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel;

typedef struct {
    uint32_t width;
    uint32_t height;
    Pixel *pixels;
} Image;

// Function declarations
Image* load_image(const char *filename);
void save_image(const char *filename, Image *image);
void encode_message(Image *image, const char *message);
char* decode_message(Image *image);
void free_image(Image *image);

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc < 4) {
        printf("Usage: %s <encode/decode> <input_image> <output_image> [message]\n", argv[0]);
        return 1;
    }

    const char *mode = argv[1];
    const char *input_image = argv[2];
    const char *output_image = argv[3];

    Image *image = load_image(input_image);
    if (!image) {
        printf("Failed to load image: %s\n", input_image);
        return 1;
    }

    if (strcmp(mode, "encode") == 0) {
        if (argc != 5) {
            printf("Usage for encoding: %s encode <input_image> <output_image> <message>\n", argv[0]);
            free_image(image);
            return 1;
        }
        encode_message(image, argv[4]);
        save_image(output_image, image);
        printf("Message encoded and saved to %s\n", output_image);
    } else if (strcmp(mode, "decode") == 0) {
        char *decoded_message = decode_message(image);
        if (decoded_message) {
            printf("Decoded message: %s\n", decoded_message);
            free(decoded_message);
        } else {
            printf("No hidden message found.\n");
        }
    } else {
        printf("Invalid mode. Use 'encode' or 'decode'.\n");
    }

    free_image(image);
    return 0;
}

// Load an image from a PPM file (assumes P3 format)
Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P3") != 0) {
        fclose(file);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    fscanf(file, "%u %u", &image->width, &image->height);
    fgetc(file); // Read the newline after width and height
    image->pixels = malloc(image->width * image->height * sizeof(Pixel));

    for (size_t i = 0; i < image->width * image->height; i++) {
        fscanf(file, "%hhu %hhu %hhu", &image->pixels[i].r, &image->pixels[i].g, &image->pixels[i].b);
    }

    fclose(file);
    return image;
}

// Save the image to a PPM file (assumes P3 format)
void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "w");
    if (!file) return;

    fprintf(file, "P3\n");
    fprintf(file, "%u %u\n255\n", image->width, image->height);

    for (size_t i = 0; i < image->width * image->height; i++) {
        fprintf(file, "%u %u %u ", image->pixels[i].r, image->pixels[i].g, image->pixels[i].b);
    }

    fclose(file);
}

// Encode message into the image
void encode_message(Image *image, const char *message) {
    size_t msg_len = strlen(message);
    if (msg_len > MAX_PAYLOAD_SIZE) {
        printf("Message too long. Maximum payload size is %d characters.\n", MAX_PAYLOAD_SIZE);
        return;
    }

    // Encode message length
    for (size_t i = 0; i < msg_len; i++) {
        image->pixels[i].r = (image->pixels[i].r & 0xFE) | ((message[i] & 0x80) >> 7);
        image->pixels[i].g = (image->pixels[i].g & 0xFE) | ((message[i] & 0x40) >> 6);
        image->pixels[i].b = (image->pixels[i].b & 0xFE) | ((message[i] & 0x20) >> 5);
    }
}

// Decode message from the image
char* decode_message(Image *image) {
    char *message = malloc(MAX_PAYLOAD_SIZE + 1);
    size_t msg_len = 0;

    for (size_t i = 0; i < MAX_PAYLOAD_SIZE; i++) {
        if (image->pixels[i].r & 0x01) {
            message[msg_len] |= 0x80;
        }
        if (image->pixels[i].g & 0x01) {
            message[msg_len] |= 0x40;
        }
        if (image->pixels[i].b & 0x01) {
            message[msg_len] |= 0x20;
        }

        // Increment the message length if the character is complete
        if ((msg_len < (MAX_PAYLOAD_SIZE - 1)) && (message[msg_len] & 0x80) == 0) {
            msg_len++;
        } else {
            message[msg_len] = '\0'; // Null terminate the string
            return message;
        }
    }
    
    free(message); // If no message was found, free the allocated memory
    return NULL;
}

// Free image memory
void free_image(Image *image) {
    if (image) {
        free(image->pixels);
        free(image);
    }
}