//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
    int i, j, n, iterations;
    double x, y, real, imag, c_re, c_im;
    char filename[20];

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    for (n = 0; n < iterations; n++) {
        for (i = 0; i < HEIGHT; i++) {
            y = (double)i / HEIGHT * 3.0;
            for (j = 0; j < WIDTH; j++) {
                x = (double)j / WIDTH * 2.0 - 1.0;
                c_re = x;
                c_im = y;
                real = 0.0;
                imag = 0.0;

                for (int k = 0; k < iterations; k++) {
                    real = real*real - imag*imag + c_re;
                    imag = 2*real*imag + c_im;
                }

                if (real*real + imag*imag > 4.0) {
                    printf(".");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\nPress any key to save the fractal image...\n");
        scanf(" %c", &filename[0]);
        FILE *fp;
        fp = fopen(filename, "wb");
        fprintf(fp, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                fprintf(fp, "%c", (int)((double)n / iterations * 256.0));
            }
        }
        fclose(fp);
    }

    return 0;
}