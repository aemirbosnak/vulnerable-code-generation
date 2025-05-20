//FormAI DATASET v1.0 Category: Memory Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initializeBoard(char board[ROWS][COLS], int *numPairs);
void displayBoard(char board[ROWS][COLS]);
void getGuess(int *row, int *col);
int checkGuess(char board[ROWS][COLS], int row1, int col1, int row2, int col2);

int main(void) {
  char board[ROWS][COLS];
  int numPairs = (ROWS * COLS) / 2;
  int matchedPairs = 0;
  int guess1Row, guess1Col, guess2Row, guess2Col;
  
  srand(time(NULL));
  
  initializeBoard(board, &numPairs);
  
  while (matchedPairs < numPairs) {
    displayBoard(board);
    
    printf("Enter your first guess (row,column): ");
    getGuess(&guess1Row, &guess1Col);
    
    printf("Enter your second guess (row,column): ");
    getGuess(&guess2Row, &guess2Col);
    
    if (checkGuess(board, guess1Row, guess1Col, guess2Row, guess2Col)) {
      printf("Matched pair!!\n");
      matchedPairs++;
    } else {
      printf("Not a match. Try again.\n");
    }
  }
  
  printf("Congratulations! You completed the game!\n");
  
  return 0;
}

void initializeBoard(char board[ROWS][COLS], int *numPairs) {
  int i, j, k;
  int numPairsCopy = *numPairs;
  char symbol = 'A';
  
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      board[i][j] = '-';
    }
  }
  
  for (k = 0; k < numPairsCopy; k++) {
    for (i = 0; i < ROWS && numPairsCopy > 0; i++) {
      for (j = 0; j < COLS && numPairsCopy > 0; j++) {
        if (board[i][j] == '-') {
          board[i][j] = symbol;
          numPairsCopy--;
          if (numPairsCopy <= 0) break;
        }
      }
      if (numPairsCopy <= 0) break;
    }
    symbol++;
  }
  
  // Shuffle the board
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      int randomRow = rand() % ROWS;
      int randomCol = rand() % COLS;
      char temp = board[i][j];
      board[i][j] = board[randomRow][randomCol];
      board[randomRow][randomCol] = temp;
    }
  }
}

void displayBoard(char board[ROWS][COLS]) {
  int i, j;
  
  printf("   ");
  for (i = 0; i < COLS; i++) {
    printf("%d ", i+1);
  }
  printf("\n");
  
  printf("  +-");
  for (i = 0; i < COLS; i++) {
    printf("--");
  }
  printf("+\n");
  
  for (i = 0; i < ROWS; i++) {
    printf("%d | ", i+1);
    for (j = 0; j < COLS; j++) {
      printf("%c ", board[i][j]);
    }
    printf("|\n");
  }
  
  printf("  +-");
  for (i = 0; i < COLS; i++) {
    printf("--");
  }
  printf("+\n");
}

void getGuess(int *row, int *col) {
  scanf("%d,%d", row, col);
  (*row)--;
  (*col)--;
}

int checkGuess(char board[ROWS][COLS], int row1, int col1, int row2, int col2) {
  if (board[row1][col1] == board[row2][col2]) {
    board[row1][col1] = ' ';
    board[row2][col2] = ' ';
    return 1;
  }
  return 0;
}