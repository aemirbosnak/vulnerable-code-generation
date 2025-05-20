//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
char board[3][3];

// Define the player symbols
char player1 = 'X';
char player2 = 'O';

// Define the game state
enum GameState {
  PLAYING,
  PLAYER1_WIN,
  PLAYER2_WIN,
  DRAW
};

// Function to initialize the game board
void initBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the game board
void printBoard() {
  printf("\n");
  for (int i = 0; i < 3; i++) {
    printf("  %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
    if (i < 2) {
      printf("---+---+---\n");
    }
  }
  printf("\n");
}

// Function to get the player's move
int getPlayerMove(char player) {
  int move;
  do {
    printf("Player %c, enter your move (1-9): ", player);
    scanf("%d", &move);
  } while (move < 1 || move > 9 || board[(move - 1) / 3][(move - 1) % 3] != ' ');
  return move - 1;
}

// Function to check for a win
enum GameState checkWin() {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == player1 ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      return board[0][i] == player1 ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == player1 ? PLAYER1_WIN : PLAYER2_WIN;
  }
  if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
    return board[2][0] == player1 ? PLAYER1_WIN : PLAYER2_WIN;
  }

  // Check for a draw
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != ' ') {
        count++;
      }
    }
  }
  if (count == 9) {
    return DRAW;
  }

  // No win or draw yet
  return PLAYING;
}

// Function to play the game
void playGame() {
  // Initialize the game board
  initBoard();

  // Print the game board
  printBoard();

  // Get the player's moves
  int move;
  enum GameState state = PLAYING;
  while (state == PLAYING) {
    // Get the player 1's move
    move = getPlayerMove(player1);

    // Update the game board
    board[move / 3][move % 3] = player1;

    // Print the game board
    printBoard();

    // Check for a win
    state = checkWin();

    // If there is no winner, get the player 2's move
    if (state == PLAYING) {
      move = getPlayerMove(player2);

      // Update the game board
      board[move / 3][move % 3] = player2;

      // Print the game board
      printBoard();

      // Check for a win
      state = checkWin();
    }
  }

  // Print the game result
  switch (state) {
    case PLAYER1_WIN:
      printf("Player 1 wins!\n");
      break;
    case PLAYER2_WIN:
      printf("Player 2 wins!\n");
      break;
    case DRAW:
      printf("Draw!\n");
      break;
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