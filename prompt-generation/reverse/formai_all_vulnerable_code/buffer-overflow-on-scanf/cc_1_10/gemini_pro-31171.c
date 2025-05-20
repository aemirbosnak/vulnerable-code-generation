//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: shape shifting
#include <stdio.h>

// A function that prints a right triangle of height n.
void printTriangle(int n) {
  // If n is less than or equal to 0, then the triangle is not valid.
  if (n <= 0) {
    printf("Invalid triangle height.\n");
    return;
  }

  // Print the first line of the triangle.
  for (int i = 0; i < n; i++) {
    printf("*");
  }
  printf("\n");

  // Print the remaining lines of the triangle.
  for (int i = 1; i < n; i++) {
    // Print the spaces for the current line.
    for (int j = 0; j < i; j++) {
      printf(" ");
    }

    // Print the stars for the current line.
    for (int j = i; j < n; j++) {
      printf("*");
    }
    printf("\n");
  }
}

// A function that prints a diamond of height n.
void printDiamond(int n) {
  // If n is less than or equal to 0, then the diamond is not valid.
  if (n <= 0) {
    printf("Invalid diamond height.\n");
    return;
  }

  // Print the top half of the diamond.
  for (int i = 1; i <= n; i++) {
    // Print the spaces for the current line.
    for (int j = 0; j < n - i; j++) {
      printf(" ");
    }

    // Print the stars for the current line.
    for (int j = 0; j < 2 * i - 1; j++) {
      printf("*");
    }
    printf("\n");
  }

  // Print the bottom half of the diamond.
  for (int i = n - 1; i >= 1; i--) {
    // Print the spaces for the current line.
    for (int j = 0; j < n - i; j++) {
      printf(" ");
    }

    // Print the stars for the current line.
    for (int j = 0; j < 2 * i - 1; j++) {
      printf("*");
    }
    printf("\n");
  }
}

// A function that prints a pyramid of height n.
void printPyramid(int n) {
  // If n is less than or equal to 0, then the pyramid is not valid.
  if (n <= 0) {
    printf("Invalid pyramid height.\n");
    return;
  }

  // Print the layers of the pyramid.
  for (int i = 1; i <= n; i++) {
    // Print the spaces for the current layer.
    for (int j = 0; j < n - i; j++) {
      printf(" ");
    }

    // Print the stars for the current layer.
    for (int j = 0; j < 2 * i - 1; j++) {
      printf("*");
    }
    printf("\n");
  }
}

int main() {
  // Get the height of the shape from the user.
  int n;
  printf("Enter the height of the shape: ");
  scanf("%d", &n);

  // Print the shape based on the user's input.
  printf("\nTriangle:\n");
  printTriangle(n);
  printf("\nDiamond:\n");
  printDiamond(n);
  printf("\nPyramid:\n");
  printPyramid(n);

  return 0;
}