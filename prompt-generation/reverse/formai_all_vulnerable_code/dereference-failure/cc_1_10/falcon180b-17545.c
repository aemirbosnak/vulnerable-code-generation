//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_WATERMARKS 10

typedef struct {
    int x, y;
    int strength;
} Watermark;

void add_watermark(Watermark *watermarks, int num_watermarks, int x, int y, int strength) {
    if (num_watermarks >= MAX_WATERMARKS) {
        printf("Error: Too many watermarks!\n");
        exit(1);
    }
    watermarks[num_watermarks].x = x;
    watermarks[num_watermarks].y = y;
    watermarks[num_watermarks].strength = strength;
    num_watermarks++;
}

void apply_watermarks(unsigned char *image, int width, int height, Watermark *watermarks, int num_watermarks) {
    for (int i = 0; i < num_watermarks; i++) {
        int x = watermarks[i].x % width;
        int y = watermarks[i].y % height;
        int strength = watermarks[i].strength;

        for (int j = 0; j < strength; j++) {
            int index = (y * width + x) * 3;
            image[index] += j;
            image[index + 1] += j;
            image[index + 2] += j;
        }
    }
}

int main() {
    FILE *fp;
    unsigned char *image;
    int width, height, num_components;
    Watermark watermarks[MAX_WATERMARKS];
    int num_watermarks = 0;

    fp = fopen("image.png", "rb");
    if (fp == NULL) {
        printf("Error: Could not open image file!\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image = (unsigned char *) malloc(file_size);
    if (image == NULL) {
        printf("Error: Could not allocate memory for image!\n");
        exit(1);
    }

    fread(image, file_size, 1, fp);
    fclose(fp);

    width = *((int *) (image + 18));
    height = *((int *) (image + 22));
    num_components = *((int *) (image + 28));

    printf("Image size: %dx%d, %d components\n", width, height, num_components);

    add_watermark(watermarks, num_watermarks, 100, 100, 50);
    add_watermark(watermarks, num_watermarks, 200, 200, 100);

    apply_watermarks(image, width, height, watermarks, num_watermarks);

    fp = fopen("watermarked_image.png", "wb");
    if (fp == NULL) {
        printf("Error: Could not open output file!\n");
        exit(1);
    }

    fwrite(image, file_size, 1, fp);
    fclose(fp);

    printf("Watermarking completed!\n");

    return 0;
}