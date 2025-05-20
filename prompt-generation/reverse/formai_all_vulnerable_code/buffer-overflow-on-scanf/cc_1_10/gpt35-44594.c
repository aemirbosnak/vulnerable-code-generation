//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: statistical
/* In this program, we will implement an algorithm to find the convex hull of a given set of points using a Divide and Conquer approach.
   The convex hull is a polygon that is the smallest convex polygon enclosing a set of points.

   The input to this program is a list of n points in the form (x,y), where x and y are coordinates of the point.

   The output of the program is the list of vertices of the convex hull in the clockwise order.

   This program makes use of the following geometric algorithms:
   1. Finding the leftmost and rightmost points in a set of points.
   2. Calculating the cross product of 3 points.
   3. Finding the upper and lower tangents of two convex hulls.
*/

#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a point with x and y coordinates
struct Point {
    int x;
    int y;
};

// Function to find the leftmost point in a set of points
struct Point leftmostPoint(struct Point points[], int n) {
    struct Point left = points[0];
    for (int i = 1; i < n; i++) {
        if (points[i].x < left.x) {
            left = points[i];
        }
    }
    return left;
}

// Function to find the rightmost point in a set of points
struct Point rightmostPoint(struct Point points[], int n) {
    struct Point right = points[0];
    for (int i = 1; i < n; i++) {
        if (points[i].x > right.x) {
            right = points[i];
        }
    }
    return right;
}

// Function to calculate the cross product of three points
int crossProduct(struct Point a, struct Point b, struct Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

// Function to find the upper tangent of two convex hulls
int upperTangent(struct Point hull1[], int n1, struct Point hull2[], int n2) {
    int i = 0, j = 0;
    while (hull1[i+1].y > hull2[j+1].y) {
        i++;
    }
    while (hull2[j+1].y > hull1[i].y) {
        j++;
    }
    return i + j;
}

// Function to find the lower tangent of two convex hulls
int lowerTangent(struct Point hull1[], int n1, struct Point hull2[], int n2) {
    int i = n1 - 1, j = n2 - 1;
    while (hull1[i-1].y > hull2[j-1].y) {
        i--;
    }
    while (hull2[j-1].y > hull1[i-1].y) {
        j--;
    }
    return i + j;
}

// Function to merge two convex hulls using the upper and lower tangents
void mergeConvexHulls(struct Point hull1[], int n1, struct Point hull2[], int n2, struct Point hull3[]) {
    int n3 = upperTangent(hull1, n1, hull2, n2) + lowerTangent(hull1, n1, hull2, n2) - 1;
    int i = 0, j = upperTangent(hull1, n1, hull2, n2);
    for (int k = 0; k < n3; k++) {
        if (j == n2 || (i < n1 && crossProduct(hull1[i], hull2[j], hull1[i+1]) >= 0)) {
            hull3[k] = hull1[i++];
        }
        else {
            hull3[k] = hull2[j++];
        }
    }
}

// Function to find the convex hull of a set of points using a Divide and Conquer approach
void convexHull(struct Point points[], int n, struct Point hull[]) {
    if (n <= 3) {
        for (int i = 0; i < n; i++) {
            hull[i] = points[i];
        }
        return;
    }
    int mid = n / 2;
    struct Point hull1[mid+1], hull2[n-mid+1];
    convexHull(points, mid, hull1);
    convexHull(points+mid, n-mid, hull2);
    mergeConvexHulls(hull1, mid, hull2, n-mid, hull);
}

// Main function
int main() {
    int n, i;
    printf("Enter the number of points: ");
    scanf("%d",&n);
    struct Point points[n];
    printf("Enter the coordinates of the points:\n");
    for (i = 0; i < n; i++) {
        scanf("%d",&points[i].x);
        scanf("%d",&points[i].y);
    }
    struct Point hull[n+1];
    convexHull(points, n, hull);
    printf("The convex hull is:\n");
    for (i = 0; i < n; i++) {
        printf("(%d,%d)\n",hull[i].x,hull[i].y);
    }
    return 0;
}