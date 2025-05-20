//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define WATERMARK_SIZE 16
#define IMAGE_SIZE 512
#define MAX_WATERMARK 10

typedef struct {
    char *filename;
    int watermark_count;
} image_t;

void generate_watermark(char *filename, int count) {
    FILE *fp;
    char *watermark = (char *) malloc(WATERMARK_SIZE * sizeof(char));
    int i;

    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    for (i = 0; i < count; i++) {
        sprintf(watermark, "Watermark %d", i+1);
        fseek(fp, 0, SEEK_END);
        fwrite(watermark, 1, WATERMARK_SIZE, fp);
        fseek(fp, 0, SEEK_SET);
    }

    fclose(fp);
}

void read_images(image_t *images, int num_images) {
    FILE *fp;
    char *buffer;
    int i;

    for (i = 0; i < num_images; i++) {
        sprintf(images[i].filename, "image%d.jpg", i+1);
        fp = fopen(images[i].filename, "r");
        if (fp == NULL) {
            printf("Error: Cannot open file %s\n", images[i].filename);
            exit(1);
        }

        buffer = (char *) malloc(IMAGE_SIZE * sizeof(char));
        fread(buffer, 1, IMAGE_SIZE, fp);
        fclose(fp);

        images[i].watermark_count = 0;
    }
}

void add_watermark(image_t *images, int num_images) {
    int i;

    for (i = 0; i < num_images; i++) {
        if (images[i].watermark_count < MAX_WATERMARK) {
            generate_watermark(images[i].filename, images[i].watermark_count+1);
            images[i].watermark_count++;
        }
    }
}

int main() {
    image_t images[10];
    int num_images;

    printf("Enter the number of images: ");
    scanf("%d", &num_images);

    read_images(images, num_images);

    printf("Adding watermarks to images...\n");
    add_watermark(images, num_images);

    printf("Done.\n");

    return 0;
}