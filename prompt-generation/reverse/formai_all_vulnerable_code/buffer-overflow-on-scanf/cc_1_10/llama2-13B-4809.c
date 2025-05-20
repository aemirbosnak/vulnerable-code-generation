//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Function to print a pattern
void print_pattern(int width, int height, char pattern[]) {
  int i, j;
  for (i = 0; i < width; i++) {
    for (j = 0; j < height; j++) {
      if (i % 2 == 0 && j % 2 == 0) {
        printf("%c", pattern[i * height + j]);
      } else if (i % 2 == 1 && j % 2 == 0) {
        printf("%c", pattern[i * height + j] + 1);
      } else if (i % 2 == 0 && j % 2 == 1) {
        printf("%c", pattern[i * height + j] - 1);
      } else {
        printf("%c", pattern[i * height + j]);
      }
    }
    printf("\n");
  }
}

int main() {
  int width, height;
  char pattern[MAX_WIDTH][MAX_HEIGHT];

  // Get the width and height of the pattern
  printf("Enter the width of the pattern: ");
  scanf("%d", &width);
  printf("Enter the height of the pattern: ");
  scanf("%d", &height);

  // Generate the pattern
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      // Generate a random character for the pattern
      char random_char = 'A' + (rand() % 26);
      pattern[i][j] = random_char;
    }
  }

  // Print the pattern
  print_pattern(width, height, pattern);

  return 0;
}