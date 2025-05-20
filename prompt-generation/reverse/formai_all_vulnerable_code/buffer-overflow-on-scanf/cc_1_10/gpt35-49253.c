//FormAI DATASET v1.0 Category: Fractal Generation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 500
#define MAX_ITER 500

void drawPixel(int x, int y, char pixel[SIZE][SIZE], int iter)
{
    if(iter == MAX_ITER)
        pixel[y][x] = '.';
    else
        pixel[y][x] = ' ';
}

void fractal(double cx, double cy, double scale, char pixel[SIZE][SIZE])
{
    double x, y, xtemp;
    double x0, y0;
    double dist;
    int iter;

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            x0 = (double)j/SIZE*scale - scale/2.0 + cx;
            y0 = (double)i/SIZE*scale - scale/2.0 + cy;
            x = 0.0;
            y = 0.0;
            iter = 0;
            while(x*x + y*y < 4 && iter < MAX_ITER)
            {
                xtemp = x*x - y*y + x0;
                y = 2*x*y + y0;
                x = xtemp;
                iter++;
            }
            drawPixel(j, i, pixel, iter);
        }
    }
}


int main()
{
    double cx, cy, scale;
    char pixel[SIZE][SIZE];
    
    printf("Enter the cx value (-1.5 to 1.5): ");
    scanf("%lf", &cx);
    printf("Enter the cy value (-1.5 to 1.5): ");
    scanf("%lf", &cy);
    printf("Enter the scale value (0.001 to 10): ");
    scanf("%lf", &scale);

    fractal(cx, cy, scale, pixel);

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            printf("%c", pixel[i][j]);
        }
        printf("\n");
    }

    return 0;
}