//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_IMAGE_SIZE (WIDTH * HEIGHT * 3)

typedef struct {
    char *data;
    int width;
    int height;
} image_t;

image_t *load_image(const char *file_name) {
    image_t *image = malloc(sizeof(image_t));
    int width, height;
    unsigned char *data;

    // Load image data from file
    FILE *file = fopen(file_name, "rb");
    fseek(file, 0, SEEK_END);
    width = ftell(file) / 3;
    height = width * (float)HEIGHT / WIDTH;
    data = malloc(width * height * 3);
    fseek(file, 0, SEEK_SET);
    fread(data, 1, width * height * 3, file);
    fclose(file);

    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

void save_image(const char *file_name, image_t *image) {
    FILE *file = fopen(file_name, "wb");
    fwrite(image->data, 1, image->width * image->height * 3, file);
    fclose(file);
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2, unsigned char color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int step_x = 1;
    int step_y = 1;
    int x = x1;
    int y = y1;

    if (dx > 0) {
        step_x = 1;
    } else if (dx < 0) {
        step_x = -1;
    }

    if (dy > 0) {
        step_y = 1;
    } else if (dy < 0) {
        step_y = -1;
    }

    for (int i = 0; i < abs(dx); i++) {
        image->data[y * image->width * 3 + x * 3] = color;
        x += step_x;
        if (x >= x2) {
            break;
        }
    }
}

void draw_rectangle(image_t *image, int x, int y, int width, int height, unsigned char color) {
    int left = x;
    int top = y;
    int right = x + width;
    int bottom = y + height;

    for (int i = left; i <= right; i++) {
        for (int j = top; j <= bottom; j++) {
            image->data[j * image->width * 3 + i * 3] = color;
        }
    }
}

void draw_circle(image_t *image, int x, int y, int radius, unsigned char color) {
    int x_offset = 0;
    int y_offset = 0;
    int factor = 1;

    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < radius; j++) {
            int dist = sqrt((x - x_offset) * (x - x_offset) + (y - y_offset) * (y - y_offset));
            if (dist <= radius) {
                image->data[((y_offset + j) * image->width * 3) + (x_offset + i) * 3] = color;
            }
            x_offset += factor;
            y_offset += factor;
            factor++;
        }
    }
}

void main() {
    image_t *image = load_image("image.bmp");

    // Draw some shapes
    draw_line(image, 100, 100, 200, 200, 0xFF0000);
    draw_rectangle(image, 300, 300, 100, 50, 0x00FF00);
    draw_circle(image, 400, 400, 50, 0x0000FF);

    // Save the modified image
    save_image("modified_image.bmp", image);

    // Clean up
    free(image->data);
    free(image);
}