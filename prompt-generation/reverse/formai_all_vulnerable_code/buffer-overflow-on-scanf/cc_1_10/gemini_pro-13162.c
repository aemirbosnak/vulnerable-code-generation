//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Define the light states
#define OFF 0
#define ON 1

// Define the light commands
#define TURN_ON 1
#define TURN_OFF 2

// Define the light status
int lightStatus = OFF;

// Function to turn on the light
void turnOnLight() {
  lightStatus = ON;
  printf("Light turned on!\n");
}

// Function to turn off the light
void turnOffLight() {
  lightStatus = OFF;
  printf("Light turned off!\n");
}

// Function to handle light commands
void handleCommand(int command) {
  switch (command) {
    case TURN_ON:
      turnOnLight();
      break;
    case TURN_OFF:
      turnOffLight();
      break;
    default:
      printf("Invalid command!\n");
  }
}

int main() {
  // Get the light command from the user
  int command;
  printf("Enter a command (1 to turn on, 2 to turn off): ");
  scanf("%d", &command);

  // Handle the light command
  handleCommand(command);

  return 0;
}