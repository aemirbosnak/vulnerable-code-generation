//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int main() {
  char name[20];
  printf("Please enter your name: ");
  scanf("%s", name);

  int room = 1;
  int inventory[] = {0, 0, 0};

  while (room != 5) {
    switch (room) {
      case 1:
        printf("You are in a dark and dusty tavern.\n");
        printf("You see a suspicious character sitting in the corner.\n");
        break;
      case 2:
        printf("You are in a cluttered laboratory.\n");
        printf("You find a key on the table.\n");
        break;
      case 3:
        printf("You are in a mysterious cave.\n");
        printf("You hear a rustling sound.\n");
        break;
      case 4:
        printf("You are in a burning building.\n");
        printf("You find a bottle of water.\n");
        break;
      case 5:
        printf("You have escaped the dungeon.\n");
        break;
    }

    int choice = 0;
    printf("Please select an option: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Attack the suspicious character
        break;
      case 2:
        // Use the key to unlock a secret door
        break;
      case 3:
        // Investigate the rustling sound
        break;
      case 4:
        // Use the bottle of water to extinguish the fire
        break;
      case 5:
        // Leave the dungeon
        room = 5;
        break;
    }

    room++;
  }

  return 0;
}