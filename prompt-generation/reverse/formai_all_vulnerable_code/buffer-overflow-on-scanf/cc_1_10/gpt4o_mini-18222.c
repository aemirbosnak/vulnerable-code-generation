//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_ITER 1000

void generate_mandelbrot() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            double zx = 0, zy = 0; // Real and Imaginary parts
            double cX = (x - WIDTH / 4.0) * 4.0 / WIDTH; // Mapping to complex plane
            double cY = (y - HEIGHT / 2.0) * 4.0 / HEIGHT; // Mapping to complex plane
            int iter = 0;

            while (zx * zx + zy * zy < 4.0 && iter < MAX_ITER) {
                double temp = zx * zx - zy * zy + cX;
                zy = 2.0 * zx * zy + cY;
                zx = temp;
                iter++;
            }

            if (iter == MAX_ITER) {
                putchar('#'); // Inside the Mandelbrot set
            } else {
                putchar(' '); // Outside the Mandelbrot set
            }
        }
        putchar('\n');
    }
}

void save_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Could not open file for writing\n");
        return;
    }
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            double zx = 0, zy = 0; 
            double cX = (x - WIDTH / 4.0) * 4.0 / WIDTH; 
            double cY = (y - HEIGHT / 2.0) * 4.0 / HEIGHT; 
            int iter = 0;

            while (zx * zx + zy * zy < 4.0 && iter < MAX_ITER) {
                double temp = zx * zx - zy * zy + cX;
                zy = 2.0 * zx * zy + cY;
                zx = temp;
                iter++;
            }

            if (iter == MAX_ITER) {
                fputc('#', file); // Inside the Mandelbrot set
            } else {
                fputc(' ', file); // Outside the Mandelbrot set
            }
        }
        fputc('\n', file);
    }
    fclose(file);
}

int main() {
    int choice;
    printf("Mandelbrot Fractal Generator\n");
    printf("1. Display Fractal\n");
    printf("2. Save Fractal to File\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            generate_mandelbrot();
            break;
        case 2: {
            char filename[100];
            printf("Enter filename to save fractal: ");
            scanf("%s", filename);
            save_to_file(filename);
            printf("Fractal saved to %s\n", filename);
            break;
        }
        default:
            printf("Invalid choice! Exiting...\n");
            break;
    }

    return 0;
}