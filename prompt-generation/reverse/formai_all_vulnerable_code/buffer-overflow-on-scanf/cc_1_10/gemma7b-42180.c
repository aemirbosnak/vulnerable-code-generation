//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
  char name[20];
  int room_num;
  int activity_level;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
  {"Mr. Jones", 1, 3},
  {"Miss Jane", 2, 2},
  {"Mr. Smith", 3, 4},
  {"Mrs. Brown", 4, 3},
  {"The Phantom", 5, 5}
};

void haunt_house(int room_num) {
  int i, ghost_num;
  for (i = 0; i < MAX_GHOSTS; i++) {
    if (ghosts[i].room_num == room_num) {
      ghost_num = i;
    }
  }

  if (ghost_num != -1) {
    switch (ghosts[ghost_num].activity_level) {
      case 1:
        printf("A cold wind whispers through the halls...\n");
        break;
      case 2:
        printf("Shadows dance and flicker...\n");
        break;
      case 3:
        printf("The hairs on your neck stand on end...\n");
        break;
      case 4:
        printf("You hear footsteps echoing through the house...\n");
        break;
      case 5:
        printf("The scent of decay and blood permeates the air...\n");
        break;
    }
  }
}

int main() {
  int room_num;

  printf("Enter the room number: ");
  scanf("%d", &room_num);

  haunt_house(room_num);

  return 0;
}