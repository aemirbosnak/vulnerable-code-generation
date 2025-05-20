//FormAI DATASET v1.0 Category: Smart home light control ; Style: thoughtful
#include <stdio.h>

int main() {
  // Declare variables
  int bedroomLight, livingRoomLight, kitchenLight, bathroomLight;
  int userInput;

  // Initialize all lights to be off
  bedroomLight = 0;
  livingRoomLight = 0;
  kitchenLight = 0;
  bathroomLight = 0;

  // Display options to the user
  printf("Welcome to the Smart Home light control program!\n");
  printf("Please select a room to control:\n");
  printf("1. Bedroom\n2. Living Room\n3. Kitchen\n4. Bathroom\n");

  // Get user input
  scanf("%d", &userInput);

  // Control the selected room's light
  switch(userInput) {
    case 1:
      if (bedroomLight == 0) {
        bedroomLight = 1;
        printf("The bedroom light is now on.\n");
      } else {
        bedroomLight = 0;
        printf("The bedroom light is now off.\n");
      }
      break;
    case 2:
      if (livingRoomLight == 0) {
        livingRoomLight = 1;
        printf("The living room light is now on.\n");
      } else {
        livingRoomLight = 0;
        printf("The living room light is now off.\n");
      }
      break;
    case 3:
      if (kitchenLight == 0) {
        kitchenLight = 1;
        printf("The kitchen light is now on.\n");
      } else {
        kitchenLight = 0;
        printf("The kitchen light is now off.\n");
      }
      break;
    case 4:
      if (bathroomLight == 0) {
        bathroomLight = 1;
        printf("The bathroom light is now on.\n");
      } else {
        bathroomLight = 0;
        printf("The bathroom light is now off.\n");
      }
      break;
    default:
      printf("Invalid input.\n");
      break;
  }

  return 0;
}