//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: multivariable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846
#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point points[MAX_POINTS];
    int pointCount;
} Polygon;

void addPoint(Polygon* polygon, double x, double y) {
    if (polygon->pointCount < MAX_POINTS) {
        polygon->points[polygon->pointCount].x = x;
        polygon->points[polygon->pointCount].y = y;
        polygon->pointCount++;
    } else {
        printf("Error: Maximum number of points reached.\n");
    }
}

double calculateArea(Polygon* polygon) {
    double area = 0.0;
    for (int i = 0; i < polygon->pointCount; i++) {
        int j = (i + 1) % polygon->pointCount;
        area += (polygon->points[i].x * polygon->points[j].y) - (polygon->points[j].x * polygon->points[i].y);
    }
    return fabs(area) / 2.0;
}

double calculatePerimeter(Polygon* polygon) {
    double perimeter = 0.0;
    for (int i = 0; i < polygon->pointCount; i++) {
        int j = (i + 1) % polygon->pointCount;
        double dx = polygon->points[j].x - polygon->points[i].x;
        double dy = polygon->points[j].y - polygon->points[i].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }
    return perimeter;
}

void displayPolygon(Polygon* polygon) {
    printf("Polygon Points:\n");
    for (int i = 0; i < polygon->pointCount; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, polygon->points[i].x, polygon->points[i].y);
    }
}

int isPointInside(Polygon* polygon, Point p) {
    int count = 0;
    for (int i = 0; i < polygon->pointCount; i++) {
        int j = (i + 1) % polygon->pointCount;
        if ((polygon->points[i].y > p.y) != (polygon->points[j].y > p.y) &&
            (p.x < (polygon->points[j].x - polygon->points[i].x) * (p.y - polygon->points[i].y) / 
            (polygon->points[j].y - polygon->points[i].y) + polygon->points[i].x)) {
            count++;
        }
    }
    return count % 2;
}

void rotatePolygon(Polygon* polygon, double angle) {
    double radians = angle * (PI / 180.0);
    double cosTheta = cos(radians);
    double sinTheta = sin(radians);
    for (int i = 0; i < polygon->pointCount; i++) {
        double xOld = polygon->points[i].x;
        double yOld = polygon->points[i].y;
        polygon->points[i].x = xOld * cosTheta - yOld * sinTheta;
        polygon->points[i].y = xOld * sinTheta + yOld * cosTheta;
    }
}

int main() {
    Polygon polygon;
    polygon.pointCount = 0;

    printf("Enter the number of points to define the polygon: ");
    int numPoints;
    scanf("%d", &numPoints);

    for (int i = 0; i < numPoints; i++) {
        double x, y;
        printf("Enter coordinates for point %d (x y): ", i + 1);
        scanf("%lf %lf", &x, &y);
        addPoint(&polygon, x, y);
    }

    displayPolygon(&polygon);
    
    double area = calculateArea(&polygon);
    double perimeter = calculatePerimeter(&polygon);
    
    printf("Area of the polygon: %.2f\n", area);
    printf("Perimeter of the polygon: %.2f\n", perimeter);

    Point testPoint;
    printf("Enter a point to check if it's inside the polygon (x y): ");
    scanf("%lf %lf", &testPoint.x, &testPoint.y);
    
    if (isPointInside(&polygon, testPoint)) {
        printf("The point (%.2f, %.2f) is inside the polygon.\n", testPoint.x, testPoint.y);
    } else {
        printf("The point (%.2f, %.2f) is outside the polygon.\n", testPoint.x, testPoint.y);
    }

    double rotateAngle;
    printf("Enter an angle to rotate the polygon (in degrees): ");
    scanf("%lf", &rotateAngle);
    rotatePolygon(&polygon, rotateAngle);
    displayPolygon(&polygon);
    
    return 0;
}