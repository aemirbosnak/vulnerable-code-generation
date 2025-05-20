//FormAI DATASET v1.0 Category: Smart home light control ; Style: calm
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool isLightOn(int);
void turnOnLight(int);
void turnOffLight(int);

// Main function
int main() {
  // Array of boolean values to indicate the current state of each light in the house
  bool lightStates[8] = {false};

  // Infinitely loop to receive and process commands
  while (true) {
    printf("Enter command (e.g. 1 ON, 5 OFF): ");
    int lightNum;
    char command[4];  // Max length of command is 3 (ON/OFF) + null terminator
    scanf("%d %s", &lightNum, command);

    if (strcmp(command, "ON") == 0) {
      turnOnLight(lightNum);
      lightStates[lightNum-1] = true;  // Update the state of the light
      printf("Light %d turned ON\n", lightNum);
    }
    else if (strcmp(command, "OFF") == 0) {
      turnOffLight(lightNum);
      lightStates[lightNum-1] = false;  // Update the state of the light
      printf("Light %d turned OFF\n", lightNum);
    }
    else {
      printf("Invalid command\n");
    }

    // Print the current state of all lights after processing the command
    printf("Current state of lights: ");
    for (int i = 0; i < 8; i++) {
      printf("%d ", lightStates[i]);
    }
    printf("\n");
  }

  return 0;
}

// Function to check if a light is currently on or off
bool isLightOn(int lightNum) {
  // Assume all lights are off initially
  return false;
}

// Function to turn on a specific light
void turnOnLight(int lightNum) {
  printf("Turning ON light %d\n", lightNum);
  // Code to turn on the specific light goes here
}

// Function to turn off a specific light
void turnOffLight(int lightNum) {
  printf("Turning OFF light %d\n", lightNum);
  // Code to turn off the specific light goes here
}