//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: romantic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    float x, y, r, theta, x1, y1, x2, y2, x3, y3, x4, y4, angle, a, b, c, d, e, f, g, h, i, j, k, l;

    printf("Enter the radius of the circle: ");
    scanf("%f", &r);

    printf("Enter the angle in degrees: ");
    scanf("%f", &angle);

    angle = angle * (PI / 180);

    x = r * cos(angle);
    y = r * sin(angle);

    printf("The coordinates of the first point are (%f, %f)\n", x, y);

    theta = 0;

    for (int i = 0; i < 360; i += 45) {
        x1 = r * cos(theta);
        y1 = r * sin(theta);

        theta += PI / 8;

        x2 = r * cos(theta);
        y2 = r * sin(theta);

        theta += PI / 8;

        x3 = r * cos(theta);
        y3 = r * sin(theta);

        theta += PI / 8;

        x4 = r * cos(theta);
        y4 = r * sin(theta);

        theta += PI / 8;

        printf("The coordinates of the %d point are (%f, %f)\n", i, x1, y1);
        printf("The coordinates of the %d point are (%f, %f)\n", i, x2, y2);
        printf("The coordinates of the %d point are (%f, %f)\n", i, x3, y3);
        printf("The coordinates of the %d point are (%f, %f)\n", i, x4, y4);
    }

    return 0;
}