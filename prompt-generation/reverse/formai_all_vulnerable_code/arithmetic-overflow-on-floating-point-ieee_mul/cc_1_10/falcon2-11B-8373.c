//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: imaginative
#include <stdio.h>
#include <math.h>

int main() {
    int i, j;
    float x, y;
    float cx, cy;
    float r, g, b;
    float xr, yr, xi, yi;
    int iter = 0;
    float xmin = -2.0;
    float xmax = 1.0;
    float ymin = -1.5;
    float ymax = 1.5;
    int width = 800;
    int height = 600;

    printf("Enter the center coordinates of the Mandelbrot set (x, y):\n");
    scanf("%f %f", &cx, &cy);

    printf("Enter the maximum number of iterations:\n");
    scanf("%d", &iter);

    printf("Enter the width and height of the image:\n");
    scanf("%d %d", &width, &height);

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            x = xmin + (xmax - xmin) * (float)i / width;
            y = ymin + (ymax - ymin) * (float)j / height;
            xr = x - cx;
            yr = y - cy;
            xi = xr * xr - yr * yr + cx;
            yi = 2.0 * xr * yr + cy;

            r = 0.0;
            g = 0.0;
            b = 0.0;

            while (r * r + g * g < 4.0 && iter > 0) {
                x = xi - yi * r * r;
                y = yi + xi * r * r;
                xr = x - cx;
                yr = y - cy;
                xi = xr * xr - yr * yr + cx;
                yi = 2.0 * xr * yr + cy;
                r += yi;
                g += xr;
                b += yr;
                iter--;
            }

            if (r * r + g * g < 4.0) {
                b = 255.0;
            } else {
                r = 255.0;
            }

            printf("%d %d %d\n", (int)r, (int)g, (int)b);
        }
    }

    return 0;
}