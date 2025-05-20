//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Donald Knuth
#include <stdio.h>
#include <math.h>

void draw_fractal(int x1, int y1, int x2, int y2, int n);
void draw_line(int x1, int y1, int x2, int y2);
void wait();

int main()
{
    int x1, y1, x2, y2, n;

    printf("Enter the initial x coordinate: ");
    scanf("%d", &x1);

    printf("Enter the initial y coordinate: ");
    scanf("%d", &y1);

    printf("Enter the final x coordinate: ");
    scanf("%d", &x2);

    printf("Enter the final y coordinate: ");
    scanf("%d", &y2);

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    draw_fractal(x1, y1, x2, y2, n);

    wait();

    return 0;
}

void draw_fractal(int x1, int y1, int x2, int y2, int n)
{
    if(n == 0)
    {
        draw_line(x1, y1, x2, y2);
    }
    else
    {
        int dx = x2 - x1;
        int dy = y2 - y1;

        int x3 = x1 + dx / 3;
        int y3 = y1 + dy / 3;

        int x4 = x2 - dx / 3;
        int y4 = y2 - dy / 3;

        int x5 = x3 + (x4 - x3) * cos(M_PI / 3) - (y4 - y3) * sin(M_PI / 3);
        int y5 = y3 + (x4 - x3) * sin(M_PI / 3) + (y4 - y3) * cos(M_PI / 3);

        draw_fractal(x1, y1, x3, y3, n - 1);
        draw_fractal(x3, y3, x5, y5, n - 1);
        draw_fractal(x5, y5, x4, y4, n - 1);
        draw_fractal(x4, y4, x2, y2, n - 1);
    }
}

void draw_line(int x1, int y1, int x2, int y2)
{
    printf("line(%d, %d, %d, %d)\n", x1, y1, x2, y2);
}

void wait()
{
    printf("Press any key to continue...");
    getchar();
}