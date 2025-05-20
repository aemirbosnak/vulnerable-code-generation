//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  Point *points;
  int size;
} Polygon;

Polygon *create_polygon(int size) {
  Polygon *polygon = (Polygon *)malloc(sizeof(Polygon));
  polygon->points = (Point *)malloc(sizeof(Point) * size);
  polygon->size = size;
  return polygon;
}

void destroy_polygon(Polygon *polygon) {
  free(polygon->points);
  free(polygon);
}

void add_point(Polygon *polygon, Point point) {
  polygon->points[polygon->size++] = point;
}

double polygon_area(Polygon *polygon) {
  double area = 0;
  for (int i = 0; i < polygon->size; i++) {
    Point p1 = polygon->points[i];
    Point p2 = polygon->points[(i + 1) % polygon->size];
    area += (p1.x * p2.y) - (p1.y * p2.x);
  }
  return fabs(area) / 2;
}

int main() {
  Polygon *polygon = create_polygon(3);
  add_point(polygon, (Point){0, 0});
  add_point(polygon, (Point){1, 1});
  add_point(polygon, (Point){0, 1});
  printf("Area of the polygon: %f\n", polygon_area(polygon));
  destroy_polygon(polygon);
  return 0;
}