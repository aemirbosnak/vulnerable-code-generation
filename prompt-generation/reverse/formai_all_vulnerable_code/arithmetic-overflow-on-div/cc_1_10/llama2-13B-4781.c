//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159

// Define a struct to represent a point in 2D space
typedef struct {
    int x;
    int y;
} Point;

// Define a function to calculate the distance between two points
int distance(Point p1, Point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// Define a function to calculate the midpoint of two points
Point midpoint(Point p1, Point p2) {
    return (Point) {
        (p1.x + p2.x) / 2,
        (p1.y + p2.y) / 2
    };
}

// Define a function to calculate the slope of a line
float slope(Point p1, Point p2) {
    return (p2.y - p1.y) / (p2.x - p1.x);
}

// Define a function to calculate the equation of a line
char* lineEquation(Point p1, Point p2) {
    char* equation = malloc(100);
    sprintf(equation, "y = %f*x + %f", slope(p1, p2), p1.y - slope(p1, p2) * p1.x);
    return equation;
}

// Define a function to calculate the area of a circle
float area(int radius) {
    return PI * radius * radius;
}

// Define a function to calculate the circumference of a circle
float circumference(int radius) {
    return 2 * PI * radius;
}

int main() {
    // Declare and initialize variables
    int x1, y1, x2, y2, radius;
    Point p1, p2;

    // Read input from the user
    printf("Enter the coordinates of point 1 (x, y): ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the coordinates of point 2 (x, y): ");
    scanf("%d%d", &x2, &y2);
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

    // Calculate and display the distance between the two points
    p1.x = x1;
    p1.y = y1;
    p2.x = x2;
    p2.y = y2;
    printf("The distance between the two points is: %d\n", distance(p1, p2));

    // Calculate and display the midpoint of the two points
    p1.x = x1;
    p1.y = y1;
    p2.x = x2;
    p2.y = y2;
    printf("The midpoint of the two points is: (%d, %d)\n", midpoint(p1, p2).x, midpoint(p1, p2).y);

    // Calculate and display the slope of the line connecting the two points
    p1.x = x1;
    p1.y = y1;
    p2.x = x2;
    p2.y = y2;
    printf("The slope of the line connecting the two points is: %f\n", slope(p1, p2));

    // Calculate and display the equation of the line connecting the two points
    p1.x = x1;
    p1.y = y1;
    p2.x = x2;
    p2.y = y2;
    char* equation = lineEquation(p1, p2);
    printf("The equation of the line connecting the two points is: %s\n", equation);

    // Calculate and display the area of the circle with the given radius
    printf("The area of the circle with radius %d is: %f\n", radius, area(radius));

    // Calculate and display the circumference of the circle with the given radius
    printf("The circumference of the circle with radius %d is: %f\n", radius, circumference(radius));

    return 0;
}