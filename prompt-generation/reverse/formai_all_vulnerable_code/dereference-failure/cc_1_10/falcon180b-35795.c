//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define MAX_CHARS (MAX_WIDTH * MAX_HEIGHT)

typedef struct {
    char *filename;
    int width;
    int height;
    char *data;
} Image;

int load_image(Image *image) {
    FILE *fp = fopen(image->filename, "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", image->filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = malloc(size);
    if (image->data == NULL) {
        printf("Error: cannot allocate memory for image data\n");
        return 1;
    }

    size_t n = fread(image->data, 1, size, fp);
    if (n!= size) {
        printf("Error: cannot read image data\n");
        return 1;
    }

    fclose(fp);
    return 0;
}

int save_ascii_art(Image *image, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return 1;
    }

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int index = y * image->width + x;
            char c = image->data[index];

            if (isprint(c)) {
                fprintf(fp, "%c", c);
            } else {
                fprintf(fp, ".");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s input.bmp output.txt\n", argv[0]);
        return 1;
    }

    Image image = {
       .filename = argv[1],
       .width = 0,
       .height = 0,
       .data = NULL,
    };

    if (load_image(&image)) {
        return 1;
    }

    char *output_filename = argv[2];
    if (save_ascii_art(&image, output_filename)) {
        return 1;
    }

    printf("ASCII art saved to %s\n", output_filename);
    return 0;
}