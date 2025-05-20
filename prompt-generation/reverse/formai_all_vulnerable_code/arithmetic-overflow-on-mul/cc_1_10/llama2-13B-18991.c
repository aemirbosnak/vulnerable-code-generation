//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    int width, height;
    unsigned char *image;
} Image;

void load_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    image->width = (int)ftell(file);
    image->height = (int)ftell(file) / 3;
    image->image = (unsigned char *)malloc(image->width * image->height * 3);
    fseek(file, 0, SEEK_SET);
    fread(image->image, 3, image->width * image->height, file);
    fclose(file);
}

void grateful_filter(Image *image) {
    int i, j, k, sum, diff;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            sum = 0;
            diff = 0;
            for (k = 0; k < 3; k++) {
                sum += image->image[i * image->width * 3 + j * 3 + k];
                diff = abs(sum - image->image[i * image->width * 3 + j * 3 + k]);
            }
            image->image[i * image->width * 3 + j * 3 + 0] = (diff * 10) / sum;
            image->image[i * image->width * 3 + j * 3 + 1] = (diff * 10) / sum;
            image->image[i * image->width * 3 + j * 3 + 2] = (diff * 10) / sum;
        }
    }
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(image->image, 3, image->width * image->height * 3, file);
    fclose(file);
}

int main() {
    Image image;
    load_image(&image, "grateful.bmp");
    grateful_filter(&image);
    save_image(&image, "grateful_filtered.bmp");
    return 0;
}