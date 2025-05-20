//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

// Function to load a PPM image
Image* load_image(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }
    
    char header[3];
    fscanf(file, "%s", header);
    if (header[1] != '6') {
        fprintf(stderr, "Unsupported PPM format\n");
        fclose(file);
        return NULL;
    }
    
    Image *img = (Image*) malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // read the newline character after the header

    img->data = (Pixel*) malloc(sizeof(Pixel) * img->width * img->height);
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

// Function to save a PPM image
void save_image(const char* filename, Image* img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Function to flip an image vertically
void flip_vertical(Image* img) {
    for (int i = 0; i < img->height / 2; i++) {
        for (int j = 0; j < img->width; j++) {
            Pixel temp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[(img->height - 1 - i) * img->width + j];
            img->data[(img->height - 1 - i) * img->width + j] = temp;
        }
    }
}

// Function to flip an image horizontally
void flip_horizontal(Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            Pixel temp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[i * img->width + (img->width - 1 - j)];
            img->data[i * img->width + (img->width - 1 - j)] = temp;
        }
    }
}

// Function to adjust brightness
void adjust_brightness(Image* img, int value) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            Pixel* p = &img->data[i * img->width + j];
            p->r = (p->r + value > 255) ? 255 : (p->r + value < 0) ? 0 : p->r + value;
            p->g = (p->g + value > 255) ? 255 : (p->g + value < 0) ? 0 : p->g + value;
            p->b = (p->b + value > 255) ? 255 : (p->b + value < 0) ? 0 : p->b + value;
        }
    }
}

// Function to adjust contrast
void adjust_contrast(Image* img, float factor) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            Pixel* p = &img->data[i * img->width + j];

            p->r = (p->r - 128) * factor + 128;
            p->g = (p->g - 128) * factor + 128;
            p->b = (p->b - 128) * factor + 128;
            p->r = (p->r < 0) ? 0 : (p->r > 255) ? 255 : (unsigned char)p->r;
            p->g = (p->g < 0) ? 0 : (p->g > 255) ? 255 : (unsigned char)p->g;
            p->b = (p->b < 0) ? 0 : (p->b > 255) ? 255 : (unsigned char)p->b;
        }
    }
}

// Main function to demonstrate the image processing tasks
int main(int argc, char* argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    Image* img = load_image(argv[1]);
    if (!img) return 1;

    flip_horizontal(img);
    flip_vertical(img);
    adjust_brightness(img, brightness);
    adjust_contrast(img, contrast);

    save_image(argv[2], img);

    free(img->data);
    free(img);
    return 0;
}