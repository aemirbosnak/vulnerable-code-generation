//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define states of the traffic light
typedef enum {
  GREEN,
  YELLOW,
  RED
} State;

// Define struct for the traffic light
typedef struct {
  State state;         // Current state of the traffic light
  int timeRemaining;   // Time remaining in the current state
} TrafficLight;

// Function to update the traffic light's state and time remaining
void updateTrafficLight(TrafficLight* tl) {
  switch (tl->state) {
    case GREEN:
      tl->timeRemaining = rand() % 6 + 15;   // Random time between 15-20s
      tl->state = YELLOW;                    // Change to yellow state
      break;
    case YELLOW:
      tl->timeRemaining = rand() % 3 + 3;    // Random time between 3-5s
      tl->state = RED;                       // Change to red state
      break;
    case RED:
      tl->timeRemaining = rand() % 6 + 25;   // Random time between 25-30s
      tl->state = GREEN;                     // Change to green state
      break;
  }
}

int main() {
  // Initialize variables
  TrafficLight northSouth;
  TrafficLight eastWest;
  srand(time(NULL));    // Seed random number generator
  northSouth.state = GREEN;
  eastWest.state = RED;
  
  // Loop to simulate traffic light changing states
  for (int i = 0; i < 10; i++) {
    printf("North/South: %d seconds %s\n", northSouth.timeRemaining, northSouth.state == GREEN ? "GREEN" : northSouth.state == YELLOW ? "YELLOW" : "RED");
    printf("East/West: %d seconds %s\n", eastWest.timeRemaining, eastWest.state == GREEN ? "GREEN" : eastWest.state == YELLOW ? "YELLOW" : "RED");
    
    // Update time remaining for each traffic light
    northSouth.timeRemaining--;
    eastWest.timeRemaining--;
    
    // Check if time remaining has reached 0 and update state
    if (northSouth.timeRemaining == 0) {
      updateTrafficLight(&northSouth);
    }
    if (eastWest.timeRemaining == 0) {
      updateTrafficLight(&eastWest);
    }
    
    printf("\n");   // Print blank line for readability
  }
  
  return 0;
}