//FormAI DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdio.h>

void print_triangle(int size) {
  int i, j;
  for(i = 1; i <= size; i++) {
    for(j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }
}

void print_square(int size) {
  int i, j;
  for(i = 1; i <= size; i++) {
    for(j = 1; j <= size; j++) {
      printf("* ");
    }
    printf("\n");
  }
}

void print_rectangle(int width, int height) {
  int i, j;
  for(i = 1; i <= height; i++) {
    for(j = 1; j <= width; j++) {
      printf("* ");
    }
    printf("\n");
  }
}

int main() {
  int choice, size, width, height;
  printf("1. Triangle\n");
  printf("2. Square\n");
  printf("3. Rectangle\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  switch(choice) {
    case 1:
      printf("Enter the size of triangle: ");
      scanf("%d", &size);
      print_triangle(size);
      break;
    case 2:
      printf("Enter the size of square: ");
      scanf("%d", &size);
      print_square(size);
      break;
    case 3:
      printf("Enter the width of rectangle: ");
      scanf("%d", &width);
      printf("Enter the height of rectangle: ");
      scanf("%d", &height);
      print_rectangle(width, height);
      break;
    default:
      printf("Invalid choice\n");
      break;
  }
  return 0;
}