//FormAI DATASET v1.0 Category: Smart home automation ; Style: mind-bending
#include <stdio.h>
#include <stdbool.h>

int main() {
  bool lights = false;
  bool soundSystem = false;
  bool doorLocks = false;
  bool temperatureControl = false;

  printf("Welcome to Smart Home Automation!\n");

  while (true) {
    printf("Please select an option:\n");
    printf("1. Turn on/off lights\n");
    printf("2. Turn on/off sound system\n");
    printf("3. Lock/unlock doors\n");
    printf("4. Control temperature\n");
    printf("5. Exit program\n");

    int option;
    scanf("%d", &option);

    switch (option) {
      case 1:
        lights = !lights;
        if (lights) {
          printf("Turning on lights...\n");
        } else {
          printf("Turning off lights...\n");
        }
        break;

      case 2:
        soundSystem = !soundSystem;
        if (soundSystem) {
          printf("Turning on sound system...\n");
        } else {
          printf("Turning off sound system...\n");
        }
        break;

      case 3:
        doorLocks = !doorLocks;
        if (doorLocks) {
          printf("Locking doors...\n");
        } else {
          printf("Unlocking doors...\n");
        }
        break;

      case 4:
        temperatureControl = !temperatureControl;
        if (temperatureControl) {
          printf("Temperature control enabled...\n");
          printf("Please enter desired temperature: ");
          int temperature;
          scanf("%d", &temperature);
          printf("Setting temperature to %d degrees Celsius...\n", temperature);
        } else {
          printf("Temperature control disabled...\n");
        }
        break;

      case 5:
        printf("Exiting program...\n");
        return 0;

      default:
        printf("Invalid option selected. Please try again.\n");
        break;
    }
  }
}