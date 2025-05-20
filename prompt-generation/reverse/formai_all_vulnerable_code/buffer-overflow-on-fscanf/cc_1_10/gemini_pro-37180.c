//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH  1024
#define MAX_HEIGHT 1024

// Paranoid checks
#define CHECK_PTR(ptr)   if (!(ptr)) { fprintf(stderr, "NULL pointer: %s\n", __func__); exit(EXIT_FAILURE); }
#define CHECK_SIZE(var, size) if ((var) < 0 || (var) > (size)) { fprintf(stderr, "Invalid size: %s\n", __func__); exit(EXIT_FAILURE); }
#define CHECK_RANGE(var, min, max) if ((var) < (min) || (var) > (max)) { fprintf(stderr, "Invalid range: %s\n", __func__); exit(EXIT_FAILURE); }

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

// Paranoid memory allocation
void *xmalloc(size_t size) {
    void *ptr = malloc(size);
    CHECK_PTR(ptr);
    memset(ptr, 0, size);
    return ptr;
}

// Paranoid file reading
Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    CHECK_PTR(fp);
    Image *img = xmalloc(sizeof(Image));
    fscanf(fp, "P6\n%d %d\n255\n", &img->width, &img->height);
    CHECK_SIZE(img->width, MAX_WIDTH);
    CHECK_SIZE(img->height, MAX_HEIGHT);
    img->data = xmalloc(img->width * img->height * 3);
    fread(img->data, 1, img->width * img->height * 3, fp);
    fclose(fp);
    return img;
}

// Paranoid file writing
void write_image(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    CHECK_PTR(fp);
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 1, img->width * img->height * 3, fp);
    fclose(fp);
}

// Paranoid image processing
void process_image(Image *img) {
    int x, y, i;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            i = (y * img->width + x) * 3;
            // Paranoid color conversion
            CHECK_RANGE(img->data[i], 0, 255);
            CHECK_RANGE(img->data[i + 1], 0, 255);
            CHECK_RANGE(img->data[i + 2], 0, 255);
            // Paranoid color inversion
            img->data[i] = 255 - img->data[i];
            img->data[i + 1] = 255 - img->data[i + 1];
            img->data[i + 2] = 255 - img->data[i + 2];
        }
    }
}

// Paranoid memory deallocation
void free_image(Image *img) {
    if (img) {
        if (img->data) {
            free(img->data);
        }
        free(img);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    Image *img = read_image(argv[1]);
    process_image(img);
    write_image(argv[2], img);
    free_image(img);
    return EXIT_SUCCESS;
}