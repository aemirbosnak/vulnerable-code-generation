//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: statistical
#include <stdio.h>
#include <math.h>
#define MAX_POINTS 100

typedef struct point_s {
  double x,y;
} point;

double get_distance(point p1, point p2){
  double distance = sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
  return distance;
}

double get_perimeter(point* points, int size){
  double perimeter = 0;
  for(int i=0; i<size-1; i++){
    perimeter += get_distance(points[i], points[i+1]);
  }
  perimeter += get_distance(points[size-1], points[0]);
  return perimeter;
}

double get_area(point* points, int size){
  double area = 0;
  for(int i=0; i<size-1; i++){
    area += points[i].x*points[i+1].y - points[i+1].x*points[i].y;
  }
  area += points[size-1].x*points[0].y - points[0].x*points[size-1].y;
  area /= 2;
  return fabs(area);
}

int main(){
  point points[MAX_POINTS];
  int size = 0;

  printf("Enter coordinates of points in the format (x,y):\n");
  while(size<MAX_POINTS){
    printf("Point %d: ", size+1);
    if(scanf("(%lf,%lf)", &points[size].x, &points[size].y)!=2) break;
    size++;
  }

  printf("\nPoint coordinates are:\n");
  for(int i=0; i<size; i++){
    printf("(%.1f,%.1f)\n", points[i].x, points[i].y);
  }

  double perimeter = get_perimeter(points, size);
  double area = get_area(points, size);
  
  printf("\nPerimeter: %.2f\n", perimeter);
  printf("\nArea: %.2f\n", area);

  return 0;
}