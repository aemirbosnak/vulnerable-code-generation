//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genious
#include <stdio.h>
#include <stdlib.h>

struct Image {
    char *pixels;
    int width;
    int height;
};

struct Image *read_image(char filename[]) {
    FILE *file;
    struct Image *image = NULL;
    int width, height;
    char format[3];

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }

    if (fscanf(file, "%s %d %d", format, &width, &height) != 3) {
        printf("Error reading file header\n");
        exit(1);
    }

    if (strcmp(format, "P5") != 0) {
        printf("Error: Only P5 format supported\n");
        exit(1);
    }

    fgetc(file);

    image = malloc(sizeof(struct Image));
    image->pixels = malloc(sizeof(char) * width * height);
    image->width = width;
    image->height = height;

    fread(image->pixels, sizeof(char), width * height, file);

    fclose(file);

    return image;
}

void write_image(struct Image *image, char filename[]) {
    FILE *file;

    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }

    fprintf(file, "P5\n%d %d\n255\n", image->width, image->height);

    fwrite(image->pixels, sizeof(char), image->width * image->height, file);

    fclose(file);
}

void flip_image(struct Image *image) {
    int i, j, k;
    char temp;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width / 2; j++) {
            k = i * image->width + j;
            temp = image->pixels[k];
            image->pixels[k] = image->pixels[i * image->width + image->width - j - 1];
            image->pixels[i * image->width + image->width - j - 1] = temp;
        }
    }
}

void adjust_brightness(struct Image *image, int amount) {
    int i;

    for (i = 0; i < image->width * image->height; i++) {
        if (image->pixels[i] + amount > 255) {
            image->pixels[i] = 255;
        } else if (image->pixels[i] + amount < 0) {
            image->pixels[i] = 0;
        } else {
            image->pixels[i] += amount;
        }
    }
}

void adjust_contrast(struct Image *image, float amount) {
    int i;
    float fac = (259.0 * (amount + 255.0)) / (255.0 * (259.0 - amount));

    for (i = 0; i < image->width * image->height; i++) {
        image->pixels[i] = fac * (image->pixels[i] - 128) + 128;
    }
}

int main(int argc, char *argv[]) {
    struct Image *image;
    char *filename_in, *filename_out;

    if (argc != 4) {
        printf("Usage: %s [input file] [output file] [options]\n\n", argv[0]);
        printf("Options:\n");
        printf("\t-f\t Flip image horizontally\n");
        printf("\t-b N\t Adjust brightness by N (positive or negative)\n");
        printf("\t-c N\t Adjust contrast by N (positive or negative)\n");
        exit(1);
    }

    filename_in = argv[1];
    filename_out = argv[2];

    image = read_image(filename_in);

    if (strcmp(argv[3], "-f") == 0) {
        flip_image(image);
    } else if (strcmp(argv[3], "-b") == 0) {
        int amount = atoi(argv[4]);
        adjust_brightness(image, amount);
    } else if (strcmp(argv[3], "-c") == 0) {
        float amount = atof(argv[4]);
        adjust_contrast(image, amount);
    } else {
        printf("Invalid option: %s\n", argv[3]);
        exit(1);
    }

    write_image(image, filename_out);

    free(image->pixels);
    free(image);

    return 0;
}