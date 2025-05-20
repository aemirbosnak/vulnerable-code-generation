//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 8
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player colors
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game state
#define GAME_IN_PROGRESS 0
#define PLAYER_1_WINS 1
#define PLAYER_2_WINS 2
#define DRAW 3

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
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

// Function to get the player's move
int getMove(char player) {
  int move;
  printf("Player %c, enter your move (1-%d): ", player, BOARD_SIZE * BOARD_SIZE);
  scanf("%d", &move);
  return move - 1;
}

// Function to check if the move is valid
int isValidMove(int move) {
  return move >= 0 && move < BOARD_SIZE * BOARD_SIZE && board[move / BOARD_SIZE][move % BOARD_SIZE] == ' ';
}

// Function to make the move
void makeMove(int move, char player) {
  board[move / BOARD_SIZE][move % BOARD_SIZE] = player;
}

// Function to check if the game is over
int isGameOver() {
  // Check for a win in any row
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0] == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
    }
  }

  // Check for a win in any column
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return board[0][j] == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
    }
  }

  // Check for a win in any diagonal
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0] == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2] == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
  }

  // Check for a draw
  int count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] != ' ') {
        count++;
      }
    }
  }
  return count == BOARD_SIZE * BOARD_SIZE ? DRAW : GAME_IN_PROGRESS;
}

// Function to play the game
void playGame() {
  int player = PLAYER_1;
  int gameOver = GAME_IN_PROGRESS;

  while (gameOver == GAME_IN_PROGRESS) {
    printBoard();
    int move = getMove(player);

    if (isValidMove(move)) {
      makeMove(move, player);
      gameOver = isGameOver();
      player = player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
    } else {
      printf("Invalid move, try again.\n");
    }
  }

  printBoard();

  switch (gameOver) {
    case PLAYER_1_WINS:
      printf("Player 1 wins!\n");
      break;
    case PLAYER_2_WINS:
      printf("Player 2 wins!\n");
      break;
    case DRAW:
      printf("It's a draw!\n");
      break;
  }
}

// Main function
int main() {
  srand(time(NULL));

  initBoard();
  playGame();

  return 0;
}