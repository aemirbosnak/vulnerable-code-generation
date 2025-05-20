//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
  char name[20];
  int room_num;
  int type;
  int is_active;
} Ghost;

Ghost ghosts[MAX_GHOULS] = {
  {"Mr. Jones", 1, 1, 1},
  {"Mrs. Smith", 2, 2, 1},
  {"Mr. Johnson", 3, 1, 0},
  {"Miss Brown", 4, 2, 0},
  {"Mr. Brown", 5, 1, 0}
};

void move_ghosts(void) {
  for (int i = 0; i < MAX_GHOULS; i++) {
    if (ghosts[i].is_active) {
      switch (ghosts[i].type) {
        case 1:
          ghosts[i].room_num = (ghosts[i].room_num + 1) % MAX_GHOULS;
          break;
        case 2:
          ghosts[i].room_num = (ghosts[i].room_num - 1) % MAX_GHOULS;
          break;
      }
    }
  }
}

void interact_with_ghosts(void) {
  for (int i = 0; i < MAX_GHOULS; i++) {
    if (ghosts[i].is_active) {
      printf("You hear a whisper from the hallway:\n");
      printf("%s\n", ghosts[i].name);
      printf("What do you want to do? (help/ignore): ");
      char input[20];
      scanf("%s", input);

      switch (input[0]) {
        case 'h':
          printf("Here are the available options:\n");
          printf("1. Help\n");
          printf("2. Ignore\n");
          break;
        case '2':
          ghosts[i].is_active = 0;
          printf("The ghost has retreated.\n");
          break;
      }
    }
  }
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < MAX_GHOULS; i++) {
    ghosts[i].is_active = rand() % 2;
  }

  while (1) {
    move_ghosts();
    interact_with_ghosts();

    printf("Do you want to continue? (y/n): ");
    char cont_input;
    scanf("%c", &cont_input);

    if (cont_input != 'y') {
      break;
    }
  }

  return 0;
}