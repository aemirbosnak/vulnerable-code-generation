//FormAI DATASET v1.0 Category: Smart home automation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Welcome message
  printf("Welcome to Smart Home Automation!\n\n");

  // Variables initialization
  int temp = 25; // Current temperature
  int threshold = 20; // Temperature threshold for heater
  int lights = 0; // Lights status
  int doors = 1; // Doors status

  // Main loop
  while (1) {

    // Display current status
    printf("Current temperature: %d\n", temp);
    printf("Heater threshold: %d\n", threshold);
    printf("Lights: %s\n", lights ? "On" : "Off");
    printf("Doors: %s\n", doors ? "Locked" : "Unlocked");
    printf("\n");

    // User input
    printf("What would you like to do?\n");
    printf("1. Set temperature threshold\n");
    printf("2. Turn on/off lights\n");
    printf("3. Lock/unlock doors\n");
    printf("4. Quit\n");
    printf("Choice: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
      // Set temperature threshold
      printf("Enter new threshold: ");
      scanf("%d", &threshold);
      printf("\n");
    } else if (choice == 2) {
      // Turn on/off lights
      lights = !lights;
      printf("\n");
    } else if (choice == 3) {
      // Lock/unlock doors
      doors = !doors;
      printf("\n");
    } else if (choice == 4) {
      // Quit program
      printf("Thank you for using Smart Home Automation!\n");
      exit(0);
    } else {
      // Invalid choice
      printf("Invalid choice, please try again.\n\n");
    }

    // Adjust temperature based on heater threshold and outside temperature sensor
    int outside_temp = rand() % 10 + 10; // Simulate outside temperature
    if (temp < threshold && outside_temp < temp) {
      temp += 1;
    } else if (temp > threshold) {
      temp -= 1;
    }

  }

  return 0;
}