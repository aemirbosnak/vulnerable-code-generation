//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the board size
#define BOARD_SIZE 3

// Declare the board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER1_SYMBOL 'X'
#define PLAYER2_SYMBOL 'O'

// Define the game states
#define GAME_IN_PROGRESS 0
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define TIE 3

// Function to initialize the game board
void initializeBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the game board
void printBoard() {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to get the player's move
void getPlayerMove(char playerSymbol) {
  int row, col;
  bool validMove = false;

  while (!validMove) {
    printf("Player %c, enter your move (row, col): ", playerSymbol);
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ') {
      validMove = true;
    } else {
      printf("Invalid move. Please try again.\n");
    }
  }

  // Place the player's symbol on the board
  board[row][col] = playerSymbol;
}

// Function to check if the game is over
int checkGameOver() {
  // Check for rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      if (board[i][0] == PLAYER1_SYMBOL) {
        return PLAYER1_WIN;
      } else if (board[i][0] == PLAYER2_SYMBOL) {
        return PLAYER2_WIN;
      }
    }
  }

  // Check for columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      if (board[0][j] == PLAYER1_SYMBOL) {
        return PLAYER1_WIN;
      } else if (board[0][j] == PLAYER2_SYMBOL) {
        return PLAYER2_WIN;
      }
    }
  }

  // Check for diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    if (board[0][0] == PLAYER1_SYMBOL) {
      return PLAYER1_WIN;
    } else if (board[0][0] == PLAYER2_SYMBOL) {
      return PLAYER2_WIN;
    }
  }

  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    if (board[0][2] == PLAYER1_SYMBOL) {
      return PLAYER1_WIN;
    } else if (board[0][2] == PLAYER2_SYMBOL) {
      return PLAYER2_WIN;
    }
  }

  // Check for a tie
  int numEmptyCells = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        numEmptyCells++;
      }
    }
  }

  if (numEmptyCells == 0) {
    return TIE;
  }

  // The game is still in progress
  return GAME_IN_PROGRESS;
}

// Function to play the game
void playGame() {
  // Initialize the game board
  initializeBoard();

  // Print the game board
  printBoard();

  // Set the current player to player 1
  char currentPlayerSymbol = PLAYER1_SYMBOL;

  // Play the game until it is over
  while (checkGameOver() == GAME_IN_PROGRESS) {
    // Get the current player's move
    getPlayerMove(currentPlayerSymbol);

    // Print the game board
    printBoard();

    // Switch to the other player
    if (currentPlayerSymbol == PLAYER1_SYMBOL) {
      currentPlayerSymbol = PLAYER2_SYMBOL;
    } else {
      currentPlayerSymbol = PLAYER1_SYMBOL;
    }
  }

  // Print the game result
  int gameOverState = checkGameOver();
  if (gameOverState == PLAYER1_WIN) {
    printf("Player 1 wins!\n");
  } else if (gameOverState == PLAYER2_WIN) {
    printf("Player 2 wins!\n");
  } else {
    printf("Tie!\n");
  }
}

// Main function
int main() {
  // Play the game
  playGame();

  return 0;
}