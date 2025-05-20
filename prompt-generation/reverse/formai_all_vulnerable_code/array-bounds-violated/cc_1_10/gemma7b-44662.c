//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3

typedef struct Cell {
  char state;
  int x;
  int y;
} Cell;

Cell board[BOARD_SIZE][BOARD_SIZE] = {{
  {' ', 0, 0},
  {' ', 0, 0},
  {' ', 0, 0}
}};

int is_board_full() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j].state == ' ') {
        return 0;
      }
    }
  }

  return 1;
}

int check_win(char player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i].state == player && board[1][i].state == player && board[2][i].state == player) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[j][0].state == player && board[j][1].state == player && board[j][2].state == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0].state == player && board[1][1].state == player && board[2][2].state == player) {
    return 1;
  } else if (board[0][2].state == player && board[1][1].state == player && board[2][0].state == player) {
    return 1;
  }

  return 0;
}

void place_move(int x, int y, char player) {
  board[x][y].state = player;
  board[x][y].x = x;
  board[x][y].y = y;
}

int main() {
  char current_player = 'X';

  // Game loop
  while (!is_board_full() && !check_win(current_player)) {
    int move_x;
    int move_y;

    // Get the move from the player
    printf("Enter move (x, y): ");
    scanf("%d %d", &move_x, &move_y);

    // Place the move
    place_move(move_x, move_y, current_player);

    // Switch the player
    current_player = (current_player == 'X') ? 'O' : 'X';
  }

  // Game over
  if (check_win(current_player)) {
    printf("Winner: %c!", current_player);
  } else {
    printf("Draw!");
  }

  return 0;
}