//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// The Case of the Missing Polygon
// Written by Sherlock Holmes

typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to determine if three points are collinear
int collinear(Point p1, Point p2, Point p3) {
    double slope1 = (p2.y - p1.y) / (p2.x - p1.x);
    double slope2 = (p3.y - p2.y) / (p3.x - p2.x);
    return (slope1 == slope2);
}

// Function to read in n points from a file
// in the format "x y\n"
Point* readPoints(char* filename, int n) {
    Point* points = malloc(n * sizeof(Point));
    FILE* fp = fopen(filename, "r");
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%lf %lf\n", &points[i].x, &points[i].y);
    }
    fclose(fp);
    return points;
}

// Function to find the polygon with the largest perimeter
// given a set of n points
void findLargestPerimeter(Point* points, int n) {
    double maxPerimeter = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            for (int k = j+1; k < n; k++) {
                if (!collinear(points[i], points[j], points[k])) {
                    double perimeter = distance(points[i], points[j]) + distance(points[j], points[k]) + distance(points[k], points[i]);
                    if (perimeter > maxPerimeter) {
                        maxPerimeter = perimeter;
                    }
                }
            }
        }
    }
    printf("The largest perimeter is: %lf\n", maxPerimeter);
}

int main() {
    Point* points = readPoints("points.txt", 7);
    findLargestPerimeter(points, 7);
    free(points);
    return 0;
}