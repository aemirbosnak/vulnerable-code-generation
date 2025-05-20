//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rooms in the haunted house
#define NUM_ROOMS 10

// Define the possible events that can occur in each room
#define EVENT_NONE 0
#define EVENT_GHOST 1
#define EVENT_CREAK 2
#define EVENT_SCREAM 3
#define EVENT_DOOR_OPEN 4
#define EVENT_DOOR_CLOSE 5

// Define the player's current location in the haunted house
int current_room = 0;

// Define the player's health
int health = 100;

// Define the game's state
enum game_state {
  GAME_STATE_PLAYING,
  GAME_STATE_GAME_OVER,
  GAME_STATE_VICTORY
};

// Define the game's state
enum game_state state = GAME_STATE_PLAYING;

// Function to generate a random event
int generate_event() {
  // Get a random number between 0 and 4
  int random_number = rand() % 5;

  // Return the corresponding event
  switch (random_number) {
    case 0:
      return EVENT_NONE;
    case 1:
      return EVENT_GHOST;
    case 2:
      return EVENT_CREAK;
    case 3:
      return EVENT_SCREAM;
    case 4:
      return EVENT_DOOR_OPEN;
    case 5:
      return EVENT_DOOR_CLOSE;
  }

  return 0;
}

// Function to handle the player's movement
void move_player(int direction) {
  // Check if the player is trying to move to a valid room
  if (direction < 0 || direction >= NUM_ROOMS) {
    printf("Invalid room number.\n");
    return;
  }

  // Move the player to the new room
  current_room = direction;
}

// Function to handle the player's interaction with an event
void handle_event(int event) {
  // Check which event occurred
  switch (event) {
    case EVENT_NONE:
      // Nothing happened
      break;
    case EVENT_GHOST:
      // The player encountered a ghost
      printf("You saw a ghost!\n");
      health -= 10;
      break;
    case EVENT_CREAK:
      // The player heard a creak
      printf("You heard a creak.\n");
      break;
    case EVENT_SCREAM:
      // The player heard a scream
      printf("You heard a scream.\n");
      break;
    case EVENT_DOOR_OPEN:
      // The player opened a door
      printf("You opened a door.\n");
      break;
    case EVENT_DOOR_CLOSE:
      // The player closed a door
      printf("You closed a door.\n");
      break;
  }
}

// Function to check the player's health
void check_health() {
  // Check if the player's health is below 0
  if (health <= 0) {
    // The player has died
    state = GAME_STATE_GAME_OVER;
  }
}

// Function to print the game's state
void print_state() {
  // Check which game state the player is in
  switch (state) {
    case GAME_STATE_PLAYING:
      // The player is still playing the game
      printf("You are in room %d.\n", current_room);
      printf("Your health is %d.\n", health);
      break;
    case GAME_STATE_GAME_OVER:
      // The player has died
      printf("Game over!\n");
      break;
    case GAME_STATE_VICTORY:
      // The player has escaped the haunted house
      printf("You escaped!\n");
      break;
  }
}

// Main game loop
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // While the game is still playing
  while (state == GAME_STATE_PLAYING) {
    // Print the game's state
    print_state();

    // Get the player's input
    int direction;
    printf("Enter a direction (0-9): ");
    scanf("%d", &direction);

    // Move the player
    move_player(direction);

    // Generate a random event
    int event = generate_event();

    // Handle the event
    handle_event(event);

    // Check the player's health
    check_health();
  }

  return 0;
}