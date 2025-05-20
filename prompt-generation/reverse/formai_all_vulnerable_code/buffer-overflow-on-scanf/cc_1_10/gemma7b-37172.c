//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
  char name[20];
  int room_num;
  int trigger_chance;
  int haunt_effect;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
  {"Annabelle", 1, 20, 3},
  {"The Babbling Woman", 2, 15, 2},
  {"The Bloody Butcher", 3, 10, 1},
  {"The Disembodied Hand", 4, 12, 2},
  {"The Floating Ghost", 5, 8, 3},
  {"The Ghostly Bride", 6, 13, 1},
  {"The Hungry Ghost", 7, 11, 2},
  {"The Screaming Ghost", 8, 9, 3},
  {"The Shadow Bride", 9, 14, 1},
  {"The Spectral Terror", 10, 16, 3}
};

void haunt_house(int room_num) {
  int i;
  for (i = 0; i < MAX_GHOSTS; i++) {
    if (ghosts[i].room_num == room_num && ghosts[i].trigger_chance > rand() % 100) {
      switch (ghosts[i].haunt_effect) {
        case 1:
          printf("You hear disembodied voices echoing through the halls.\n");
          break;
        case 2:
          printf("You feel cold and alone, as if a cold hand is brushing against your skin.\n");
          break;
        case 3:
          printf("You sense a sudden shift in air pressure, and feel a ghostly presence in the room.\n");
          break;
      }
    }
  }
}

int main() {
  int room_num;

  printf("Welcome to the Haunted House Simulator!\n");
  printf("Please enter the room number you want to visit: ");
  scanf("%d", &room_num);

  haunt_house(room_num);

  return 0;
}