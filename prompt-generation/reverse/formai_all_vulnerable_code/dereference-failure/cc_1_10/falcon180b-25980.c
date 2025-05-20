//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define CHAR_SET ".:-=+*#@"

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image loadImage(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(filesize);
    fread(data, 1, filesize, fp);
    fclose(fp);

    int width, height;
    unsigned char *p = data;
    while (*p!= 0xff) p++;
    p++;
    width = *(int *)p;
    p += 4;
    height = *(int *)p;

    Image img = {width, height, data};
    return img;
}

void saveAscii(const Image *img, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    int width = img->width;
    int height = img->height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = (int)img->data[y * width + x] / 16;
            fprintf(fp, "%c", CHAR_SET[value]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii>\n", argv[0]);
        return 1;
    }

    Image img = loadImage(argv[1]);
    saveAscii(&img, argv[2]);

    free(img.data);
    return 0;
}