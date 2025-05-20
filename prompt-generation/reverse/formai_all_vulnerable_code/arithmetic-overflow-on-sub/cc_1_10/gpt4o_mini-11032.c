//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point points[MAX_POINTS];
    int size;
} Polygon;

double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double area(Polygon *poly) {
    double area = 0.0;
    int j = poly->size - 1;

    for (int i = 0; i < poly->size; i++) {
        area += (poly->points[j].x + poly->points[i].x) * (poly->points[j].y - poly->points[i].y);
        j = i;  // j is previous vertex to i
    }

    return fabs(area) / 2.0;
}

int isInside(Polygon *poly, Point p) {
    int count = 0, i, next;
    for (i = 0; i < poly->size; i++) {
        next = (i + 1) % poly->size;
        if ((poly->points[i].y > p.y) != (poly->points[next].y > p.y) &&
            (p.x < (poly->points[next].x - poly->points[i].x) * (p.y - poly->points[i].y) / 
            (poly->points[next].y - poly->points[i].y) + poly->points[i].x)) {
            count++;
        }
    }
    return count % 2;  // Inside if odd number of intersections
}

void inputPolygon(Polygon *poly) {
    printf("Enter the number of vertices: ");
    scanf("%d", &poly->size);
    
    if (poly->size > MAX_POINTS) {
        printf("Maximum vertices allowed: %d\n", MAX_POINTS);
        exit(1);
    }

    printf("Enter the coordinates of the vertices (x y):\n");
    for (int i = 0; i < poly->size; i++) {
        scanf("%lf %lf", &poly->points[i].x, &poly->points[i].y);
    }
}

void printPolygon(Polygon *poly) {
    printf("Polygon vertices:\n");
    for (int i = 0; i < poly->size; i++) {
        printf("(%lf, %lf)\n", poly->points[i].x, poly->points[i].y);
    }
}

Point inputPoint() {
    Point p;
    printf("Enter the coordinates of the point (x y): ");
    scanf("%lf %lf", &p.x, &p.y);
    return p;
}

int main() {
    Polygon poly;
    Point p;
    
    inputPolygon(&poly);
    printPolygon(&poly);
    
    double poly_area = area(&poly);
    printf("Area of the polygon: %lf\n", poly_area);
    
    p = inputPoint();
    if (isInside(&poly, p)) {
        printf("Point (%lf, %lf) is inside the polygon.\n", p.x, p.y);
    } else {
        printf("Point (%lf, %lf) is outside the polygon.\n", p.x, p.y);
    }

    return 0;
}