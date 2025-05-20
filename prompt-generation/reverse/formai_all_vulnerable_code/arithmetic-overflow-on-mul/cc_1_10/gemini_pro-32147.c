//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

typedef struct {
    int width;
    int height;
    pixel *data;
} image;

image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    char header[54];
    fread(header, sizeof(char), 54, fp);

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel));

    fread(img->data, sizeof(pixel), width * height, fp);

    fclose(fp);

    return img;
}

void save_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    char header[54];
    memset(header, 0, sizeof(char) * 54);

    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = 54 + img->width * img->height * 3;
    *(int *)&header[10] = 54;
    *(int *)&header[14] = 40;
    *(int *)&header[18] = img->width;
    *(int *)&header[22] = img->height;
    *(short *)&header[26] = 1;
    *(short *)&header[28] = 24;
    *(int *)&header[34] = img->width * img->height * 3;

    fwrite(header, sizeof(char), 54, fp);

    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);

    fclose(fp);
}

void invert_colors(image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].red = 255 - img->data[i].red;
        img->data[i].green = 255 - img->data[i].green;
        img->data[i].blue = 255 - img->data[i].blue;
    }
}

void grayscale(image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (img->data[i].red + img->data[i].green + img->data[i].blue) / 3;
        img->data[i].red = gray;
        img->data[i].green = gray;
        img->data[i].blue = gray;
    }
}

void blur(image *img) {
    // Create a temporary image to store the blurred image
    image *tmp = malloc(sizeof(image));
    tmp->width = img->width;
    tmp->height = img->height;
    tmp->data = malloc(img->width * img->height * sizeof(pixel));

    // Apply a 3x3 blur kernel to the image
    for (int i = 1; i < img->width - 1; i++) {
        for (int j = 1; j < img->height - 1; j++) {
            int red = 0;
            int green = 0;
            int blue = 0;

            // Sum the colors of the neighboring pixels
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    red += img->data[(i + k) * img->width + (j + l)].red;
                    green += img->data[(i + k) * img->width + (j + l)].green;
                    blue += img->data[(i + k) * img->width + (j + l)].blue;
                }
            }

            // Divide the sum by the number of neighboring pixels
            red /= 9;
            green /= 9;
            blue /= 9;

            // Set the color of the pixel in the temporary image
            tmp->data[i * img->width + j].red = red;
            tmp->data[i * img->width + j].green = green;
            tmp->data[i * img->width + j].blue = blue;
        }
    }

    // Copy the temporary image back to the original image
    memcpy(img->data, tmp->data, img->width * img->height * sizeof(pixel));

    // Free the temporary image
    free(tmp->data);
    free(tmp);
}

void sharpen(image *img) {
    // Create a temporary image to store the sharpened image
    image *tmp = malloc(sizeof(image));
    tmp->width = img->width;
    tmp->height = img->height;
    tmp->data = malloc(img->width * img->height * sizeof(pixel));

    // Apply a 3x3 sharpen kernel to the image
    for (int i = 1; i < img->width - 1; i++) {
        for (int j = 1; j < img->height - 1; j++) {
            int red = 0;
            int green = 0;
            int blue = 0;

            // Sum the colors of the neighboring pixels, weighted by the kernel
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int weight = 1;
                    if (k == 0 && l == 0) {
                        weight = 9;
                    }
                    red += img->data[(i + k) * img->width + (j + l)].red * weight;
                    green += img->data[(i + k) * img->width + (j + l)].green * weight;
                    blue += img->data[(i + k) * img->width + (j + l)].blue * weight;
                }
            }

            // Clamp the colors to the range 0-255
            red = red < 0 ? 0 : (red > 255 ? 255 : red);
            green = green < 0 ? 0 : (green > 255 ? 255 : green);
            blue = blue < 0 ? 0 : (blue > 255 ? 255 : blue);

            // Set the color of the pixel in the temporary image
            tmp->data[i * img->width + j].red = red;
            tmp->data[i * img->width + j].green = green;
            tmp->data[i * img->width + j].blue = blue;
        }
    }

    // Copy the temporary image back to the original image
    memcpy(img->data, tmp->data, img->width * img->height * sizeof(pixel));

    // Free the temporary image
    free(tmp->data);
    free(tmp);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    image *img = load_image(argv[1]);
    if (img == NULL) {
        printf("Error: could not load image %s\n", argv[1]);
        return 1;
    }

    if (strcmp(argv[2], "-invert") == 0) {
        invert_colors(img);
    } else if (strcmp(argv[2], "-grayscale") == 0) {
        grayscale(img);
    } else if (strcmp(argv[2], "-blur") == 0) {
        blur(img);
    } else if (strcmp(argv[2], "-sharpen") == 0) {
        sharpen(img);
    } else {
        printf("Error: unknown option %s\n", argv[2]);
        return 1;
    }

    save_image(img, argv[3]);

    free(img->data);
    free(img);

    return 0;
}