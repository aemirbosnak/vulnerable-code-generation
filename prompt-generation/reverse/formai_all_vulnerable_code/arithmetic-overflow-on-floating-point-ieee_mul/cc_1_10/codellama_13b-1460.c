//Code Llama-13B DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
/*
 * Program: geo_alg.c
 * Author: Your Name
 * Purpose: A program to demonstrate geometric algorithms using C
 * Date: Date of creation
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a struct to represent a point
typedef struct {
    double x;
    double y;
} point;

// Define a struct to represent a line
typedef struct {
    point start;
    point end;
} line;

// Define a struct to represent a circle
typedef struct {
    point center;
    double radius;
} circle;

// Function to calculate the distance between two points
double distance(point p1, point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to calculate the midpoint of a line
point midpoint(line l) {
    point mid;
    mid.x = (l.start.x + l.end.x) / 2;
    mid.y = (l.start.y + l.end.y) / 2;
    return mid;
}

// Function to calculate the distance between a point and a line
double point_line_distance(point p, line l) {
    point m = midpoint(l);
    double x = p.x - m.x;
    double y = p.y - m.y;
    return sqrt(x * x + y * y);
}

// Function to calculate the distance between a point and a circle
double point_circle_distance(point p, circle c) {
    double x = p.x - c.center.x;
    double y = p.y - c.center.y;
    return sqrt(x * x + y * y) - c.radius;
}

int main() {
    // Define two points
    point p1 = {1, 1};
    point p2 = {5, 4};

    // Define a line
    line l = {p1, p2};

    // Define a circle
    circle c = {{2, 3}, 2};

    // Calculate the distance between the points
    double d = distance(p1, p2);
    printf("Distance between (%lf, %lf) and (%lf, %lf) is %lf\n", p1.x, p1.y, p2.x, p2.y, d);

    // Calculate the midpoint of the line
    point m = midpoint(l);
    printf("Midpoint of line (%lf, %lf) and (%lf, %lf) is (%lf, %lf)\n", l.start.x, l.start.y, l.end.x, l.end.y, m.x, m.y);

    // Calculate the distance between a point and a line
    d = point_line_distance(p1, l);
    printf("Distance between point (%lf, %lf) and line (%lf, %lf) and (%lf, %lf) is %lf\n", p1.x, p1.y, l.start.x, l.start.y, l.end.x, l.end.y, d);

    // Calculate the distance between a point and a circle
    d = point_circle_distance(p1, c);
    printf("Distance between point (%lf, %lf) and circle (%lf, %lf) with radius %lf is %lf\n", p1.x, p1.y, c.center.x, c.center.y, c.radius, d);

    return 0;
}