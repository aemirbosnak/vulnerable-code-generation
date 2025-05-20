//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define IMAGE_SIZE WIDTH * HEIGHT
#define THRESHOLD 0.1
#define EMBED_BITS 10

typedef struct {
    int value;
    int position;
} pair;

typedef struct {
    int *data;
    int size;
} array;

void read_image(char *filename, int *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }
    fread(image, sizeof(int), IMAGE_SIZE, fp);
    fclose(fp);
}

void write_image(char *filename, int *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }
    fwrite(image, sizeof(int), IMAGE_SIZE, fp);
    fclose(fp);
}

void add_watermark(int *image, int *watermark, pair *positions, int num_positions) {
    for (int i = 0; i < num_positions; i++) {
        int x = positions[i].position % WIDTH;
        int y = positions[i].position / WIDTH;
        int value = watermark[i];
        int index = y * WIDTH + x;
        image[index] += value;
    }
}

void extract_watermark(int *image, int *watermark, pair *positions, int num_positions) {
    for (int i = 0; i < num_positions; i++) {
        int x = positions[i].position % WIDTH;
        int y = positions[i].position / WIDTH;
        int index = y * WIDTH + x;
        watermark[i] = image[index] - (i % 2 == 0? 0 : 1);
    }
}

void generate_watermark(int *watermark, int num_bits) {
    for (int i = 0; i < num_bits; i++) {
        watermark[i] = rand() % 2;
    }
}

int main() {
    char input_filename[256];
    char output_filename[256];
    printf("Enter input image filename: ");
    scanf("%s", input_filename);
    printf("Enter output image filename: ");
    scanf("%s", output_filename);

    int *image = malloc(IMAGE_SIZE * sizeof(int));
    int *watermark = malloc(EMBED_BITS * sizeof(int));
    pair *positions = malloc(EMBED_BITS * sizeof(pair));

    read_image(input_filename, image);

    generate_watermark(watermark, EMBED_BITS);

    for (int i = 0; i < EMBED_BITS; i++) {
        positions[i].value = watermark[i];
        positions[i].position = rand() % IMAGE_SIZE;
    }

    add_watermark(image, watermark, positions, EMBED_BITS);

    write_image(output_filename, image);

    free(image);
    free(watermark);
    free(positions);

    return 0;
}