//GEMINI-pro DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 3

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the game board
void initializeBoard() {
  // Set all cells to empty
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the game board
void printBoard() {
  // Print the top border
  printf("   ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");

  // Print the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("| %c ", board[i][j]);
    }
    printf("|\n");
  }

  // Print the bottom border
  printf("   ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("---");
  }
  printf("\n");
}

// Function to get the player's move
int getMove(char player) {
  int move;
  while (1) {
    printf("Player %c, enter your move (1-9): ", player);
    scanf("%d", &move);
    if (move >= 1 && move <= 9) {
      return move;
    } else {
      printf("Invalid move. Please try again.\n");
    }
  }
}

// Function to check if the game is over
int checkGameOver() {
  // Check for a win
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0];
    }
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return board[0][i];
    }
  }

  // Check for a diagonal win
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0];
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2];
  }

  // Check for a tie
  int count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] != ' ') {
        count++;
      }
    }
  }
  if (count == BOARD_SIZE * BOARD_SIZE) {
    return 'T';
  }

  // The game is not over yet
  return ' ';
}

// Function to play the game
void playGame() {
  // Initialize the game board
  initializeBoard();

  // Print the game board
  printBoard();

  // Game loop
  while (1) {
    // Get the player 1's move
    int move1 = getMove('X');

    // Update the game board
    int row1 = (move1 - 1) / BOARD_SIZE;
    int col1 = (move1 - 1) % BOARD_SIZE;
    board[row1][col1] = 'X';

    // Print the game board
    printBoard();

    // Check if the game is over
    int gameOver = checkGameOver();
    if (gameOver != ' ') {
      if (gameOver == 'T') {
        printf("Tie game!\n");
      } else {
        printf("Player %c wins!\n", gameOver);
      }
      break;
    }

    // Get the player 2's move
    int move2 = getMove('O');

    // Update the game board
    int row2 = (move2 - 1) / BOARD_SIZE;
    int col2 = (move2 - 1) % BOARD_SIZE;
    board[row2][col2] = 'O';

    // Print the game board
    printBoard();

    // Check if the game is over
    gameOver = checkGameOver();
    if (gameOver != ' ') {
      if (gameOver == 'T') {
        printf("Tie game!\n");
      } else {
        printf("Player %c wins!\n", gameOver);
      }
      break;
    }
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  playGame();

  return 0;
}