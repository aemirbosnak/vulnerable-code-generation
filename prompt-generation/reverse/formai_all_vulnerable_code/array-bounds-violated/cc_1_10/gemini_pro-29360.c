//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rows and columns in the game board
#define ROWS 5
#define COLS 5

// Define the different types of squares in the game board
#define EMPTY 0
#define WALL 1
#define HEART 2
#define CUPID 3
#define GOAL 4

// Define the different states of the game
#define PLAYING 0
#define WON 1
#define LOST 2

// Define the different directions that the player can move
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Function to initialize the game board
void initBoard(int board[ROWS][COLS]) {
  // Set all squares to empty
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board[i][j] = EMPTY;
    }
  }

  // Place walls around the perimeter of the board
  for (int i = 0; i < ROWS; i++) {
    board[i][0] = WALL;
    board[i][COLS - 1] = WALL;
  }
  for (int j = 0; j < COLS; j++) {
    board[0][j] = WALL;
    board[ROWS - 1][j] = WALL;
  }

  // Place a heart in the center of the board
  board[ROWS / 2][COLS / 2] = HEART;

  // Place Cupid in a random location on the board
  srand(time(NULL));
  int cupidRow = rand() % (ROWS - 2) + 1;
  int cupidCol = rand() % (COLS - 2) + 1;
  board[cupidRow][cupidCol] = CUPID;

  // Place the goal in a random location on the board
  int goalRow = rand() % (ROWS - 2) + 1;
  int goalCol = rand() % (COLS - 2) + 1;
  board[goalRow][goalCol] = GOAL;
}

// Function to print the game board
void printBoard(int board[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      switch (board[i][j]) {
        case EMPTY:
          printf("  ");
          break;
        case WALL:
          printf("# ");
          break;
        case HEART:
          printf("♥ ");
          break;
        case CUPID:
          printf("☺ ");
          break;
        case GOAL:
          printf("♡ ");
          break;
      }
    }
    printf("\n");
  }
}

// Function to get the player's next move
int getNextMove(void) {
  int move;
  printf("Enter your next move (up, down, left, right): ");
  scanf("%d", &move);
  return move;
}

// Function to move the player
void movePlayer(int board[ROWS][COLS], int row, int col, int move) {
  switch (move) {
    case UP:
      if (board[row - 1][col] != WALL) {
        board[row][col] = EMPTY;
        board[row - 1][col] = CUPID;
      }
      break;
    case DOWN:
      if (board[row + 1][col] != WALL) {
        board[row][col] = EMPTY;
        board[row + 1][col] = CUPID;
      }
      break;
    case LEFT:
      if (board[row][col - 1] != WALL) {
        board[row][col] = EMPTY;
        board[row][col - 1] = CUPID;
      }
      break;
    case RIGHT:
      if (board[row][col + 1] != WALL) {
        board[row][col] = EMPTY;
        board[row][col + 1] = CUPID;
      }
      break;
  }
}

// Function to check if the player has won
int checkWin(int board[ROWS][COLS], int row, int col) {
  return board[row][col] == GOAL;
}

// Function to play the game
void playGame(void) {
  // Initialize the game board
  int board[ROWS][COLS];
  initBoard(board);

  // Get the player's starting position
  int row, col;
  printf("Enter your starting position (row, column): ");
  scanf("%d %d", &row, &col);

  // Set the player's position on the board
  board[row][col] = CUPID;

  // Print the game board
  printBoard(board);

  // Get the player's next move
  int move = getNextMove();

  // While the player has not won or lost
  while (!checkWin(board, row, col)) {
    // Move the player
    movePlayer(board, row, col, move);

    // Print the game board
    printBoard(board);

    // Get the player's next move
    move = getNextMove();
  }

  // If the player has won
  if (checkWin(board, row, col)) {
    printf("You win!\n");
  } else {
    printf("You lose!\n");
  }
}

// Main function
int main(void) {
  playGame();
  return 0;
}