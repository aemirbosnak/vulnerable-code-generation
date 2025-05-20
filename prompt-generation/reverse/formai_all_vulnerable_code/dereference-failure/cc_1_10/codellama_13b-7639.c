//Code Llama-13B DATASET v1.0 Category: Image Editor ; Style: happy
// Image Editor Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int width;
    int height;
    int* pixels;
} Image;

Image* create_image(int width, int height) {
    Image* image = (Image*)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (int*)malloc(width * height * sizeof(int));
    return image;
}

void destroy_image(Image* image) {
    free(image->pixels);
    free(image);
}

void draw_pixel(Image* image, int x, int y, int color) {
    image->pixels[y * image->width + x] = color;
}

int get_pixel(Image* image, int x, int y) {
    return image->pixels[y * image->width + x];
}

void set_pixel(Image* image, int x, int y, int color) {
    image->pixels[y * image->width + x] = color;
}

void draw_line(Image* image, int x1, int y1, int x2, int y2, int color) {
    int x, y;
    for (x = x1; x <= x2; x++) {
        y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
        draw_pixel(image, x, y, color);
    }
}

void draw_circle(Image* image, int x, int y, int radius, int color) {
    int x0 = x - radius;
    int y0 = y - radius;
    int x1 = x + radius;
    int y1 = y + radius;
    int dx, dy;
    for (dy = y0; dy <= y1; dy++) {
        for (dx = x0; dx <= x1; dx++) {
            int dist = sqrt((x - dx) * (x - dx) + (y - dy) * (y - dy));
            if (dist <= radius) {
                draw_pixel(image, dx, dy, color);
            }
        }
    }
}

void draw_ellipse(Image* image, int x, int y, int width, int height, int color) {
    int x0 = x - width / 2;
    int y0 = y - height / 2;
    int x1 = x + width / 2;
    int y1 = y + height / 2;
    int dx, dy;
    for (dy = y0; dy <= y1; dy++) {
        for (dx = x0; dx <= x1; dx++) {
            int a = (dx - x) * (dx - x) / (width * width);
            int b = (dy - y) * (dy - y) / (height * height);
            if (a + b <= 1) {
                draw_pixel(image, dx, dy, color);
            }
        }
    }
}

void draw_rectangle(Image* image, int x, int y, int width, int height, int color) {
    int x0 = x;
    int y0 = y;
    int x1 = x + width;
    int y1 = y + height;
    int dx, dy;
    for (dy = y0; dy <= y1; dy++) {
        for (dx = x0; dx <= x1; dx++) {
            draw_pixel(image, dx, dy, color);
        }
    }
}

void draw_triangle(Image* image, int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    int x, y;
    for (y = y1; y <= y3; y++) {
        for (x = x1; x <= x2; x++) {
            draw_pixel(image, x, y, color);
        }
        for (x = x2; x <= x3; x++) {
            draw_pixel(image, x, y, color);
        }
    }
}

void draw_text(Image* image, int x, int y, char* text, int color) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        draw_pixel(image, x + i, y, color);
    }
}

void save_image(Image* image, char* filename) {
    FILE* file = fopen(filename, "w");
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(int), image->width * image->height, file);
    fclose(file);
}

int main() {
    Image* image = create_image(1000, 1000);
    int i;
    for (i = 0; i < image->width * image->height; i++) {
        image->pixels[i] = 0;
    }
    draw_line(image, 100, 100, 900, 900, 255);
    draw_circle(image, 500, 500, 250, 255);
    draw_ellipse(image, 750, 750, 250, 150, 255);
    draw_rectangle(image, 100, 100, 300, 300, 255);
    draw_triangle(image, 100, 100, 500, 100, 500, 500, 255);
    draw_text(image, 500, 500, "Hello World!", 255);
    save_image(image, "image.ppm");
    destroy_image(image);
    return 0;
}