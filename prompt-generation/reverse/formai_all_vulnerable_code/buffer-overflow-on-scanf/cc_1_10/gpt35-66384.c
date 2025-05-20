//FormAI DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_MOVES 10
#define MAX_GUESSES 2

// function to initialize the game board
void initializeBoard(int board[][BOARD_SIZE]) {
  int count = 1;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = count++;
    }
  }
}

// function to print the game board
void printBoard(int board[][BOARD_SIZE], int visible[][BOARD_SIZE]) {
  printf("   ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
  }
  printf("\n");
  printf("  ---------\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d |", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (visible[i][j]) {
        printf("%d ", board[i][j]);
      } else {
        printf("X ");
      }
    }
    printf("|\n");
  }
  printf("  ---------\n");
}

// function to pick a random cell for the move
void pickRandomCell(int *row, int *col) {
  *row = rand() % BOARD_SIZE;
  *col = rand() % BOARD_SIZE;
}

int main() {
  int board[BOARD_SIZE][BOARD_SIZE];
  int visible[BOARD_SIZE][BOARD_SIZE] = {0};
  int remainingMoves = MAX_MOVES;
  srand(time(NULL));

  printf("Welcome to the Memory Game!\n");
  printf("You have %d moves to uncover all the cells on the board.\n", MAX_MOVES);
  initializeBoard(board);

  // reveal initial cell
  int row = 0, col = 0;
  visible[row][col] = 1;
  printBoard(board, visible);
  printf("\n");

  // start the game loop
  while (remainingMoves > 0) {
    printf("Remaining moves: %d\n", remainingMoves);
    printf("Enter your guess in the format row,col (e.g. 1,2): ");
    int guessRow[MAX_GUESSES], guessCol[MAX_GUESSES], correctGuess[MAX_GUESSES], guessCount = 0;
    scanf("%d,%d", &guessRow[guessCount], &guessCol[guessCount]);

    // make sure the cell is still hidden and within board range
    if (guessRow[guessCount] < BOARD_SIZE && guessCol[guessCount] < BOARD_SIZE && !visible[guessRow[guessCount]][guessCol[guessCount]]) {
      guessCount++;
      visible[guessRow[0]][guessCol[0]] = 0;
      visible[guessRow[1]][guessCol[1]] = 0;
      visible[guessRow[guessCount-1]][guessCol[guessCount-1]] = 1;

      // if the guessed cells match, mark them as correct
      if (board[guessRow[0]][guessCol[0]] == board[guessRow[1]][guessCol[1]]) {
        correctGuess[0] = correctGuess[1] = 1;
      } else {
        correctGuess[0] = correctGuess[1] = 0;
      }

      printBoard(board, visible);
      printf("\n");

      // check if all cells are visible, game over
      int allVisible = 1;
      for (int i = 0; i < BOARD_SIZE && allVisible; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
          if (!visible[i][j]) {
            allVisible = 0;
            break;
          }
        }
      }
      if (allVisible) {
        printf("Congratulations, you won the game!\n");
        break;
      }

      // decrement remaining moves
      remainingMoves--;

    } else {
      printf("Invalid guess, please enter a valid guess.\n");
    }
  }

  if (remainingMoves == 0) {
    printf("Sorry, you have lost the game.\n");
  }
  return 0;
}