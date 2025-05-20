//FormAI DATASET v1.0 Category: Pattern printing ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
  char c = 219;
  int rows = 10;
  int cols = 10;
  char pattern[rows][cols];
  int i, j;
  char colors[] = {105, 102, 99, 96, 93, 87, 84, 81, 78, 75, 72};
  
  printf("\nCYBERPUNK PATTERN\n");
  printf("Enter the character you want to use for the pattern: ");
  scanf("%c", &c);
  
  printf("Enter the number of rows (minimum 10): ");
  scanf("%d", &rows);
  if (rows < 10) {
    rows = 10;
  }
  
  printf("Enter the number of columns (minimum 10): ");
  scanf("%d", &cols);
  if (cols < 10) {
    cols = 10;
  }
  
  printf("Generating pattern...\n");
  
  // Generate the pattern
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      pattern[i][j] = c;
    }
  }
  
  // Print the pattern
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      // Randomly select a color from the array
      int index = rand() % 11;
      printf("%c[%d;%dm", 27, 1, colors[index]);
      printf("%c ", pattern[i][j]);
    }
    printf("%c[0m", 27);
    printf("\n");
  }
  
  printf("Pattern generated successfully.\n");
  
  return 0;
}