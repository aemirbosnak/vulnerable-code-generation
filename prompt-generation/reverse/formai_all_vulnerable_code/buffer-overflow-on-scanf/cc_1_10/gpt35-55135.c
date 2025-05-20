//FormAI DATASET v1.0 Category: Database querying ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player {
  char name[20];
  int age;
  int score;
} Player;

void add_player(Player **players, int *num_players) {
  Player *new_player = (Player *)malloc(sizeof(Player));

  printf("What is the player's name? ");
  scanf("%s", new_player->name);

  printf("What is the player's age? ");
  scanf("%d", &new_player->age);

  printf("What is the player's score? ");
  scanf("%d", &new_player->score);

  *num_players += 1;
  *players = (Player *)realloc(*players, (*num_players) * sizeof(Player));
  (*players)[*num_players - 1] = *new_player;
}

void print_player(Player player) {
  printf("%s (%d years old) - Score: %d\n", player.name, player.age, player.score);
}

void print_all_players(Player *players, int num_players) {
  printf("\n--- All Players ---\n");
  for (int i = 0; i < num_players; i++) {
    print_player(players[i]);
  }
  printf("------------------\n\n");
}

void search_player(Player *players, int num_players) {
  char name[20];
  printf("Enter the name of the player you want to search for: ");
  scanf("%s", name);
  for (int i = 0; i < num_players; i++) {
    if (strcmp(name, players[i].name) == 0) {
      printf("Player found:\n");
      print_player(players[i]);
      return;
    }
  }
  printf("Player not found.\n");
}

int main() {
  int num_players = 0;
  Player *players = NULL;

  printf("Welcome to the player database!\n");
  printf("Type 'add' to add a player, 'search' to search for a player, or 'quit' to exit.\n");

  char command[10];
  while (1) {
    printf("> ");
    scanf("%s", command);
    if (strcmp(command, "add") == 0) {
      add_player(&players, &num_players);
      print_all_players(players, num_players);
    } else if (strcmp(command, "search") == 0) {
      search_player(players, num_players);
    } else if (strcmp(command, "quit") == 0) {
      printf("Goodbye!\n");
      break;
    } else {
      printf("Invalid command. Try again.\n");
    }
  }

  return 0;
}