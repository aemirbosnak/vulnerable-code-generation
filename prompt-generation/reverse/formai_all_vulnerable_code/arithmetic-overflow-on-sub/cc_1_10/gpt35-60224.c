//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: careful
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Define the state of the traffic light as an enum
typedef enum {
  RED,
  YELLOW,
  GREEN
} lightState;

// Define the direction of the traffic light as an enum
typedef enum {
  NORTH_SOUTH,
  EAST_WEST
} lightDirection;

// Set the initial state of the traffic light to green for South-North direction and red for East-West direction
lightState northSouthState = GREEN;
lightState eastWestState = RED;

// Function prototypes
void printTrafficLightState(lightDirection direction, lightState state);
void changeTrafficLightState(lightDirection direction, lightState newState);

// Main function
int main() {
  
  // Define a variable to keep track of time elapsed
  int timeElapsed = 0;
  
  // Use the time() function to get the current time in seconds
  time_t startTime = time(NULL);
  
  // Loop indefinitely
  while (true) {
    
    // Calculate the time elapsed since the program started
    timeElapsed = (int)(time(NULL) - startTime);
    
    // Print the time elapsed
    printf("Time elapsed: %d seconds\n", timeElapsed);
    
    // If the north-south light is green and has been green for 10 seconds, change it to yellow
    if (northSouthState == GREEN && timeElapsed % 20 == 10) {
      changeTrafficLightState(NORTH_SOUTH, YELLOW);
    }
    
    // If the north-south light is yellow and has been yellow for 3 seconds, change it to red
    if (northSouthState == YELLOW && timeElapsed % 20 == 13) {
      changeTrafficLightState(NORTH_SOUTH, RED);
    }
    
    // If the north-south light is red and has been red for 10 seconds, change it to green
    if (northSouthState == RED && timeElapsed % 20 == 0) {
      changeTrafficLightState(NORTH_SOUTH, GREEN);
    }
    
    // If the east-west light is red and has been red for 10 seconds, change it to green
    if (eastWestState == RED && timeElapsed % 20 == 10) {
      changeTrafficLightState(EAST_WEST, GREEN);
    }
    
    // If the east-west light is green and has been green for 10 seconds, change it to yellow
    if (eastWestState == GREEN && timeElapsed % 20 == 0) {
      changeTrafficLightState(EAST_WEST, YELLOW);
    }
    
    // If the east-west light is yellow and has been yellow for 3 seconds, change it to red
    if (eastWestState == YELLOW && timeElapsed % 20 == 3) {
      changeTrafficLightState(EAST_WEST, RED);
    }
    
    // Wait for one second
    sleep(1);
  }
  
  return 0;
}

// Function to print the current state of a traffic light
void printTrafficLightState(lightDirection direction, lightState state) {
  printf("%s light is ", (direction == NORTH_SOUTH) ? "North-South" : "East-West");
  switch (state) {
    case RED:
      printf("red.\n");
      break;
    case YELLOW:
      printf("yellow.\n");
      break;
    case GREEN:
      printf("green.\n");
      break;
  }
}

// Function to change the state of a traffic light
void changeTrafficLightState(lightDirection direction, lightState newState) {
  
  // Print the old and new states of the traffic light
  switch (direction) {
    case NORTH_SOUTH:
      printTrafficLightState(NORTH_SOUTH, northSouthState);
      printf("Changing to ");
      printTrafficLightState(NORTH_SOUTH, newState);
      northSouthState = newState;
      break;
    case EAST_WEST:
      printTrafficLightState(EAST_WEST, eastWestState);
      printf("Changing to ");
      printTrafficLightState(EAST_WEST, newState);
      eastWestState = newState;
      break;
  }
}