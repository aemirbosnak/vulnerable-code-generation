//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    int red;
    int green;
    int blue;
} pixel;

void read_image(pixel* image, char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open image file.\n");
        exit(1);
    }

    fseek(fp, 54, SEEK_SET); // Skip header
    int size = WIDTH * HEIGHT * 3;
    image = (pixel*)malloc(size * sizeof(pixel));
    if (image == NULL) {
        printf("Error: Cannot allocate memory.\n");
        exit(1);
    }

    fread(image, sizeof(pixel), size, fp);
    fclose(fp);
}

void write_image(char* filename, pixel* image) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Cannot create output file.\n");
        exit(1);
    }

    int size = WIDTH * HEIGHT * 3;
    fwrite(image, sizeof(pixel), size, fp);
    fclose(fp);
}

void add_watermark(pixel* image, char* watermark) {
    int w = strlen(watermark);
    int x = (WIDTH - w * 8) / 2;
    int y = HEIGHT - 16;

    for (int i = 0; i < w; i++) {
        if (watermark[i] == '1') {
            image[(y - 8) * WIDTH + x + i].red = 0;
            image[(y - 8) * WIDTH + x + i].green = 0;
            image[(y - 8) * WIDTH + x + i].blue = 0;
        }
    }
}

int main() {
    pixel image[WIDTH * HEIGHT];
    char watermark[100];

    printf("Enter image filename: ");
    scanf("%s", watermark);
    strcat(watermark, ".bmp");

    read_image(image, watermark);
    add_watermark(image, "Hello, World!");

    char output[100];
    strcpy(output, watermark);
    strcat(output, "_watermarked.bmp");

    write_image(output, image);

    printf("Watermark added successfully!\n");

    return 0;
}