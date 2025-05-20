//FormAI DATASET v1.0 Category: Smart home light control ; Style: automated
#include <stdio.h>
#include <stdbool.h>

int main() {
  bool isLightOn = false;
  int time = 0;

  printf("Welcome to Smart Home Light Control System\n");
  while (true) {
    printf("\nCurrent Time : %d Hours\n", time);
    printf("Press 1 to turn on the light\n");
    printf("Press 2 to turn off the light\n");
    printf("Press 3 to exit\n");

    // Getting user input
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
      if (isLightOn) {
        printf("The light is already turned on\n");
      } else {
        printf("Turning on the light...\n");
        isLightOn = true;
      }
    } else if (choice == 2) {
      if (isLightOn) {
        printf("Turning off the light...\n");
        isLightOn = false;
      } else {
        printf("The light is already turned off\n");
      }
    } else if (choice == 3) {
      // Exiting the program
      printf("Exiting the Smart Home Light Control System...\n");
      break;
    } else {
      printf("Invalid choice, please try again\n");
      continue;
    }

    // Updating the time
    time++;

    // Simulating day and night time
    if (time >= 7 && time < 19) {
      if (isLightOn) {
        printf("It's daytime but the light is still on\n");
      } else {
        printf("It's daytime and the light is turned off\n");
      }
    } else {
      if (isLightOn) {
        printf("It's nighttime and the light is turned on\n");
      } else {
        printf("It's nighttime and the light is turned off\n");
      }
    }
  }

  return 0;
}