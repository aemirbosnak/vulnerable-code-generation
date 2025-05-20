//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITERATIONS 1000

int mandelbrot(int x, int y) {
    double real = x / (WIDTH / 2.0) - 1.0;
    double imag = y / (HEIGHT / 2.0) - 1.0;
    double zx = 0, zy = 0, temp;
    int iterations = 0;

    while (iterations < MAX_ITERATIONS && zx * zx + zy * zy < 4) {
        temp = zx * zx - zy * zy + real;
        zy = 2 * zx * zy + imag;
        zx = temp;
        iterations++;
    }

    return iterations % 8;
}

void generate_mandelbrot(char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    unsigned char header[54] = {
        0x42, 0x4d, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    fwrite(header, 1, sizeof(header), fp);

    unsigned char* data = (unsigned char*)malloc(WIDTH * HEIGHT);
    memset(data, 0, WIDTH * HEIGHT);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int value = mandelbrot(x, y);
            data[y * WIDTH + x] = value;
        }
    }

    fwrite(data, 1, WIDTH * HEIGHT, fp);

    free(data);
    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <output_file> <max_iterations>\n", argv[0]);
        return 1;
    }

    srand(time(NULL));

    int max_iterations = atoi(argv[2]);

    generate_mandelbrot(argv[1]);

    printf("Generated Mandelbrot set with max iterations %d and saved to file %s\n",
            max_iterations, argv[1]);

    return 0;
}