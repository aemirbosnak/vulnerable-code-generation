//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

void read_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P3") != 0) {
        fprintf(stderr, "Unsupported format: %s\n", format);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", &img->width, &img->height);
    int max_value;
    fscanf(file, "%d", &max_value);

    img->data = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    for (int i = 0; i < img->width * img->height; i++) {
        fscanf(file, "%hhu %hhu %hhu", &img->data[i].r, &img->data[i].g, &img->data[i].b);
    }

    fclose(file);
}

void write_image(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P3\n%d %d\n255\n", img->width, img->height);
    for (int i = 0; i < img->width * img->height; i++) {
        fprintf(file, "%d %d %d\n", img->data[i].r, img->data[i].g, img->data[i].b);
    }

    fclose(file);
}

void convert_to_grayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char grayscale = (img->data[i].r + img->data[i].g + img->data[i].b) / 3;
        img->data[i].r = img->data[i].g = img->data[i].b = grayscale;
    }
}

void flip_image_horizontal(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - x - 1)];
            img->data[y * img->width + (img->width - x - 1)] = temp;
        }
    }
}

void invert_colors(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

void free_image(Image *img) {
    free(img->data);
    img->data = NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> [option]\n", argv[0]);
        fprintf(stderr, "Options:\n");
        fprintf(stderr, "  -grayscale   Convert to grayscale\n");
        fprintf(stderr, "  -flip        Flip image horizontally\n");
        fprintf(stderr, "  -invert      Invert colors\n");
        exit(EXIT_FAILURE);
    }

    Image img;
    read_image(argv[1], &img);

    if (argc == 4) {
        if (strcmp(argv[3], "-grayscale") == 0) {
            convert_to_grayscale(&img);
        } else if (strcmp(argv[3], "-flip") == 0) {
            flip_image_horizontal(&img);
        } else if (strcmp(argv[3], "-invert") == 0) {
            invert_colors(&img);
        } else {
            fprintf(stderr, "Unknown option: %s\n", argv[3]);
            free_image(&img);
            exit(EXIT_FAILURE);
        }
    }

    write_image(argv[2], &img);
    free_image(&img);
    return EXIT_SUCCESS;
}