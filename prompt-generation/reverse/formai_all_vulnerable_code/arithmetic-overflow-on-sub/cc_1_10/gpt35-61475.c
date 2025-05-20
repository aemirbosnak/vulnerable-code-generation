//FormAI DATASET v1.0 Category: Image Editor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PIXEL_VALUE 255

typedef struct {
    int width, height;
    unsigned char* pixels;
} Image;

/* Function declarations */
void read_image(char* filename, Image* img);
void write_image(char* filename, Image* img);
void invert_colors(Image* img);
void convert_to_grayscale(Image* img);
void add_noise(Image* img, int intensity);
void high_pass_filter(Image* img);
void recursive_color_change(Image* img, int x, int y, unsigned char orig_r, unsigned char orig_g, unsigned char orig_b, unsigned char new_r, unsigned char new_g, unsigned char new_b);

/* Main function */
int main() {
    char* filename = "image.bmp";
    Image img;

    read_image(filename, &img);

    printf("Image loaded:\n");
    printf("Width: %d\n", img.width);
    printf("Height: %d\n", img.height);

    /* Invert colors */
    invert_colors(&img);
    write_image("inverted.bmp", &img);

    /* Convert to grayscale */
    convert_to_grayscale(&img);
    write_image("grayscale.bmp", &img);

    /* Add noise */
    add_noise(&img, 50);
    write_image("noisy.bmp", &img);

    /* Apply high-pass filter */
    high_pass_filter(&img);
    write_image("high_pass.bmp", &img);

    /* Change color recursively */
    recursive_color_change(&img, img.width/2, img.height/2, 0, 0, 0, MAX_PIXEL_VALUE, MAX_PIXEL_VALUE, MAX_PIXEL_VALUE);
    write_image("recursive_color_change.bmp", &img);

    /* Free memory */
    free(img.pixels);

    return 0;
}

/* Reads a BMP image file and stores its encapsulated bitmap in an Image struct */
void read_image(char* filename, Image* img) {
    FILE* file = fopen(filename, "rb");

    /* Read BMP file header */
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    /* Extract image dimensions */
    img->width = *((int*)&header[18]);
    img->height = *((int*)&header[22]);

    /* Allocate memory for pixels */
    img->pixels = (unsigned char*)malloc(img->width * img->height * sizeof(unsigned char));

    /* Read pixels */
    int padding = (4 - (img->width * 3) % 4) % 4;  // BMP images are padded
    unsigned char pixel[3];
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fread(pixel, sizeof(unsigned char), 3, file);
            img->pixels[i * img->width + j] = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];  // Convert to grayscale
        }
        fseek(file, padding, SEEK_CUR);
    }

    fclose(file);
}

/* Writes an Image struct to a BMP file */
void write_image(char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");

    /* Write BMP file header */
    unsigned char header[54] = {
        0x42, 0x4D,                 // BMP signature
        0x36, 0x2A, 0x09, 0x00,     // File size (54 bytes header + image size)
        0x00, 0x00,                 // Reserved
        0x00, 0x00,                 // Reserved
        0x36, 0x00, 0x00, 0x00,     // Offset to image data
        0x28, 0x00, 0x00, 0x00,     // Size of bitmap info header
        0x00, 0x00, 0x00, 0x02,     // Width (2 bytes)
        0x00, 0x00, 0x00, 0x02,     // Height (2 bytes)
        0x01, 0x00,                 // Number of color planes
        0x08, 0x00,                 // Bits per pixel
        0x00, 0x00, 0x00, 0x00,     // Compression method
        0x10, 0x2A, 0x09, 0x00,     // Size of image data (rounded to multiple of 4 bytes)
        0x13, 0x0B, 0x00, 0x00,     // Horizontal resolution (2835 pixels/meter)
        0x13, 0x0B, 0x00, 0x00,     // Vertical resolution (2835 pixels/meter)
        0x00, 0x00, 0x00, 0x00,     // Number of colors in the palette
        0x00, 0x00, 0x00, 0x00      // Number of important colors
    };
    *((int*)&header[18]) = img->width;
    *((int*)&header[22]) = img->height;
    *((int*)&header[34]) = (img->width * img->height * 3) + ((img->width * 3) % 4) * img->height;

    fwrite(header, sizeof(unsigned char), 54, file);

    /* Write image data */
    int padding = (4 - (img->width * 3) % 4) % 4;
    unsigned char pixel[3];
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            pixel[0] = pixel[1] = pixel[2] = img->pixels[i * img->width + j];
            fwrite(pixel, sizeof(unsigned char), 3, file);
        }
        fwrite("", sizeof(unsigned char), padding, file);
    }

    fclose(file);
}

/* Inverts the colors of an Image */
void invert_colors(Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i * img->width + j] = MAX_PIXEL_VALUE - img->pixels[i * img->width + j];
        }
    }
}

/* Converts an Image to grayscale */
void convert_to_grayscale(Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i * img->width + j] = 0.299 * img->pixels[i * img->width + j] + 0.587 * img->pixels[i * img->width + j] + 0.114 * img->pixels[i * img->width + j];
        }
    }
}

/* Adds random noise to an Image */
void add_noise(Image* img, int intensity) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            if (rand() % 100 < intensity) {
                img->pixels[i * img->width + j] = rand() % MAX_PIXEL_VALUE;
            }
        }
    }
}

/* Applies a high-pass filter to an Image */
void high_pass_filter(Image* img) {
    Image temp_img;
    temp_img.width = img->width;
    temp_img.height = img->height;
    temp_img.pixels = (unsigned char*)malloc(img->width * img->height * sizeof(unsigned char));

    /* Apply filter */
    for (int i = 1; i < img->height - 1; i++) {
        for (int j = 1; j < img->width - 1; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sum += img->pixels[(i + k) * img->width + j + l];
                }
            }
            temp_img.pixels[i * img->width + j] = fmax(fmin(sum / 9, MAX_PIXEL_VALUE), 0);
        }
    }

    /* Copy result to original image */
    memcpy(img->pixels, temp_img.pixels, img->width * img->height * sizeof(unsigned char));
    free(temp_img.pixels);
}

/* Recursively changes the color of Image pixels */
void recursive_color_change(Image* img, int x, int y, unsigned char orig_r, unsigned char orig_g, unsigned char orig_b, unsigned char new_r, unsigned char new_g, unsigned char new_b) {
    /* Change color */
    if (img->pixels[y * img->width + x] == orig_r && img->pixels[(y * img->width + x) + 1] == orig_g && img->pixels[(y * img->width + x) + 2] == orig_b) {
        img->pixels[y * img->width + x] = new_r;
        img->pixels[(y * img->width + x) + 1] = new_g;
        img->pixels[(y * img->width + x) + 2] = new_b;
    }
    else {
        return;
    }

    /* Recursive calls */
    if (x > 0) {
        recursive_color_change(img, x - 1, y, orig_r, orig_g, orig_b, new_r, new_g, new_b);
    }
    if (y > 0) {
        recursive_color_change(img, x, y - 1, orig_r, orig_g, orig_b, new_r, new_g, new_b);
    }
    if (x < img->width - 1) {
        recursive_color_change(img, x + 1, y, orig_r, orig_g, orig_b, new_r, new_g, new_b);
    }
    if (y < img->height - 1) {
        recursive_color_change(img, x, y + 1, orig_r, orig_g, orig_b, new_r, new_g, new_b);
    }
}