//FormAI DATASET v1.0 Category: Image compression ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} pixel_t;

typedef struct {
    int width, height;
    pixel_t *pixels;
} bitmap_t;

/* function to read bitmap from a file */
bitmap_t *read_bmp(FILE *f) {
    bitmap_t *bmp = malloc(sizeof(bitmap_t));
    fseek(f, 18, SEEK_SET);
    fread(&bmp->width, sizeof(bmp->width), 1, f);
    fread(&bmp->height, sizeof(bmp->height), 1, f);
    bmp->pixels = malloc(sizeof(pixel_t) * bmp->width * bmp->height);
    fseek(f, 54, SEEK_SET);
    fread(bmp->pixels, sizeof(pixel_t), bmp->width * bmp->height, f);
    return bmp;
}

/* function to write bitmap to a file */
void write_bmp(bitmap_t *bmp, FILE *f) {
    int i, j;
    fwrite("BM", 1, 2, f);
    int size = bmp->width * bmp->height * 3 + 54;
    fwrite(&size, 4, 1, f);
    fwrite("\0\0\0\0", 4, 1, f);
    int offset = 54;
    fwrite(&offset, 4, 1, f);
    int header_size = 40;
    fwrite(&header_size, 4, 1, f);
    fwrite(&bmp->width, 4, 1, f);
    fwrite(&bmp->height, 4, 1, f);
    fwrite("\1\0", 2, 1, f);
    fwrite("\x18\0", 2, 1, f);
    fwrite("\0\0\0\0", 4, 1, f);
    fwrite(&size, 4, 1, f);
    fwrite("\0\0\0\0", 4, 1, f);
    fwrite("\0\0\0\0", 4, 1, f);
    fwrite("\0\0\0\0", 4, 1, f);
    fwrite(bmp->pixels, sizeof(pixel_t), bmp->width * bmp->height, f);
}

/* function to compress bitmap */
void compress_bmp(bitmap_t *bmp) {
    int i, j;
    for (i = 0; i < bmp->width * bmp->height; i++) {
        pixel_t p = bmp->pixels[i];
        p.r = (p.r >> 2) << 2;
        p.g = (p.g >> 2) << 2;
        p.b = (p.b >> 2) << 2;
        bmp->pixels[i] = p;
    }
}

int main() {
    FILE *f = fopen("image.bmp", "rb");
    if (!f) {
        printf("Error: could not open image.bmp\n");
        return 1;
    }
    bitmap_t *bmp = read_bmp(f);
    fclose(f);
    compress_bmp(bmp);
    f = fopen("compressed.bmp", "wb");
    if (!f) {
        printf("Error: could not create compressed.bmp\n");
        return 1;
    }
    write_bmp(bmp, f);
    fclose(f);
    free(bmp->pixels);
    free(bmp);
    printf("Image compression complete.\n");
    return 0;
}