//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize random seed
  srand(time(NULL));

  // Welcome message
  printf("Welcome to the Haunted House Simulator!\n\n");

  // Get player name
  char name[50];
  printf("What is your name?\n");
  fgets(name, 50, stdin);

  // Start game
  printf("\nHello %s! You have entered a haunted house and must find your way out.\n", name);

  // Initialize game variables
  int hasKey = 0; // player does not yet have key
  int isAlive = 1; // player is still alive
  int currentRoom = 1; // start in room 1

  // Game loop
  while (isAlive && currentRoom != 0) {
    // Print current room description
    switch (currentRoom) {
      case 1:
        printf("\nYou are in a dark hallway. There is a door to your left and a staircase to your right.\n");
        break;
      case 2:
        printf("\nYou are in a dusty living room. There is a fireplace on the far wall and a door to your right.\n");
        break;
      case 3:
        printf("\nYou are in a creepy kitchen. There are cabinets and a refrigerator against the walls, and a door to your left.\n");
        break;
      case 4:
        printf("\nYou are in a musty bedroom. There is a bed against the wall, a nightstand next to it, and a door to your right.\n");
        break;
      case 5:
        printf("\nYou are in a dark bathroom. There is a sink, toilet, and shower in the room. There is a door to your left and one in front of you.\n");
        break;
      case 6:
        printf("\nYou are in a small closet. There is a jacket hanging on a hook and a door to your right.\n");
        break;
      case 7:
        printf("\nYou are in a dungeon-like basement. There are chains and shackles on the walls, and a door to your left and one in front of you.\n");
        break;
      case 8:
        printf("\nYou are in a dusty attic. There are old boxes and furniture stacked up against the walls. There is a door to your left and one in front of you.\n");
        break;
      default:
        printf("You have encountered an error. Exiting game...\n");
        exit(1);
    }

    // Prompt player for action
    printf("What would you like to do?\n");
    printf("1 - Go left\n");
    printf("2 - Go right\n");
    printf("3 - Go forward\n");
    printf("4 - Go back\n");

    // Get player action
    int playerAction;
    scanf("%d", &playerAction);

    // Determine next room based on player action
    int nextRoom;
    switch (playerAction) {
      case 1:
        nextRoom = currentRoom - 1;
        break;
      case 2:
        nextRoom = currentRoom + 1;
        break;
      case 3:
        nextRoom = currentRoom * 2;
        break;
      case 4:
        nextRoom = currentRoom / 2;
        break;
      default:
        printf("Invalid action. Try again.\n");
        continue; // loop back to beginning of game loop
    }

    // Determine outcome of movement
    if (nextRoom == 0) {
      // Player has exited the house
      printf("\nCongratulations %s! You have successfully escaped the haunted house!\n", name);
      break; // end game
    } else if (nextRoom == 3 && !hasKey) {
      // Player has entered the kitchen without key
      printf("\nYou have entered the kitchen, but the door behind you has locked itself. You need a key to open it.\n");
      continue; // loop back to beginning of game loop
    } else if (nextRoom == 3 && hasKey) {
      // Player has entered the kitchen with key
      printf("\nYou have entered the kitchen and used the key to unlock the door behind you. You can now exit the house.\n");
      currentRoom = 0; // player has exited the house
    } else if (nextRoom == 7) {
      // Player has entered the basement
      int chance = rand() % 100; // generate random number 0-99
      if (chance < 25) {
        printf("\nYou have been attacked by a ghost and died. Game over.\n");
        isAlive = 0; // player has died
      } else {
        printf("\nYou have safely navigated the basement.\n");
        currentRoom = nextRoom;
      }
    } else {
      // Player has entered a different room
      currentRoom = nextRoom;
    }

    // Check if player has found the key
    if (currentRoom == 6 && !hasKey) {
      printf("\nYou have found a key hanging on a hook in the closet.\n");
      hasKey = 1; // player now has key
    }
  }

  return 0;
}