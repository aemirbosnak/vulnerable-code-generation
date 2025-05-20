//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET ".,-:;=+*#@"

void draw_char(int x, int y, char c) {
    if (c >= 32 && c <= 126) {
        printf("%c", c);
    } else {
        printf(" ");
    }
}

void draw_image(char* filename, int scale) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char* data = malloc(file_size);
    if (data == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }

    fread(data, 1, file_size, fp);
    fclose(fp);

    int width = 0, height = 0;
    while (width * HEIGHT < height * WIDTH) {
        width += 1;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_index = (i * height + j) * 3;
            int r = data[pixel_index] * 0x101;
            int g = data[pixel_index + 1] * 0x101;
            int b = data[pixel_index + 2] * 0x101;

            int avg = (r + g + b) / 3;
            int char_index = avg / (255 / strlen(CHAR_SET));

            draw_char(j * scale, i * scale, CHAR_SET[char_index]);
        }
    }

    free(data);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <scale>\n", argv[0]);
        exit(1);
    }

    int scale = atoi(argv[2]);

    draw_image(argv[1], scale);

    return 0;
}