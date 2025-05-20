//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_VERTICES 100

// Function to calculate the area of a triangle given its three vertices
double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    return fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

// Function to calculate the area of a circle given its radius
double circleArea(double radius) {
    return PI * radius * radius;
}

// Function to calculate the area of a rectangle given its length and width
double rectangleArea(double length, double width) {
    return length * width;
}

// Function to check if a point (px, py) is inside the polygon defined by vertices
int isInsidePolygon(double polygon[][2], int n, double px, double py) {
    int count = 0, i, j;
    
    for (i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i][1] > py) != (polygon[j][1] > py)) &&
            (px < (polygon[j][0] - polygon[i][0]) * (py - polygon[i][1]) / (polygon[j][1] - polygon[i][1]) + polygon[i][0])) {
            count++;
        }
    }
    
    return count % 2; // Odd count means the point is inside
}

int main() {
    int choice, numVertices, i;
    double x1, y1, x2, y2, x3, y3, radius, length, width;
    double polygon[MAX_VERTICES][2];

    printf("Geometric Algorithms Menu:\n");
    printf("1. Area of Triangle\n");
    printf("2. Area of Circle\n");
    printf("3. Area of Rectangle\n");
    printf("4. Check if point is in Polygon\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Area of Triangle
            printf("Enter coordinates of the triangle (x1 y1 x2 y2 x3 y3): ");
            scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
            printf("Area of the triangle: %.2lf\n", triangleArea(x1, y1, x2, y2, x3, y3));
            break;

        case 2: // Area of Circle
            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            printf("Area of the circle: %.2lf\n", circleArea(radius));
            break;

        case 3: // Area of Rectangle
            printf("Enter length and width of the rectangle: ");
            scanf("%lf %lf", &length, &width);
            printf("Area of the rectangle: %.2lf\n", rectangleArea(length, width));
            break;

        case 4: // Check if point is in Polygon
            printf("Enter the number of vertices in the polygon: ");
            scanf("%d", &numVertices);
            printf("Enter the vertices (x y) of the polygon:\n");
            for (i = 0; i < numVertices; i++) {
                scanf("%lf %lf", &polygon[i][0], &polygon[i][1]);
            }
            double px, py;
            printf("Enter the coordinates of the point (px, py): ");
            scanf("%lf %lf", &px, &py);
            if (isInsidePolygon(polygon, numVertices, px, py)) {
                printf("The point is inside the polygon.\n");
            } else {
                printf("The point is outside the polygon.\n");
            }
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}