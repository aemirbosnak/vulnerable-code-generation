//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *new_image(int width, int height) {
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel));
    return img;
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

void load_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", filename);
        exit(1);
    }

    // Read the header
    int width, height;
    fscanf(fp, "P3\n%d %d\n255\n", &width, &height);

    // Check if the image is too large
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Error: image is too large\n");
        exit(1);
    }

    // Read the pixel data
    for (int i = 0; i < width * height; i++) {
        int r, g, b;
        fscanf(fp, "%d %d %d", &r, &g, &b);
        img->data[i].r = r;
        img->data[i].g = g;
        img->data[i].b = b;
    }

    fclose(fp);
}

void save_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", filename);
        exit(1);
    }

    // Write the header
    fprintf(fp, "P3\n%d %d\n255\n", img->width, img->height);

    // Write the pixel data
    for (int i = 0; i < img->width * img->height; i++) {
        fprintf(fp, "%d %d %d\n", img->data[i].r, img->data[i].g, img->data[i].b);
    }

    fclose(fp);
}

void invert_image(image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

void grayscale_image(image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        int gray = (img->data[i].r + img->data[i].g + img->data[i].b) / 3;
        img->data[i].r = gray;
        img->data[i].g = gray;
        img->data[i].b = gray;
    }
}

void blur_image(image *img, int radius) {
    // Create a temporary image to store the blurred image
    image *temp = new_image(img->width, img->height);

    // Apply the blur filter to each pixel
    for (int i = 0; i < img->width * img->height; i++) {
        int sum_r = 0, sum_g = 0, sum_b = 0;
        int count = 0;

        // Calculate the sum of the colors of the neighboring pixels
        for (int j = -radius; j <= radius; j++) {
            for (int k = -radius; k <= radius; k++) {
                int x = i % img->width + j;
                int y = i / img->width + k;

                if (x >= 0 && x < img->width && y >= 0 && y < img->height) {
                    sum_r += img->data[y * img->width + x].r;
                    sum_g += img->data[y * img->width + x].g;
                    sum_b += img->data[y * img->width + x].b;
                    count++;
                }
            }
        }

        // Set the pixel color to the average of the neighboring pixels
        temp->data[i].r = sum_r / count;
        temp->data[i].g = sum_g / count;
        temp->data[i].b = sum_b / count;
    }

    // Copy the blurred image back to the original image
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i] = temp->data[i];
    }

    // Free the temporary image
    free_image(temp);
}

void edge_detect_image(image *img) {
    // Create a temporary image to store the edge-detected image
    image *temp = new_image(img->width, img->height);

    // Apply the edge detection filter to each pixel
    for (int i = 0; i < img->width * img->height; i++) {
        int dx = 0, dy = 0;

        // Calculate the gradients in the x and y directions
        if (i % img->width > 0) {
            dx = img->data[i].r - img->data[i - 1].r;
        }
        if (i / img->width > 0) {
            dy = img->data[i].r - img->data[i - img->width].r;
        }

        // Calculate the edge strength
        int edge_strength = sqrt(dx * dx + dy * dy);

        // Set the pixel color to the edge strength
        temp->data[i].r = edge_strength;
        temp->data[i].g = edge_strength;
        temp->data[i].b = edge_strength;
    }

    // Copy the edge-detected image back to the original image
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i] = temp->data[i];
    }

    // Free the temporary image
    free_image(temp);
}

int main(int argc, char **argv) {
    // Check if the user has provided enough arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        exit(1);
    }

    // Load the input image
    image *img = new_image(0, 0);
    load_image(img, argv[1]);

    // Apply the desired filter to the image
    if (strcmp(argv[2], "invert") == 0) {
        invert_image(img);
    } else if (strcmp(argv[2], "grayscale") == 0) {
        grayscale_image(img);
    } else if (strcmp(argv[2], "blur") == 0) {
        blur_image(img, 5);
    } else if (strcmp(argv[2], "edge_detect") == 0) {
        edge_detect_image(img);
    } else {
        fprintf(stderr, "Error: invalid filter %s\n", argv[2]);
        exit(1);
    }

    // Save the output image
    save_image(img, argv[3]);

    // Free the image
    free_image(img);

    return 0;
}