//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: invasive
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pixel {
    char c;
    int x;
    int y;
} pixel;

typedef struct _font {
    int width;
    int height;
    pixel **pixels;
} font;

typedef struct _image {
    int width;
    int height;
    pixel **pixels;
} image;

void print_image(image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            printf("%c", img->pixels[y][x].c);
        }
        printf("\n");
    }
}

void destroy_image(image *img) {
    for (int y = 0; y < img->height; y++) {
        free(img->pixels[y]);
    }
    free(img->pixels);
    free(img);
}

image *create_image(int width, int height) {
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(sizeof(pixel *) * height);
    for (int y = 0; y < height; y++) {
        img->pixels[y] = malloc(sizeof(pixel) * width);
    }
    return img;
}

void set_pixel(image *img, int x, int y, char c) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return;
    }
    img->pixels[y][x].c = c;
    img->pixels[y][x].x = x;
    img->pixels[y][x].y = y;
}

pixel *get_pixel(image *img, int x, int y) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return NULL;
    }
    return &img->pixels[y][x];
}

font *create_font(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }
    font *font = malloc(sizeof(font));
    fscanf(fp, "%d %d", &font->width, &font->height);
    font->pixels = malloc(sizeof(pixel *) * font->height);
    for (int y = 0; y < font->height; y++) {
        font->pixels[y] = malloc(sizeof(pixel) * font->width);
        for (int x = 0; x < font->width; x++) {
            fscanf(fp, " %c", &font->pixels[y][x].c);
        }
    }
    fclose(fp);
    return font;
}

void destroy_font(font *font) {
    for (int y = 0; y < font->height; y++) {
        free(font->pixels[y]);
    }
    free(font->pixels);
    free(font);
}

image *render_text(font *font, char *text) {
    int width = strlen(text) * font->width;
    int height = font->height;
    image *img = create_image(width, height);
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        for (int y = 0; y < font->height; y++) {
            for (int x = 0; x < font->width; x++) {
                pixel *pixel = get_pixel(font, x, y);
                if (pixel->c == c) {
                    set_pixel(img, i * font->width + x, y, pixel->c);
                }
            }
        }
    }
    return img;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <font_file> <text>\n", argv[0]);
        return -1;
    }
    font *font = create_font(argv[1]);
    if (font == NULL) {
        printf("Error: could not load font file %s\n", argv[1]);
        return -1;
    }
    image *img = render_text(font, argv[2]);
    print_image(img);
    destroy_image(img);
    destroy_font(font);
    return 0;
}