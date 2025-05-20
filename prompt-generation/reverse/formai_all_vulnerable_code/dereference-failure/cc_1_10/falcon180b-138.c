//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define ASCII_CHARS ".,:;i1tT+@#%=&*^_~"

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    unsigned char *data = malloc(filesize);
    fread(data, filesize, 1, fp);
    fclose(fp);

    int width, height;
    if (data[0] == 'B' && data[1] == 'M') {
        width = *(int *)&data[18];
        height = *(int *)&data[22];
    } else if (data[0] == 'P' && data[1] == 'N' && data[2] == 'G') {
        width = *(int *)&data[16];
        height = *(int *)&data[20];
    } else {
        printf("Error: unsupported image format\n");
        exit(1);
    }

    Image img = {width, height, data};
    return img;
}

void convert_to_ascii(Image img, char *output) {
    int width = img.width;
    int height = img.height;
    unsigned char *data = img.data;

    int ascii_index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int brightness = data[y * width + x];
            int ascii_char = ASCII_CHARS[brightness / 32];
            output[ascii_index++] = ascii_char;
        }
        output[ascii_index++] = '\n';
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_image output_ascii\n", argv[0]);
        exit(1);
    }

    Image img = load_image(argv[1]);
    char *output = malloc(MAX_WIDTH * img.height + 1);

    convert_to_ascii(img, output);

    FILE *fp = fopen(argv[2], "wb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[2]);
        exit(1);
    }

    fwrite(output, MAX_WIDTH * img.height, 1, fp);
    fclose(fp);

    printf("ASCII art generated in %s\n", argv[2]);

    return 0;
}