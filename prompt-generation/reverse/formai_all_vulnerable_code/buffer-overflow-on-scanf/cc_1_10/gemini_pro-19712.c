//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Light control commands
#define LIGHT_ON  "on"
#define LIGHT_OFF "off"
#define LIGHT_TOGGLE "toggle"

// Room names
#define LIVING_ROOM "living room"
#define KITCHEN "kitchen"
#define BEDROOM "bedroom"

// Initialize the light states
int living_room_light = 0;
int kitchen_light = 0;
int bedroom_light = 0;

// Function to print the current light states
void print_light_states() {
  printf("Living room light: %s\n", living_room_light ? "on" : "off");
  printf("Kitchen light: %s\n", kitchen_light ? "on" : "off");
  printf("Bedroom light: %s\n", bedroom_light ? "on" : "off");
}

// Function to handle a light control command
void handle_command(char *command, char *room) {
  if (strcmp(command, LIGHT_ON) == 0) {
    if (strcmp(room, LIVING_ROOM) == 0) {
      living_room_light = 1;
    } else if (strcmp(room, KITCHEN) == 0) {
      kitchen_light = 1;
    } else if (strcmp(room, BEDROOM) == 0) {
      bedroom_light = 1;
    }
  } else if (strcmp(command, LIGHT_OFF) == 0) {
    if (strcmp(room, LIVING_ROOM) == 0) {
      living_room_light = 0;
    } else if (strcmp(room, KITCHEN) == 0) {
      kitchen_light = 0;
    } else if (strcmp(room, BEDROOM) == 0) {
      bedroom_light = 0;
    }
  } else if (strcmp(command, LIGHT_TOGGLE) == 0) {
    if (strcmp(room, LIVING_ROOM) == 0) {
      living_room_light = !living_room_light;
    } else if (strcmp(room, KITCHEN) == 0) {
      kitchen_light = !kitchen_light;
    } else if (strcmp(room, BEDROOM) == 0) {
      bedroom_light = !bedroom_light;
    }
  }
}

// Main function
int main() {
  // Get the user input
  char command[100];
  char room[100];
  printf("Enter a command (on, off, toggle) and a room (living room, kitchen, bedroom): ");
  scanf("%s %s", command, room);

  // Handle the command
  handle_command(command, room);

  // Print the new light states
  print_light_states();

  return 0;
}