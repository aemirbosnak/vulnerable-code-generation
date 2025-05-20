//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 10

// Global variables
int board[GRID_SIZE][GRID_SIZE] = {{0}};
int player_x = 0, player_y = 0;
int ball_x = GRID_SIZE - 1, ball_y = 0;
int direction = 1;

void draw_board() {
  for (int y = 0; y < GRID_SIZE; y++) {
    for (int x = 0; x < GRID_SIZE; x++) {
      printf("%c ", board[x][y] ? '#' : '.');
    }
    printf("\n");
  }
}

void move_ball() {
  switch (direction) {
    case 1:
      ball_y--;
      break;
    case 2:
      ball_x++;
      break;
    case 3:
      ball_y++;
      break;
    case 4:
      ball_x--;
      break;
  }

  if (board[ball_x][ball_y] == 2) {
    direction = (direction + 1) % 4;
  }
}

int main() {
  // Initialize the board
  for (int y = 0; y < GRID_SIZE; y++) {
    for (int x = 0; x < GRID_SIZE; x++) {
      board[x][y] = 0;
    }
  }

  // Place the player and ball
  board[player_x][player_y] = 1;
  board[ball_x][ball_y] = 2;

  // Game loop
  while (1) {
    draw_board();
    move_ball();

    if (board[ball_x][ball_y] == 3) {
      printf("Game over!\n");
      break;
    }
  }

  return 0;
}