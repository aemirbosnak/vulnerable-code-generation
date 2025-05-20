//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000
#define WATERMARK "WATERMARK"

typedef struct {
    int width;
    int height;
    unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} Image;

void read_pgm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    
    char format[3];
    fscanf(file, "%2s", format);
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_val;
    fscanf(file, "%d", &max_val);
    
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j] = fgetc(file);
        }
    }
    fclose(file);
}

void write_pgm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    
    fprintf(file, "P5\n%d %d\n255\n", img->width, img->height);
    
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fputc(img->pixels[i][j], file);
        }
    }
    fclose(file);
}

void embed_watermark(Image *img) {
    int watermark_length = strlen(WATERMARK);
    for (int i = 0; i < watermark_length && i < img->width; i++) {
        img->pixels[0][i] = (img->pixels[0][i] + WATERMARK[i]) / 2;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.pgm> <output.pgm>\n", argv[0]);
        return 1;
    }
    
    Image img;
    read_pgm(argv[1], &img);
    
    embed_watermark(&img);
    
    write_pgm(argv[2], &img);
    
    printf("Watermark embedded successfully!\n");
    return 0;
}