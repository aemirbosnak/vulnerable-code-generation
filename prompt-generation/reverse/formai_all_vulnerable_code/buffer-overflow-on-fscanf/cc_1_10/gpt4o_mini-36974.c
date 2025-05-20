//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

// Function to read the PPM image
Image* readPPM(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format, only P6 supported\n");
        fclose(file);
        return NULL;
    }

    Image *img = (Image*)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    fgetc(file); // Read the newline character after width and height

    img->pixels = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    
    return img;
}

// Function to write the modified image to a new PPM file
void writePPM(const char* filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Function to hide a message into the image
void hideMessage(Image *img, const char *message) {
    size_t msg_len = strlen(message);
    for (size_t i = 0; i < msg_len; i++) {
        for (int j = 0; j < 8; j++) {
            int pixel_index = (i * 8 + j) / 3;
            int bit_position = (i * 8 + j) % 3;

            if (pixel_index >= img->width * img->height) {
                fprintf(stderr, "Message is too long to hide in image.\n");
                return;
            }

            if (bit_position == 0) img->pixels[pixel_index].r = 
                (img->pixels[pixel_index].r & ~1) | ((message[i] >> (7 - j)) & 1);
            else if (bit_position == 1) img->pixels[pixel_index].g = 
                (img->pixels[pixel_index].g & ~1) | ((message[i] >> (7 - j)) & 1);
            else if (bit_position == 2) img->pixels[pixel_index].b = 
                (img->pixels[pixel_index].b & ~1) | ((message[i] >> (7 - j)) & 1);
        }
    }
}

// Main Function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.ppm> <message> <output.ppm>\n", argv[0]);
        return 1;
    }

    Image *img = readPPM(argv[1]);
    if (!img) return 1;

    const char *message = argv[2];
    hideMessage(img, message);

    writePPM(argv[3], img);

    free(img->pixels);
    free(img);
    printf("Message hidden successfully in %s.\n", argv[3]);
    return 0;
}