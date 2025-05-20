//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible rooms in the haunted house
typedef enum {
  FOYER,
  LIVING_ROOM,
  DINING_ROOM,
  LIBRARY,
  BILLIARD_ROOM,
  MASTER_BEDROOM,
  GUEST_BEDROOM,
  ATTIC,
  BASEMENT,
  SECRET_ROOM
} room_t;

// Define the possible events that can occur in each room
typedef enum {
  NO_EVENT,
  CREAKING_FLOORBOARDS,
  DOOR_CREAKING_OPEN,
  WINDOW_SMASHING,
  GHOST_APPEARING,
  POLTERGEIST_ACTIVITY,
  DEMONIC_POSSESSION
} event_t;

// Define the structure of a room
typedef struct {
  room_t room_type;
  event_t event;
} room;

// Define the haunted house
room haunted_house[10] = {
  {FOYER, NO_EVENT},
  {LIVING_ROOM, CREAKING_FLOORBOARDS},
  {DINING_ROOM, DOOR_CREAKING_OPEN},
  {LIBRARY, WINDOW_SMASHING},
  {BILLIARD_ROOM, GHOST_APPEARING},
  {MASTER_BEDROOM, POLTERGEIST_ACTIVITY},
  {GUEST_BEDROOM, DEMONIC_POSSESSION},
  {ATTIC, NO_EVENT},
  {BASEMENT, NO_EVENT},
  {SECRET_ROOM, NO_EVENT}
};

// Function to generate a random event for a given room
event_t generate_event(room_t room_type) {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random number between 0 and the number of possible events
  int event_index = rand() % 7;

  // Return the corresponding event
  return haunted_house[room_type].event;
}

// Function to simulate the haunted house
void simulate_haunted_house() {
  // Start in the foyer
  room_t current_room = FOYER;

  // Loop until the player leaves the haunted house
  while (current_room != SECRET_ROOM) {
    // Generate a random event for the current room
    event_t event = generate_event(current_room);

    // Print the event to the console
    switch (event) {
      case NO_EVENT:
        printf("Nothing happens.\n");
        break;
      case CREAKING_FLOORBOARDS:
        printf("You hear creaking floorboards.\n");
        break;
      case DOOR_CREAKING_OPEN:
        printf("A door creaks open.\n");
        break;
      case WINDOW_SMASHING:
        printf("A window smashes.\n");
        break;
      case GHOST_APPEARING:
        printf("A ghost appears.\n");
        break;
      case POLTERGEIST_ACTIVITY:
        printf("Poltergeist activity occurs.\n");
        break;
      case DEMONIC_POSSESSION:
        printf("A demonic possession occurs.\n");
        break;
    }

    // Get the next room from the player
    printf("Which room do you want to go to next? (0-9): ");
    int next_room;
    scanf("%d", &next_room);

    // Update the current room
    current_room = next_room;
  }

  // The player has found the secret room
  printf("You have found the secret room!\n");
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Simulate the haunted house
  simulate_haunted_house();

  return 0;
}