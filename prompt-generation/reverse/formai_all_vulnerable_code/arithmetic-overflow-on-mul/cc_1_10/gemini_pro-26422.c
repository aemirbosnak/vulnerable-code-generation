//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    unsigned char r, g, b;
} RGB;

typedef struct {
    int width, height;
    RGB *pixels;
} Image;

Image *load_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) return NULL;

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(f);
        return NULL;
    }

     fread(&image->width, sizeof(int), 1, f);
    fread(&image->height, sizeof(int), 1, f);
    image->pixels = malloc(sizeof(RGB) * image->width * image->height);
    if (!image->pixels) {
        fclose(f);
        free(image);
        return NULL;
    }

    fread(image->pixels, sizeof(RGB), image->width * image->height, f);
    fclose(f);

    return image;
}

void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

char *to_ascii(Image *image) {
    const char *chars = " .:-=+*#%@";
    int char_count = strlen(chars);

    double max_intensity = 255.0;
    char *ascii = malloc(sizeof(char) * image->width * image->height + 1);
    if (!ascii) return NULL;

    int i = 0;
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            double intensity = (double)(image->pixels[i].r + image->pixels[i].g + image->pixels[i].b) / 3.0;
            int char_index = (int)round((intensity / max_intensity) * (char_count - 1));
            ascii[i++] = chars[char_index];
        }
        ascii[i++] = '\n';
    }
    ascii[i] = '\0';

    return ascii;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        printf("Error loading image: %s\n", argv[1]);
        return 1;
    }

    char *ascii = to_ascii(image);
    if (!ascii) {
        printf("Error converting image to ASCII\n");
        return 1;
    }

    printf("%s", ascii);
    free(ascii);
    free_image(image);

    return 0;
}