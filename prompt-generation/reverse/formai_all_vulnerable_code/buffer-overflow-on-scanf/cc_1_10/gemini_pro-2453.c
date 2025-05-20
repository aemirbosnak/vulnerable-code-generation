//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Prototypes
int point_in_polygon(int n, double* vertices_x, double* vertices_y, double px, double py);
double angle_between_two_vectors(double ax, double ay, double bx, double by);

int main() {
    // Define a polygon
    int n = 4;
    double vertices_x[] = {0, 1, 1, 0};
    double vertices_y[] = {0, 0, 1, 1};

    // Get the coordinates of a point
    double px, py;
    printf("Enter the x-coordinate of the point: ");
    scanf("%lf", &px);
    printf("Enter the y-coordinate of the point: ");
    scanf("%lf", &py);

    // Check if the point is inside the polygon
    int inside = point_in_polygon(n, vertices_x, vertices_y, px, py);

    // Print the result
    if (inside) {
        printf("The point is inside the polygon.\n");
    } else {
        printf("The point is outside the polygon.\n");
    }

    // Get the angle between two vectors
    double ax, ay, bx, by;
    printf("Enter the x-coordinate of the first vector: ");
    scanf("%lf", &ax);
    printf("Enter the y-coordinate of the first vector: ");
    scanf("%lf", &ay);
    printf("Enter the x-coordinate of the second vector: ");
    scanf("%lf", &bx);
    printf("Enter the y-coordinate of the second vector: ");
    scanf("%lf", &by);

    double angle = angle_between_two_vectors(ax, ay, bx, by);

    // Print the result
    printf("The angle between the two vectors is: %lf degrees.\n", angle);

    return 0;
}

// Function to check if a point is inside a polygon
int point_in_polygon(int n, double* vertices_x, double* vertices_y, double px, double py) {
    int i, j, c = 0;
    for (i = 0, j = n-1; i < n; j = i++) {
        if (((vertices_y[i] > py) != (vertices_y[j] > py)) &&
            (px < (vertices_x[j] - vertices_x[i]) * (py - vertices_y[i]) / (vertices_y[j] - vertices_y[i]) + vertices_x[i]))
            c = !c;
    }
    return c;
}

// Function to calculate the angle between two vectors
double angle_between_two_vectors(double ax, double ay, double bx, double by) {
    double dot_product = ax * bx + ay * by;
    double magnitude_a = sqrt(ax * ax + ay * ay);
    double magnitude_b = sqrt(bx * bx + by * by);
    double angle = acos(dot_product / (magnitude_a * magnitude_b)) * 180 / M_PI;
    return angle;
}