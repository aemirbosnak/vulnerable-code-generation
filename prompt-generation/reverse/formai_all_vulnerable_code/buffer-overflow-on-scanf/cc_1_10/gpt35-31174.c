//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>

/* This program computes the area of a convex polygon using the Shoelace formula. */

struct Point {
  int x;
  int y;
};

/* The area of a polygon is half the absolute value of the sum of the 
   cross products of adjacent pairs of vertices. */
int shoelace(struct Point* polygon, int num_points) {
  int i, area = 0;

  /* Iterate through each pair of adjacent points in the polygon. */
  for (i = 0; i < num_points; i++) {
    int x1 = polygon[i].x;
    int y1 = polygon[i].y;
    int x2 = polygon[(i+1) % num_points].x;
    int y2 = polygon[(i+1) % num_points].y;
    area += x1*y2 - x2*y1;
  }

  /* Return the absolute value of the area divided by 2. */
  return abs(area/2);
}

/* Get user input for a polygon and compute its area using the functions above. */
int main() {
  int i, num_points;
  printf("Enter the number of points in the polygon: ");
  scanf("%d", &num_points);

  /* Create a dynamic array to store the polygon points. */
  struct Point* polygon = malloc(num_points * sizeof(struct Point));

  /* Get user input for each polygon point. */
  for (i = 0; i < num_points; i++) {
    printf("Enter the x coordinate of point %d: ", i+1);
    scanf("%d", &polygon[i].x);
    printf("Enter the y coordinate of point %d: ", i+1);
    scanf("%d", &polygon[i].y);
  }

  /* Compute the area of the polygon using the Shoelace formula. */
  int area = shoelace(polygon, num_points);

  printf("The area of the polygon is %d square units.\n", area);

  /* Free the memory allocated for the polygon array. */
  free(polygon);
  return 0;
}