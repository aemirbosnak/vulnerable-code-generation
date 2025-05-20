//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_MSG_LEN 255

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Pixel;

void display_message(const char *msg) {
    printf("Ah, what light through yonder window breaks!\n");
    printf("%s\n", msg);
}

Pixel *load_image(const char *filename, int *width, int *height) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Failed to open image file");
        return NULL;
    }

    // Reading BMP header
    fseek(f, 18, SEEK_SET);
    fread(width, sizeof(int), 1, f);
    fread(height, sizeof(int), 1, f);

    // Allocate memory for pixels
    Pixel *pixels = malloc((*width) * (*height) * sizeof(Pixel));
    fseek(f, 54, SEEK_SET);  // Move to pixel data

    // Read pixel data
    fread(pixels, sizeof(Pixel), (*width) * (*height), f);
    fclose(f);
    return pixels;
}

void save_image(const char *filename, Pixel *pixels, int width, int height) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("Failed to open output image file");
        return;
    }

    // Writing BMP header (simplified)
    uint8_t header[54] = {
        'B', 'M', 0, 0, 0, 0, 54, 0, 0, 0,
        0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 24, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0
    };
    
    // Set width and height in header
    *(int *)&header[18] = width;
    *(int *)&header[22] = height;
    *(int *)&header[2] = 54 + width * height * 3;  // File size

    fwrite(header, sizeof(uint8_t), 54, f);
    fwrite(pixels, sizeof(Pixel), width * height, f);
    fclose(f);
}

void embed_message(Pixel *pixels, int width, int height, const char *message) {
    int len = strlen(message);
    for (int i = 0; i < len && i < MAX_MSG_LEN; i++) {
        // Embed each character into the blue channel of pixels
        pixels[i].blue = (pixels[i].blue & 0xFE) | ((message[i] >> 7) & 0x01);
        pixels[i].green = (pixels[i].green & 0xFE) | ((message[i] >> 6) & 0x01);
        pixels[i].red = (pixels[i].red & 0xFE) | ((message[i] >> 5) & 0x01);
    }
    // Indicate the end of the message with a special character
    pixels[len].blue = (pixels[len].blue & 0xFE) | 0x01;  // Proclaim the end of our tale
}

void extract_message(Pixel *pixels, char *message, int max_len) {
    int i;
    for (i = 0; i < max_len; i++) {
        message[i] = 0;
        message[i] |= ((pixels[i].blue & 0x01) << 7);
        message[i] |= ((pixels[i].green & 0x01) << 6);
        message[i] |= ((pixels[i].red & 0x01) << 5);
        
        if (pixels[i + 1].blue & 0x01) break;  // Stop at special character
    }
    message[i] = '\0';  // Null-terminate the string
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return 1;
    }

    int width, height;
    Pixel *pixels = load_image(argv[1], &width, &height);
    if (!pixels) {
        return 1;
    }

    const char *message = argv[3];
    display_message(message);
    embed_message(pixels, width, height, message);
    save_image(argv[2], pixels, width, height);
    
    char extracted_message[MAX_MSG_LEN + 1];
    extract_message(pixels, extracted_message, MAX_MSG_LEN);
    printf("Extracted Message: %s\n", extracted_message);

    free(pixels);
    return 0;
}