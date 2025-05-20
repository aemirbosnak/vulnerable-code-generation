//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

float calculateDistance(Point p1, Point p2) {
    float distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    return distance;
}

float calculatePerimeter(Point *points, int pointCount) {
    float perimeter = 0;
    for(int i = 0; i < pointCount-1; i++) {
        perimeter += calculateDistance(points[i], points[i+1]);
    }
    perimeter += calculateDistance(points[pointCount-1], points[0]);
    return perimeter;
}

float calculateArea(Point *points, int pointCount) {
    float area = 0;
    for(int i = 0; i < pointCount-1; i++) {
        area += (points[i].x * points[i+1].y) - (points[i+1].x * points[i].y);
    }
    area += (points[pointCount-1].x * points[0].y) - (points[0].x * points[pointCount-1].y);
    area /= 2;
    return fabs(area);
}

int main() {

    Point trianglePoints[3] = {{0,0}, {3,0}, {0,4}};
    float trianglePerimeter = calculatePerimeter(trianglePoints, 3);
    printf("The perimeter of the triangle is %.2f\n", trianglePerimeter);

    float triangleArea = calculateArea(trianglePoints, 3);
    printf("The area of the triangle is %.2f\n", triangleArea);

    Point rectanglePoints[4] = {{0,0}, {0,3}, {4,3}, {4,0}};
    float rectanglePerimeter = calculatePerimeter(rectanglePoints, 4);
    printf("The perimeter of the rectangle is %.2f\n", rectanglePerimeter);

    float rectangleArea = calculateArea(rectanglePoints, 4);
    printf("The area of the rectangle is %.2f\n", rectangleArea);

    return 0;
}