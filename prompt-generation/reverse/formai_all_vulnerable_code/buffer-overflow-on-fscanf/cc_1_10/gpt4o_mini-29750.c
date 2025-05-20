//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height, max_color_value;
    Pixel* data;
} Image;

Image* load_ppm(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported format: %s\n", format);
        fclose(file);
        return NULL;
    }

    Image* img = (Image*)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    fscanf(file, "%d", &img->max_color_value);

    img->data = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void save_ppm(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "P6\n%d %d\n%d\n", img->width, img->height, img->max_color_value);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int opposite_x = img->width - x - 1;
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + opposite_x];
            img->data[y * img->width + opposite_x] = temp;
        }
    }
}

void adjust_brightness(Image* img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r + value > 255) ? 255 : img->data[i].r + value;
        img->data[i].g = (img->data[i].g + value > 255) ? 255 : img->data[i].g + value;
        img->data[i].b = (img->data[i].b + value > 255) ? 255 : img->data[i].b + value;
    }
}

void adjust_contrast(Image* img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char)((factor * (img->data[i].r - 128)) + 128);
        img->data[i].g = (unsigned char)((factor * (img->data[i].g - 128)) + 128);
        img->data[i].b = (unsigned char)((factor * (img->data[i].b - 128)) + 128);
    }
}

void free_image(Image* img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness_value> <contrast_factor>\n", argv[0]);
        return 1;
    }

    const char* input_filename = argv[1];
    const char* output_filename = argv[2];
    int brightness_value = atoi(argv[3]);
    float contrast_factor = atof(argv[4]);

    Image* img = load_ppm(input_filename);
    if (!img) return 1;

    flip_image(img);
    adjust_brightness(img, brightness_value);
    adjust_contrast(img, contrast_factor);

    save_ppm(output_filename, img);
    free_image(img);
    return 0;
}