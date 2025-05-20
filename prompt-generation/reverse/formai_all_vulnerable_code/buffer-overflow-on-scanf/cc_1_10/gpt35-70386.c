//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: interoperable
/*
This program calculates the area of a polygon using the shoelace formula and calculates
whether the polygon is convex or not using the cross product of consecutive vectors.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to hold the 2D coordinates
typedef struct coordinate {
    float x;
    float y;
} Coordinate;

// Function to calculate the cross product of two vectors
float crossProduct(Coordinate A, Coordinate B, Coordinate C) {
    float ABx = B.x - A.x;
    float ABy = B.y - A.y;
    float ACx = C.x - A.x;
    float ACy = C.y - A.y;
    return (ABx * ACy) - (ABy * ACx);
}

// Function to calculate the area of a polygon using shoelace formula
float shoelaceArea(Coordinate arr[], int N) {
    float area = 0.0;
    int j = N - 1;
    for (int i = 0; i < N; i++) { 
        area += (arr[j].x + arr[i].x) * (arr[j].y - arr[i].y); 
        j = i;
    }
    return fabs(area / 2.0);
}

// Main function
int main() {
    printf("Enter number of vertices of the polygon (minimum 3): ");
    int n;
    scanf("%d", &n);
    if (n < 3) {
        printf("Invalid input\n");
        return 0;
    }
    Coordinate poly[n];
    printf("Enter the x and y coordinates of the vertices: \n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &poly[i].x, &poly[i].y);
    }
    float area = shoelaceArea(poly, n);
    printf("Area of the polygon: %.2f sq units\n", area);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        float cp = crossProduct(poly[i], poly[(i+1)%n], poly[(i+2)%n]);
        if (cp < 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("The polygon is convex\n");
    } else {
        printf("The polygon is not convex\n");
    }
    return 0;
}