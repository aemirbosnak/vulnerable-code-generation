//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 800
#define IMAGE_HEIGHT 600

#define IMAGE_DATA_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT)

typedef struct {
    char *filename;
    unsigned char *data;
    int width;
    int height;
} image_t;

void load_image(image_t *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    unsigned int filesize = ftell(fp);
    rewind(fp);

    image->data = malloc(filesize);
    fread(image->data, filesize, 1, fp);

    fclose(fp);

    image->filename = strdup(filename);
    image->width = IMAGE_WIDTH;
    image->height = IMAGE_HEIGHT;
}

void save_image(const image_t *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: could not open file '%s' for writing\n", filename);
        exit(1);
    }

    fwrite(image->data, IMAGE_DATA_SIZE, 1, fp);

    fclose(fp);
}

void apply_filter(unsigned char *data) {
    for (int i = 0; i < IMAGE_DATA_SIZE; ++i) {
        int r = data[i] >> 16 & 0xff;
        int g = data[i] >> 8 & 0xff;
        int b = data[i] & 0xff;

        int gray = (r + g + b) / 3;

        data[i] = gray << 16 | gray << 8 | gray;
    }
}

int main() {
    image_t image;

    load_image(&image, "input.png");

    apply_filter(image.data);

    save_image(&image, "output.png");

    free(image.data);
    free(image.filename);

    return 0;
}