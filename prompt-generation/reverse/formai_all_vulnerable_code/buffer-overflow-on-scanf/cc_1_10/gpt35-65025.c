//FormAI DATASET v1.0 Category: Smart home automation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The following struct represents a smart device */
typedef struct {
  char type[20];
  int power;
  int status;
} Device;

/* The following struct represents a room in a smart home */
typedef struct {
  char roomName[20];
  Device devices[5];
} Room;

/* Function to turn on/off a specific device */
void toggleDevice(Room *room, char *deviceType) {
  for (int i = 0; i < 5; i++) {
    if (strcmp(room->devices[i].type, deviceType) == 0) {
      room->devices[i].status = !room->devices[i].status;
      printf("%s in %s is now %s\n", deviceType, room->roomName, room->devices[i].status ? "on" : "off");
      return;
    }
  }
  printf("Device not found in room\n");
}

int main() {
  Room livingRoom = {"Living Room", {
    {"Lights", 20, 0},
    {"TV", 50, 0},
    {"Air Conditioner", 100, 0},
  }};

  Room bedroom = {"Bedroom", {
    {"Lights", 10, 0},
    {"Fan", 30, 0},
  }};

  printf("Welcome to your smart home\n");

  while(1) {
    printf("Please enter a room to control (Living Room/Bedroom): ");
    char input[20];
    scanf("%s", input);

    Room *currentRoom = NULL;

    if (strcmp(input, "Living Room") == 0) {
      currentRoom = &livingRoom;
    } else if (strcmp(input, "Bedroom") == 0) {
      currentRoom = &bedroom;
    } else {
      printf("Invalid room input, please try again\n");
      continue;
    }
    printf("Select device to toggle (Lights/TV/Air Conditioner/Fan): ");
    scanf("%s", input);
    toggleDevice(currentRoom, input);
  }

  return 0;
}