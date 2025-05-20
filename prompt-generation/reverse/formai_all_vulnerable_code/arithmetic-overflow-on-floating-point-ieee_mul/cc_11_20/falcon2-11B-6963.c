//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: genius
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int iterations = 100;
    double x, y;
    double dx, dy;
    double a, b, r;
    double alpha, beta;

    printf("Enter the initial x and y coordinates: ");
    scanf("%lf %lf", &x, &y);

    printf("Enter the step size for x and y: ");
    scanf("%lf %lf", &dx, &dy);

    printf("Enter the scaling factor for x and y: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the rotation angle: ");
    scanf("%lf", &alpha);

    printf("Enter the reflection angle: ");
    scanf("%lf", &beta);

    r = sqrt(a*a + b*b);

    for (int i = 0; i < iterations; i++) {
        x += (r * sin(alpha)) * dx;
        y += (r * cos(alpha)) * dy;
        if (x < -r || x > r) {
            x *= -1;
        }
        if (y < -r || y > r) {
            y *= -1;
        }
        if (x >= 0 && x <= r) {
            x += r;
        }
        if (y >= 0 && y <= r) {
            y += r;
        }
        if (fabs(x - a) < fabs(y - b)) {
            x += (fabs(x - a) - fabs(y - b)) * (y / (fabs(x - a))) * dy;
        }
        else {
            y += (fabs(x - a) - fabs(y - b)) * (x / (fabs(x - a))) * dx;
        }
        if (x > r) {
            x -= r;
        }
        if (y > r) {
            y -= r;
        }
        if (x < -r) {
            x += r;
        }
        if (y < -r) {
            y += r;
        }
    }

    printf("Iterations: %d\n", iterations);
    printf("x: %f\n", x);
    printf("y: %f\n", y);
    printf("r: %f\n", r);

    return 0;
}