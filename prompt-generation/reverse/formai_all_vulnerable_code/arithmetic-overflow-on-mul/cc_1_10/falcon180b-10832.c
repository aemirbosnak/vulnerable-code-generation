//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define PI 3.1415926535897932384626433832795
#define MAX_PIXELS 1024
#define MAX_ROWS 1024
#define MAX_COLS 1024
#define MAX_WATERMARK_SIZE 64
#define MAX_WATERMARK_ROWS 64
#define MAX_WATERMARK_COLS 64
#define MAX_WATERMARK_PIXELS 4096

typedef struct {
    int rows;
    int cols;
    int pixels;
    int watermark_rows;
    int watermark_cols;
    int watermark_pixels;
    int watermark_image[MAX_WATERMARK_ROWS][MAX_WATERMARK_COLS];
    int image[MAX_ROWS][MAX_COLS];
} image_t;

void create_watermark(image_t *watermark, int rows, int cols, int pixels) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            watermark->watermark_image[i][j] = rand() % 256;
        }
    }
}

void add_watermark(image_t *image, image_t *watermark) {
    for (int i = 0; i < image->rows; i++) {
        for (int j = 0; j < image->cols; j++) {
            int pixel = image->image[i][j];
            int watermark_pixel = watermark->watermark_image[i % watermark->watermark_rows][j % watermark->watermark_cols];
            int new_pixel = pixel + watermark_pixel;
            if (new_pixel > 255) {
                new_pixel = 255;
            }
            image->image[i][j] = new_pixel;
        }
    }
}

void save_image(image_t *image, char *filename) {
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fwrite(image->image, sizeof(int), image->pixels, fp);
    fclose(fp);
}

int main() {
    image_t image, watermark;
    int rows, cols, pixels;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Error: invalid image size\n");
        return 1;
    }

    pixels = rows * cols;

    if (pixels > MAX_PIXELS) {
        printf("Error: image size too large\n");
        return 1;
    }

    image.rows = rows;
    image.cols = cols;
    image.pixels = pixels;
    watermark.rows = rows / 4;
    watermark.cols = cols / 4;
    watermark.pixels = watermark.rows * watermark.cols;
    watermark.watermark_rows = watermark.rows;
    watermark.watermark_cols = watermark.cols;
    watermark.watermark_pixels = watermark.pixels;

    create_watermark(&watermark, watermark.rows, watermark.cols, watermark.pixels);

    printf("Enter the filename to save the watermarked image: ");
    char filename[100];
    scanf("%s", filename);

    save_image(&image, filename);

    return 0;
}