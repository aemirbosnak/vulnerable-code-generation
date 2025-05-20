//FormAI DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum number of lights and maximum input length
#define MAX_LIGHTS 10
#define MAX_INPUT_LENGTH 20

// Declare functions
void printCurrentState(int lights[], int numLights);
void turnOnLight(int lights[], int lightNum);
void turnOffLight(int lights[], int lightNum);
int validInput(char input[]);
int parseInput(char input[]);

int main() {
  // Initialize variables
  int lights[MAX_LIGHTS] = {0};
  char input[MAX_INPUT_LENGTH];

  printf("Welcome to the Smart Home Light Control program.\n");

  // Loop until user enters "exit"
  do {
    // Prompt user for input
    printf("\nEnter a command ('on'/'off' followed by a light number, 'state' to see current state, or 'exit' to quit): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Parse input and execute corresponding command
    if (validInput(input)) { // Check if input is valid
      int lightNum = parseInput(input);
      if (strstr(input, "on")) {
        turnOnLight(lights, lightNum);
      } else if (strstr(input, "off")) {
        turnOffLight(lights, lightNum);
      } else if (strstr(input, "state")) {
        printCurrentState(lights, MAX_LIGHTS);
      }
    } else if (strstr(input, "exit")) { // Exit program if user enters "exit"
      printf("Exiting program.\n");
      return 0;
    } else {
      printf("Invalid input. Please try again.\n");
    }
  } while(1);

  return 0;
}

// Function to print the current state of the lights
void printCurrentState(int lights[], int numLights) {
  printf("Current state of lights: ");
  for (int i = 1; i <= numLights; i++) {
    if (lights[i-1] == 1) {
      printf("Light %d is on, ", i);
    } else {
      printf("Light %d is off, ", i);
    }
  }
  printf("\n");
}

// Function to turn on a specific light
void turnOnLight(int lights[], int lightNum) {
  lights[lightNum-1] = 1;
  printf("Light %d turned on.\n", lightNum);
}

// Function to turn off a specific light
void turnOffLight(int lights[], int lightNum) {
  lights[lightNum-1] = 0;
  printf("Light %d turned off.\n", lightNum);
}

// Function to check if input is valid
int validInput(char input[]) {
  char command[MAX_INPUT_LENGTH];
  int lightNum;
  int numItems = sscanf(input, "%s %d", command, &lightNum);
  
  if (numItems == 2 && ((strstr(command, "on") && lightNum >= 1 && lightNum <= MAX_LIGHTS) || (strstr(command, "off") && lightNum >= 1 && lightNum <= MAX_LIGHTS))) {
    return 1;
  } else if (numItems == 1 && strstr(command, "state")) {
    return 1;
  } else if (strstr(input, "exit")) {
    return 1;
  } else {
    return 0;
  }
}

// Function to parse input and extract the light number
int parseInput(char input[]) {
  char command[MAX_INPUT_LENGTH];
  int lightNum;
  sscanf(input, "%s %d", command, &lightNum);
  return lightNum;
}