//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: thoughtful
#include <stdio.h>

int main() {
  int choice, inventory[] = {0, 0, 0}, room = 1;
  char name[20];

  printf("Welcome to the fantastical realm of Aethelred.\n");
  printf("Please enter your name: ");
  scanf("%s", name);

  while (1) {
    switch (room) {
      case 1:
        printf("You are in the Grand Hall of the Dragon's Keep.\n");
        printf("You see a glowing portal and a chest.\n");
        printf("What do you want to do? (1) Enter the portal, (2) Open the chest, (3) Examine the surroundings: ");
        scanf("%d", &choice);

        switch (choice) {
          case 1:
            room = 2;
            break;
          case 2:
            inventory[0] = 1;
            inventory[1] = 1;
            break;
          case 3:
            printf("You see a dragon statue, a fountain, and a tapestry.\n");
            break;
        }
        break;

      case 2:
        printf("You are in the Realm of the Fire Dragon.\n");
        printf("You see a dragon warrior and a treasure chest.\n");
        printf("What do you want to do? (1) Attack the dragon warrior, (2) Open the treasure chest, (3) Return to the Grand Hall: ");
        scanf("%d", &choice);

        switch (choice) {
          case 1:
            // Combat code
            break;
          case 2:
            inventory[2] = 1;
            break;
          case 3:
            room = 1;
            break;
        }
        break;
    }

    if (inventory[2] == 1) {
      printf("Congratulations, %s, you have won the game!\n", name);
      break;
    }
  }

  return 0;
}