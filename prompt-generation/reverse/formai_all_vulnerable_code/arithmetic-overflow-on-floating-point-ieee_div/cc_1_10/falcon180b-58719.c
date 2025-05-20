//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the intersection of two circles
double intersect(double x1, double y1, double r1, double x2, double y2, double r2)
{
    double d = distance(x1, y1, x2, y2);
    double a = r1 + r2;
    double h = a * a - d * d;

    if (h < 0)
    {
        return -1;
    }

    double c = 2 * sqrt(h);
    double xc = x1 + c * (x2 - x1) / d;
    double yc = y1 + c * (y2 - y1) / d;

    return c;
}

// Function to generate a Fibonacci spiral
void spiral(int n, double x1, double y1, double x2, double y2, double r1, double r2)
{
    double angle = 0;
    double delta = PI / n;

    for (int i = 0; i < n; i++)
    {
        double x = x1 + r1 * cos(angle);
        double y = y1 + r1 * sin(angle);

        if (i > 0)
        {
            double c = intersect(x1, y1, r1, x2, y2, r2);

            if (c >= 0)
            {
                double xc = x1 + c * (x2 - x1) / distance(x1, y1, x2, y2);
                double yc = y1 + c * (y2 - y1) / distance(x1, y1, x2, y2);

                x = xc;
                y = yc;
            }
        }

        printf("%.2f %.2f\n", x, y);

        angle += delta;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    double x1 = 0, y1 = 0;
    double x2 = 1, y2 = 1;
    double r1 = 0.05, r2 = 0.15;

    spiral(n, x1, y1, x2, y2, r1, r2);

    return 0;
}