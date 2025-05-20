//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

int main()
{
    int x, y, iterations;
    double real, imag, temp;

    printf("Enter the fractal type:\n");
    printf("1. Mandelbrot set\n");
    printf("2. Julia set\n");
    scanf("%d", &iterations);

    for(y=0; y<HEIGHT; y++)
    {
        for(x=0; x<WIDTH; x++)
        {
            real = (double)x/(double)WIDTH*3.5-2.5;
            imag = (double)y/(double)HEIGHT*2-1;

            if(iterations == 1)
            {
                temp = real;
                real = imag;
                imag = temp;
            }

            int i;
            for(i=0; i<MAX_ITERATIONS; i++)
            {
                temp = real*real - imag*imag + real;
                imag = 2*real*imag + imag;
                real = temp;

                if(real*real + imag*imag > 4)
                {
                    break;
                }
            }

            if(i == MAX_ITERATIONS)
            {
                printf("*");
            }
            else
            {
                int color = i % 8;
                printf("\x1b[38;5;%dm ", (30+color) % 256);
            }
        }
        printf("\n");
    }

    return 0;
}