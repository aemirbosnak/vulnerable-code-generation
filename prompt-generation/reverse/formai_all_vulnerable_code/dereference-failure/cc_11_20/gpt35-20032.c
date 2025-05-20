//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define room structure
typedef struct Room {
  int roomNumber;
  int isHaunted;
  struct Room* north;
  struct Room* south;
  struct Room* east;
  struct Room* west;
} Room;

int main() {
  // Set up random seed
  srand(time(NULL));

  // Initialize all rooms
  Room room1, room2, room3, room4, room5, room6, room7, room8, room9;

  // Store room number and set all rooms as not haunted
  room1.roomNumber = 1;
  room1.isHaunted = 0;
  room2.roomNumber = 2;
  room2.isHaunted = 0;
  room3.roomNumber = 3;
  room3.isHaunted = 0;
  room4.roomNumber = 4;
  room4.isHaunted = 0;
  room5.roomNumber = 5;
  room5.isHaunted = 0;
  room6.roomNumber = 6;
  room6.isHaunted = 0;
  room7.roomNumber = 7;
  room7.isHaunted = 0;
  room8.roomNumber = 8;
  room8.isHaunted = 0;
  room9.roomNumber = 9;
  room9.isHaunted = 0;

  // Connect rooms together
  room1.north = NULL;
  room1.south = &room4;
  room1.east = &room2;
  room1.west = NULL;

  room2.north = NULL;
  room2.south = &room5;
  room2.east = &room3;
  room2.west = &room1;

  room3.north = NULL;
  room3.south = &room6;
  room3.east = NULL;
  room3.west = &room2;

  room4.north = &room1;
  room4.south = &room7;
  room4.east = &room5;
  room4.west = NULL;

  room5.north = &room2;
  room5.south = &room8;
  room5.east = &room6;
  room5.west = &room4;

  room6.north = &room3;
  room6.south = &room9;
  room6.east = NULL;
  room6.west = &room5;

  room7.north = &room4;
  room7.south = NULL;
  room7.east = &room8;
  room7.west = NULL;

  room8.north = &room5;
  room8.south = NULL;
  room8.east = &room9;
  room8.west = &room7;

  room9.north = &room6;
  room9.south = NULL;
  room9.east = NULL;
  room9.west = &room8;

  // Choose a random starting room
  int startingRoom = rand() % 9 + 1;
  Room* currentRoom;
  switch (startingRoom) {
    case 1:
      currentRoom = &room1;
      break;
    case 2:
      currentRoom = &room2;
      break;
    case 3:
      currentRoom = &room3;
      break;
    case 4:
      currentRoom = &room4;
      break;
    case 5:
      currentRoom = &room5;
      break;
    case 6:
      currentRoom = &room6;
      break;
    case 7:
      currentRoom = &room7;
      break;
    case 8:
      currentRoom = &room8;
      break;
    case 9:
      currentRoom = &room9;
      break;
    default:
      printf("Error: Starting room not found.");
      return 0;
  }

  // Start exploring the Haunted House
  int steps = 0;
  printf("Welcome to the Haunted House. You are starting in Room %d.\n", currentRoom->roomNumber);
  while (currentRoom->isHaunted == 0) {
    currentRoom->isHaunted = 1; // Mark room as haunted once visited
    int options = 0;
    printf("You are in Room %d. You can go:", currentRoom->roomNumber);
    if (currentRoom->north != NULL) {
      options++;
      printf(" North");
    }
    if (currentRoom->south != NULL) {
      options++;
      printf(" South");
    }
    if (currentRoom->east != NULL) {
      options++;
      printf(" East");
    }
    if (currentRoom->west != NULL) {
      options++;
      printf(" West");
    }
    printf(".\n");

    // Choose a random direction to move
    int direction = rand() % options + 1;
    printf("You chose to go ");
    switch (direction) {
      case 1:
        printf("North");
        currentRoom = currentRoom->north;
        break;
      case 2:
        printf("South");
        currentRoom = currentRoom->south;
        break;
      case 3:
        printf("East");
        currentRoom = currentRoom->east;
        break;
      case 4:
        printf("West");
        currentRoom = currentRoom->west;
        break;
      default:
        printf("Error: Direction not found.");
        return 0;
    }
    printf(".\n");
    steps++;
  }

  // End of game
  printf("You are in Room %d. It's haunted! Game over.\n", currentRoom->roomNumber);
  printf("You took %d steps to find the haunted room.\n", steps);

  return 0;
}