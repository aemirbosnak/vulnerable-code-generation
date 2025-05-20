//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_TURNS 100

typedef struct {
  char name[20];
  int score;
  int turns_left;
} player_t;

typedef struct {
  player_t players[MAX_PLAYERS];
  int num_players;
  int current_turn;
} game_t;

game_t game;

void init_game() {
  game.num_players = 0;
  game.current_turn = 0;
}

void add_player(char *name) {
  if (game.num_players >= MAX_PLAYERS) {
    printf("Error: Too many players\n");
    return;
  }

  strcpy(game.players[game.num_players].name, name);
  game.players[game.num_players].score = 0;
  game.players[game.num_players].turns_left = MAX_TURNS;
  game.num_players++;
}

void start_game() {
  while (game.current_turn < MAX_TURNS) {
    for (int i = 0; i < game.num_players; i++) {
      if (game.players[i].turns_left <= 0) {
        continue;
      }

      // Get the player's move
      char move;
      printf("%s's turn: ", game.players[i].name);
      scanf(" %c", &move);

      // Process the player's move
      switch (move) {
        case 'a':
          game.players[i].score += 1;
          break;
        case 'b':
          game.players[i].score += 2;
          break;
        case 'c':
          game.players[i].score += 3;
          break;
        case 'd':
          game.players[i].score += 4;
          break;
        case 'e':
          game.players[i].score += 5;
          break;
        default:
          printf("Error: Invalid move\n");
          break;
      }

      // Decrement the player's turns left
      game.players[i].turns_left--;
    }

    // Increment the current turn
    game.current_turn++;
  }
}

void print_scores() {
  printf("Scores:\n");
  for (int i = 0; i < game.num_players; i++) {
    printf("%s: %d\n", game.players[i].name, game.players[i].score);
  }
}

int main() {
  // Initialize the game
  init_game();

  // Add players to the game
  add_player("Alice");
  add_player("Bob");
  add_player("Carol");

  // Start the game
  start_game();

  // Print the scores
  print_scores();

  return 0;
}