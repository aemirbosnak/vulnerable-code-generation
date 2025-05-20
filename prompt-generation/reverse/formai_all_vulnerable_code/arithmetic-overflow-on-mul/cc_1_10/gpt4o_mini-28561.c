//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#define ASCII_WIDTH 80
#define ASCII_HEIGHT 60
#define ASCII_CHARS "@%#*+=-:. "

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

int read_ppm(const char *filename, Image *img);
void free_image(Image *img);
void convert_to_ascii(Image *img);
char map_pixel_to_ascii(Pixel pixel);
void display_ascii_art(const char *ascii_art);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image img;
    if (read_ppm(argv[1], &img) == -1) {
        fprintf(stderr, "Error reading image file\n");
        return EXIT_FAILURE;
    }

    convert_to_ascii(&img);
    free_image(&img);
    return EXIT_SUCCESS;
}

int read_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return -1;
    }

    char header[3];
    fscanf(file, "%2s\n", header);
    if (strcmp(header, "P6") != 0) {
        fclose(file);
        fprintf(stderr, "File is not in P6 PPM format\n");
        return -1;
    }

    fscanf(file, "%d %d\n255\n", &img->width, &img->height);
    img->data = malloc(img->width * img->height * sizeof(Pixel));
    if (!img->data) {
        fclose(file);
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }

    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return 0;
}

void free_image(Image *img) {
    free(img->data);
}

char map_pixel_to_ascii(Pixel pixel) {
    int avg = (pixel.r + pixel.g + pixel.b) / 3;
    return ASCII_CHARS[(avg * (strlen(ASCII_CHARS) - 1)) / 255];
}

void convert_to_ascii(Image *img) {
    char ascii_art[ASCII_HEIGHT][ASCII_WIDTH + 1];
    for (int y = 0; y < ASCII_HEIGHT; y++) {
        for (int x = 0; x < ASCII_WIDTH; x++) {
            int img_x = x * img->width / ASCII_WIDTH;
            int img_y = y * img->height / ASCII_HEIGHT;
            Pixel p = img->data[img_y * img->width + img_x];
            ascii_art[y][x] = map_pixel_to_ascii(p);
        }
        ascii_art[y][ASCII_WIDTH] = '\0'; // Null-terminate each line
    }

    display_ascii_art((const char *)ascii_art);
}

void display_ascii_art(const char *ascii_art) {
    for (int y = 0; y < ASCII_HEIGHT; y++) {
        puts(ascii_art + y * (ASCII_WIDTH + 1)); // Each line is ASCII_WIDTH + 1 for '\0'
    }
}