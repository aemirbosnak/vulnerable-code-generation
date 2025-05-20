//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

// Function to calculate the Mandelbrot set
void mandelbrot(unsigned char *image, int width, int height, double zoom, double moveX, double moveY) {
    int x, y, i;
    double zx, zy, tmp;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            zx = 1.5 * (x - width / 2) / (0.5 * zoom * width) + moveX;
            zy = (y - height / 2) / (0.5 * zoom * height) + moveY;

            i = 0;
            while (zx * zx + zy * zy < 4 && i < MAX_ITER) {
                tmp = zx * zx - zy * zy + 0.355;
                zy = 2.0 * zx * zy + 0.355;
                zx = tmp;
                i++;
            }

            int pixel_index = (x + y * width) * 3;
            image[pixel_index] = (unsigned char)(i % 256);        // Red
            image[pixel_index + 1] = (unsigned char)(i % 256 / 2); // Green
            image[pixel_index + 2] = (unsigned char)(i % 256 / 4); // Blue
        }
    }
}

// Function to save the image to a PPM file
void save_image(const char *filename, unsigned char *image, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(image, 3, width * height, fp);
    fclose(fp);
}

// Function to display usage
void usage(const char *progname) {
    printf("Usage: %s <zoom> <moveX> <moveY>\n", progname);
    printf("  zoom: Zoom level for the fractal.\n");
    printf("  moveX: X-coordinate shift.\n");
    printf("  moveY: Y-coordinate shift.\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
        return 1;
    }

    double zoom = atof(argv[1]);
    double moveX = atof(argv[2]);
    double moveY = atof(argv[3]);

    unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT * 3);
    if (!image) {
        perror("Unable to allocate memory for image");
        return 1;
    }

    mandelbrot(image, WIDTH, HEIGHT, zoom, moveX, moveY);
    save_image("mandelbrot.ppm", image, WIDTH, HEIGHT);

    free(image);
    printf("Fractal generated and saved as mandelbrot.ppm\n");

    return 0;
}