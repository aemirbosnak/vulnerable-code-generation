//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

// Define the ASCII characters to use for the image
const char *ascii_chars = "@%#*+=-:. ";

typedef struct {
    int width;
    int height;
    int *data;
} Image;

// Load an image from a file
Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    Image img = {
       .width = width,
       .height = height,
       .data = malloc(width * height * sizeof(int))
    };

    if (img.data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        exit(1);
    }

    fread(img.data, sizeof(int), width * height, fp);
    fclose(fp);

    return img;
}

// Convert an image to ASCII art
void image_to_ascii(Image img, char *output) {
    int x, y;
    for (y = 0; y < img.height; y++) {
        for (x = 0; x < img.width; x++) {
            int value = img.data[y * img.width + x] / 256; // Convert from grayscale to 0-9
            output[y * MAX_WIDTH + x] = ascii_chars[value % 10];
        }
    }
}

// Save the ASCII art to a file
void save_ascii(const char *filename, const char *data) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s' for writing\n", filename);
        exit(1);
    }

    int len = strlen(data);
    if (len > MAX_WIDTH * MAX_HEIGHT) {
        fprintf(stderr, "Error: ASCII art is too large to fit in a %dx%d grid\n", MAX_WIDTH, MAX_HEIGHT);
        exit(1);
    }

    fwrite(data, sizeof(char), len, fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii>\n", argv[0]);
        exit(1);
    }

    Image img = load_image(argv[1]);
    char ascii[MAX_WIDTH * MAX_HEIGHT];

    image_to_ascii(img, ascii);
    save_ascii(argv[2], ascii);

    printf("ASCII art saved to file '%s'\n", argv[2]);

    return 0;
}