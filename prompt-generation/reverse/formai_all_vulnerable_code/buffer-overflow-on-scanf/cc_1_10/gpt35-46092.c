//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
#include <stdio.h>

// Define a structure for a point
struct Point {
  int x;
  int y;
};

// Function to calculate distance between two points
float distance(struct Point p1, struct Point p2) {
  int diffx = p1.x - p2.x;
  int diffy = p1.y - p2.y;
  return sqrt(diffx * diffx + diffy * diffy);
}

// Function to check if three points are collinear
int areCollinear(struct Point p1, struct Point p2, struct Point p3) {
  float slope1 = (float)(p1.y - p2.y)/(p1.x - p2.x);
  float slope2 = (float)(p1.y - p3.y)/(p1.x - p3.x);
  if(slope1 == slope2) {
    return 1;
  }
  return 0;
}

// MAIN FUNCTION
int main(void) {
  printf("Enter coordinates for 3 points:\n");

  struct Point p1, p2, p3;
  printf("Point 1 (x,y): ");
  scanf("%d,%d", &p1.x, &p1.y);
  printf("Point 2 (x,y): ");
  scanf("%d,%d", &p2.x, &p2.y);
  printf("Point 3 (x,y): ");
  scanf("%d,%d", &p3.x, &p3.y);

  // Distance calculation
  float dist12 = distance(p1, p2);
  float dist13 = distance(p1, p3);
  float dist23 = distance(p2, p3);
  printf("Distance between point 1 and 2: %.2f\n", dist12);
  printf("Distance between point 1 and 3: %.2f\n", dist13);
  printf("Distance between point 2 and 3: %.2f\n", dist23);

  // Collinear check
  if(areCollinear(p1, p2, p3)) {
    printf("The points are collinear!\n");
  } else {
    printf("The points are not collinear!\n");
  }

  return 0;
}