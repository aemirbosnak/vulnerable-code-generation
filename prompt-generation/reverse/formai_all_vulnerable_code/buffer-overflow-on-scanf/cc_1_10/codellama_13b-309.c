//Code Llama-13B DATASET v1.0 Category: Haunted House Simulator ; Style: enthusiastic
// Haunted House Simulator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constants
#define NUM_ROOMS 10
#define NUM_PLAYERS 2
#define TOTAL_POINTS 500

// Structures
typedef struct {
  char name[50];
  int points;
  int current_room;
  int last_room;
} player;

typedef struct {
  int room_number;
  int num_ghosts;
  int points_per_ghost;
  char room_name[50];
} room;

// Functions
void init_players(player *players);
void init_rooms(room *rooms);
void print_intro(player *players, room *rooms);
void play_game(player *players, room *rooms);
void print_winner(player *players);

// Main function
int main() {
  // Initialize players and rooms
  player players[NUM_PLAYERS];
  init_players(players);
  room rooms[NUM_ROOMS];
  init_rooms(rooms);

  // Print intro
  print_intro(players, rooms);

  // Play game
  play_game(players, rooms);

  // Print winner
  print_winner(players);

  return 0;
}

// Function definitions
void init_players(player *players) {
  for (int i = 0; i < NUM_PLAYERS; i++) {
    players[i].points = 0;
    players[i].current_room = 0;
    players[i].last_room = -1;
    printf("Enter player %d's name: ", i + 1);
    scanf("%s", players[i].name);
  }
}

void init_rooms(room *rooms) {
  for (int i = 0; i < NUM_ROOMS; i++) {
    rooms[i].room_number = i;
    rooms[i].num_ghosts = rand() % 10 + 1;
    rooms[i].points_per_ghost = rand() % 100 + 1;
    sprintf(rooms[i].room_name, "Room %d", i);
  }
}

void print_intro(player *players, room *rooms) {
  printf("Welcome to the Haunted House Simulator!\n");
  printf("You are %d players, each with %d points.\n", NUM_PLAYERS, TOTAL_POINTS);
  printf("You must navigate through the haunted house, avoiding ghosts.\n");
  printf("The goal is to be the last player standing, with the most points.\n");
  printf("Here are the rooms:\n");
  for (int i = 0; i < NUM_ROOMS; i++) {
    printf("%s: %d ghosts, %d points per ghost\n", rooms[i].room_name, rooms[i].num_ghosts, rooms[i].points_per_ghost);
  }
}

void play_game(player *players, room *rooms) {
  while (1) {
    // Move players to new room
    for (int i = 0; i < NUM_PLAYERS; i++) {
      int new_room = rand() % NUM_ROOMS;
      while (players[i].last_room == new_room) {
        new_room = rand() % NUM_ROOMS;
      }
      players[i].current_room = new_room;
      players[i].last_room = new_room;
      printf("%s moved to room %d\n", players[i].name, players[i].current_room);
    }

    // Check for ghosts
    for (int i = 0; i < NUM_PLAYERS; i++) {
      if (rooms[players[i].current_room].num_ghosts > 0) {
        players[i].points -= rooms[players[i].current_room].points_per_ghost;
        rooms[players[i].current_room].num_ghosts--;
        printf("%s encountered a ghost and lost %d points\n", players[i].name, rooms[players[i].current_room].points_per_ghost);
        if (players[i].points <= 0) {
          printf("%s has been eliminated\n", players[i].name);
          return;
        }
      }
    }
  }
}

void print_winner(player *players) {
  int winner_index = 0;
  for (int i = 1; i < NUM_PLAYERS; i++) {
    if (players[i].points > players[winner_index].points) {
      winner_index = i;
    }
  }
  printf("The winner is %s with %d points!\n", players[winner_index].name, players[winner_index].points);
}