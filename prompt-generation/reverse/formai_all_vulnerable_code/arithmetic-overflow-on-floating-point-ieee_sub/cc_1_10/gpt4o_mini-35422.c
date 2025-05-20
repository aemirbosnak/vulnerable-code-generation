//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

double calculateTriangleArea(Point a, Point b, Point c) {
    return fabs((a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y)) / 2.0);
}

double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateCircleArea(double radius) {
    return M_PI * radius * radius;
}

int isPointInPolygon(Point *polygon, int n, Point p) {
    int i, j;
    int oddNodes = 0;

    for (i = 0, j = n - 1; i < n; j = i++) {
        if ((polygon[i].y < p.y && polygon[j].y >= p.y) || (polygon[j].y < p.y && polygon[i].y >= p.y)) {
            if (polygon[i].x + (p.y - polygon[i].y) / (polygon[j].y - polygon[i].y) * (polygon[j].x - polygon[i].x) < p.x) {
                oddNodes = !oddNodes;
            }
        }
    }
    return oddNodes;
}

void displayMenu() {
    printf("Geometric Algorithms Menu:\n");
    printf("1. Calculate Area of Triangle\n");
    printf("2. Calculate Area of Rectangle\n");
    printf("3. Calculate Area of Circle\n");
    printf("4. Check if Point is Inside Polygon\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                // Calculate Area of Triangle
                Point a, b, c;
                printf("Enter coordinates of Point A (x y): ");
                scanf("%lf %lf", &a.x, &a.y);
                printf("Enter coordinates of Point B (x y): ");
                scanf("%lf %lf", &b.x, &b.y);
                printf("Enter coordinates of Point C (x y): ");
                scanf("%lf %lf", &c.x, &c.y);
                
                double triangleArea = calculateTriangleArea(a, b, c);
                printf("Area of Triangle: %.2lf\n", triangleArea);
                break;
            }
            case 2: {
                // Calculate Area of Rectangle
                double length, width;
                printf("Enter length and width of the rectangle: ");
                scanf("%lf %lf", &length, &width);
                
                double rectangleArea = calculateRectangleArea(length, width);
                printf("Area of Rectangle: %.2lf\n", rectangleArea);
                break;
            }
            case 3: {
                // Calculate Area of Circle
                double radius;
                printf("Enter radius of the circle: ");
                scanf("%lf", &radius);
                
                double circleArea = calculateCircleArea(radius);
                printf("Area of Circle: %.2lf\n", circleArea);
                break;
            }
            case 4: {
                // Check if Point is Inside Polygon
                int n;
                printf("Enter number of vertices of the polygon: ");
                scanf("%d", &n);
                
                if (n > MAX_POINTS) {
                    printf("Exceeded the maximum number of points (%d).\n", MAX_POINTS);
                    break;
                }
                
                Point polygon[MAX_POINTS];
                printf("Enter coordinates of the vertices (x y):\n");
                for (int i = 0; i < n; i++) {
                    printf("Vertex %d: ", i + 1);
                    scanf("%lf %lf", &polygon[i].x, &polygon[i].y);
                }
                
                Point p;
                printf("Enter coordinates of the point (x y): ");
                scanf("%lf %lf", &p.x, &p.y);

                if (isPointInPolygon(polygon, n, p)) {
                    printf("The point is inside the polygon.\n");
                } else {
                    printf("The point is outside the polygon.\n");
                }
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}