//FormAI DATASET v1.0 Category: Smart home automation ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main() {
  // Initialization of variables
  int temp = 0;
  int lights = 0;
  int blinds = 0;
  int music = 0;

  printf("Welcome to the Smart Home Automation System!\n");

  // Loop until input is 'exit'
  while (1) {
    // User input
    char input[10];
    printf("Enter a command (temp/lights/blinds/music/exit): ");
    scanf("%9s", input);

    // Temperature control
    if (strcmp(input, "temp") == 0) {
      int newTemp;
      printf("Current temperature: %d\n", temp);
      printf("Enter new temperature: ");
      scanf("%d", &newTemp);

      // Limit temperature range
      if (newTemp < 60) {
        printf("Temperature set to minimum value of 60.\n");
        temp = 60;
      } else if (newTemp > 80) {
        printf("Temperature set to maximum value of 80.\n");
        temp = 80;
      } else {
        temp = newTemp;
        printf("Temperature set to %d.\n", temp);
      }
    }

    // Light control
    else if (strcmp(input, "lights") == 0) {
      printf("Current light level: %d\n", lights);
      printf("Enter new light level (0-100): ");
      scanf("%d", &lights);

      // Limit light level range
      if (lights < 0) {
        printf("Light level set to minimum value of 0.\n");
        lights = 0;
      } else if (lights > 100) {
        printf("Light level set to maximum value of 100.\n");
        lights = 100;
      } else {
        printf("Light level set to %d.\n", lights);
      }
    }

    // Blinds control
    else if (strcmp(input, "blinds") == 0) {
      printf("Current blinds level: %d\n", blinds);
      printf("Enter new blinds level (0-100): ");
      scanf("%d", &blinds);

      // Limit blinds level range
      if (blinds < 0) {
        printf("Blinds level set to minimum value of 0.\n");
        blinds = 0;
      } else if (blinds > 100) {
        printf("Blinds level set to maximum value of 100.\n");
        blinds = 100;
      } else {
        printf("Blinds level set to %d.\n", blinds);
      }
    }

    // Music control
    else if (strcmp(input, "music") == 0) {
      printf("Enter 'on' to play music or 'off' to stop music: ");
      char onOff[4];
      scanf("%3s", onOff);

      // Play or stop music
      if (strcmp(onOff, "on") == 0) {
        music = 1;
        printf("Music turned on.\n");
      } else {
        music = 0;
        printf("Music turned off.\n");
      }
    }

    // Exit program
    else if (strcmp(input, "exit") == 0) {
      printf("Exiting Smart Home Automation System.\n");
      break;
    }

    // Invalid input
    else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}