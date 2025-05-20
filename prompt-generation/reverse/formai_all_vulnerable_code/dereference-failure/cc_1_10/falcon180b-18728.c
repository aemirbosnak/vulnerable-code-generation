//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]\:;?><,./-="


typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image loadImage(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open image file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(filesize);
    if (data == NULL) {
        printf("Error: Failed to allocate memory for image data\n");
        exit(1);
    }

    fread(data, filesize, 1, fp);
    fclose(fp);

    Image img = {0};
    img.width = *(int *)data;
    img.height = *(int *)(data + 4);
    img.data = data + 8;

    return img;
}

void saveAsciiArt(Image img, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Failed to open output file %s\n", filename);
        exit(1);
    }

    int maxCharWidth = strlen(CHAR_SET);
    int asciiArtWidth = img.width * maxCharWidth;

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            int pixel = *(img.data + y * img.width + x) * maxCharWidth;
            fputc(CHAR_SET[pixel], fp);
        }
        fputc('\n', fp);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image img = loadImage(argv[1]);
    saveAsciiArt(img, argv[2]);

    printf("Conversion completed successfully!\n");
    return 0;
}