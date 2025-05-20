//FormAI DATASET v1.0 Category: Smart home light control ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>

int main() {
  // Declare variables
  int lightInt = 0;
  bool lightBool = false;

  // Ask for user input
  printf("Enter the current light intensity (0-100): ");
  scanf("%d", &lightInt);

  // Convert light intensity to boolean value
  if (lightInt >= 50) {
    printf("Light is on.\n");
    lightBool = true;
  } else {
    printf("Light is off.\n");
    lightBool = false;
  }

  // Allow user to change light setting
  printf("Would you like to change the light status? (y/n): ");
  char input;
  scanf(" %c", &input);
  if (input == 'y') {
    printf("Enter the new light status (on/off): ");
    char status[4];
    scanf("%s", status);
    if (strcmp(status, "on") == 0) {
      lightBool = true;
      printf("Light is on.\n");
    } else if (strcmp(status, "off") == 0) {
      lightBool = false;
      printf("Light is off.\n");
    } else {
      printf("Invalid input.\n");
    }
  } else {
    // Do nothing
  }

  // Convert boolean value to light intensity
  if (lightBool == true) {
    lightInt = 100;
  } else {
    lightInt = 0;
  }

  // Output final light intensity
  printf("Final light intensity: %d\n", lightInt);

  // End program
  return 0;
}