//Falcon2-11B DATASET v1.0 Category: Geometric algorithms ; Style: grateful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to find the area of a triangle
float areaOfTriangle(float base, float height) {
    return 0.5 * base * height;
}

// Function to find the distance between two points
float distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to find the midpoint of two points
float midpoint(float x1, float y1, float x2, float y2) {
    return ((x1 + x2) / 2, (y1 + y2) / 2);
}

// Function to find the intersection of two lines
float intersection(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    // Calculating the determinant of the two lines
    float determinant = (x1 - x2) * (y3 - y4) - (x1 - x3) * (y2 - y4) + (x2 - x3) * (y1 - y2);

    // Calculating the cross product of the two lines
    float cross_product = (x1 - x2) * (y3 - y4) - (x1 - x3) * (y2 - y4) + (x2 - x3) * (y1 - y2);

    // Calculating the slopes of the two lines
    float slope1 = (y3 - y4) / (x3 - x4);
    float slope2 = (y1 - y2) / (x1 - x2);

    // Calculating the x-intercept of the two lines
    float x_intercept1 = (slope1 * x1) - (slope1 * y1) + y1;
    float x_intercept2 = (slope2 * x1) - (slope2 * y1) + y1;

    // Checking if the lines intersect
    if (determinant!= 0 && cross_product!= 0) {
        // Calculating the intersection point
        float x_intersect = (slope2 * x_intercept1 - slope1 * x_intercept2) / (slope1 - slope2);
        float y_intersect = (slope1 * x_intercept1 - slope2 * x_intercept2) / (slope1 - slope2);

        return x_intersect;
    } else {
        return 0.0;
    }
}

int main() {
    float base1, height1, base2, height2, x1, y1, x2, y2, x3, y3, x4, y4;

    printf("Enter the base and height of the first triangle: ");
    scanf("%f %f", &base1, &height1);
    printf("Enter the base and height of the second triangle: ");
    scanf("%f %f", &base2, &height2);

    x1 = base1 / 2;
    y1 = height1 / 2;
    x2 = base2 / 2;
    y2 = height2 / 2;
    x3 = (base1 + base2) / 2;
    y3 = (height1 + height2) / 2;
    x4 = (base1 + base2) / 2;
    y4 = (height1 + height2) / 2;

    float intersection_point = intersection(x1, y1, x2, y2, x3, y3, x4, y4);
    printf("The intersection point of the two lines is (%f, %f).\n", intersection_point, 0);

    return 0;
}