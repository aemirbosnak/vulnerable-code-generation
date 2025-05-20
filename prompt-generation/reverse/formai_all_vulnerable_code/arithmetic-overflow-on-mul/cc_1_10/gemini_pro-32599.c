//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Pixel data structure
typedef struct pixel {
    unsigned char r, g, b, a;
} pixel;

// Image data structure
typedef struct image {
    int width, height;
    pixel *data;
} image;

// Load an image from a file
image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the header information
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Allocate memory for the image data
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel));

    // Read the pixel data
    fread(img->data, sizeof(pixel), width * height, fp);

    // Close the file
    fclose(fp);

    return img;
}

// Save an image to a file
void save_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the header information
    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);

    // Write the pixel data
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);

    // Close the file
    fclose(fp);
}

// Invert the colors of an image
void invert_colors(image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

// Blur an image
void blur(image *img) {
    // Create a temporary image to store the blurred data
    image *tmp = malloc(sizeof(image));
    tmp->width = img->width;
    tmp->height = img->height;
    tmp->data = malloc(img->width * img->height * sizeof(pixel));

    // Apply a box blur to the image
    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            // Calculate the average color of the surrounding pixels
            int r = 0, g = 0, b = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int x = i + k;
                    int y = j + l;
                    if (x >= 0 && x < img->width && y >= 0 && y < img->height) {
                        r += img->data[x + y * img->width].r;
                        g += img->data[x + y * img->width].g;
                        b += img->data[x + y * img->width].b;
                    }
                }
            }
            r /= 9;
            g /= 9;
            b /= 9;

            // Set the pixel color in the temporary image
            tmp->data[i + j * img->width].r = r;
            tmp->data[i + j * img->width].g = g;
            tmp->data[i + j * img->width].b = b;
        }
    }

    // Copy the blurred data back to the original image
    memcpy(img->data, tmp->data, img->width * img->height * sizeof(pixel));

    // Free the temporary image
    free(tmp->data);
    free(tmp);
}

// Sharpen an image
void sharpen(image *img) {
    // Create a temporary image to store the sharpened data
    image *tmp = malloc(sizeof(image));
    tmp->width = img->width;
    tmp->height = img->height;
    tmp->data = malloc(img->width * img->height * sizeof(pixel));

    // Apply a sharpening filter to the image
    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            // Calculate the Laplacian of the pixel
            int laplacian = -4 * img->data[i + j * img->width].r;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int x = i + k;
                    int y = j + l;
                    if (x >= 0 && x < img->width && y >= 0 && y < img->height) {
                        laplacian += img->data[x + y * img->width].r;
                    }
                }
            }

            // Clamp the pixel value to the range [0, 255]
            int r = img->data[i + j * img->width].r + laplacian;
            if (r < 0) {
                r = 0;
            } else if (r > 255) {
                r = 255;
            }

            // Set the pixel color in the temporary image
            tmp->data[i + j * img->width].r = r;
            tmp->data[i + j * img->width].g = r;
            tmp->data[i + j * img->width].b = r;
        }
    }

    // Copy the sharpened data back to the original image
    memcpy(img->data, tmp->data, img->width * img->height * sizeof(pixel));

    // Free the temporary image
    free(tmp->data);
    free(tmp);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    // Load the input image
    image *img = load_image(argv[1]);
    if (img == NULL) {
        return 1;
    }

    // Apply the image processing operation
    invert_colors(img);
    blur(img);
    sharpen(img);

    // Save the output image
    save_image(img, argv[2]);

    // Free the image data
    free(img->data);
    free(img);

    return 0;
}