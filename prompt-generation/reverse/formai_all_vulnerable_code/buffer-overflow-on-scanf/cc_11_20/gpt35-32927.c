//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: funny
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10
#define MAX_ROOMS 5

const char* roomNames[MAX_ROOMS] = {
  "Foyer", "Bedroom", "Kitchen", "Bathroom", "Attic"
};

const char* ghostNames[MAX_GHOSTS] = {
  "Casper", "Slimer", "Boo", "Poltergeist", "Phantom",
  "Specter", "Wraith", "Apparition", "Spook", "Yurei"
};

int main() {
  srand(time(NULL)); // Start the clock

  printf("Welcome to the Haunted House Simulator\n\n");

  int currentRoom = 0;
  bool gameOver = false;

  while(!gameOver) {
    // Print current room name and description
    printf("You are in the %s. It is dark and spooky.\n", roomNames[currentRoom]);

    // Determine if there are any ghosts in the room
    int numGhosts = rand() % MAX_GHOSTS;

    if(numGhosts > 0) {
      printf("Oh no! There are %d ghosts here! They are:\n", numGhosts);

      // Print out ghost names
      for(int i = 0; i < numGhosts; i++) {
        printf("* %s\n", ghostNames[rand() % MAX_GHOSTS]);
      }

      // Determine if player gets scared and loses the game
      if(rand() % 2 == 0) {
        printf("You got scared and ran out of the house! Game over.\n");
        gameOver = true;
      }
      else {
        printf("You bravely face the ghosts and continue exploring.\n");
      }
    }
    else {
      printf("There are no ghosts here. You continue exploring.\n");
    }

    // Move to a new room
    printf("Which direction would you like to go? (Type N, S, E, W): ");
    char direction;
    scanf(" %c", &direction);

    // Determine which room to move to
    switch(direction) {
      case 'N':
        currentRoom = (currentRoom == 0) ? MAX_ROOMS - 1 : currentRoom - 1;
        break;
      case 'S':
        currentRoom = (currentRoom == MAX_ROOMS - 1) ? 0 : currentRoom + 1;
        break;
      case 'E':
        printf("You walk into a wall. Ouch!\n");
        break;
      case 'W':
        printf("You walk into a wall. Ouch!\n");
        break;
      default:
        printf("Invalid direction. Please try again.\n");
        break;
    }

    printf("\n"); // Add some spacing for readability
  }

  return 0;
}