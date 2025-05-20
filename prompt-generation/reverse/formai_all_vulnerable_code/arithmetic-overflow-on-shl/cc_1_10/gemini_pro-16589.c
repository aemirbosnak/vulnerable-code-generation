//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: portable
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WIDTH  800
#define HEIGHT 600

#define MAX_ITER  255
#define EPSILON   0.00001

typedef uint8_t u8;
typedef uint32_t u32;

struct complex {
    double re, im;
};

void mandelbrot(struct complex c, u8 iterations[]) {
    struct complex z = {0, 0};
    for (u8 i = 0; i < MAX_ITER; i++) {
        z.re = z.re * z.re - z.im * z.im + c.re;
        z.im = 2 * z.re * z.im + c.im;
        iterations[i] = i;
        if (z.re * z.re + z.im * z.im > 4.0) {
            return;
        }
    }
    memset(iterations, 0, MAX_ITER);
}

u8 colorize(u8 iterations[]) {
    if (iterations[0] == MAX_ITER) {
        return 0;  // black
    }
    u32 color = 0x00FF00;  // green
    for (u8 i = 0; i < MAX_ITER; i++) {
        if (iterations[i] != i) {
            color = (color >> 8) | ((MAX_ITER - 1 - i) << 24);  // shift color to red
            break;
        }
    }
    return color;
}

int main() {
    u8 iterations[MAX_ITER];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            struct complex c = {
                .re = 3.5 * (x - WIDTH / 2) / (WIDTH / 4),
                .im = 2.5 * (y - HEIGHT / 2) / (HEIGHT / 3)
            };
            mandelbrot(c, iterations);
            u8 color = colorize(iterations);
            // output the color to a file or display it on the screen
        }
    }
    return 0;
}