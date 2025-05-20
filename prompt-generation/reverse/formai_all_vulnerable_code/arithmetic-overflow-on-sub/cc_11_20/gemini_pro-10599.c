//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>

int main() {
  // Pattern: Square

  // Declare variables
  int sideLength;

  // Get input from user
  printf("Enter the side length of the square: ");
  scanf("%d", &sideLength);

  // Print the pattern
  for (int i = 0; i < sideLength; i++) {
    for (int j = 0; j < sideLength; j++) {
      printf("* ");
    }
    printf("\n");
  }

  // Pattern: Triangle

  // Declare variables
  int height;

  // Get input from user
  printf("Enter the height of the triangle: ");
  scanf("%d", &height);

  // Print the pattern
  for (int i = 0; i < height; i++) {
    for (int j = 0; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  // Pattern: Diamond

  // Declare variables
  int diamondHeight;

  // Get input from user
  printf("Enter the height of the diamond: ");
  scanf("%d", &diamondHeight);

  // Print the upper half of the diamond
  for (int i = 0; i < diamondHeight; i++) {
    for (int j = 0; j < diamondHeight - i - 1; j++) {
      printf(" ");
    }
    for (int j = 0; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  // Print the lower half of the diamond
  for (int i = diamondHeight - 1; i > 0; i--) {
    for (int j = 0; j < diamondHeight - i; j++) {
      printf(" ");
    }
    for (int j = 0; j < i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  return 0;
}