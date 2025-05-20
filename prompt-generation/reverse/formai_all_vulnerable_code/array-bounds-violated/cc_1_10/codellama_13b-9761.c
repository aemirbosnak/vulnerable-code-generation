//Code Llama-13B DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
// Haunted House Simulator in Dennis Ritchie Style
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_ROOMS 10
#define NUM_GHOSTS 5

typedef struct {
  int room_number;
  bool is_ghost;
} Room;

int main() {
  srand(time(NULL));

  Room rooms[NUM_ROOMS];
  for (int i = 0; i < NUM_ROOMS; i++) {
    rooms[i].room_number = i + 1;
    rooms[i].is_ghost = false;
  }

  int ghost_rooms[NUM_GHOSTS];
  for (int i = 0; i < NUM_GHOSTS; i++) {
    ghost_rooms[i] = rand() % NUM_ROOMS + 1;
    rooms[ghost_rooms[i]].is_ghost = true;
  }

  while (true) {
    int player_room = rand() % NUM_ROOMS + 1;
    if (rooms[player_room].is_ghost) {
      printf("You've been haunted by a ghost!\n");
      return 0;
    }

    printf("You're in room %d\n", player_room);
    for (int i = 0; i < NUM_GHOSTS; i++) {
      if (ghost_rooms[i] == player_room) {
        printf("A ghost is in this room!\n");
      }
    }

    printf("Do you want to move to another room (y/n)? ");
    char move = getchar();
    if (move == 'y') {
      int new_room = rand() % NUM_ROOMS + 1;
      while (rooms[new_room].is_ghost) {
        new_room = rand() % NUM_ROOMS + 1;
      }
      player_room = new_room;
    }
  }

  return 0;
}