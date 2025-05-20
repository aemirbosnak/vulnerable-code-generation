//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the light states
#define OFF 0
#define ON 1
#define DIM 2

// Define the room names
#define LIVING_ROOM "Living Room"
#define KITCHEN "Kitchen"
#define BEDROOM "Bedroom"
#define BATHROOM "Bathroom"

// Define the command names
#define TURN_ON "Turn On"
#define TURN_OFF "Turn Off"
#define DIM_LIGHT "Dim Light"

// Define the user input buffer size
#define BUFFER_SIZE 1024

// Main function
int main() {
  // Initialize the light states
  int living_room_light = OFF;
  int kitchen_light = OFF;
  int bedroom_light = OFF;
  int bathroom_light = OFF;

  // Main loop
  while (1) {
    // Prompt the user for input
    printf("Enter a command (e.g. \"Turn On Living Room\"): ");
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);

    // Parse the user input
    char *command = strtok(buffer, " ");
    char *room = strtok(NULL, " ");

    // Handle the command
    if (strcmp(command, TURN_ON) == 0) {
      if (strcmp(room, LIVING_ROOM) == 0) {
        living_room_light = ON;
        printf("Living Room light is now on.\n");
      } else if (strcmp(room, KITCHEN) == 0) {
        kitchen_light = ON;
        printf("Kitchen light is now on.\n");
      } else if (strcmp(room, BEDROOM) == 0) {
        bedroom_light = ON;
        printf("Bedroom light is now on.\n");
      } else if (strcmp(room, BATHROOM) == 0) {
        bathroom_light = ON;
        printf("Bathroom light is now on.\n");
      } else {
        printf("Invalid room name.\n");
      }
    } else if (strcmp(command, TURN_OFF) == 0) {
      if (strcmp(room, LIVING_ROOM) == 0) {
        living_room_light = OFF;
        printf("Living Room light is now off.\n");
      } else if (strcmp(room, KITCHEN) == 0) {
        kitchen_light = OFF;
        printf("Kitchen light is now off.\n");
      } else if (strcmp(room, BEDROOM) == 0) {
        bedroom_light = OFF;
        printf("Bedroom light is now off.\n");
      } else if (strcmp(room, BATHROOM) == 0) {
        bathroom_light = OFF;
        printf("Bathroom light is now off.\n");
      } else {
        printf("Invalid room name.\n");
      }
    } else if (strcmp(command, DIM_LIGHT) == 0) {
      if (strcmp(room, LIVING_ROOM) == 0) {
        living_room_light = DIM;
        printf("Living Room light is now dimmed.\n");
      } else if (strcmp(room, KITCHEN) == 0) {
        kitchen_light = DIM;
        printf("Kitchen light is now dimmed.\n");
      } else if (strcmp(room, BEDROOM) == 0) {
        bedroom_light = DIM;
        printf("Bedroom light is now dimmed.\n");
      } else if (strcmp(room, BATHROOM) == 0) {
        bathroom_light = DIM;
        printf("Bathroom light is now dimmed.\n");
      } else {
        printf("Invalid room name.\n");
      }
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}