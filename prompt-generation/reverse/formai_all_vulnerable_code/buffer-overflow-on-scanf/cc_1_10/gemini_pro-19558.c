//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: light-weight
#include <stdio.h>

// Table game board
int board[10][10];

// Player pieces
int player1[2] = {0, 0};
int player2[2] = {9, 9};

// Game state
int turn = 1;
int winner = 0;

// Function to print the board
void printBoard() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (board[i][j] == 1) {
        printf("x ");
      } else if (board[i][j] == 2) {
        printf("o ");
      } else {
        printf("- ");
      }
    }
    printf("\n");
  }
}

// Function to check if a move is valid
int isValidMove(int player[2], int moveX, int moveY) {
  // Check if the move is within the bounds of the board
  if (moveX < 0 || moveX > 9 || moveY < 0 || moveY > 9) {
    return 0;
  }

  // Check if the move is on an empty square
  if (board[moveX][moveY] != 0) {
    return 0;
  }

  // Check if the move is adjacent to the player's current position
  if (abs(moveX - player[0]) > 1 || abs(moveY - player[1]) > 1) {
    return 0;
  }

  return 1;
}

// Function to make a move
void makeMove(int player[2], int moveX, int moveY) {
  // Update the board
  board[player[0]][player[1]] = 0;
  board[moveX][moveY] = player[2];

  // Update the player's position
  player[0] = moveX;
  player[1] = moveY;
}

// Function to check if a player has won
int checkWinner() {
  // Check if a player has reached the opposite side of the board
  if (player1[0] == 9 && player1[1] == 9) {
    return 1;
  } else if (player2[0] == 0 && player2[1] == 0) {
    return 2;
  }

  // Check if a player has captured the other player's piece
  if (board[player1[0]][player1[1]] == 2) {
    return 1;
  } else if (board[player2[0]][player2[1]] == 1) {
    return 2;
  }

  // No winner yet
  return 0;
}

// Main game loop
int main() {
  // Initialize the game board
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      board[i][j] = 0;
    }
  }

  // Main game loop
  while (!winner) {
    // Print the board
    printBoard();

    // Get the player's move
    int moveX, moveY;
    printf("Player %d, enter your move (x, y): ", turn);
    scanf("%d %d", &moveX, &moveY);

    // Check if the move is valid
    if (!isValidMove(player1, moveX, moveY)) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Make the move
    makeMove(player1, moveX, moveY);

    // Check if the player has won
    winner = checkWinner();

    // Switch turns
    turn = 3 - turn;
  }

  // Print the winner
  printf("Player %d wins!\n", winner);

  return 0;
}