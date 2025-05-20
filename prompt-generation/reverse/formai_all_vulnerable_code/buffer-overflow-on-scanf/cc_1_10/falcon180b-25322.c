//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>
#define MAX 100

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the area of a triangle
double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double s = (x1 + x2 + x3) / 2;
    double area = sqrt(s * (s - x1) * (s - x2) * (s - x3));
    return area;
}

// Function to check if three points form a triangle
int is_triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    double d1 = distance(x1, y1, x2, y2);
    double d2 = distance(x2, y2, x3, y3);
    double d3 = distance(x3, y3, x1, y1);

    if (d1 + d2 > d3 && d1 + d3 > d2 && d2 + d3 > d1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int i, j, k;
    double x[MAX], y[MAX];

    // Read in coordinates of points
    for (i = 0; i < MAX; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    // Check if each set of three points forms a triangle
    for (i = 0; i < MAX - 2; i++) {
        for (j = i + 1; j < MAX - 1; j++) {
            for (k = j + 1; k < MAX; k++) {
                if (is_triangle(x[i], y[i], x[j], y[j], x[k], y[k])) {
                    printf("The points (%lf, %lf), (%lf, %lf), and (%lf, %lf) form a triangle.\n", x[i], y[i], x[j], y[j], x[k], y[k]);
                    printf("The area of the triangle is %lf.\n", triangle_area(x[i], y[i], x[j], y[j], x[k], y[k]));
                } else {
                    printf("The points (%lf, %lf), (%lf, %lf), and (%lf, %lf) do not form a triangle.\n", x[i], y[i], x[j], y[j], x[k], y[k]);
                }
            }
        }
    }

    return 0;
}