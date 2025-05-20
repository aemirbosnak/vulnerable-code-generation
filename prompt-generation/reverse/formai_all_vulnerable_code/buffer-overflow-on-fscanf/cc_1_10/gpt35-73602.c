//FormAI DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct image {
    Pixel* pixels;
    int width;
    int height;
} Image;

void set_pixel(Image* img, int x, int y, Pixel p) {
    if (x >= 0 && x < img->width && y >= 0 && y < img->height) {
        img->pixels[y * img->width + x] = p;
    }
}

Pixel get_pixel(Image* img, int x, int y) {
    if (x >= 0 && x < img->width && y >= 0 && y < img->height) {
        return img->pixels[y * img->width + x];
    }
    return (Pixel){0, 0, 0};
}

Image* create_image(int width, int height) {
    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = calloc(width * height, sizeof(Pixel));
    return img;
}

void destroy_image(Image* img) {
    free(img->pixels);
    free(img);
}

Image* load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    char type[3];
    int width, height, max_color;
    if (fscanf(file, "%2s\n%d %d\n%d\n", type, &width, &height, &max_color) != 4
        || type[0] != 'P' || type[1] != '6' || max_color != 255) {
        fclose(file);
        return NULL;
    }

    Image* img = create_image(width, height);

    int num_pixels = width * height;
    if (fread(img->pixels, sizeof(Pixel), num_pixels, file) != num_pixels) {
        destroy_image(img);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return img;
}

int save_image(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        return 0;
    }

    fprintf(file, "P6\n%d %d\n%d\n", img->width, img->height, 255);
    if (fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file) != img->width * img->height) {
        fclose(file);
        return 0;
    }

    fclose(file);
    return 1;
}

void grayscale(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel p = get_pixel(img, x, y);
            unsigned char gray = (unsigned char)((p.r + p.g + p.b) / 3);
            set_pixel(img, x, y, (Pixel){gray, gray, gray});
        }
    }
}

void invert(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel p = get_pixel(img, x, y);
            set_pixel(img, x, y, (Pixel){255 - p.r, 255 - p.g, 255 - p.b});
        }
    }
}

void blur(Image* img, int radius) {
    Pixel* pixels = calloc(img->width * img->height, sizeof(Pixel));

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int pixel_index = y * img->width + x;
            int min_x = x - radius < 0 ? 0 : x - radius;
            int max_x = x + radius >= img->width ? img->width - 1 : x + radius;
            int min_y = y - radius < 0 ? 0 : y - radius;
            int max_y = y + radius >= img->height ? img->height - 1 : y + radius;

            Pixel acc = {0, 0, 0};
            int count = 0;
            for (int j = min_y; j <= max_y; j++) {
                for (int i = min_x; i <= max_x; i++) {
                    count++;
                    Pixel p = get_pixel(img, i, j);
                    acc.r += p.r;
                    acc.g += p.g;
                    acc.b += p.b;
                }
            }

            pixels[pixel_index].r = (unsigned char)(acc.r / count);
            pixels[pixel_index].g = (unsigned char)(acc.g / count);
            pixels[pixel_index].b = (unsigned char)(acc.b / count);
        }
    }

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int pixel_index = y * img->width + x;
            set_pixel(img, x, y, pixels[pixel_index]);
        }
    }

    free(pixels);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [input image] [output image]\n", argv[0]);
        return 0;
    }

    Image* img = load_image(argv[1]);
    if (!img) {
        printf("Failed to load image '%s'\n", argv[1]);
        return 1;
    }

    // Apply a few filters to the image
    grayscale(img);
    invert(img);
    blur(img, 10);

    if (!save_image(argv[2], img)) {
        printf("Failed to save image '%s'\n", argv[2]);
        destroy_image(img);
        return 1;
    }

    destroy_image(img);
    return 0;
}