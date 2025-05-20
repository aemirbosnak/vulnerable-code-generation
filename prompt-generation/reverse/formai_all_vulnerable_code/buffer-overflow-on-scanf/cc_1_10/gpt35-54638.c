//FormAI DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool livingRoomLight = false;
bool kitchenLight = false;
bool bedroomLight = false;

void turnOnLivingRoomLight() {
  livingRoomLight = true;
  printf("Living room light is now ON!\n");
}

void turnOffLivingRoomLight() {
  livingRoomLight = false;
  printf("Living room light is now OFF!\n");
}

void turnOnKitchenLight() {
  kitchenLight = true;
  printf("Kitchen light is now ON!\n");
}

void turnOffKitchenLight() {
  kitchenLight = false;
  printf("Kitchen light is now OFF!\n");
}

void turnOnBedroomLight() {
  bedroomLight = true;
  printf("Bedroom light is now ON!\n");
}

void turnOffBedroomLight() {
  bedroomLight = false;
  printf("Bedroom light is now OFF!\n");
}

int main() {
  int option;
  while (true) {
    printf("Which light would you like to control?\n");
    printf("1 - Living Room Light\n");
    printf("2 - Kitchen Light\n");
    printf("3 - Bedroom Light\n");
    printf("4 - Exit\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        if (livingRoomLight) {
          turnOffLivingRoomLight();
        } else {
          turnOnLivingRoomLight();
        }
        break;
      case 2:
        if (kitchenLight) {
          turnOffKitchenLight();
        } else {
          turnOnKitchenLight();
        }
        break;
      case 3:
        if (bedroomLight) {
          turnOffBedroomLight();
        } else {
          turnOnBedroomLight();
        }
        break;
      case 4:
        printf("Exiting...\n");
        exit(0);
      default:
        printf("Invalid option\n");
        break;
    }
  }
  return 0;
}