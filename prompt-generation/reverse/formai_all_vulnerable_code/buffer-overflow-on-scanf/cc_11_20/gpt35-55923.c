//FormAI DATASET v1.0 Category: Smart home automation ; Style: shocked
#include <stdio.h>
#include <stdbool.h>

int main() {
  bool light = true;
  bool fan = false;
  bool ac = false;

  printf("Welcome to Smart Home Automation\n");
  printf("----------------------------------------\n");

  while(true) {
    printf("What would you like to do?\n");
    printf("1. Turn on/off the lights\n");
    printf("2. Turn on/off the fan\n");
    printf("3. Turn on/off the AC\n");
    printf("4. Exit\n");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        if(light) {
          printf("Turning off the lights...\n");
          light = false;
        } else {
          printf("Turning on the lights...\n");
          light = true;
        }
        break;
      case 2:
        if(fan) {
          printf("Turning off the fan...\n");
          fan = false;
        } else {
          printf("Turning on the fan...\n");
          fan = true;
        }
        break;
      case 3:
        if(ac) {
          printf("Turning off the AC...\n");
          ac = false;
        } else {
          printf("Turning on the AC...\n");
          ac = true;
        }
        break;
      case 4:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid choice. Please try again.\n");
    }

    printf("\nCurrent Status:\n");
    printf("Lights: %s\n", light ? "On" : "Off");
    printf("Fan: %s\n", fan ? "On" : "Off");
    printf("AC: %s\n", ac ? "On" : "Off");
    printf("----------------------------------------\n");
  }

  return 0;
}