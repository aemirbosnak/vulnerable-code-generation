//FormAI DATASET v1.0 Category: Smart home automation ; Style: excited
#include <stdio.h>
#include <stdbool.h>

int main() {
  bool isHome = true;
  bool airCondStatus = false;
  bool lightStatus = false;

  printf("Welcome to Our Smart Home Automation!\n\n");

  while (isHome) {
    int option;
    printf("Please select an option:\n");
    printf("1. Turn on/off Air Conditioner\n");
    printf("2. Turn on/off Lights\n");
    printf("3. Quit\n");
    scanf("%d", &option);

    switch (option) {
      case 1:
        if (airCondStatus) {
          printf("Turning off Air Conditioner...\n");
          airCondStatus = false;
        } else {
          printf("Turning on Air Conditioner...\n");
          airCondStatus = true;
        }
        break;
      case 2:
        if (lightStatus) {
          printf("Turning off Lights...\n");
          lightStatus = false;
        } else {
          printf("Turning on Lights...\n");
          lightStatus = true;
        }
        break;
      case 3:
        printf("Goodbye!\n");
        isHome = false;
        break;
      default:
        printf("Invalid option selected. Please try again.\n\n");
        break;
    }

    if (airCondStatus && lightStatus) {
      printf("It's a hot summer day, but the lights are on! Please save energy and turn off the lights if you are not in the room.\n\n");
    }
  }

  return 0;
}