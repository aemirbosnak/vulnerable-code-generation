//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Board structure
typedef struct {
  char board[3][3];
} board_t;

// Function to print the board
void print_board(board_t board) {
  printf(" %c | %c | %c\n", board.board[0][0], board.board[0][1], board.board[0][2]);
  printf(" %c | %c | %c\n", board.board[1][0], board.board[1][1], board.board[1][2]);
  printf(" %c | %c | %c\n", board.board[2][0], board.board[2][1], board.board[2][2]);
}

// Function to check if the game is over
int is_game_over(board_t board) {
  for (int i = 0; i < 3; i++) {
    if (strlen(board.board[i]) < 3) {
      return 0;
    }
  }
  return 1;
}

// Function to check if a player won
int is_player_won(board_t board, char player) {
  for (int i = 0; i < 3; i++) {
    if (strncmp(board.board[i], player, 3) == 0 && strncmp(board.board[i + 3], player, 3) == 0 && strncmp(board.board[i + 6], player, 3) == 0) {
      return 1;
    }
  }
  return 0;
}

// Function to check if the game is a draw
int is_draw(board_t board) {
  for (int i = 0; i < 3; i++) {
    if (strlen(board.board[i]) == 0) {
      return 0;
    }
  }
  return 1;
}

// Function to make a move
void make_move(board_t board, char player, char symbol) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board.board[i][j] == '-') {
        board.board[i][j] = symbol;
        if (is_player_won(board, symbol)) {
          printf("Player %c won the game!\n", symbol);
        } else if (is_draw(board)) {
          printf("It's a draw!\n");
        } else {
          board.board[i][j] = '-';
        }
        break;
      }
    }
  }
}

int main() {
  board_t board;

  // Initialize the board
  memset(board.board, '-', 3 * 3 * sizeof(char));

  char player1 = 'X';
  char player2 = 'O';

  int turn = 1;
  int game_over = 0;

  while (!game_over) {
    print_board(board);
    printf("Player %d's turn.\n", turn);
    char symbol;

    if (turn == 1) {
      symbol = player1;
    } else {
      symbol = player2;
    }

    printf("Enter your move (row, column): ");
    int row, col;
    scanf("%d%d", &row, &col);

    make_move(board, symbol, board.board[row][col]);

    game_over = is_game_over(board);
    if (game_over) {
      break;
    }
    turn = 3 - turn;
  }

  return 0;
}