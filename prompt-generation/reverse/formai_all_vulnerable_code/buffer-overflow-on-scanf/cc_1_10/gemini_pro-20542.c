//GEMINI-pro DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rows and columns on the game board
#define ROWS 5
#define COLUMNS 5

// Define the possible moves a player can make
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

// Define the possible game states
#define PLAYING 0
#define WON 1
#define LOST 2

// Create the game board
char board[ROWS][COLUMNS];

// Create the player's position
int playerRow = 0;
int playerColumn = 0;

// Create the goal position
int goalRow = ROWS - 1;
int goalColumn = COLUMNS - 1;

// Initialize the game state
int gameState = PLAYING;

// Print the game board to the console
void printBoard() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

// Check if the player has won the game
int checkWin() {
  if (playerRow == goalRow && playerColumn == goalColumn) {
    return WON;
  } else {
    return PLAYING;
  }
}

// Check if the player has lost the game
int checkLoss() {
  // Check if the player has moved off the game board
  if (playerRow < 0 || playerRow >= ROWS || playerColumn < 0 || playerColumn >= COLUMNS) {
    return LOST;
  }

  // Check if the player has moved into a wall
  if (board[playerRow][playerColumn] == '#') {
    return LOST;
  }

  // Otherwise, the player has not lost
  return PLAYING;
}

// Move the player in the specified direction
void movePlayer(char direction) {
  switch (direction) {
    case UP:
      playerRow--;
      break;
    case DOWN:
      playerRow++;
      break;
    case LEFT:
      playerColumn--;
      break;
    case RIGHT:
      playerColumn++;
      break;
  }
}

// Get the player's next move from the console
char getNextMove() {
  char move;
  printf("Enter your move (w, s, a, d): ");
  scanf(" %c", &move);
  return move;
}

// Main game loop
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create the game board
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      // Generate a random character for the cell
      char character = rand() % 2 == 0 ? '.' : '#';
      board[i][j] = character;
    }
  }

  // Print the game board to the console
  printBoard();

  // While the game is still playing
  while (gameState == PLAYING) {
    // Get the player's next move
    char move = getNextMove();

    // Move the player in the specified direction
    movePlayer(move);

    // Check if the player has won or lost the game
    gameState = checkWin();
    if (gameState == WON) {
      printf("You win!\n");
    } else if (gameState == LOST) {
      printf("You lose!\n");
    } else {
      // Continue playing the game
      printBoard();
    }
  }

  return 0;
}