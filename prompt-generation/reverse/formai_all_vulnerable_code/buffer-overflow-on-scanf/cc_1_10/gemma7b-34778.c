//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
  char name[20];
  int room;
  int health;
  int attack_power;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
  {"Mr. Mortis", 1, 100, 20},
  {"Ms. Morticia", 2, 80, 15},
  {"Mr. Bartholomew", 3, 60, 10},
  {"The Bloody Bride", 4, 40, 5},
  {"The Disembodied Hand", 5, 20, 2}
};

int main() {
  srand(time(NULL));

  // Choose a random ghost
  int ghost_index = rand() % MAX_GHOSTS;

  // Create a haunted house
  int haunted_house = ghosts[ghost_index].room;

  // Enter the haunted house
  printf("You have entered the haunted house of %s.\n", ghosts[ghost_index].name);

  // Interact with the ghost
  printf("What do you want to do? (attack, flee, examine)\n");
  char input[20];
  scanf("%s", input);

  // Take action
  switch (input[0]) {
    case 'a':
      ghosts[ghost_index].health -= 20;
      printf("You have attacked the ghost and inflicted damage.\n");
      break;
    case 'f':
      printf("You have fled the haunted house.\n");
      break;
    case 'e':
      printf("You have examined the ghost.\n");
      break;
    default:
      printf("Invalid input.\n");
  }

  // Check if the ghost is dead
  if (ghosts[ghost_index].health <= 0) {
    printf("The ghost is dead.\n");
  } else {
    printf("The ghost is still alive.\n");
  }

  return 0;
}