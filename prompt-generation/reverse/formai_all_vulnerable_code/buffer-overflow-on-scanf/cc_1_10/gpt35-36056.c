//FormAI DATASET v1.0 Category: Smart home automation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 4
#define MAX_APPLIANCES 4

typedef struct appliance {
  char name[20];
  int state;
} Appliance;

typedef struct player {
  int id;
  Appliance appliances[MAX_APPLIANCES];
} Player;

void print_appliances(Appliance *appliances, int num_appliances) {
  printf("Appliances:\n");
  for (int i = 0; i < num_appliances; i++) {
    printf("%s: ", appliances[i].name);
    if (appliances[i].state) printf("On\n");
    else printf("Off\n");
  }
}

void print_players(Player *players, int num_players) {
  for (int i = 0; i < num_players; i++) {
    printf("Player %d:\n", players[i].id);
    print_appliances(players[i].appliances, MAX_APPLIANCES);
  }
}

void toggle_appliance(Appliance *appliance) {
  if (appliance->state) appliance->state = 0;
  else appliance->state = 1;
}

int main() {
  Player players[MAX_PLAYERS] = {
    { .id = 1, .appliances = { { "Light", 0 }, { "TV", 0 }, { "Fan", 0 }, { "AC", 0 } } },
    { .id = 2, .appliances = { { "Light", 0 }, { "TV", 0 }, { "Fan", 0 }, { "AC", 0 } } },
    { .id = 3, .appliances = { { "Light", 0 }, { "TV", 0 }, { "Fan", 0 }, { "AC", 0 } } },
    { .id = 4, .appliances = { { "Light", 0 }, { "TV", 0 }, { "Fan", 0 }, { "AC", 0 } } }
  };
  int num_players = 4;

  printf("Welcome to Smart Home Automation!\n");

  int done = 0;
  while (!done) {
    print_players(players, num_players);

    int player_id, appliance_num;
    printf("Which player would you like to control? (1-%d, 0 to quit): ", num_players);
    scanf("%d", &player_id);
    if (player_id == 0) {
      done = 1;
      continue;
    }
    if (player_id < 1 || player_id > num_players) {
      printf("Invalid player. Please try again.\n");
      continue;
    }

    printf("Which appliance would you like to toggle? (1-%d, 0 to cancel): ", MAX_APPLIANCES);
    scanf("%d", &appliance_num);
    if (appliance_num == 0) {
      continue;
    }
    if (appliance_num < 1 || appliance_num > MAX_APPLIANCES) {
      printf("Invalid appliance. Please try again.\n");
      continue;
    }

    toggle_appliance(&players[player_id-1].appliances[appliance_num-1]);

    printf("Done.\n");
  }

  return 0;
}