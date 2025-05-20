//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: statistical
/*
 * Author: Jane Doe
 * Date: 06/30/2021
 * Program: Geometric Algorithms Example
 * Description: This program takes user input for a set of 2D points and calculates the convex hull using the Graham's Scan algorithm. The program also outputs the area of the convex hull.
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Point {
    int x, y;
};

struct Point p0; // Reference point for sorting

// Swap two points
void swap(struct Point *p1, struct Point *p2) {
    struct Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Find orientation of ordered triplet (p, q, r)
int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Colinear
    return (val > 0) ? 1 : 2; // Clockwise or counterclockwise
}

// Calculate the square of Euclidean distance between two points
int distSq(struct Point p1, struct Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Compare two points based on polar angle
int compare(const void *vp1, const void *vp2) {
    struct Point *p1 = (struct Point *)vp1;
    struct Point *p2 = (struct Point *)vp2;
    int o = orientation(p0, *p1, *p2);
    if (o == 0) return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;
    return (o == 2) ? -1 : 1;
}

// Perform Graham's Scan algorithm to find convex hull
void convexHull(struct Point points[], int n) {
    // Find bottommost point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Place the bottom-most point at first position
    swap(&points[0], &points[min]);
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(struct Point), compare);

    // Remove points that denote same angle with respect to p0 except the one farthest from it
    int m = 1;
    for(int i = 1; i < n; i++) {
        while(i < n-1 && orientation(p0, points[i], points[i+1]) == 0) i++;
        points[m] = points[i];
        m++;
    }

    if (m < 3) return; // Not enough unique points for a convex hull

    struct Point hull[m]; // Stores the final convex hull
    int top = 2;
    hull[0] = points[0], hull[1] = points[1], hull[2] = points[2];

    // Calculate the convex hull
    for (int i = 3; i < m; i++) {
        while (top > 0 && orientation(hull[top-1], hull[top], points[i]) != 2) top--;
        hull[++top] = points[i];
    }

    // Print the points of the convex hull
    printf("Convex hull:\n");
    for (int i = 0; i <= top; i++) printf("(%d, %d)\n", hull[i].x, hull[i].y);

    // Calculate the area of the convex hull
    double area = 0.0;
    int j = top;
    for (int i = 0; i <= top; i++) {
        area += (double)(hull[j].x + hull[i].x) * (double)(hull[j].y - hull[i].y);
        j = i;
    }
    area = fabs(area / 2.0);
    printf("Area of convex hull: %.2f square units\n", area);
}

// Main function
int main() {
    int n;
    printf("Enter the number of 2D points (minimum 3): ");
    scanf("%d", &n);

    while (n < 3) {
        printf("Invalid input. Enter at least 3 points: ");
        scanf("%d", &n);
    }

    struct Point points[n];
    printf("Enter the %d 2D points:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Point %d: ", i+1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    convexHull(points, n);

    return 0;
}