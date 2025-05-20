//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Ada Lovelace
// Ada Lovelace style Haunted House Simulator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize random seed
  srand(time(NULL));

  // Welcome message
  printf("Welcome to the Haunted House Simulator!\n\n");

  // Set up the rooms
  char* rooms[] = {"Entrance", "Kitchen", "Living Room", "Bedroom", "Bathroom", "Basement", "Attic", "Library"};
  int numRooms = sizeof(rooms) / sizeof(rooms[0]);

  // Set up the ghosts
  char* ghosts[] = {"Friendly Ghost", "Poltergeist", "Shadow Figure", "Demon", "Revenant"};
  int numGhosts = sizeof(ghosts) / sizeof(ghosts[0]);

  // Set up the player's starting room
  int playerRoom = rand() % numRooms;

  // Set up the ghost's starting room
  int ghostRoom = rand() % numRooms;

  // Print out the starting room and ghost
  printf("You are in the %s.\n", rooms[playerRoom]);
  printf("There is a %s in the %s!\n", ghosts[ghostRoom], rooms[ghostRoom]);

  // Initialize game loop variables
  int gameOver = 0;
  int numMoves = 0;
  char userInput[10];

  // Game loop
  while (!gameOver) {
    // Get user input
    printf("\nWhat do you want to do? (move/quit)\n");
    scanf("%s", userInput);

    // Process user input
    if (strcmp(userInput, "move") == 0) {
      // Move the player to a new room
      int newRoom = rand() % numRooms;
      printf("\nYou move to the %s.\n", rooms[newRoom]);
      playerRoom = newRoom;

      // Move the ghost to a new room
      int newGhostRoom = rand() % numRooms;
      printf("The %s moves to the %s.\n", ghosts[ghostRoom], rooms[newGhostRoom]);
      ghostRoom = newGhostRoom;

      // Check if the player has found the ghost
      if (playerRoom == ghostRoom) {
        printf("\nYou found the %s! Game over!\n", ghosts[ghostRoom]);
        printf("You made %d moves.\n", numMoves);
        gameOver = 1;
      } else {
        numMoves++;
      }
    } else if (strcmp(userInput, "quit") == 0) {
      // Quit the game
      printf("\nGoodbye!\n");
      gameOver = 1;
    } else {
      // Invalid input
      printf("\nInvalid input. Try again.\n");
    }
  }

  return 0;
}