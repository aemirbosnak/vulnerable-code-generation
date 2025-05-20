//FormAI DATASET v1.0 Category: Fractal Generation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 1000
#define MULTIPLIER 8

typedef struct {
    double x;
    double y;
} complex;

int main() {
    int x, y, i;
    complex c, z, temp;
    double xmin = -2.0, xmax = 2.0, ymin = -2.0, ymax = 2.0;
    double pixel_width = (xmax - xmin) / WIDTH;
    double pixel_height = (ymax - ymin) / HEIGHT;
    int red, green, blue;
    char filename[20];
    sprintf(filename, "fractal-%d.bmp", (int) time(NULL));
    unsigned char header[54] = {
        0x42, 0x4D, 0x36, 0x00, 0x0C, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x20, 0x03, 0x00, 0x00, 0x00, 0x01,
        0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24,
        0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00
    };
    int padding_size = (4 - ((WIDTH * 3) % 4)) % 4;
    int stride = WIDTH * 3 + padding_size;
    int file_size = sizeof(header) + (stride * HEIGHT);
    unsigned char *image = (unsigned char *) malloc(stride * HEIGHT);
    memcpy(image, header, sizeof(header));
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            c.x = xmin + x * pixel_width;
            c.y = ymin + y * pixel_height;
            z.x = 0.0;
            z.y = 0.0;
            for (i = 0; i < MAX_ITERATIONS; i++) {
                temp.x = z.x * z.x - z.y * z.y + c.x;
                temp.y = 2 * z.x * z.y + c.y;
                if (temp.x * temp.x + temp.y * temp.y >= 4.0) {
                    break;
                }
                z = temp;
            }
            red = green = blue = (int) ((double) i / MAX_ITERATIONS * 255);
            image[(HEIGHT - 1 - y) * stride + x * 3 + 2] = red;
            image[(HEIGHT - 1 - y) * stride + x * 3 + 1] = green;
            image[(HEIGHT - 1 - y) * stride + x * 3] = blue;
            if (i == MAX_ITERATIONS && x % MULTIPLIER == 0 && y % MULTIPLIER == 0) {
                int size_multiplier = (int) ceil(MULTIPLIER / 2);
                for (int j = 0; j < size_multiplier; j++) {
                    for (int k = 0; k < size_multiplier; k++) {
                        image[(HEIGHT - 1 - (y - j)) * stride + (x - k) * 3 + 2] = 0xFF - red;
                        image[(HEIGHT - 1 - (y - j)) * stride + (x - k) * 3 + 1] = 0xFF - green;
                        image[(HEIGHT - 1 - (y - j)) * stride + (x - k) * 3] = 0xFF - blue;
                        if (k != 0) {
                            image[(HEIGHT - 1 - (y - j)) * stride + (x + k) * 3 + 2] = 0xFF - red;
                            image[(HEIGHT - 1 - (y - j)) * stride + (x + k) * 3 + 1] = 0xFF - green;
                            image[(HEIGHT - 1 - (y - j)) * stride + (x + k) * 3] = 0xFF - blue;
                        }
                        if (j != 0) {
                            image[(HEIGHT - 1 - (y + j)) * stride + (x - k) * 3 + 2] = 0xFF - red;
                            image[(HEIGHT - 1 - (y + j)) * stride + (x - k) * 3 + 1] = 0xFF - green;
                            image[(HEIGHT - 1 - (y + j)) * stride + (x - k) * 3] = 0xFF - blue;
                            if (k != 0) {
                                image[(HEIGHT - 1 - (y + j)) * stride + (x + k) * 3 + 2] = 0xFF - red;
                                image[(HEIGHT - 1 - (y + j)) * stride + (x + k) * 3 + 1] = 0xFF - green;
                                image[(HEIGHT - 1 - (y + j)) * stride + (x + k) * 3] = 0xFF - blue;
                            }
                        }
                    }
                }
            }
        }
    }
    FILE *fp = fopen(filename, "wb");
    fwrite(image, sizeof(unsigned char), stride * HEIGHT, fp);
    fclose(fp);
    printf("Fractal generated successfully and saved as %s\n", filename);
    free(image);
    return 0;
}