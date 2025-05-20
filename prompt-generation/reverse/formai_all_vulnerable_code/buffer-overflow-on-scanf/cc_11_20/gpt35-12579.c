//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main() {
    // Getting the input from the user
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initializing arrays for storing the vertex coordinates
    int x[n], y[n];

    // Getting the coordinates from the user
    printf("Enter the coordinates of the vertices:\n");
    for(int i=0; i<n; i++) {
        printf("Vertex %d (x, y): ", i+1);
        scanf("%d %d", &x[i], &y[i]);
    }

    // Calculating the area and perimeter of the polygon
    double area = 0.0, perimeter = 0.0;
    for(int i=0; i<n; i++) {
        int j = (i+1) % n; // Next vertex index
        area += (x[i]*y[j] - y[i]*x[j]); // Calculating area
        perimeter += sqrt(pow((x[j]-x[i]), 2) + pow((y[j]-y[i]), 2)); // Calculating perimeter
    }
    area /= 2.0; // Dividing area by 2

    // Outputting the results to the user
    printf("The area of the polygon is %.2lf square units.\n", fabs(area));
    printf("The perimeter of the polygon is %.2lf units.\n", perimeter);

    // Checking if the polygon is convex or not
    int isConvex = 1;
    for(int i=0; i<n; i++) {
        int j = (i+1) % n; // Next vertex index
        int k = (j+1) % n; // Point after next index

        // Calculating the cross product
        double crossProduct = (x[j]-x[i])*(y[k]-y[j]) - (y[j]-y[i])*(x[k]-x[j]);

        // Checking the sign of the cross product
        if(i == 0) {
            isConvex = (crossProduct > 0) ? 1 : -1;
        } else {
            if((crossProduct > 0 && isConvex == -1) || (crossProduct < 0 && isConvex == 1)) {
                isConvex = 0;
                break;
            }
        }
    }

    // Outputting if the polygon is convex or not
    if(isConvex == 0) {
        printf("The polygon is non-convex.\n");
    } else if(isConvex == 1) {
        printf("The polygon is convex and has its vertices in the counter-clockwise direction.\n");
    } else {
        printf("The polygon is convex and has its vertices in the clockwise direction.\n");
    }

    return 0;
}