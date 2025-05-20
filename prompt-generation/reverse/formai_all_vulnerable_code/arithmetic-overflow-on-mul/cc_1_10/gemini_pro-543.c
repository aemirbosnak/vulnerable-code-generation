//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an image
typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

// Function to flip an image horizontally
void flip_horizontally(Image *img) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width / 2; j++) {
            unsigned char temp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[i * img->width + img->width - j - 1];
            img->data[i * img->width + img->width - j - 1] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertically(Image *img) {
    int i, j;
    for (i = 0; i < img->height / 2; i++) {
        for (j = 0; j < img->width; j++) {
            unsigned char temp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[(img->height - i - 1) * img->width + j];
            img->data[(img->height - i - 1) * img->width + j] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(Image *img, int brightness) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            int new_value = img->data[i * img->width + j] + brightness;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            img->data[i * img->width + j] = new_value;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(Image *img, float contrast) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            int new_value = (img->data[i * img->width + j] - 127) * contrast + 127;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            img->data[i * img->width + j] = new_value;
        }
    }
}

// Function to read an image from a file
Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    // Read the header
    char header[54];
    fread(header, 1, 54, fp);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fclose(fp);
        return NULL;
    }

    // Read the width and height of the image
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Create an image struct
    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->channels = 3;
    img->data = malloc(img->width * img->height * img->channels);

    // Read the image data
    fread(img->data, 1, img->width * img->height * img->channels, fp);

    // Close the file
    fclose(fp);

    // Return the image
    return img;
}

// Function to write an image to a file
void write_image(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    // Write the header
    char header[54];
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = sizeof(header) + img->width * img->height * img->channels;
    *(int *)&header[10] = sizeof(header);
    *(int *)&header[14] = 40;
    *(int *)&header[18] = img->width;
    *(int *)&header[22] = img->height;
    *(short *)&header[26] = 1;
    *(short *)&header[28] = 24;
    *(int *)&header[30] = 0;
    *(int *)&header[34] = img->width * img->height * img->channels;
    *(int *)&header[38] = 2835;
    *(int *)&header[42] = 2835;
    *(int *)&header[46] = 0;
    *(int *)&header[50] = 0;
    fwrite(header, 1, 54, fp);

    // Write the image data
    fwrite(img->data, 1, img->width * img->height * img->channels, fp);

    // Close the file
    fclose(fp);
}

int main() {
    // Read an image from a file
    Image *img = read_image("image.bmp");
    if (img == NULL) {
        printf("Error reading image\n");
        return 1;
    }

    // Flip the image horizontally
    flip_horizontally(img);

    // Change the brightness of the image
    change_brightness(img, 50);

    // Change the contrast of the image
    change_contrast(img, 1.5);

    // Write the image to a file
    write_image("new_image.bmp", img);

    // Free the image data
    free(img->data);
    free(img);

    return 0;
}