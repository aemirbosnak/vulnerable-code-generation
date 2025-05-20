//Gemma-7B DATASET v1.0 Category: Table Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_SHAPES 5

typedef struct Shape {
  char name;
  int points;
  int color;
} Shape;

Shape shapes[MAX_SHAPES] = {
  {'C', 4, 1},
  {'R', 3, 2},
  {'T', 2, 3},
  {'A', 1, 4},
  {'O', 0, 5}
};

int main() {
  int numShapes = 0;
  char chosenShape = ' ';

  // Create a new shape
  Shape newShape;
  newShape.name = 'N';
  newShape.points = 5;
  newShape.color = 3;

  // Add the new shape to the array
  shapes[numShapes++] = newShape;

  // Display the list of shapes
  for (int i = 0; i < numShapes; i++) {
    printf("Shape: %c, Points: %d, Color: %d\n", shapes[i].name, shapes[i].points, shapes[i].color);
  }

  // Ask the user to choose a shape
  printf("Choose a shape: ");
  scanf("%c", &chosenShape);

  // Find the shape and display its details
  for (int i = 0; i < numShapes; i++) {
    if (shapes[i].name == chosenShape) {
      printf("Shape: %c, Points: %d, Color: %d\n", shapes[i].name, shapes[i].points, shapes[i].color);
    }
  }

  return 0;
}