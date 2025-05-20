//GEMINI-pro DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER1 'X'
#define PLAYER2 'O'

// Define the game states
#define GAME_STATE_IN_PROGRESS 0
#define GAME_STATE_PLAYER1_WIN 1
#define GAME_STATE_PLAYER2_WIN 2
#define GAME_STATE_DRAW 3

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
}

// Function to get the player's move
int getPlayerMove(char playerSymbol) {
  int move;
  printf("Player %c, enter your move (1-9): ", playerSymbol);
  scanf("%d", &move);
  return move - 1;
}

// Function to check if the move is valid
int isValidMove(int move) {
  return move >= 0 && move < BOARD_SIZE * BOARD_SIZE && board[move / BOARD_SIZE][move % BOARD_SIZE] == ' ';
}

// Function to make the move
void makeMove(int move, char playerSymbol) {
  board[move / BOARD_SIZE][move % BOARD_SIZE] = playerSymbol;
}

// Function to check if the game is over
int isGameOver() {
  // Check for a win in rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0] == PLAYER1 ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
    }
  }

  // Check for a win in columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return board[0][j] == PLAYER1 ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
    }
  }

  // Check for a win in diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0] == PLAYER1 ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2] == PLAYER1 ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
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
    return GAME_STATE_DRAW;
  }

  // The game is still in progress
  return GAME_STATE_IN_PROGRESS;
}

// Function to play the game
void playGame() {
  // Initialize the game board
  initializeBoard();

  // Print the game board
  printBoard();

  // Get the first player's move
  int move = getPlayerMove(PLAYER1);

  // Make the move
  makeMove(move, PLAYER1);

  // Loop until the game is over
  while (isGameOver() == GAME_STATE_IN_PROGRESS) {
    // Print the game board
    printBoard();

    // Get the second player's move
    move = getPlayerMove(PLAYER2);

    // Make the move
    makeMove(move, PLAYER2);
  }

  // Print the game board
  printBoard();

  // Get the game state
  int gameState = isGameOver();

  // Print the game result
  switch (gameState) {
    case GAME_STATE_PLAYER1_WIN:
      printf("Player 1 wins!\n");
      break;
    case GAME_STATE_PLAYER2_WIN:
      printf("Player 2 wins!\n");
      break;
    case GAME_STATE_DRAW:
      printf("The game is a draw!\n");
      break;
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  playGame();

  return 0;
}