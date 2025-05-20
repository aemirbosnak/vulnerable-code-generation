//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int width;
    int height;
    char data[MAX_SIZE];
} Image;

Image createImage(int width, int height) {
    Image img = {0};
    img.width = width;
    img.height = height;
    img.data[0] = '\0';
    return img;
}

void drawPixel(Image *img, int x, int y, char color) {
    int offset = (y * img->width + x) * 3;
    img->data[offset] = color;
    img->data[offset + 1] = color;
    img->data[offset + 2] = color;
}

void drawLine(Image *img, int x1, int y1, int x2, int y2, char color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2? 1 : -1;
    int sy = y1 < y2? 1 : -1;
    int err = dx - dy;

    while (1) {
        drawPixel(img, x1, y1, color);
        if (x1 == x2 && y1 == y2) {
            break;
        }
        int e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x1 += sx;
        } else {
            err += dx;
            y1 += sy;
        }
    }
}

void drawRect(Image *img, int x, int y, int width, int height, char color) {
    drawLine(img, x, y, x + width - 1, y, color);
    drawLine(img, x, y, x, y + height - 1, color);
    drawLine(img, x + width - 1, y, x + width - 1, y + height - 1, color);
    drawLine(img, x, y + height - 1, x + width - 1, y + height - 1, color);
}

void drawCircle(Image *img, int x, int y, int radius, char color) {
    int xc = x + radius;
    int yc = y + radius;

    for (int i = 0; i <= radius; i++) {
        drawLine(img, xc, yc, xc + i, yc, color);
        drawLine(img, xc, yc, xc, yc + i, color);
        drawLine(img, xc - i, yc, xc, yc + i, color);
        drawLine(img, xc, yc - i, xc + i, yc, color);
    }
}

void saveImage(Image *img, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Cannot open file for writing.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 1, strlen(img->data), fp);

    fclose(fp);
}

int main() {
    Image img = createImage(500, 500);

    drawRect(&img, 50, 50, 200, 200, 'R');
    drawCircle(&img, 300, 300, 100, 'G');

    saveImage(&img, "example.png");

    return 0;
}