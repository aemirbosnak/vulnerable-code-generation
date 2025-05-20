//Code Llama-13B DATASET v1.0 Category: Geometric algorithms ; Style: accurate
/*
 * Program: Geometric Algorithms Example
 * Author:
 * Date:
 *
 * Description:
 * This program demonstrates the use of geometric algorithms to solve problems in computer graphics.
 * It includes examples of line intersection, line segment intersection, and point in polygon tests.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    double x, y;
} point_t;

// Function to check if two line segments intersect
int line_intersect(point_t p1, point_t p2, point_t p3, point_t p4) {
    double s1_x, s1_y, s2_x, s2_y;
    s1_x = p2.x - p1.x;
    s1_y = p2.y - p1.y;
    s2_x = p4.x - p3.x;
    s2_y = p4.y - p3.y;

    double s, t;
    s = (-s1_y * (p1.x - p3.x) + s1_x * (p1.y - p3.y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = (s2_x * (p1.y - p3.y) - s2_y * (p1.x - p3.x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1) {
        // Collision detected
        return 1;
    }

    // No collision
    return 0;
}

// Function to check if two line segments intersect
int line_segment_intersect(point_t p1, point_t p2, point_t p3, point_t p4) {
    double s1_x, s1_y, s2_x, s2_y;
    s1_x = p2.x - p1.x;
    s1_y = p2.y - p1.y;
    s2_x = p4.x - p3.x;
    s2_y = p4.y - p3.y;

    double s, t;
    s = (-s1_y * (p1.x - p3.x) + s1_x * (p1.y - p3.y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = (s2_x * (p1.y - p3.y) - s2_y * (p1.x - p3.x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1) {
        // Collision detected
        return 1;
    }

    // No collision
    return 0;
}

// Function to check if a point is inside a polygon
int point_in_polygon(point_t p, point_t *poly, int n) {
    int i, j = n - 1;
    int c = 0;

    for (i = 0; i < n; i++) {
        if (poly[i].y < p.y && poly[j].y >= p.y || poly[j].y < p.y && poly[i].y >= p.y) {
            if (poly[i].x + (p.y - poly[i].y) / (poly[j].y - poly[i].y) * (poly[j].x - poly[i].x) < p.x) {
                c = !c;
            }
        }
        j = i;
    }

    return c;
}

int main() {
    // Declare variables
    point_t p1, p2, p3, p4;
    point_t poly[] = {{1, 1}, {3, 1}, {3, 3}, {1, 3}};
    int n = 4;

    // Initialize variables
    p1.x = 2;
    p1.y = 2;
    p2.x = 4;
    p2.y = 2;
    p3.x = 2;
    p3.y = 4;
    p4.x = 4;
    p4.y = 4;

    // Check if two line segments intersect
    int intersect = line_intersect(p1, p2, p3, p4);
    if (intersect) {
        printf("Line segments intersect\n");
    } else {
        printf("Line segments do not intersect\n");
    }

    // Check if two line segments intersect
    intersect = line_segment_intersect(p1, p2, p3, p4);
    if (intersect) {
        printf("Line segments intersect\n");
    } else {
        printf("Line segments do not intersect\n");
    }

    // Check if a point is inside a polygon
    int inside = point_in_polygon(p1, poly, n);
    if (inside) {
        printf("Point is inside polygon\n");
    } else {
        printf("Point is outside polygon\n");
    }

    return 0;
}