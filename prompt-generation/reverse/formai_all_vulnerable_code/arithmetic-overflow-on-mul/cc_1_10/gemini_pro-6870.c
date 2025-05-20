//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Line;

typedef struct {
    Point center;
    int radius;
} Circle;

void loadImage(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    fseek(file, 10, SEEK_SET);
    fread(&image->width, 4, 1, file);
    fread(&image->height, 4, 1, file);

    image->data = malloc(image->width * image->height);
    fread(image->data, 1, image->width * image->height, file);
    fclose(file);
}

void saveImage(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    fwrite("BM", 2, 1, file);
    fwrite(&image->width, 4, 1, file);
    fwrite(&image->height, 4, 1, file);
    fwrite("\0\0", 2, 1, file);
    fwrite("\0\0\0\0", 4, 1, file);
    fwrite("\0\0\0\0", 4, 1, file);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fwrite(&image->data[y * image->width + x], 1, 1, file);
        }
    }

    fclose(file);
}

void drawLine(Image *image, Line line, unsigned char color) {
    int dx = line.p2.x - line.p1.x;
    int dy = line.p2.y - line.p1.y;

    if (abs(dx) >= abs(dy)) {
        for (int x = line.p1.x; x <= line.p2.x; x++) {
            int y = line.p1.y + (x - line.p1.x) * dy / dx;
            image->data[y * image->width + x] = color;
        }
    } else {
        for (int y = line.p1.y; y <= line.p2.y; y++) {
            int x = line.p1.x + (y - line.p1.y) * dx / dy;
            image->data[y * image->width + x] = color;
        }
    }
}

void drawCircle(Image *image, Circle circle, unsigned char color) {
    for (int x = circle.center.x - circle.radius; x <= circle.center.x + circle.radius; x++) {
        for (int y = circle.center.y - circle.radius; y <= circle.center.y + circle.radius; y++) {
            int dx = x - circle.center.x;
            int dy = y - circle.center.y;
            if (dx * dx + dy * dy <= circle.radius * circle.radius) {
                image->data[y * image->width + x] = color;
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image>\n", argv[0]);
        exit(1);
    }

    Image image;
    loadImage(&image, argv[1]);

    // Create a new image that is twice the size of the original image
    Image newImage;
    newImage.width = image.width * 2;
    newImage.height = image.height * 2;
    newImage.data = malloc(newImage.width * newImage.height);

    // Copy the original image to the new image
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            newImage.data[y * newImage.width + x] = image.data[y * image.width + x];
        }
    }

    // Shift the pixels in the new image
    for (int y = 0; y < newImage.height; y++) {
        for (int x = 0; x < newImage.width; x++) {
            int newX = (x + y) % newImage.width;
            int newY = (x + y) / newImage.width;
            newImage.data[y * newImage.width + x] = image.data[newY * image.width + newX];
        }
    }

    // Save the new image
    saveImage(&newImage, "output.bmp");

    // Free the memory allocated for the images
    free(image.data);
    free(newImage.data);

    return 0;
}