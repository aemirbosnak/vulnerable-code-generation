//FormAI DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void shuffle(int array[], int size) {
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    int j = rand() % size;
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

void printBoard(int board[][SIZE], int size) {
  printf("\t ");
  for (int i = 0; i < size; i++) {
    printf("%d\t ", i);
  }
  printf("\n\n");
  for (int i = 0; i < size; i++) {
    printf("%d\t ", i);
    for (int j = 0; j < size; j++) {
      printf("%d\t ", board[i][j]);
    }
    printf("\n\n");
  }
}

int main() {
  int board[SIZE][SIZE] = {0};
  int numbers[SIZE*SIZE/2];
  for (int i = 0; i < SIZE*SIZE/2; i++) {
    numbers[i] = i+1;
  }
  shuffle(numbers, SIZE*SIZE/2);
  int index = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE/2; j++) {
      board[i][j] = numbers[index];
      board[i][SIZE-j-1] = numbers[index];
      index++;
    }
  }
  printBoard(board, SIZE);

  int moves = 0;
  while (1) {
    int row1, col1, row2, col2;
    printf("Enter the row and column of the first number: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the row and column of the second number: ");
    scanf("%d %d", &row2, &col2);

    if (board[row1][col1] == board[row2][col2]) {
      board[row1][col1] = 0;
      board[row2][col2] = 0;
      moves++;
      printf("You found a match! Moves: %d\n", moves);
    }
    else {
      printf("Sorry, those numbers don't match. Try again.\n");
    }

    printBoard(board, SIZE);

    // check if game is over
    int gameover = 1;
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        if (board[i][j] != 0) {
          gameover = 0;
          break;
        }
      }
      if (gameover == 0) {
        break;
      }
    }
    if (gameover == 1) {
      printf("Congratulations! You won in %d moves!\n", moves);
      break;
    }
  }

  return 0;
}