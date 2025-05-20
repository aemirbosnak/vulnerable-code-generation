//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: puzzling
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ROOMS 3
#define NUM_LIGHTS 4

// Room names
const char *room_names[NUM_ROOMS] = { "Living Room", "Bedroom", "Kitchen" };

// Light names
const char *light_names[NUM_LIGHTS] = { "Main Light", "Lamp 1", "Lamp 2", "Ceiling Fan" };

// Light states (on/off)
bool light_states[NUM_ROOMS][NUM_LIGHTS];

// Room states (occupied/unoccupied)
bool room_states[NUM_ROOMS];

// Function to print the current state of the lights
void print_lights() {
  printf("Current light states:\n");
  for (int room = 0; room < NUM_ROOMS; room++) {
    printf("  %s:\n", room_names[room]);
    for (int light = 0; light < NUM_LIGHTS; light++) {
      printf("    %s: %s\n", light_names[light], light_states[room][light] ? "On" : "Off");
    }
  }
}

// Function to toggle a light on or off
void toggle_light(int room, int light) {
  light_states[room][light] = !light_states[room][light];
}

// Function to enter a room
void enter_room(int room) {
  room_states[room] = true;
  if (room == 0) {  // Living Room
    toggle_light(room, 0);  // Main Light
  } else if (room == 1) {  // Bedroom
    toggle_light(room, 1);  // Lamp 1
  } else if (room == 2) {  // Kitchen
    toggle_light(room, 2);  // Lamp 2
  }
}

// Function to leave a room
void leave_room(int room) {
  room_states[room] = false;
  if (room == 0) {  // Living Room
    toggle_light(room, 0);  // Main Light
  } else if (room == 1) {  // Bedroom
    toggle_light(room, 1);  // Lamp 1
  } else if (room == 2) {  // Kitchen
    toggle_light(room, 2);  // Lamp 2
  }
}

// Main function
int main() {
  // Initialize light states
  memset(light_states, false, sizeof(light_states));

  // Initialize room states
  memset(room_states, false, sizeof(room_states));

  // Main loop
  while (1) {
    print_lights();

    // Get input from the user
    char input[100];
    printf("Enter a command (enter/leave/toggle/quit): ");
    scanf("%s", input);

    // Parse the input
    if (strcmp(input, "enter") == 0) {
      int room;
      printf("Enter the room you want to enter (0-2): ");
      scanf("%d", &room);
      enter_room(room);
    } else if (strcmp(input, "leave") == 0) {
      int room;
      printf("Enter the room you want to leave (0-2): ");
      scanf("%d", &room);
      leave_room(room);
    } else if (strcmp(input, "toggle") == 0) {
      int room, light;
      printf("Enter the room and light you want to toggle (0-2, 0-3): ");
      scanf("%d %d", &room, &light);
      toggle_light(room, light);
    } else if (strcmp(input, "quit") == 0) {
      break;
    } else {
      printf("Invalid command\n");
    }
  }

  return 0;
}