//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scientific
/* C Fractal Generation Example Program */

#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 

/* Function Prototypes */
int mandelbrot_set(double x, double y, int max_iterations);
int julia_set(double x, double y, double c_real, double c_img, int max_iterations);
void generate_fractal(char set_type, double start_x, double end_x, double start_y, double end_y, double c_real, double c_img, int max_iterations);

/* Main Function */
int main()
{
    char set_type;
    double start_x, end_x, start_y, end_y, c_real, c_img;
    int max_iterations;

    /* Prompt User for Inputs */
    printf("Which Set Would You Like to Generate? (M for Mandelbrot, J for Julia)\n");
    scanf("%c", &set_type);
    printf("Start X: ");
    scanf("%lf", &start_x);
    printf("End X: ");
    scanf("%lf", &end_x);
    printf("Start Y: ");
    scanf("%lf", &start_y);
    printf("End Y: ");
    scanf("%lf", &end_y);
    printf("C Real: ");
    scanf("%lf", &c_real);
    printf("C Imaginary: ");
    scanf("%lf", &c_img);
    printf("Maximum Iterations: ");
    scanf("%d", &max_iterations);

    /* Generate Fractal */
    generate_fractal(set_type, start_x, end_x, start_y, end_y, c_real, c_img, max_iterations);

    return 0;
}

/* Mandelbrot Set Function */
int mandelbrot_set(double x, double y, int max_iterations)
{
    double real_part = 0, imag_part = 0;
    double next_real_part, next_imag_part;
    int iteration = 0;

    while ((real_part * real_part) + (imag_part * imag_part) <= 4 && iteration < max_iterations)
    {
        next_real_part = (real_part * real_part) - (imag_part * imag_part) + x;
        next_imag_part = (2 * real_part * imag_part) + y;
        real_part = next_real_part;
        imag_part = next_imag_part;
        iteration++;
    }

    return iteration;
}

/* Julia Set Function */
int julia_set(double x, double y, double c_real, double c_img, int max_iterations)
{
    double real_part = x, imag_part = y;
    double next_real_part, next_imag_part;
    int iteration = 0;

    while ((real_part * real_part) + (imag_part * imag_part) <= 4 && iteration < max_iterations)
    {
        next_real_part = (real_part * real_part) - (imag_part * imag_part) + c_real;
        next_imag_part = (2 * real_part * imag_part) + c_img;
        real_part = next_real_part;
        imag_part = next_imag_part;
        iteration++;
    }

    return iteration;
}

/* Generate Fractal Function */
void generate_fractal(char set_type, double start_x, double end_x, double start_y, double end_y, double c_real, double c_img, int max_iterations)
{
    int width = 80, height = 40;

    double interval_x = (end_x - start_x) / width;
    double interval_y = (end_y - start_y) / height;

    int i, j, iterations;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            double x = start_x + j * interval_x;
            double y = start_y + i * interval_y;

            if (set_type == 'M')
            {
                iterations = mandelbrot_set(x, y, max_iterations);
            }
            else if (set_type == 'J')
            {
                iterations = julia_set(x, y, c_real, c_img, max_iterations);
            }

            /* Colorize Terminal Output */
            if (iterations >= max_iterations)
            {
                printf("\033[0;30m"); /* Black */
            }
            else if (iterations >= max_iterations * 3 / 4)
            {
                printf("\033[0;34m"); /* Blue */
            }
            else if (iterations >= max_iterations / 2)
            {
                printf("\033[0;32m"); /* Green */
            }
            else if (iterations >= max_iterations / 4)
            {
                printf("\033[0;33m"); /* Yellow */
            }
            else
            {
                printf("\033[0;31m"); /* Red */
            }

            printf("%c", iterations == max_iterations ? '*' : ' '); /* Asterisk Means Inside Set, Empty Space Means Outside */
        }
        printf("\036[m\n"); /* Reset Terminal Colors */
    }
}