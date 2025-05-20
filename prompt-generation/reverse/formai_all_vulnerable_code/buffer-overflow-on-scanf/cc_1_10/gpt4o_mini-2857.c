//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793
#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point points[MAX_POINTS];
    int num_points;
} Polygon;

// Function prototypes
void inputPolygon(Polygon *polygon);
void printPolygon(const Polygon *polygon);
double calculateArea(const Polygon *polygon);
void calculateCentroid(const Polygon *polygon, Point *centroid);
int isPointInsidePolygon(const Polygon *polygon, Point p);
void translatePolygon(Polygon *polygon, double tx, double ty);
void rotatePolygon(Polygon *polygon, double angle);
void scalePolygon(Polygon *polygon, double scale_factor);

int main() {
    Polygon polygon;
    Point centroid;
    double area;
    double tx, ty, angle, scale_factor;

    inputPolygon(&polygon);
    printPolygon(&polygon);
    
    area = calculateArea(&polygon);
    printf("Area of the polygon: %.2f\n", area);

    calculateCentroid(&polygon, &centroid);
    printf("Centroid of the polygon: (%.2f, %.2f)\n", centroid.x, centroid.y);
    
    printf("Enter translation distances (tx, ty): ");
    scanf("%lf %lf", &tx, &ty);
    translatePolygon(&polygon, tx, ty);
    printf("Polygon after translation:\n");
    printPolygon(&polygon);
    
    printf("Enter rotation angle (in degrees): ");
    scanf("%lf", &angle);
    rotatePolygon(&polygon, angle);
    printf("Polygon after rotation:\n");
    printPolygon(&polygon);
    
    printf("Enter scaling factor: ");
    scanf("%lf", &scale_factor);
    scalePolygon(&polygon, scale_factor);
    printf("Polygon after scaling:\n");
    printPolygon(&polygon);
    
    return 0;
}

void inputPolygon(Polygon *polygon) {
    printf("Enter number of points (3 to 100): ");
    scanf("%d", &polygon->num_points);
    if (polygon->num_points < 3 || polygon->num_points > MAX_POINTS) {
        printf("Invalid number of points. Please try again.\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < polygon->num_points; i++) {
        printf("Enter coordinates for point %d (x y): ", i + 1);
        scanf("%lf %lf", &polygon->points[i].x, &polygon->points[i].y);
    }
}

void printPolygon(const Polygon *polygon) {
    printf("Polygon vertices:\n");
    for (int i = 0; i < polygon->num_points; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, polygon->points[i].x, polygon->points[i].y);
    }
}

double calculateArea(const Polygon *polygon) {
    double area = 0.0;
    int j = polygon->num_points - 1; // The last vertex
    for (int i = 0; i < polygon->num_points; i++) {
        area += (polygon->points[j].x + polygon->points[i].x) * (polygon->points[j].y - polygon->points[i].y);
        j = i;  // j is previous vertex to i
    }
    return fabs(area) / 2.0;
}

void calculateCentroid(const Polygon *polygon, Point *centroid) {
    double area = calculateArea(polygon);
    double Cx = 0, Cy = 0;
    int j = polygon->num_points - 1; // The last vertex
    for (int i = 0; i < polygon->num_points; i++) {
        Cx += (polygon->points[j].x + polygon->points[i].x) * (polygon->points[j].x * polygon->points[i].y - polygon->points[i].x * polygon->points[j].y);
        Cy += (polygon->points[j].y + polygon->points[i].y) * (polygon->points[j].x * polygon->points[i].y - polygon->points[i].x * polygon->points[j].y);
        j = i;  // j is previous vertex to i
    }
    centroid->x = Cx / (6 * area);
    centroid->y = Cy / (6 * area);
}

int isPointInsidePolygon(const Polygon *polygon, Point p) {
    int count = 0, i, j;
    for (i = 0, j = polygon->num_points - 1; i < polygon->num_points; j = i++) {
        if (((polygon->points[i].y > p.y) != (polygon->points[j].y > p.y)) &&
            (p.x < (polygon->points[j].x - polygon->points[i].x) * (p.y - polygon->points[i].y) / (polygon->points[j].y - polygon->points[i].y) + polygon->points[i].x)) {
            count++;
        }
    }
    return count % 2; // If odd, inside
}

void translatePolygon(Polygon *polygon, double tx, double ty) {
    for (int i = 0; i < polygon->num_points; i++) {
        polygon->points[i].x += tx;
        polygon->points[i].y += ty;
    }
}

void rotatePolygon(Polygon *polygon, double angle) {
    angle = angle * PI / 180; // Convert to radians
    double cosA = cos(angle);
    double sinA = sin(angle);
    for (int i = 0; i < polygon->num_points; i++) {
        double x_new = polygon->points[i].x * cosA - polygon->points[i].y * sinA;
        double y_new = polygon->points[i].x * sinA + polygon->points[i].y * cosA;
        polygon->points[i].x = x_new;
        polygon->points[i].y = y_new;
    }
}

void scalePolygon(Polygon *polygon, double scale_factor) {
    Point centroid;
    calculateCentroid(polygon, &centroid);
    
    for (int i = 0; i < polygon->num_points; i++) {
        polygon->points[i].x = centroid.x + (polygon->points[i].x - centroid.x) * scale_factor;
        polygon->points[i].y = centroid.y + (polygon->points[i].y - centroid.y) * scale_factor;
    }
}