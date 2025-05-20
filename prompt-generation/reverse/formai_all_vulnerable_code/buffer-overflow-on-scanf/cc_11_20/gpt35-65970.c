//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int roomCount; // number of rooms in the haunted house
  int ghostCount; // number of ghosts in the house
  int maxVisits; // maximum number of times a room can be visited before becoming "haunted"
  int currentRoom = 1; // current room the player is in
  int moved = 0; // flag to check if the player has moved to a new room
  int visits[roomCount]; // array to keep track of the number of times a room has been visited
  
  // Prompt the user for the configuration options
  printf("Welcome to the Haunted House Simulator!\n");
  printf("Please enter the number of rooms in the house: ");
  scanf("%d", &roomCount);
  printf("Please enter the number of ghosts in the house: ");
  scanf("%d", &ghostCount);
  printf("Please enter the maximum number of visits a room can have: ");
  scanf("%d", &maxVisits);
  
  // Seed the random number generator
  srand(time(NULL));
  
  // Loop to simulate the player exploring the haunted house
  while (1) {
    // Check if the player has exceeded the maximum number of visits for the current room
    if (visits[currentRoom - 1] >= maxVisits) {
      printf("You hear strange noises coming from this room...\n");
      if (rand() % 2 == 0) {
        printf("Oh no! The room is haunted! You have been trapped forever...\n");
        break;
      } else {
        printf("Phew! You narrowly escaped!\n");
      }
    }
    
    // Check if the player has encountered any ghosts
    if (rand() % 100 < ghostCount) {
      printf("You sense a ghost nearby...\n");
      printf("BOO! You have been scared to death!\n");
      break;
    }
    
    // Check if the player has already moved to a new room in this iteration
    if (moved) {
      printf("You are in room %d.\n", currentRoom);
    } else {
      moved = 1;
    }
    
    // Prompt the player to choose a direction to move in
    printf("Which direction would you like to move in? (N/S/E/W): ");
    char direction;
    scanf(" %c", &direction);
    
    // Move the player to the new room
    switch (direction) {
      case 'N':
        if (currentRoom > 1) {
          currentRoom--;
        } else {
          printf("There is no room to the north!\n");
          moved = 0;
        }
        break;
      case 'S':
        if (currentRoom < roomCount) {
          currentRoom++;
        } else {
          printf("There is no room to the south!\n");
          moved = 0;
        }
        break;
      case 'E':
        printf("You see a locked door to the east...\n");
        moved = 0;
        break;
      case 'W':
        printf("You see a window with iron bars to the west...\n");
        moved = 0;
        break;
      default:
        printf("Invalid direction!\n");
        moved = 0;
        break;
    }
    
    // Increment the visit count for the current room
    visits[currentRoom - 1]++;
    
    // Check if the player has made it to the last room
    if (currentRoom == roomCount) {
      printf("Congratulations! You have successfully navigated the haunted house!\n");
      break;
    }
  }
  
  return 0;
}