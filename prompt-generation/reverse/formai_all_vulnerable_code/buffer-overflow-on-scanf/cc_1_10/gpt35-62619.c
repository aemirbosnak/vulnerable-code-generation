//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3

void printBoard(int board[][COLUMNS]);
bool checkWin(int board[][COLUMNS], int player);
bool checkTie(int board[][COLUMNS]);
void updateBoard(int board[][COLUMNS], int player);
int getRandomMove(int board[][COLUMNS]);

int main(void) {
  // Initialize the game board
  int board[ROWS][COLUMNS] = {{0,0,0}, {0,0,0}, {0,0,0}};
  bool gameOver = false;
  int currentPlayer = 1;
  
  printf("Welcome to the Tic Tac Toe C Table Game\n\n");
  printf("Player 1 represents X and Player 2 represents O\n");
  printf("Player %d goes first\n", currentPlayer);
  printf("The board is numbered from 1 to 9, as shown below:\n\n");
  printf(" 1 | 2 | 3 \n");
  printf("-----------\n");
  printf(" 4 | 5 | 6 \n");
  printf("-----------\n");
  printf(" 7 | 8 | 9 \n\n");

  // Game loop
  while (!gameOver) {
    // Print the board
    printBoard(board);

    // Get move from player
    updateBoard(board, currentPlayer);
    
    // Check if the game is over
    if (checkWin(board, currentPlayer)) {
      printf("Player %d wins!\n", currentPlayer);
      gameOver = true;
    } else if (checkTie(board)) {
      printf("The game is a tie!\n");
      gameOver = true;
    }
    
    // Switch to other player
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
  }

  return 0;
}

/**
 * Prints the current game board
 */
void printBoard(int board[][COLUMNS]) {
  printf(" %c | %c | %c \n", board[0][0] == 0 ? ' ' : board[0][0] == 1 ? 'X' : 'O',
                           board[0][1] == 0 ? ' ' : board[0][1] == 1 ? 'X' : 'O',
                           board[0][2] == 0 ? ' ' : board[0][2] == 1 ? 'X' : 'O');
  printf("-----------\n");
  printf(" %c | %c | %c \n", board[1][0] == 0 ? ' ' : board[1][0] == 1 ? 'X' : 'O',
                           board[1][1] == 0 ? ' ' : board[1][1] == 1 ? 'X' : 'O',
                           board[1][2] == 0 ? ' ' : board[1][2] == 1 ? 'X' : 'O');
  printf("-----------\n");
  printf(" %c | %c | %c \n\n", board[2][0] == 0 ? ' ' : board[2][0] == 1 ? 'X' : 'O',
                             board[2][1] == 0 ? ' ' : board[2][1] == 1 ? 'X' : 'O',
                             board[2][2] == 0 ? ' ' : board[2][2] == 1 ? 'X' : 'O');
}

/**
 * Checks if player has won the game
 */
bool checkWin(int board[][COLUMNS], int player) {
  // Check rows
  for (int i = 0; i < ROWS; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }

  // Check columns
  for (int j = 0; j < COLUMNS; j++) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
      return true;
    }
  }

  // Check diagonal
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }

  // Check reverse diagonal
  if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
    return true;
  }

  return false;
}

/**
 * Checks if the game is a tie
 */
bool checkTie(int board[][COLUMNS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      if (board[i][j] == 0) {
        return false;
      }
    }
  }
  return true;
}

/**
 * Updates the game board with player's move
 */
void updateBoard(int board[][COLUMNS], int player) {
  bool validMove = false;

  while (!validMove) {
    int move;
    if (player == 1) {
      printf("Player 1 (X): Enter a move (1-9): ");
      scanf("%d", &move);
    } else {
      // simulate player 2 move
      move = getRandomMove(board);
      printf("Player 2 (O) chooses move: %d\n", move);
    }
    
    // Check if move is valid
    int row = (move - 1) / ROWS;
    int col = (move - 1) % COLUMNS;
    if (move >= 1 && move <= 9 && board[row][col] == 0) {
      board[row][col] = player;
      validMove = true;
    } else {
      printf("Invalid move, please choose an available cell (1-9)\n");
    }
  }
}

/**
 * Returns a random move for player 2
 * Only used for simulation purposes
 */
int getRandomMove(int board[][COLUMNS]) {
  int availableMoves[9];
  int numMoves = 0;

  // check available moves
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      if (board[i][j] == 0) {
        availableMoves[numMoves++] = i * ROWS + j + 1;
      }
    }
  }

  // simulate a thinking time before making a move
  srand(time(NULL));
  int delay = (rand() % 2) + 1;
  sleep(delay);

  // choose a random available move
  return availableMoves[rand() % numMoves];
}