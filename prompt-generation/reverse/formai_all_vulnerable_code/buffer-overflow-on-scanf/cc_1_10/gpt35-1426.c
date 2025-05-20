//FormAI DATASET v1.0 Category: Smart home light control ; Style: happy
#include <stdio.h>

// Define constants for light states
#define LIVING_ROOM 1
#define KITCHEN 2
#define BEDROOM 3

// Define functions
void turnOn(int light);
void turnOff(int light);

// Main function
int main() {
  int light;
  char action;

  // Initial prompt
  printf("Welcome to Smart Home Light Control!\n");
  printf("Which light would you like to control?\n");
  printf("1 - Living Room\n");
  printf("2 - Kitchen\n");
  printf("3 - Bedroom\n");
  scanf("%d", &light);

  // Loop until user quits
  while (1) {
    // Prompt user for action
    printf("What would you like to do with the light? (o for on, f for off, q to quit)\n");
    scanf(" %c", &action);

    // Switch statement to handle different actions
    switch (action) {
      case 'o':
        turnOn(light);
        break;
      case 'f':
        turnOff(light);
        break;
      case 'q':
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid action.\n");
        break;
    }
  }
}

// Function to turn a light on
void turnOn(int light) {
  switch (light) {
    case LIVING_ROOM:
      printf("Turning on living room light...\n");
      break;
    case KITCHEN:
      printf("Turning on kitchen light...\n");
      break;
    case BEDROOM:
      printf("Turning on bedroom light...\n");
      break;
    default:
      printf("Invalid light selection.\n");
      break;
  }
}

// Function to turn a light off
void turnOff(int light) {
  switch (light) {
    case LIVING_ROOM:
      printf("Turning off living room light...\n");
      break;
    case KITCHEN:
      printf("Turning off kitchen light...\n");
      break;
    case BEDROOM:
      printf("Turning off bedroom light...\n");
      break;
    default:
      printf("Invalid light selection.\n");
      break;
  }
}