//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
/* Program to calculate the area of a regular polygon using geometric algorithms */

#include <stdio.h>
#include <math.h>

// Structure to hold the coordinates of a point
struct point {
    double x;
    double y;
};

// Function to calculate the distance between two points
double distance(struct point a, struct point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate the area of a regular polygon given the number of sides and the distance between the center and one of the vertices
double polygon_area(int sides, double radius) {
    double apothem = radius * cos(M_PI/sides);
    double side_length = 2 * radius * sin(M_PI/sides);
    double perimeter = sides * side_length;
    double area = 0.5 * apothem * perimeter;
    return area;
}

int main() {
    int sides;
    double radius;
    struct point center;

    // Get the input from the user
    printf("Enter the number of sides: ");
    scanf("%d", &sides);
    printf("Enter the radius: ");
    scanf("%lf", &radius);
    printf("Enter the x-coordinate of the center: ");
    scanf("%lf", &center.x);
    printf("Enter the y-coordinate of the center: ");
    scanf("%lf", &center.y);

    // Calculate the area of the polygon
    double area = polygon_area(sides, radius);

    // Output the results
    printf("The area of the %d-sided polygon with radius %lf and center (%lf, %lf) is %lf\n", sides, radius, center.x, center.y, area);

    return 0;
}