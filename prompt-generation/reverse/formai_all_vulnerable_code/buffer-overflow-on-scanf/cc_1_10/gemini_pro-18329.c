//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int milliseconds);
void clearScreen(void);
void createRoom(int roomNumber);
int main(void) {
  // Seed the random number generator.
  srand(time(NULL));

  // Number of rooms in the haunted house.
  int numRooms = 10;

  // Create the haunted house.
  int i;
  for (i = 0; i < numRooms; i++) {
    createRoom(i);
  }

  // Start the game.
  int currentRoom = 0;
  int gameOver = 0;
  while (!gameOver) {
    // Print the current room's description.
    printf("\nYou are in room %d.\n", currentRoom);

    // Get the player's input.
    char input;
    printf("What do you want to do?\n");
    printf("(n)orth, (e)ast, (s)outh, (w)est, (q)uit\n");
    scanf(" %c", &input);

    // Handle the player's input.
    switch (input) {
    case 'n':
      currentRoom--;
      break;
    case 'e':
      currentRoom++;
      break;
    case 's':
      currentRoom++;
      break;
    case 'w':
      currentRoom--;
      break;
    case 'q':
      gameOver = 1;
      break;
    default:
      printf("Invalid input. Please try again.\n");
      break;
    }

    // Check if the player has won or lost the game.
    if (currentRoom < 0 || currentRoom >= numRooms) {
      printf("You have escaped the haunted house!\n");
      gameOver = 1;
    } else if (rand() % 10 == 0) {
      printf("You have been caught by a ghost!\n");
      gameOver = 1;
    }
  }

  // End the game.
  printf("Thank you for playing the Haunted House Simulator!\n");
  return 0;
}

void delay(int milliseconds) {
  long pause;
  clock_t now, then;

  pause = milliseconds * (CLOCKS_PER_SEC / 1000);
  now = then = clock();
  while ((now - then) < pause)
    now = clock();
}

void clearScreen(void) {
  system("clear");
}

void createRoom(int roomNumber) {
  // Create a random room description.
  char *roomDescriptions[] = {
    "A dark and musty room with a single window.",
    "A large and airy room with a fireplace.",
    "A small and cozy room with a bed.",
    "A long and narrow room with a winding staircase.",
    "A secret room hidden behind a bookcase.",
    "A room filled with cobwebs and dust.",
    "A room with a pool of blood on the floor.",
    "A room with a ghost standing in the corner.",
    "A room with a strange and eerie noise coming from the walls.",
    "A room with a door that leads to nowhere."
  };
  char *roomDescription = roomDescriptions[rand() % 10];

  // Print the room description.
  printf("\n%s\n", roomDescription);
}