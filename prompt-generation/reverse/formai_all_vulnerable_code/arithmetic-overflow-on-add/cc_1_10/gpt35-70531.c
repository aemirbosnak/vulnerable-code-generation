//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// Define the different possible states for the traffic light
typedef enum States {
  GREEN,
  YELLOW,
  RED
} State;

// Function to delay the execution of the program
void delay(int seconds) {
  int milli_seconds = 1000 * seconds;
  clock_t start_time = clock();
  while (clock() < start_time + milli_seconds) {}
}

// Main function
int main() {
  // Initialize the state to green
  State state = GREEN;

  // Infinite loop to keep the program running
  while (1) {
    switch (state) {
      case GREEN:
        printf("Green light is on.\n");
        // Wait for 10 seconds
        delay(10);

        // Change state to yellow
        state = YELLOW;
        break;
  
      case YELLOW:
        printf("Yellow light is on.\n");
        // Wait for 3 seconds
        delay(3);

        // Change state to red
        state = RED;
        break;

      case RED:
        printf("Red light is on.\n");
        // Wait for 8 seconds
        delay(8);

        // Change state to green
        state = GREEN;
        break;
    }
  }
  return 0;
}