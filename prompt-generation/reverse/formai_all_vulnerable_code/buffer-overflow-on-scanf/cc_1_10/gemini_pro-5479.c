//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 8
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER1 'X'
#define PLAYER2 'O'

// Define the game states
#define GAME_IN_PROGRESS 0
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define TIE 3

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

// Function to get the player's move
int getMove(char player) {
  int move;
  printf("Player %c, enter your move (1-9): ", player);
  scanf("%d", &move);
  return move - 1;
}

// Function to check if the move is valid
int isValidMove(int move) {
  return move >= 0 && move < BOARD_SIZE && board[move / BOARD_SIZE][move % BOARD_SIZE] == ' ';
}

// Function to make a move
void makeMove(int move, char player) {
  board[move / BOARD_SIZE][move % BOARD_SIZE] = player;
}

// Function to check if the game is over
int isGameOver() {
  // Check for horizontal wins
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check for vertical wins
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return board[0][j] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check for diagonal wins
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
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
  int gameState = GAME_IN_PROGRESS;
  char currentPlayer = PLAYER1;

  while (gameState == GAME_IN_PROGRESS) {
    // Print the game board
    printBoard();

    // Get the player's move
    int move = getMove(currentPlayer);

    // Check if the move is valid
    if (isValidMove(move)) {
      // Make the move
      makeMove(move, currentPlayer);

      // Check if the game is over
      gameState = isGameOver();
    } else {
      printf("Invalid move. Please try again.\n");
    }

    // Switch to the other player
    currentPlayer = currentPlayer == PLAYER1 ? PLAYER2 : PLAYER1;
  }

  // Print the game board
  printBoard();

  // Print the game result
  switch (gameState) {
    case PLAYER1_WIN:
      printf("Player 1 wins!\n");
      break;
    case PLAYER2_WIN:
      printf("Player 2 wins!\n");
      break;
    case TIE:
      printf("Tie!\n");
      break;
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the game board
  initBoard();

  // Play the game
  playGame();

  return 0;
}