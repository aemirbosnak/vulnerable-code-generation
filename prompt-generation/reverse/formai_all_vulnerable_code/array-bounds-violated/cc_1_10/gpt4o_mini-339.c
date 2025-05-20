//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 40
#define HEIGHT 20

typedef struct {
    char pixels[HEIGHT][WIDTH + 1]; // Extra space for null terminator
} Canvas;

void initCanvas(Canvas *canvas) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            canvas->pixels[y][x] = ' ';
        }
        canvas->pixels[y][WIDTH] = '\0'; // Null terminate each row
    }
}

void drawPixel(Canvas *canvas, int x, int y, char c) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas->pixels[y][x] = c;
    }
}

void drawRectangle(Canvas *canvas, int x, int y, int width, int height, char c) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            drawPixel(canvas, x + j, y + i, c);
        }
    }
}

void drawCircle(Canvas *canvas, int centerX, int centerY, int radius, char c) {
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                drawPixel(canvas, centerX + x, centerY + y, c);
            }
        }
    }
}

void drawHeart(Canvas *canvas) {
    char heart[] = {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ',
        ' ', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ',
        '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
    };
    int idx = 0;
    for (int y = 6; y < 15; y++) {
        for (int x = 12; x < 28; x++) {
            drawPixel(canvas, x, y, heart[idx++]);
        }
    }
}

void renderCanvas(const Canvas *canvas) {
    system("clear");
    for (int y = 0; y < HEIGHT; y++) {
        printf("%s\n", canvas->pixels[y]);
    }
}

void saveCanvasToFile(const Canvas *canvas, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing: %s\n", filename);
        return;
    }
    for (int y = 0; y < HEIGHT; y++) {
        fprintf(file, "%s\n", canvas->pixels[y]);
    }
    fclose(file);
}

int main() {
    Canvas canvas;
    initCanvas(&canvas);

    // Draw a rectangle
    drawRectangle(&canvas, 1, 1, 38, 18, '#');

    // Draw a circle
    drawCircle(&canvas, 20, 10, 5, 'O');

    // Draw a heart
    drawHeart(&canvas);

    // Render the canvas
    renderCanvas(&canvas);

    // Optional save to file
    saveCanvasToFile(&canvas, "pixel_art.txt");

    return 0;
}