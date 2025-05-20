//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60

void convert_to_grayscale(unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *gray, int pixels);
void convert_to_ascii(unsigned char *gray, char *ascii, int pixels, int width);
void draw_ascii(char *ascii, int width, int height);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s [image file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    unsigned char header[54];
    fread(header, 1, 54, fp);

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    if (width > WIDTH || height > HEIGHT) {
        printf("Image is too large. Maximum size is %dx%d.\n", WIDTH, HEIGHT);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    int row_padding = (4 - (width * 3) % 4) % 4;
    int pixels = width * height;
    unsigned char *data = (unsigned char *)malloc(pixels * 3 + height * row_padding);
    fread(data, 1, pixels * 3 + height * row_padding, fp);
    fclose(fp);

    unsigned char *r = (unsigned char *)malloc(pixels);
    unsigned char *g = (unsigned char *)malloc(pixels);
    unsigned char *b = (unsigned char *)malloc(pixels);
    unsigned char *gray = (unsigned char *)malloc(pixels);
    char *ascii = (char *)malloc(pixels + height);

    int idx = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            b[idx] = data[3 * (y * width + x)];
            g[idx] = data[3 * (y * width + x) + 1];
            r[idx] = data[3 * (y * width + x) + 2];
            idx++;
        }
        idx += row_padding;
    }

    convert_to_grayscale(r, g, b, gray, pixels);
    convert_to_ascii(gray, ascii, pixels, width);
    draw_ascii(ascii, width, height);

    free(data);
    free(r);
    free(g);
    free(b);
    free(gray);
    free(ascii);
}

void convert_to_grayscale(unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *gray, int pixels)
{
    for (int i = 0; i < pixels; i++) {
        gray[i] = (unsigned char)(0.21 * r[i] + 0.72 * g[i] + 0.07 * b[i]);
    }
}

void convert_to_ascii(unsigned char *gray, char *ascii, int pixels, int width)
{
    const char *ascii_chars = " .,:;i1tfLCG08@";
    const int num_chars = strlen(ascii_chars);
    const double range = 255.0 / (num_chars - 1);

    for (int i = 0; i < pixels; i++) {
        int index = (int)floor(gray[i] / range + 0.5);
        ascii[i] = ascii_chars[index];
        if ((i + 1) % width == 0) {
            ascii[i] = '\n';
        }
    }
}

void draw_ascii(char *ascii, int width, int height)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(ascii[i * width + j]);
        }
    }
    putchar('\n');
}