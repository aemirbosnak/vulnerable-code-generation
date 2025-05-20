//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5
#define GHOST_SOUND_DURATION 2

typedef struct Ghost {
  char name[20];
  int room_number;
  int is_active;
  int sound_played;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
  {"Mr. Bartholomew", 1, 1, 0},
  {"Ms. Sophia", 2, 1, 0},
  {"Mr. Henderson", 3, 1, 0},
  {"Mrs. Johnson", 4, 1, 0},
  {"The Disembodied", 5, 1, 0}
};

void play_ghost_sound(int ghost_index) {
  if (!ghosts[ghost_index].sound_played) {
    printf("SOUND: %s\n", ghosts[ghost_index].name);
    ghosts[ghost_index].sound_played = 1;
  }
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < MAX_GHOSTS; i++) {
    if (rand() % 2) {
      ghosts[i].is_active = 1;
    }
  }

  int current_room = 1;
  printf("You are in room %d.\n", current_room);

  while (1) {
    int next_room = rand() % MAX_GHOSTS + 1;

    if (ghosts[next_room].is_active) {
      play_ghost_sound(next_room);
    }

    printf("You have moved to room %d.\n", next_room);
    current_room = next_room;

    if (current_room == MAX_GHOSTS) {
      printf("You have escaped the haunted house!\n");
      break;
    }
  }

  return 0;
}