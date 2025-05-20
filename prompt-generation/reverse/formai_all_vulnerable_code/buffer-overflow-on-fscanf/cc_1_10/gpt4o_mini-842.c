//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_VALUE 255

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_ppm(const char *filename);
void save_ppm(const char *filename, Image *img);
void invert_colors(Image *img);
void convert_to_grayscale(Image *img);
void free_image(Image *img);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.ppm output.ppm\n", argv[0]);
        return 1;
    }

    Image *img = load_ppm(argv[1]);
    if (!img) {
        fprintf(stderr, "Could not load image: %s\n", argv[1]);
        return 1;
    }

    printf("Image loaded: %d x %d\n", img->width, img->height);
    printf("Choose an operation:\n");
    printf("1. Invert Colors\n");
    printf("2. Convert to Grayscale\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        invert_colors(img);
        printf("Colors inverted.\n");
        break;
    case 2:
        convert_to_grayscale(img);
        printf("Converted to grayscale.\n");
        break;
    default:
        fprintf(stderr, "Invalid choice.\n");
        free_image(img);
        return 1;
    }

    save_ppm(argv[2], img);
    printf("Image saved to: %s\n", argv[2]);
    free_image(img);
    return 0;
}

Image* load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format: %s\n", format);
        fclose(file);
        return NULL;
    }
    
    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_color;
    fscanf(file, "%d", &max_color);
    fgetc(file); // Consume the newline after max color value

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void save_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n%d\n", img->width, img->height, MAX_COLOR_VALUE);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void invert_colors(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = MAX_COLOR_VALUE - img->data[i].r;
        img->data[i].g = MAX_COLOR_VALUE - img->data[i].g;
        img->data[i].b = MAX_COLOR_VALUE - img->data[i].b;
    }
}

void convert_to_grayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (unsigned char)(0.299 * img->data[i].r + 0.587 * img->data[i].g + 0.114 * img->data[i].b);
        img->data[i].r = gray;
        img->data[i].g = gray;
        img->data[i].b = gray;
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}