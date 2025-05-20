//FormAI DATASET v1.0 Category: Smart home automation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  int temperature = 25;
  int lights = 0;
  int lock = 0;

  printf("Welcome to your Smart Home!\n");

  while(1) {
    printf("\nCurrent Temperature: %d°C\n", temperature);
    printf("Lights are %s\n", lights ? "On" : "Off");
    printf("Lock is %s\n", lock ? "Engaged" : "Disengaged");

    printf("\nWhat would you like to do?\n");
    printf("1. Increase Temperature\n");
    printf("2. Decrease Temperature\n");
    printf("3. Turn Lights On/Off\n");
    printf("4. Engage/Disengage Lock\n");
    printf("5. Exit\n\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        temperature++;
        printf("\nTemperature increased to %d°C\n", temperature);
        break;

      case 2:
        temperature--;
        printf("\nTemperature decreased to %d°C\n", temperature);
        break;

      case 3:
        lights = !lights;
        printf("\nLights turned %s\n", lights ? "On" : "Off");
        break;

      case 4:
        lock = !lock;
        printf("\nLock %s\n", lock ? "Engaged" : "Disengaged");
        break;

      case 5:
        printf("\nGoodbye!\n");
        exit(0);

      default:
        printf("\nInvalid Choice. Please try again.\n");
    }
  }

  return 0;
}