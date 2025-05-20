//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game board
char board[3][3];

// Define the player symbols
char player1Symbol = 'X';
char player2Symbol = 'O';

// Define the game state
enum GameState {
  PLAYING,
  PLAYER1_WIN,
  PLAYER2_WIN,
  DRAW
};

// Function to print the game board
void printBoard() {
  printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to check if a player has won
enum GameState checkWin() {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == player1Symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      return board[0][i] == player1Symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == player1Symbol ? PLAYER1_WIN : PLAYER2_WIN;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2] == player1Symbol ? PLAYER1_WIN : PLAYER2_WIN;
  }

  // Check for a draw
  int numEmptyCells = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        numEmptyCells++;
      }
    }
  }

  if (numEmptyCells == 0) {
    return DRAW;
  }

  // Otherwise, the game is still ongoing
  return PLAYING;
}

// Function to get the next move from a player
void getNextMove(char playerSymbol) {
  int row, col;

  do {
    printf("Player %c, enter your move (row, column): ", playerSymbol);
    scanf("%d %d", &row, &col);
  } while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ');

  // Update the game board
  board[row - 1][col - 1] = playerSymbol;
}

// Function to start a new game
void startGame() {
  // Initialize the game board
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }

  // Set the current player to player 1
  char currentPlayer = player1Symbol;

  // Game loop
  while (1) {
    // Print the game board
    printBoard();

    // Get the next move from the current player
    getNextMove(currentPlayer);

    // Check if the game has been won or drawn
    enum GameState gameState = checkWin();

    // If the game has been won or drawn, print the result and exit the loop
    if (gameState != PLAYING) {
      if (gameState == PLAYER1_WIN) {
        printf("Player 1 wins!\n");
      } else if (gameState == PLAYER2_WIN) {
        printf("Player 2 wins!\n");
      } else {
        printf("Draw!\n");
      }
      break;
    }

    // Switch the current player
    currentPlayer = currentPlayer == player1Symbol ? player2Symbol : player1Symbol;
  }
}

// Main function
int main() {
  // Start a new game
  startGame();

  return 0;
}