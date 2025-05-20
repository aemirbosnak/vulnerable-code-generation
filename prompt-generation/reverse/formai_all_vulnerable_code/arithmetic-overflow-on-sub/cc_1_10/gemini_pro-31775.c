//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BOARD_SIZE 3
#define NUM_PLAYERS 2
#define EMPTY 0
#define X 1
#define O 2

// Function to initialize the game board
void initBoard(int board[][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = EMPTY;
    }
  }
}

// Function to print the game board
void printBoard(int board[][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      char symbol;
      switch (board[i][j]) {
        case X:
          symbol = 'X';
          break;
        case O:
          symbol = 'O';
          break;
        default:
          symbol = ' ';
      }
      printf("%c ", symbol);
    }
    printf("\n");
  }
}

// Function to check if a player has won
int checkWin(int board[][BOARD_SIZE], int player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }

  return 0;
}

// Function to get the best move for the AI
int getBestMove(int board[][BOARD_SIZE], int player) {
  int bestScore = -1000;
  int bestMove = -1;

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == EMPTY) {
        board[i][j] = player;

        int score = minimax(board, 0, player, 1 - player);

        board[i][j] = EMPTY;

        if (score > bestScore) {
          bestScore = score;
          bestMove = i * BOARD_SIZE + j;
        }
      }
    }
  }

  return bestMove;
}

// Function to implement the minimax algorithm
int minimax(int board[][BOARD_SIZE], int depth, int player, int maximizingPlayer) {
  int winner = checkWin(board, player);

  if (winner == player) {
    return 1;
  } else if (winner == 1 - player) {
    return -1;
  }

  if (depth == 0) {
    return 0;
  }

  int bestScore;
  if (maximizingPlayer) {
    bestScore = -1000;
    for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[i][j] == EMPTY) {
          board[i][j] = player;

          int score = minimax(board, depth - 1, player, 1 - player);

          board[i][j] = EMPTY;

          if (score > bestScore) {
            bestScore = score;
          }
        }
      }
    }
  } else {
    bestScore = 1000;
    for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[i][j] == EMPTY) {
          board[i][j] = player;

          int score = minimax(board, depth - 1, player, 1 - player);

          board[i][j] = EMPTY;

          if (score < bestScore) {
            bestScore = score;
          }
        }
      }
    }
  }

  return bestScore;
}

// Function to get the player's move
int getPlayerMove(int board[][BOARD_SIZE]) {
  int move;
  do {
    printf("Enter your move (row, column): ");
    scanf("%d %d", &move, &move);
    move--;
  } while (move < 0 || move >= BOARD_SIZE * BOARD_SIZE || board[move / BOARD_SIZE][move % BOARD_SIZE] != EMPTY);

  return move;
}

// Function to play the game
void playGame() {
  int board[BOARD_SIZE][BOARD_SIZE];
  initBoard(board);

  int player = X;
  int winner = EMPTY;

  while (winner == EMPTY) {
    printBoard(board);

    int move;
    if (player == X) {
      move = getPlayerMove(board);
    } else {
      move = getBestMove(board, player);
    }

    board[move / BOARD_SIZE][move % BOARD_SIZE] = player;

    winner = checkWin(board, player);

    player = 1 - player;
  }

  printBoard(board);

  if (winner == X) {
    printf("Player X wins!\n");
  } else if (winner == O) {
    printf("Player O wins!\n");
  } else {
    printf("Tie game!\n");
  }
}

// Main function
int main() {
  srand(time(NULL));

  playGame();

  return 0;
}