//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the game board size
#define BOARD_SIZE 8

// Define the player symbols
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game state
#define GAME_IN_PROGRESS 0
#define PLAYER_1_WINS 1
#define PLAYER_2_WINS 2
#define DRAW 3

// Create the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Initialize the game board
void initBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Print the game board
void printBoard() {
  printf("  ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");

  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("|%c", board[i][j]);
    }
    printf("|\n");
  }
}

// Get the player's move
int getMove(char player) {
  int move;

  printf("Player %c, enter your move (1-%d): ", player, BOARD_SIZE * BOARD_SIZE);
  scanf("%d", &move);

  return move;
}

// Place the player's move on the board
void placeMove(int move, char player) {
  int row = (move - 1) / BOARD_SIZE;
  int col = (move - 1) % BOARD_SIZE;

  board[row][col] = player;
}

// Check if the game is over
int checkGameOver() {
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
  int numEmptyCells = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        numEmptyCells++;
      }
    }
  }

  return numEmptyCells == 0 ? DRAW : GAME_IN_PROGRESS;
}

// Play the game
void playGame() {
  // Initialize the game board
  initBoard();

  // Print the game board
  printBoard();

  // Get the players' names
  char player1Name[20];
  char player2Name[20];
  printf("Enter player 1's name: ");
  scanf("%s", player1Name);
  printf("Enter player 2's name: ");
  scanf("%s", player2Name);

  // Set the current player to player 1
  char currentPlayer = PLAYER_1;

  // Play the game until it is over
  int gameOver = GAME_IN_PROGRESS;
  while (gameOver == GAME_IN_PROGRESS) {
    // Get the current player's move
    int move = getMove(currentPlayer);

    // Place the move on the board
    placeMove(move, currentPlayer);

    // Print the game board
    printBoard();

    // Check if the game is over
    gameOver = checkGameOver();

    // Switch the current player
    currentPlayer = currentPlayer == PLAYER_1 ? PLAYER_2 : PLAYER_1;
  }

  // Print the game result
  if (gameOver == PLAYER_1_WINS) {
    printf("%s wins!\n", player1Name);
  } else if (gameOver == PLAYER_2_WINS) {
    printf("%s wins!\n", player2Name);
  } else {
    printf("Draw!\n");
  }
}

int main() {
  // Play the game
  playGame();

  return 0;
}