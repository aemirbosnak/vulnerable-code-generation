//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];

// Define the game states
enum GameState {
  PLAYING,
  X_WON,
  O_WON,
  TIE
};

// Function to initialize the game board
void initBoard() {
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
}

// Function to check if a player has won
enum GameState checkWin() {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0] == 'X' ? X_WON : O_WON;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return board[0][j] == 'X' ? X_WON : O_WON;
    }
  }

  // Check diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0] == 'X' ? X_WON : O_WON;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2] == 'X' ? X_WON : O_WON;
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

  // No winner yet
  return PLAYING;
}

// Function to get the player's move
void getPlayerMove(char player) {
  int row, col;

  printf("Player %c, enter your move (row, column): ", player);
  scanf("%d %d", &row, &col);

  // Validate the move
  while (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE || board[row - 1][col - 1] != ' ') {
    printf("Invalid move. Please enter a valid move: ");
    scanf("%d %d", &row, &col);
  }

  // Place the player's symbol on the board
  board[row - 1][col - 1] = player;
}

// Function to play the game
void playGame() {
  // Initialize the game board
  initBoard();

  // Set the current player to X
  char currentPlayer = 'X';

  // Game loop
  enum GameState gameState = PLAYING;
  while (gameState == PLAYING) {
    // Print the game board
    printBoard();

    // Get the player's move
    getPlayerMove(currentPlayer);

    // Check if a player has won
    gameState = checkWin();

    // Switch the current player
    currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
  }

  // Print the game result
  if (gameState == X_WON) {
    printf("\nPlayer X wins!\n");
  } else if (gameState == O_WON) {
    printf("\nPlayer O wins!\n");
  } else {
    printf("\nTie game!\n");
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  playGame();

  return 0;
}