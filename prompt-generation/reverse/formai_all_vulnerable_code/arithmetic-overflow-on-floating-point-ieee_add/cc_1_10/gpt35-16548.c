//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>

// Function to calculate the area of a triangle given three coordinates
double area_of_triangle(double x1, double y1, double x2, double y2, double x3, double y3) {

    double area = ((x1*(y2-y3)) + (x2*(y3-y1)) + (x3*(y1-y2))) / 2;

    return area;
}

// Function to check if a point lies inside a circle or not
int point_inside_circle(double x, double y, double cx, double cy, double r) {

    double d = ((x - cx) * (x - cx)) + ((y - cy) * (y - cy));

    if(d < (r*r)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    // Define arrays for x and y coordinates
    double x[3], y[3];

    printf("Enter the coordinates of the first point:\n");
    scanf("%lf%lf", &x[0], &y[0]);

    printf("Enter the coordinates of the second point:\n");
    scanf("%lf%lf", &x[1], &y[1]);

    printf("Enter the coordinates of the third point:\n");
    scanf("%lf%lf", &x[2], &y[2]);

    // Calculate the area of the triangle
    double area = area_of_triangle(x[0], y[0], x[1], y[1], x[2], y[2]);

    printf("The area of the triangle is: %lf\n", area);

    // Check if the fourth point lies inside the circle
    printf("Enter the coordinates of the center of the circle:\n");
    double cx, cy;
    scanf("%lf%lf", &cx, &cy);

    printf("Enter the radius of the circle:\n");
    double r;
    scanf("%lf", &r);

    printf("Enter the coordinates of the fourth point:\n");
    double px, py;
    scanf("%lf%lf", &px, &py);

    if(point_inside_circle(px, py, cx, cy, r)) {
        printf("The point is inside the circle.\n");
    } else {
        printf("The point is not inside the circle.\n");
    }

    return 0;
}