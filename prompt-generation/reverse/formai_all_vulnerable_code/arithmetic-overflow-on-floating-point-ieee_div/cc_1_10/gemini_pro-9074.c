//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} point;

typedef struct line {
    point p1;
    point p2;
} line;

// Function to calculate the distance between two points
double distance(point p1, point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// Function to calculate the slope of a line
double slope(line l) {
    return (l.p2.y - l.p1.y) / (l.p2.x - l.p1.x);
}

// Function to calculate the y-intercept of a line
double y_intercept(line l) {
    return l.p1.y - slope(l) * l.p1.x;
}

// Function to check if two lines are parallel
int are_parallel(line l1, line l2) {
    return slope(l1) == slope(l2);
}

// Function to check if two lines are perpendicular
int are_perpendicular(line l1, line l2) {
    return slope(l1) * slope(l2) == -1;
}

// Function to check if two lines intersect
int do_intersect(line l1, line l2) {
    if (are_parallel(l1, l2)) {
        return 0;
    } else {
        double x_intersect = (y_intercept(l2) - y_intercept(l1)) / (slope(l1) - slope(l2));
        double y_intersect = slope(l1) * x_intersect + y_intercept(l1);
        return (x_intersect >= l1.p1.x && x_intersect <= l1.p2.x && y_intersect >= l2.p1.y && y_intersect <= l2.p2.y);
    }
}

int main() {
    // Define two points
    point p1 = {0, 0};
    point p2 = {1, 1};

    // Define two lines
    line l1 = {p1, p2};
    line l2 = {{1, 0}, {1, 2}};

    // Print the distance between the two points
    printf("The distance between the two points is: %f\n", distance(p1, p2));

    // Print the slope of the line l1
    printf("The slope of the line l1 is: %f\n", slope(l1));

    // Print the y-intercept of the line l1
    printf("The y-intercept of the line l1 is: %f\n", y_intercept(l1));

    // Check if the two lines are parallel
    if (are_parallel(l1, l2)) {
        printf("The two lines are parallel\n");
    } else {
        printf("The two lines are not parallel\n");
    }

    // Check if the two lines are perpendicular
    if (are_perpendicular(l1, l2)) {
        printf("The two lines are perpendicular\n");
    } else {
        printf("The two lines are not perpendicular\n");
    }

    // Check if the two lines intersect
    if (do_intersect(l1, l2)) {
        printf("The two lines intersect\n");
    } else {
        printf("The two lines do not intersect\n");
    }

    return 0;
}