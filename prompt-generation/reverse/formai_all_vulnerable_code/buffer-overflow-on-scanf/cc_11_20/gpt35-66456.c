//FormAI DATASET v1.0 Category: Smart home automation ; Style: happy
#include <stdio.h>

int main() {
  printf("Welcome to your happy Smart Home Automation program!\n");
  printf("The purpose of this program is to make your life easier and more enjoyable.\n");
  printf("Let's get started!\n\n");

  // Set the initial values
  int lights_on = 0;
  int temperature = 70;
  int door_locked = 1;
  int tv_on = 0;

  // Display the initial state
  printf("Lights: %s\n", lights_on ? "On" : "Off");
  printf("Temperature: %d degrees Fahrenheit\n", temperature);
  printf("Door: %s\n", door_locked ? "Locked" : "Unlocked");
  printf("TV: %s\n", tv_on ? "On" : "Off");

  // Wait for user input
  char input;
  do {
    printf("\nEnter a command (L = lights, T = temperature, D = door, V = TV, Q = quit): ");
    scanf(" %c", &input);

    switch (input) {
      case 'L':
        // Toggle the lights
        lights_on = !lights_on;
        printf("Lights: %s\n", lights_on ? "On" : "Off");
        break;

      case 'T':
        // Adjust the temperature
        printf("Enter a temperature (from 50 to 90 degrees Fahrenheit): ");
        scanf("%d", &temperature);
        if (temperature < 50) {
          temperature = 50;
        } else if (temperature > 90) {
          temperature = 90;
        }
        printf("Temperature: %d degrees Fahrenheit\n", temperature);
        break;

      case 'D':
        // Toggle the door lock
        door_locked = !door_locked;
        printf("Door: %s\n", door_locked ? "Locked" : "Unlocked");
        break;

      case 'V':
        // Toggle the TV
        tv_on = !tv_on;
        printf("TV: %s\n", tv_on ? "On" : "Off");
        break;

      case 'Q':
        // Exit the program
        printf("Goodbye!\n");
        break;

      default:
        printf("Invalid command: %c\n", input);
    }
  } while (input != 'Q');

  // End the program
  return 0;
}