//GEMINI-pro DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 10
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player's position
int playerX = 0;
int playerY = 0;

// Define the goal position
int goalX = BOARD_SIZE - 1;
int goalY = BOARD_SIZE - 1;

// Define the number of moves
int numMoves = 0;

// Initialize the game board
void initBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = '.';
    }
  }

  // Place the player at the starting position
  board[playerX][playerY] = 'P';

  // Place the goal at the ending position
  board[goalX][goalY] = 'G';
}

// Print the game board
void printBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

// Get the player's input
void getPlayerInput() {
  char input;
  printf("Enter your move (w, a, s, d): ");
  scanf(" %c", &input);

  // Update the player's position based on the input
  switch (input) {
    case 'w':
      playerY--;
      break;
    case 'a':
      playerX--;
      break;
    case 's':
      playerY++;
      break;
    case 'd':
      playerX++;
      break;
  }
}

// Check if the player has reached the goal
int checkGoal() {
  return playerX == goalX && playerY == goalY;
}

// Play the game
void playGame() {
  // Initialize the game board
  initBoard();

  // Print the game board
  printBoard();

  // Get the player's input
  while (!checkGoal()) {
    getPlayerInput();

    // Update the game board
    board[playerX][playerY] = 'P';
    board[playerX - 1][playerY] = '.';
    board[playerX + 1][playerY] = '.';
    board[playerX][playerY - 1] = '.';
    board[playerX][playerY + 1] = '.';

    // Print the game board
    printBoard();

    // Increment the number of moves
    numMoves++;
  }

  // Print the winning message
  printf("Congratulations! You reached the goal in %d moves.\n", numMoves);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  playGame();

  return 0;
}