//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the room layout
#define NUM_ROOMS 5
char *room_names[] = {"Foyer", "Living Room", "Kitchen", "Dining Room", "Bedroom", "Bathroom"};

// Define the possible events
#define NUM_EVENTS 3
char *event_names[] = {"Footsteps", "Whispers", "Door Creak"};

// Define the player's inventory
typedef enum {
  // Flashlight
  LIGHT,
  // Key
  KEY,
  // Nothing
  NONE
} inventory_item;

// Define the game state
typedef struct {
  int current_room; // The player's current room
  inventory_item inventory; // The player's inventory
  int fear_level; // The player's fear level
} game_state;

// Initialize the game state
game_state game = {
  .current_room = 0,
  .inventory = NONE,
  .fear_level = 0
};

// Simulate a single event
void simulate_event() {
  // Get a random event
  int event_index = rand() % NUM_EVENTS;

  // Print the event name
  printf("You hear %s\n", event_names[event_index]);

  // Increase the player's fear level
  game.fear_level++;
}

// Handle the player's input
void handle_input() {
  // Get the player's input
  char input;
  scanf(" %c", &input);

  // Check the player's input
  switch (input) {
    case 'w': // Go west
      if (game.current_room > 0) {
        game.current_room--;
      }
      break;
    case 'e': // Go east
      if (game.current_room < NUM_ROOMS - 1) {
        game.current_room++;
      }
      break;
    case 'f': // Find
      if (game.inventory == NONE) {
        game.inventory = LIGHT;
        printf("You found a flashlight.\n");
      } else {
        printf("You already have a flashlight.\n");
      }
      break;
    case 'u': // Use
      if (game.inventory == LIGHT) {
        game.fear_level--;
        printf("You used the flashlight to calm your fears.\n");
      } else {
        printf("You don't have a flashlight.\n");
      }
      break;
    case 'q': // Quit
      exit(0);
      break;
  }
}

// Print the game state
void print_game_state() {
  // Print the player's current room
  printf("You are in the %s\n", room_names[game.current_room]);

  // Print the player's inventory
  if (game.inventory == NONE) {
    printf("You are carrying nothing.\n");
  } else if (game.inventory == LIGHT) {
    printf("You are carrying a flashlight.\n");
  }

  // Print the player's fear level
  printf("Your fear level is %d\n", game.fear_level);
}

// Main game loop
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Loop until the player quits
  while (game.fear_level < 10) {
    // Print the game state
    print_game_state();

    // Simulate an event
    simulate_event();

    // Handle the player's input
    handle_input();
  }

  // Print the game over message
  printf("Game over! You died of fright.\n");

  return 0;
}