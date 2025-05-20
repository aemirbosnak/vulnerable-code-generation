//FormAI DATASET v1.0 Category: Smart home light control ; Style: shocked
#include <stdio.h>
#include <stdbool.h>

#define NUM_LIGHTS 6
#define MAX_BRIGHTNESS 100

typedef struct {
  int brightness;
  bool on;
} Light;

typedef enum {
  LIVING_ROOM,
  KITCHEN,
  BEDROOM,
  BATHROOM,
  OFFICE,
  GUEST_ROOM
} Room;

Light lights[NUM_LIGHTS] = {
  {0, false},  
  {50, true},
  {75, true},
  {25, false},
  {100, true},
  {10, false}
};

void printMenu() {
  printf("\n\nSmart Home Light Control\n");
  printf("------------------------\n");
  printf("1. Living room\n");
  printf("2. Kitchen\n");
  printf("3. Bedroom\n");
  printf("4. Bathroom\n");
  printf("5. Office\n");
  printf("6. Guest room\n");
  printf("7. Turn all lights off\n");
  printf("\nChoose an option: ");
}

void printLightState(Room room) {
  Light light = lights[room];
  printf("The %s light is ", (char *)room);
  if (light.on) {
    printf("on ");
  } else {
    printf("off ");
  }
  printf("and has a brightness of %d%%.\n", light.brightness);
}

void turnAllLightsOff() {
  for (int i = 0; i < NUM_LIGHTS; i++) {
    lights[i].on = false;
    lights[i].brightness = 0;
  }
}

int main() {
  bool running = true;
  while (running) {
    printMenu();
    int choice;
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printLightState(LIVING_ROOM);
        break;
      case 2:
        printLightState(KITCHEN);
        break;
      case 3:
        printLightState(BEDROOM);
        break;
      case 4:
        printLightState(BATHROOM);
        break;
      case 5:
        printLightState(OFFICE);
        break;
      case 6:
        printLightState(GUEST_ROOM);
        break;
      case 7:
        turnAllLightsOff();
        printf("All lights have been turned off.\n");
        break;
      default:
        printf("Invalid option.\n");
        break;
    }
  }
  return 0;
}