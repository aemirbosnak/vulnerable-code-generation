#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

typedef struct {
    int width;
    int height;
    unsigned char pixels[MAX_IMAGE_SIZE * MAX_IMAGE_SIZE];
} Image;

void process_image(Image *img) {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return;
    }

    fscanf(file, "%d %d", &img->width, &img->height);
    if (img->width <= 0 || img->height <= 0) {
        printf("Invalid image dimensions\n");
        fclose(file);
        return;
    }

    for (int i = 0; i < img->width * img->height; i++) {
        fscanf(file, "%hhu", &img->pixels[i]);
    }

    fclose(file);

    // Process image here
}

int main() {
    Image img;
    process_image(&img);
    return 0;
}
