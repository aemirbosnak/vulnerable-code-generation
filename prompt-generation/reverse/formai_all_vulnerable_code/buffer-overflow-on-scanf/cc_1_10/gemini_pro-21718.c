//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the room struct
typedef struct room {
  char *name;
  char *description;
  struct room *north;
  struct room *east;
  struct room *south;
  struct room *west;
} room;

// Define the player struct
typedef struct player {
  char *name;
  room *current_room;
} player;

// Create the rooms
room room1 = {"Foyer", "You are in the foyer of a haunted house. The air is cold and damp, and you can hear the wind howling outside.", NULL, NULL, NULL, NULL};
room room2 = {"Living Room", "You are in the living room of the haunted house. The furniture is covered in dust, and the curtains are drawn shut.", NULL, NULL, NULL, &room1};
room room3 = {"Dining Room", "You are in the dining room of the haunted house. The table is set for dinner, but the food is long gone.", &room2, NULL, NULL, NULL};
room room4 = {"Kitchen", "You are in the kitchen of the haunted house. The stove is cold, and the sink is full of dirty dishes.", NULL, NULL, &room3, NULL};
room room5 = {"Bedroom", "You are in the bedroom of the haunted house. The bed is unmade, and the closet door is open.", NULL, &room4, NULL, NULL};
room room6 = {"Bathroom", "You are in the bathroom of the haunted house. The mirror is cracked, and the shower is running.", NULL, NULL, &room5, NULL};
room room7 = {"Attic", "You are in the attic of the haunted house. The air is thick with dust, and you can see cobwebs everywhere.", &room6, NULL, NULL, NULL};
room room8 = {"Basement", "You are in the basement of the haunted house. The walls are covered in mold, and the floor is littered with junk.", NULL, NULL, &room7, NULL};

// Create the player
player player1 = {"Player 1", &room1};

// Define the commands
void goNorth() {
  if (player1.current_room->north != NULL) {
    player1.current_room = player1.current_room->north;
    printf("You go north to the %s.\n", player1.current_room->name);
  } else {
    printf("You can't go north from here.\n");
  }
}

void goEast() {
  if (player1.current_room->east != NULL) {
    player1.current_room = player1.current_room->east;
    printf("You go east to the %s.\n", player1.current_room->name);
  } else {
    printf("You can't go east from here.\n");
  }
}

void goSouth() {
  if (player1.current_room->south != NULL) {
    player1.current_room = player1.current_room->south;
    printf("You go south to the %s.\n", player1.current_room->name);
  } else {
    printf("You can't go south from here.\n");
  }
}

void goWest() {
  if (player1.current_room->west != NULL) {
    player1.current_room = player1.current_room->west;
    printf("You go west to the %s.\n", player1.current_room->name);
  } else {
    printf("You can't go west from here.\n");
  }
}

void look() {
  printf("%s\n", player1.current_room->description);
}

void quit() {
  printf("Goodbye!\n");
  exit(0);
}

// Main game loop
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Game loop
  while (1) {
    // Display the current room
    look();

    // Get the player's input
    char input[256];
    printf("> ");
    scanf("%s", input);

    // Parse the player's input
    if (strcmp(input, "go north") == 0) {
      goNorth();
    } else if (strcmp(input, "go east") == 0) {
      goEast();
    } else if (strcmp(input, "go south") == 0) {
      goSouth();
    } else if (strcmp(input, "go west") == 0) {
      goWest();
    } else if (strcmp(input, "look") == 0) {
      look();
    } else if (strcmp(input, "quit") == 0) {
      quit();
    } else {
      printf("I don't understand that command.\n");
    }
  }

  return 0;
}