//FormAI DATASET v1.0 Category: Fractal Generation ; Style: safe
#include <stdio.h>

#define SIZE 100

char square[SIZE][SIZE];

void drawFractal(int x, int y, int size) {
  if (size == 1) {
    square[x][y] = '*';
    return;
  }
  
  int newSize = size / 3;
  
  /* Draw the 8 sub-squares. */
  drawFractal(x, y, newSize);
  drawFractal(x + newSize, y, newSize);
  drawFractal(x + 2 * newSize, y, newSize);
  
  drawFractal(x, y + newSize, newSize);
  drawFractal(x + 2 * newSize, y + newSize, newSize);
  
  drawFractal(x, y + 2 * newSize, newSize);
  drawFractal(x + newSize, y + 2 * newSize, newSize);
  drawFractal(x + 2 * newSize, y + 2 * newSize, newSize);
}

int main() {
  int size;
  
  printf("Enter the size of the fractal (1 to %d): ", SIZE);
  scanf("%d", &size);
  
  /* Initialize the square. */
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      square[i][j] = ' ';
    }
  }
  
  drawFractal(0, 0, size);
  
  /* Print the square. */
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%c", square[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}