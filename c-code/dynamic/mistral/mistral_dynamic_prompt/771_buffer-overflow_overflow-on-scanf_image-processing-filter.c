#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[32];
    unsigned int width, height;
    unsigned char *data;
} Image;

void load_image(Image *img, char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: unable to open file %s\n", filename);
        return;
    }

    fscanf(file, "%s %u %u\n", img->name, &img->width, &img->height);
    img->data = (unsigned char *)malloc(img->width * img->height);
    fread(img->data, sizeof(unsigned char), img->width * img->height, file);
    fclose(file);
}

void process_image(Image *img) {
    for (int i = 0; i < img->width * img->height; ++i) {
        img->data[i] += 5; // Simple image processing filter
    }
}

void save_image(Image *img, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: unable to open file %s\n", filename);
        return;
    }

    fprintf(file, "%s %u %u\n", img->name, img->width, img->height);
    fwrite(img->data, sizeof(unsigned char), img->width * img->height, file);
    fclose(file);
}

int main(int argc, char **argv) {
    Image img;
    load_image(&img, argv[1]);
    process_image(&img);
    save_image(&img, argv[2]);

    free(img.data);
    return 0;
}
