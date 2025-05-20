//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point{
   float x;
   float y;
};
typedef struct point Point;

float area(Point *a, Point *b, Point *c){
   float area = 0.0;
   area = (a->x*(b->y-c->y) + b->x*(c->y-a->y) + c->x*(a->y-b->y))/2.0;
   return fabs(area);
}

int is_inside_triangle(Point *a, Point *b, Point *c, Point *p){
   float abc_area = area(a, b, c);
   float pab_area = area(p, a, b);
   float pbc_area = area(p, b, c);
   float pca_area = area(p, c, a);
   float sum_of_areas = pab_area + pbc_area + pca_area;

   if(abc_area == sum_of_areas)
      return 1;
   else
      return 0;
}

int main(){
   Point a, b, c, p;
   printf("Enter the co-ordinates of vertex A of triangle:\n");
   scanf("%f%f", &a.x, &a.y);

   printf("Enter the co-ordinates of vertex B of triangle:\n");
   scanf("%f%f", &b.x, &b.y);

   printf("Enter the co-ordinates of vertex C of triangle:\n");
   scanf("%f%f", &c.x, &c.y);

   printf("Enter the co-ordinates of point P to check if its inside the triangle or not:\n");
   scanf("%f%f", &p.x, &p.y);

   if(is_inside_triangle(&a, &b, &c, &p))
      printf("Point P is inside the triangle ABC.\n");
   else
      printf("Point P is outside the triangle ABC.\n");

   return 0;
}