//FormAI DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL));
  
  int row, col;
  
  printf("Welcome to the C Table Game!\n");
  printf("Enter the number of rows: ");
  scanf("%d", &row);
  printf("Enter the number of columns: ");
  scanf("%d", &col);
  
  int table[row][col];
  
  printf("Generating random table...\n");
  
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      table[i][j] = rand() % 10;
    }
  }
  
  printf("Table generated.\n");
  
  printf("Your table is:\n");
  
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }
  
  printf("Choose a cell to start from...\n");
  int startX, startY;
  printf("Enter the row number: ");
  scanf("%d", &startX);
  printf("Enter the column number: ");
  scanf("%d", &startY);
  
  printf("Starting from cell (%d, %d).\n", startX, startY);
  
  int currentX = startX;
  int currentY = startY;
  int sum = table[startX][startY];
  int numMoves = 0;
  int totalMoves = row * col;
  
  while (numMoves < totalMoves) {
    int nextX = rand() % row;
    int nextY = rand() % col;
    if ((nextX >= currentX - 1) && (nextX <= currentX + 1) && (nextY >= currentY - 1) && (nextY <= currentY + 1) && (nextX != currentX || nextY != currentY)) {
      currentX = nextX;
      currentY = nextY;
      sum += table[currentX][currentY];
      numMoves++;
      printf("Moved to cell (%d, %d).\n", currentX, currentY);
    }
  }
  
  printf("You made %d moves and the sum of the numbers you passed through is %d.", numMoves, sum);
  
  return 0;
}