//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 5
#define MAX_HEIGHT 5

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int board[MAX_WIDTH][MAX_HEIGHT] = {{0, 0, 0, 0, 0},
                              {0, 1, 1, 0, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

int player_x = 0;
int player_y = 0;

void draw_board() {
  for (int y = 0; y < MAX_HEIGHT; y++) {
    for (int x = 0; x < MAX_WIDTH; x++) {
      if (board[x][y] == 1) {
        printf("%c ", '*');
      } else if (x == player_x && y == player_y) {
        printf("%c ", '@');
      } else {
        printf("%c ", '.');
      }
    }
    printf("\n");
  }
}

int main() {

  draw_board();

  int direction = 0;
  while (direction != -1) {
    printf("Enter direction (left/right/up/down): ");
    scanf("%d", &direction);

    switch (direction) {
      case LEFT:
        if (player_x > 0) {
          player_x--;
        }
        break;
      case RIGHT:
        if (player_x < MAX_WIDTH - 1) {
          player_x++;
        }
        break;
      case UP:
        if (player_y > 0) {
          player_y--;
        }
        break;
      case DOWN:
        if (player_y < MAX_HEIGHT - 1) {
          player_y++;
        }
        break;
      default:
        break;
    }

    draw_board();
  }

  return 0;
}