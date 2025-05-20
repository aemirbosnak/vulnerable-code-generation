//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct img {
    uint16_t width;
    uint16_t height;
    uint8_t *data;
};

static void flip_horizontal(struct img *img)
{
    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width / 2; ++x) {
            int tmp = img->data[x + y * img->width];
            img->data[x + y * img->width] = img->data[(img->width - x - 1) + y * img->width];
            img->data[(img->width - x - 1) + y * img->width] = tmp;
        }
    }
}

static void flip_vertical(struct img *img)
{
    for (int y = 0; y < img->height / 2; ++y) {
        for (int x = 0; x < img->width; ++x) {
            int tmp = img->data[x + y * img->width];
            img->data[x + y * img->width] = img->data[x + (img->height - y - 1) * img->width];
            img->data[x + (img->height - y - 1) * img->width] = tmp;
        }
    }
}

static void change_brightness(struct img *img, int delta)
{
    for (int i = 0; i < img->width * img->height; ++i) {
        int tmp = img->data[i] + delta;
        if (tmp < 0)
            tmp = 0;
        else if (tmp > 255)
            tmp = 255;
        img->data[i] = tmp;
    }
}

static void change_contrast(struct img *img, int delta)
{
    for (int i = 0; i < img->width * img->height; ++i) {
        int tmp = (img->data[i] - 128) * delta / 128 + 128;
        if (tmp < 0)
            tmp = 0;
        else if (tmp > 255)
            tmp = 255;
        img->data[i] = tmp;
    }
}

int main(int argc, char **argv)
{
    if (argc != 5) {
        printf("Usage: %s <input> <output> <operation> <value>\n", argv[0]);
        printf("Operations: flip-h, flip-v, bright, contrast\n");
        return 1;
    }

    struct img img;
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror(argv[1]);
        return 1;
    }

    if (fscanf(fp, "P5\n%hu %hu\n255\n", &img.width, &img.height) != 2) {
        fprintf(stderr, "Invalid header\n");
        fclose(fp);
        return 1;
    }

    img.data = malloc(img.width * img.height);
    if (!img.data) {
        perror("malloc()");
        fclose(fp);
        return 1;
    }

    if (fread(img.data, 1, img.width * img.height, fp) != img.width * img.height) {
        fprintf(stderr, "Invalid data\n");
        fclose(fp);
        return 1;
    }

    fclose(fp);

    int value = atoi(argv[4]);
    if (strcmp(argv[3], "flip-h") == 0)
        flip_horizontal(&img);
    else if (strcmp(argv[3], "flip-v") == 0)
        flip_vertical(&img);
    else if (strcmp(argv[3], "bright") == 0)
        change_brightness(&img, value);
    else if (strcmp(argv[3], "contrast") == 0)
        change_contrast(&img, value);

    fp = fopen(argv[2], "wb");
    if (!fp) {
        perror(argv[2]);
        return 1;
    }

    fprintf(fp, "P5\n%hu %hu\n255\n", img.width, img.height);
    fwrite(img.data, 1, img.width * img.height, fp);
    fclose(fp);

    free(img.data);

    return 0;
}