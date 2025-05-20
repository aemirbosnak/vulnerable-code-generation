//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 4

// Define the player symbols
#define PLAYER1 'X'
#define PLAYER2 'O'

// Define the game state
#define GAME_IN_PROGRESS 0
#define PLAYER1_WON 1
#define PLAYER2_WON 2
#define DRAW 3

// Define the function prototypes
void initializeBoard(char board[][BOARD_SIZE]);
void printBoard(char board[][BOARD_SIZE]);
int checkForWin(char board[][BOARD_SIZE]);
void makeMove(char board[][BOARD_SIZE], int player);
void playGame();

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  playGame();

  return 0;
}

// Initialize the game board
void initializeBoard(char board[][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Print the game board
void printBoard(char board[][BOARD_SIZE]) {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("| %c ", board[i][j]);
    }
    printf("|\n");
  }
  printf("\n");
}

// Check for a win
int checkForWin(char board[][BOARD_SIZE]) {
  // Check for a win in each row
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
      return board[i][0] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
    }
  }

  // Check for a win in each column
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i]) {
      return board[0][i] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
    }
  }

  // Check for a win in each diagonal
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
    return board[0][0] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
  }
  if (board[0][3] != ' ' && board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]) {
    return board[0][3] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
  }

  // Check for a draw
  int numEmptyCells = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        numEmptyCells++;
      }
    }
  }

  if (numEmptyCells == 0) {
    return DRAW;
  }

  // No win or draw yet
  return GAME_IN_PROGRESS;
}

// Make a move
void makeMove(char board[][BOARD_SIZE], int player) {
  int row, col;

  do {
    // Get the player's move
    printf("Player %c, enter a row and column (1-4): ", player == PLAYER1 ? 'X' : 'O');
    scanf("%d %d", &row, &col);

    // Check if the move is valid
  } while (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE || board[row - 1][col - 1] != ' ');

  // Make the move
  board[row - 1][col - 1] = player;
}

// Play the game
void playGame() {
  char board[BOARD_SIZE][BOARD_SIZE];
  int player = PLAYER1;
  int gameState;

  // Initialize the game board
  initializeBoard(board);

  // Play the game until there is a winner or a draw
  do {
    // Print the game board
    printBoard(board);

    // Get the player's move
    makeMove(board, player);

    // Check for a win or a draw
    gameState = checkForWin(board);

    // Switch players
    player = player == PLAYER1 ? PLAYER2 : PLAYER1;
  } while (gameState == GAME_IN_PROGRESS);

  // Print the game board
  printBoard(board);

  // Announce the winner or the draw
  if (gameState == PLAYER1_WON) {
    printf("Player X wins!\n");
  } else if (gameState == PLAYER2_WON) {
    printf("Player O wins!\n");
  } else if (gameState == DRAW) {
    printf("Draw!\n");
  }
}