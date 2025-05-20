//FormAI DATASET v1.0 Category: Smart home automation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* deviceName;
  int room;
  int isOn;
} Device;

void turnOn(Device* device) {
  device->isOn = 1;
  printf("%s has been turned on in room %d.\n", device->deviceName, device->room);
}

void turnOff(Device* device) {
  device->isOn = 0;
  printf("%s has been turned off in room %d.\n", device->deviceName, device->room);
}

int main() {
  Device devices[6];
  devices[0].deviceName = "Chandelier";
  devices[0].room = 1;
  devices[0].isOn = 0;

  devices[1].deviceName = "Fireplace";
  devices[1].room = 1;
  devices[1].isOn = 0;

  devices[2].deviceName = "Candlestick";
  devices[2].room = 2;
  devices[2].isOn = 0;

  devices[3].deviceName = "Torch";
  devices[3].room = 2;
  devices[3].isOn = 0;

  devices[4].deviceName = "Lock";
  devices[4].room = 3;
  devices[4].isOn = 0;

  devices[5].deviceName = "Gate";
  devices[5].room = 3;
  devices[5].isOn = 0;

  printf("Greetings, welcome to your medieval Smart Home.\n");

  char input[10];
  while(1) {
    printf("What would you like to do? (turn on, turn off, quit): ");
    fgets(input, 10, stdin);
    
    if (strcmp(input, "quit\n") == 0) {
      printf("Farewell, traveler.\n");
      break;
    }

    int room;
    printf("Which room? (1-3): ");
    scanf("%d", &room);
    getchar();

    if (room < 1 || room > 3) {
      printf("Invalid room number. Try again.\n");
      continue;
    }

    if (strcmp(input, "turn on\n") == 0) {
      int deviceIndex;
      printf("Which device? (1-2 for room 1, 3-4 for room 2, 5-6 for room 3): ");
      scanf("%d", &deviceIndex);
      getchar();

      if (deviceIndex < (room - 1) * 2 || deviceIndex > (room - 1) * 2 + 1) {
        printf("Invalid device number for room %d. Try again.\n", room);
        continue;
      }

      turnOn(&devices[deviceIndex - 1]);
    }
    else if (strcmp(input, "turn off\n") == 0) {
      int deviceIndex;
      printf("Which device? (1-2 for room 1, 3-4 for room 2, 5-6 for room 3): ");
      scanf("%d", &deviceIndex);
      getchar();

      if (deviceIndex < (room - 1) * 2 || deviceIndex > (room - 1) * 2 + 1) {
        printf("Invalid device number for room %d. Try again.\n", room);
        continue;
      }

      turnOff(&devices[deviceIndex - 1]);
    }
    else {
      printf("Invalid input. Try again.\n");
    }
  }

  return 0;
}