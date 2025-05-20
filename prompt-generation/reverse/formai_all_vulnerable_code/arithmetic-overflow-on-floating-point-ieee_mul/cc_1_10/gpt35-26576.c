//FormAI DATASET v1.0 Category: Fractal Generation ; Style: visionary
#include <stdio.h>
#include <math.h>

#define WIDTH 1920
#define HEIGHT 1080
#define MAX_ITERATIONS 50

void generateFractal(unsigned char *buffer, double minReal, double maxReal, double minImaginary, double maxImaginary) {
    double realFactor = (maxReal - minReal) / WIDTH;
    double imaginaryFactor = (maxImaginary - minImaginary) / HEIGHT;
    double real, imaginary, zReal, zImaginary, nextZReal;
    unsigned char red, green, blue, brightness;
    int row, column, iteration;
    for (row = 0; row < HEIGHT; row++) {
        for (column = 0; column < WIDTH; column++) {
            real = minReal + column * realFactor;
            imaginary = maxImaginary - row * imaginaryFactor;
            zReal = 0;
            zImaginary = 0;
            brightness = 0;
            for (iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
                nextZReal = pow(zReal, 2) - pow(zImaginary, 2) + real;
                zImaginary = 2 * zReal * zImaginary + imaginary;
                zReal = nextZReal;
                if (pow(zReal, 2) + pow(zImaginary, 2) > 4) {
                    brightness = 255 - (iteration * 255 / MAX_ITERATIONS);
                    break;
                }
            }
            red = brightness;
            green = 0;
            blue = 0;
            buffer[row * WIDTH * 3 + column * 3] = red;
            buffer[row * WIDTH * 3 + column * 3 + 1] = green;
            buffer[row * WIDTH * 3 + column * 3 + 2] = blue;
        }
    }
}

int main(void) {
    unsigned char buffer[WIDTH * HEIGHT * 3];
    double minReal = -2;
    double maxReal = 2;
    double minImaginary = -1.5;
    double maxImaginary = 1.5;
    generateFractal(buffer, minReal, maxReal, minImaginary, maxImaginary);
    FILE *imageFile = fopen("fractal.ppm", "wb");
    fprintf(imageFile, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);
    fwrite(buffer, 1, WIDTH * HEIGHT * 3, imageFile);
    fclose(imageFile);
    return 0;
}