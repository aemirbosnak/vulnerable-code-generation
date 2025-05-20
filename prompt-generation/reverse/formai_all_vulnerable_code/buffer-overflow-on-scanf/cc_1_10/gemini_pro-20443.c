//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the room structure
typedef struct Room {
  char *name;
  char *description;
  struct Room *north;
  struct Room *east;
  struct Room *south;
  struct Room *west;
} Room;

// Define the player structure
typedef struct Player {
  char *name;
  int health;
  int sanity;
  Room *currentRoom;
} Player;

// Create the rooms
Room room1 = {"Foyer", "You are in the foyer of a haunted house. The air is cold and damp, and you can hear the wind whistling through the cracks in the walls. There is a door to the north, east, and south."};
Room room2 = {"Living Room", "You are in the living room of the haunted house. The furniture is covered in dust and cobwebs, and the fireplace is cold. There is a door to the north and east."};
Room room3 = {"Dining Room", "You are in the dining room of the haunted house. The table is set for dinner, but the food is long gone. There is a door to the north and south."};
Room room4 = {"Kitchen", "You are in the kitchen of the haunted house. The stove is cold, and the sink is filled with dirty dishes. There is a door to the west."};
Room room5 = {"Master Bedroom", "You are in the master bedroom of the haunted house. The bed is unmade, and the closet door is open. There is a door to the south."};
Room room6 = {"Guest Bedroom", "You are in the guest bedroom of the haunted house. The bed is made, and there is a dresser in the corner. There is a door to the north."};
Room room7 = {"Bathroom", "You are in the bathroom of the haunted house. The sink is cracked, and the mirror is covered in toothpaste. There is a door to the east."};
Room room8 = {"Attic", "You are in the attic of the haunted house. The air is dusty and there are cobwebs everywhere. There is a door to the south."};
Room room9 = {"Basement", "You are in the basement of the haunted house. The walls are damp and there is a strange smell in the air. There is a door to the north."};

// Create the player
Player player = {"Player", 100, 100, &room1};

// Define the game loop
void gameLoop() {
  while (player.health > 0 && player.sanity > 0) {
    // Print the player's current room
    printf("You are in the %s.\n", player.currentRoom->name);
    printf("%s\n", player.currentRoom->description);

    // Print the player's options
    printf("What do you want to do?\n");
    printf("1. Go north\n");
    printf("2. Go east\n");
    printf("3. Go south\n");
    printf("4. Go west\n");
    printf("5. Examine room\n");
    printf("6. Quit\n");

    // Get the player's input
    int choice;
    scanf("%d", &choice);

    // Handle the player's choice
    switch (choice) {
      case 1:
        if (player.currentRoom->north != NULL) {
          player.currentRoom = player.currentRoom->north;
        } else {
          printf("There is no door to the north.\n");
        }
        break;
      case 2:
        if (player.currentRoom->east != NULL) {
          player.currentRoom = player.currentRoom->east;
        } else {
          printf("There is no door to the east.\n");
        }
        break;
      case 3:
        if (player.currentRoom->south != NULL) {
          player.currentRoom = player.currentRoom->south;
        } else {
          printf("There is no door to the south.\n");
        }
        break;
      case 4:
        if (player.currentRoom->west != NULL) {
          player.currentRoom = player.currentRoom->west;
        } else {
          printf("There is no door to the west.\n");
        }
        break;
      case 5:
        printf("%s\n", player.currentRoom->description);
        break;
      case 6:
        printf("Goodbye!\n");
        exit(0);
    }

    // Check if the player has won or lost
    if (player.currentRoom == &room9) {
      printf("Congratulations! You have escaped the haunted house.\n");
      exit(0);
    } else if (player.health <= 0) {
      printf("You have died!\n");
      exit(0);
    } else if (player.sanity <= 0) {
      printf("You have gone insane!\n");
      exit(0);
    }
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Start the game loop
  gameLoop();

  return 0;
}