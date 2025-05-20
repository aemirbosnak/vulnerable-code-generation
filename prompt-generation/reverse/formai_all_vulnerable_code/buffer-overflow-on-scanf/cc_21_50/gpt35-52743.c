//FormAI DATASET v1.0 Category: Smart home light control ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
  int lights[5] = {0, 0, 0, 0, 0};
  int hallwayLight = 0;
  int livingRoomLight = 0;
  int kitchenLight = 0;
  int bedroomLight = 0;
  int bathroomLight = 0;

  printf("Welcome to your Smart Home Light Control!\n\n\n");

  while (1) {
    printf("Choose a room to control the lights:\n");
    printf("1 - Hallway\n");
    printf("2 - Living Room\n");
    printf("3 - Kitchen\n");
    printf("4 - Bedroom\n");
    printf("5 - Bathroom\n");
    printf("6 - Exit\n\n");
    int input;
    scanf("%d", &input);
    if (input == 6) {
      printf("Thank you for using your Smart Home Light Control!\n");
      break;
    } else if (input > 6 || input < 1) {
      printf("Invalid input, please try again!\n\n\n");
      continue;
    }
    printf("Choose an option:\n");
    printf("1 - Turn on lights\n");
    printf("2 - Turn off lights\n\n");
    int option;
    scanf("%d", &option);
    if (option > 2 || option < 1) {
      printf("Invalid input, please try again!\n\n\n");
      continue;
    }
    if (option == 1) {
      if (lights[input - 1] == 1) {
        printf("Lights in this room are already turned on!\n\n\n");
      } else {
        lights[input - 1] = 1;
        switch(input){
          case 1:
            hallwayLight = 1;
            break;
          case 2:
            livingRoomLight = 1;
            break;
          case 3:
            kitchenLight = 1;
            break;
          case 4:
            bedroomLight = 1;
            break;
          case 5:
            bathroomLight = 1;
            break;
        }
        printf("Lights turned on in room %d!\n\n\n", input);
      }
    } else {
      if (lights[input - 1] == 0) {
        printf("Lights in this room are already turned off!\n\n\n");
      } else {
        lights[input - 1] = 0;
        switch(input){
          case 1:
            hallwayLight = 0;
            break;
          case 2:
            livingRoomLight = 0;
            break;
          case 3:
            kitchenLight = 0;
            break;
          case 4:
            bedroomLight = 0;
            break;
          case 5:
            bathroomLight = 0;
            break;
        }
        printf("Lights turned off in room %d!\n\n\n", input);
      }
    }
    // Print state of lights
    printf("State of lights in each room:\n");
    printf("Hallway: %s\n", hallwayLight ? "ON" : "OFF");
    printf("Living Room: %s\n", livingRoomLight ? "ON" : "OFF");
    printf("Kitchen: %s\n", kitchenLight ? "ON" : "OFF");
    printf("Bedroom: %s\n", bedroomLight ? "ON" : "OFF");
    printf("Bathroom: %s\n", bathroomLight ? "ON" : "OFF");
  }

  return 0;
}