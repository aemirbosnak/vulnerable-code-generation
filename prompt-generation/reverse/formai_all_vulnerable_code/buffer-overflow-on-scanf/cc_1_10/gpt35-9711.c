//FormAI DATASET v1.0 Category: Robot movement control ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define NUM_MOVES 5
#define MAX_NAME_LEN 20

enum Move { LEFT, RIGHT, UP, DOWN, NO_MOVE };
struct Robot {
  int x, y;
  int battery;
  enum Move moves[NUM_MOVES];
};

void create_moves(struct Robot *bot) {
  bot->moves[LEFT] = LEFT;
  bot->moves[RIGHT] = RIGHT;
  bot->moves[UP] = UP;
  bot->moves[DOWN] = DOWN;
  bot->moves[NO_MOVE] = NO_MOVE;
}

enum Move get_next_move(struct Robot *bot) {
  int dir_num = rand() % NUM_MOVES;
  enum Move dir = bot->moves[dir_num];
  return dir;
}

void print_move(enum Move m) {
  switch(m) {
    case LEFT:
      printf("LEFT");
      break;
    case RIGHT:
      printf("RIGHT");
      break;
    case UP:
      printf("UP");
      break;
    case DOWN:
      printf("DOWN");
      break;
    case NO_MOVE:
      printf("NO_MOVE");
      break;
    default:
      printf("INVALID MOVE");
      break;
  }
}

void output_instructions(struct Robot *bot) {
  printf("Possible moves: ");
  for (int i = 0; i < NUM_MOVES; i++) {
    print_move(bot->moves[i]);
    printf(", ");
  }
  printf("\n");

  printf("INSTRUCTIONS: \n");

  while (bot->battery > 0) {
    enum Move move = get_next_move(bot);
    printf("MOVE: %s\n", move);
    bot->battery--;
  }
}

int main(void) {
  struct Robot bot = {0, 0, 100, {NO_MOVE}};
  printf("Please enter your name: ");
  char name[MAX_NAME_LEN];
  scanf("%s", name);
  printf("Hello, %s!\n", name);
  create_moves(&bot);
  output_instructions(&bot);
  printf("Your robot has run out of battery.\n");
  return 0;
}