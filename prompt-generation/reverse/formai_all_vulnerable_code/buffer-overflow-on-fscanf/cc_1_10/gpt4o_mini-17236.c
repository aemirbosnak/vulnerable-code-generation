//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define ASCII_CHARS "@%#*+=-:. "

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel pixels[MAX_WIDTH][MAX_HEIGHT];
} Image;

void usage(const char *program_name) {
    printf("Usage: %s <input_image.ppm>\n", program_name);
}

Image* load_ppm(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    if (!img) {
        fprintf(stderr, "Could not allocate memory for image.\n");
        fclose(file);
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P3") != 0) {
        fprintf(stderr, "Unsupported format: %s. Only P3 PPM is supported.\n", header);
        fclose(file);
        free(img);
        return NULL;
    }

    fscanf(file, "%d %d", &img->width, &img->height);
    int max_val;
    fscanf(file, "%d", &max_val);
    if (max_val != 255) {
        fprintf(stderr, "Only 255 max color value is supported.\n");
        fclose(file);
        free(img);
        return NULL;
    }

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int r, g, b;
            fscanf(file, "%d %d %d", &r, &g, &b);
            img->pixels[x][y].r = r;
            img->pixels[x][y].g = g;
            img->pixels[x][y].b = b;
        }
    }

    fclose(file);
    return img;
}

int get_brightness(Pixel p) {
    return (0.299 * p.r + 0.587 * p.g + 0.114 * p.b);
}

char pixel_to_ascii(int brightness) {
    int index = (brightness * strlen(ASCII_CHARS)) / 256;
    return ASCII_CHARS[index];
}

void convert_image_to_ascii(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int brightness = get_brightness(img->pixels[x][y]);
            char ascii_char = pixel_to_ascii(brightness);
            putchar(ascii_char);
        }
        putchar('\n');
    }
}

void free_image(Image *img) {
    free(img);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = load_ppm(argv[1]);
    if (!img) {
        return EXIT_FAILURE;
    }

    convert_image_to_ascii(img);
    free_image(img);
    
    return EXIT_SUCCESS;
}