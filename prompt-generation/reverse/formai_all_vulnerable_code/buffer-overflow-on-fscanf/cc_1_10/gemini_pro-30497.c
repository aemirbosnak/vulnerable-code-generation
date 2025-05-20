//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_DIM 1024

typedef struct {
    int width, height;
    unsigned char *data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(unsigned char));
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P5\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, 1, image->width * image->height, file);
    fclose(file);
}

void load_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "rb");
    fscanf(file, "P5\n%d %d\n255\n", &image->width, &image->height);
    image->data = malloc(image->width * image->height * sizeof(unsigned char));
    fread(image->data, 1, image->width * image->height, file);
    fclose(file);
}

void invert(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->data[i * 3] + image->data[i * 3 + 1] + image->data[i * 3 + 2]) / 3;
        image->data[i * 3] = gray;
        image->data[i * 3 + 1] = gray;
        image->data[i * 3 + 2] = gray;
    }
}

void blur(Image *image, int radius) {
    int width = image->width;
    int height = image->height;
    Image *blurred = new_image(width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int sum = 0;
            int count = 0;
            for (int dy = -radius; dy <= radius; dy++) {
                for (int dx = -radius; dx <= radius; dx++) {
                    int ix = x + dx;
                    int iy = y + dy;
                    if (ix >= 0 && ix < width && iy >= 0 && iy < height) {
                        sum += image->data[iy * width + ix];
                        count++;
                    }
                }
            }
            blurred->data[y * width + x] = sum / count;
        }
    }

    free_image(image);
    *image = *blurred;
    free_image(blurred);
}

void edge(Image *image) {
    int width = image->width;
    int height = image->height;
    Image *edged = new_image(width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int gx = 0;
            int gy = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int ix = x + dx;
                    int iy = y + dy;
                    if (ix >= 0 && ix < width && iy >= 0 && iy < height) {
                        gx += (image->data[iy * width + ix] - image->data[y * width + x]) * dx;
                        gy += (image->data[iy * width + ix] - image->data[y * width + x]) * dy;
                    }
                }
            }
            edged->data[y * width + x] = sqrt(gx * gx + gy * gy);
        }
    }

    free_image(image);
    *image = *edged;
    free_image(edged);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <image.pgm>\n", argv[0]);
        return 1;
    }

    Image *image = new_image(MAX_DIM, MAX_DIM);
    load_image(image, argv[1]);

    int choice;
    do {
        printf("1. Invert\n2. Grayscale\n3. Blur\n4. Edge\n5. Save\n6. Quit\n?");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                invert(image);
                break;
            case 2:
                grayscale(image);
                break;
            case 3: {
                int radius;
                printf("Enter blur radius: ");
                scanf("%d", &radius);
                blur(image, radius);
                break;
            }
            case 4:
                edge(image);
                break;
            case 5: {
                char filename[256];
                printf("Enter filename: ");
                scanf("%s", filename);
                save_image(image, filename);
                break;
            }
        }
    } while (choice != 6);

    free_image(image);
    return 0;
}