//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r,g,b;
} RGB;

typedef struct {
    RGB *data;
    int width, height;
} Image;

// Flips the image horizontally
void flip_horizontally(Image *img) {
    int row_size = img->width * sizeof(RGB);
    RGB *temp_row = malloc(row_size);

    for (int row = 0; row < img->height; row++) {
        int row_offset = row * img->width;

        // Swap pixels horizontally in this row
        for (int col = 0; col < img->width / 2; col++) {
            int left = row_offset + col;
            int right = row_offset + img->width - col - 1;

            temp_row[col] = img->data[left];
            img->data[left] = img->data[right];
            img->data[right] = temp_row[col];
        }
    }

    free(temp_row);
}

// Adjusts the brightness of the image
void adjust_brightness(Image *img, int amount) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r += amount;
        img->data[i].g += amount;
        img->data[i].b += amount;
    }
}

// Adjusts the contrast of the image
void adjust_contrast(Image *img, float amount) {
    for (int i = 0; i < img->width * img->height; i++) {
        float r = img->data[i].r / 255.0;
        float g = img->data[i].g / 255.0;
        float b = img->data[i].b / 255.0;

        r = (r - 0.5) * amount + 0.5;
        g = (g - 0.5) * amount + 0.5;
        b = (b - 0.5) * amount + 0.5;

        if (r < 0.0) r = 0.0;
        if (g < 0.0) g = 0.0;
        if (b < 0.0) b = 0.0;
        if (r > 1.0) r = 1.0;
        if (g > 1.0) g = 1.0;
        if (b > 1.0) b = 1.0;

        img->data[i].r = (unsigned char) (r * 255.0);
        img->data[i].g = (unsigned char) (g * 255.0);
        img->data[i].b = (unsigned char) (b * 255.0);
    }
}

// Reads an image from a PPM file
Image *read_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return NULL;
    }

    char magic[3], line[256];
    int width, height, max_val;

    if (!fgets(magic, sizeof(magic), file) ||
        magic[0] != 'P' || magic[1] != '6' ||
        !fgets(line, sizeof(line), file) ||
        sscanf(line, "%d %d", &width, &height) != 2 ||
        !fgets(line, sizeof(line), file) ||
        sscanf(line, "%d", &max_val) != 1 ||
        max_val != 255) {
        fprintf(stderr, "Invalid PPM file\n");
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    img->data = malloc(width * height * sizeof(RGB));
    img->width = width;
    img->height = height;

    for (int i = 0; i < width * height; i++) {
        if (fread(&img->data[i], sizeof(RGB), 1, file) != 1) {
            fprintf(stderr, "Failed to read pixel data from file\n");
            free(img->data);
            free(img);
            fclose(file);
            return NULL;
        }
    }

    fclose(file);
    return img;
}

// Writes an image to a PPM file
void write_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to open file for writing: %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n%d\n", img->width, img->height, 255);

    for (int i = 0; i < img->width * img->height; i++) {
        fwrite(&img->data[i], sizeof(RGB), 1, file);
    }

    fclose(file);
}

// Main function to perform image processing tasks
int main() {
    // Read an image from file
    Image *img = read_ppm("input.ppm");
    if (!img) {
        return 1;
    }

    // Flip the image horizontally
    flip_horizontally(img);

    // Adjust brightness by 50
    adjust_brightness(img, 50);

    // Adjust contrast by 1.5
    adjust_contrast(img, 1.5);

    // Write the modified image to file
    write_ppm("output.ppm", img);

    // Free memory used by the image
    free(img->data);
    free(img);

    return 0;
}