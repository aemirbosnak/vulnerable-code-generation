//FormAI DATASET v1.0 Category: Smart home light control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10 // Maximum number of rooms

// Constant variables for light on/off status
#define OFF 0
#define ON 1

// Structure to store room information
typedef struct {
  char name[20];
  int light_status;
} Room;

// Function to turn on the lights in a specified room
void turn_on_light(Room* room) {
  room->light_status = ON;
  printf("%s light is now ON.\n", room->name);
}

// Function to turn off the lights in a specified room
void turn_off_light(Room* room) {
  room->light_status = OFF;
  printf("%s light is now OFF.\n", room->name);
}

// Function to get user input and execute the appropriate action
void handle_user_input(Room* rooms, int num_rooms) {
  char input[20];
  char room_name[20];

  printf("Enter room name and action (on/off): ");
  scanf("%s %s", room_name, input);

  for (int i = 0; i < num_rooms; i++) {
    if (strcmp(room_name, rooms[i].name) == 0) {
      if (strcmp(input, "on") == 0) {
        turn_on_light(&rooms[i]);
      } else if (strcmp(input, "off") == 0) {
        turn_off_light(&rooms[i]);
      } else {
        printf("Invalid input.\n");
      }
      return;
    }
  }

  printf("Room not found.\n");
}

int main() {
  Room rooms[MAX_ROOMS];
  int num_rooms;

  // Get the number of rooms
  printf("Enter the number of rooms: ");
  scanf("%d", &num_rooms);

  // Get the name of each room
  for (int i = 0; i < num_rooms; i++) {
    printf("Enter the name of room #%d: ", i + 1);
    scanf("%s", rooms[i].name);
    rooms[i].light_status = OFF; // Default light status is off
  }

  // Listen for user input and execute the appropriate action
  while (1) {
    handle_user_input(rooms, num_rooms);
  }

  return 0;
}