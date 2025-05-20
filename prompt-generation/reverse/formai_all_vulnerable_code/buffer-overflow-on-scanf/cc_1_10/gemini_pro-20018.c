//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LEN 20
#define GRID_SIZE 10
#define MIN_CONSECUTIVE_WATER 5

typedef struct {
  char name[MAX_NAME_LEN];
  int score;
  int grid[GRID_SIZE][GRID_SIZE];
} Player;

typedef struct {
  int num_players;
  Player players[MAX_PLAYERS];
  int grid[GRID_SIZE][GRID_SIZE];
} Game;

void init_grid(Game *game) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      game->grid[i][j] = 0;
    }
  }
}

void init_players(Game *game) {
  for (int i = 0; i < game->num_players; i++) {
    printf("Enter player %d's name: ", i + 1);
    scanf("%s", game->players[i].name);
    game->players[i].score = 0;
    init_grid(&game->players[i]);
  }
}

void print_grid(Game *game) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", game->grid[i][j]);
    }
    printf("\n");
  }
}

int check_consecutive_water(Game *game, int x, int y) {
  int count = 0;
  for (int i = x; i < GRID_SIZE; i++) {
    if (game->grid[i][y] == 1) {
      count++;
    } else {
      break;
    }
  }
  return count;
}

void add_water(Game *game, int x, int y) {
  if (game->grid[x][y] == 0) {
    game->grid[x][y] = 1;
    int consecutive_water = check_consecutive_water(game, x, y);
    if (consecutive_water >= MIN_CONSECUTIVE_WATER) {
      // A player has won!
      for (int i = 0; i < game->num_players; i++) {
        if (game->players[i].grid[x][y] == 1) {
          game->players[i].score++;
        }
      }
    }
  }
}

void take_turn(Game *game, Player *player) {
  int x, y;
  printf("%s's turn: ", player->name);
  scanf("%d %d", &x, &y);
  add_water(game, x, y);
}

void play_game(Game *game) {
  while (1) {
    for (int i = 0; i < game->num_players; i++) {
      take_turn(game, &game->players[i]);
      print_grid(game);
      for (int j = 0; j < game->num_players; j++) {
        printf("%s: %d\n", game->players[j].name, game->players[j].score);
      }
    }
  }
}

int main() {
  srand(time(NULL));

  Game game;
  printf("Enter the number of players (2-4): ");
  scanf("%d", &game.num_players);
  while (game.num_players < 2 || game.num_players > 4) {
    printf("Invalid number of players. Enter a number between 2 and 4: ");
    scanf("%d", &game.num_players);
  }

  init_players(&game);
  init_grid(&game);

  play_game(&game);

  return 0;
}