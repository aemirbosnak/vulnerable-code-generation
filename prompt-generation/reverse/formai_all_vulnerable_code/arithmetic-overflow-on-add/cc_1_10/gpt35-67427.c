//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to delay execution for a given number of milliseconds
void delay(int milliseconds) {
  int start_time = clock();
  while (clock() < start_time + milliseconds);
}

int main() {
  // Initialize random seed
  srand((unsigned) time(NULL));
  
  // Initialize variables
  int green_time, yellow_time, red_time, cycle_time, time_elapsed;
  char state = 'R'; // Start in red state
  printf("Traffic light program starting...\n\n");
  
  // Run the program indefinitely
  while (1) {
    // Set the cycle time randomly between 60 and 120 seconds
    cycle_time = rand() % 60 + 60;
    printf("Cycle time: %d seconds\n", cycle_time);
    
    // Set the green, yellow, and red times based on the cycle time
    green_time = cycle_time * 0.4;
    yellow_time = cycle_time * 0.2;
    red_time = cycle_time * 0.4;
    
    // Print the current state of the traffic light
    printf("\nCurrent state: ");
    if (state == 'G') {
      printf("Green\n");
    } else if (state == 'Y') {
      printf("Yellow\n");
    } else {
      printf("Red\n");
    }
    
    // Run the traffic light cycle
    for (time_elapsed = 0; time_elapsed < cycle_time; time_elapsed++) {
      // Change to yellow state from green
      if (state == 'G' && time_elapsed == green_time) {
        printf("Changing state from Green to Yellow\n");
        state = 'Y';
      }
      // Change to red state from yellow
      if (state == 'Y' && time_elapsed == green_time + yellow_time) {
        printf("Changing state from Yellow to Red\n");
        state = 'R';
      }
      // Change to green state from red
      if (state == 'R' && time_elapsed == 0) {
        printf("Changing state from Red to Green\n");
        state = 'G';
      }
      
      // Delay for 1 second at each time interval
      delay(1000);
    }
  }
  
  return 0;
}