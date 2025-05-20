//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize the traffic light variables
  int greenLight = 0;
  int yellowLight = 0;
  int redLight = 1;

  // Set the timer for the traffic lights
  clock_t start = clock();
  int timer = 0;

  // Start the traffic light loop
  while (timer < 30) { // 30 seconds of traffic lights

    // Print the current state of the traffic lights
    if (greenLight == 1) {
      printf("Green Light: ON\n");
      printf("Yellow Light: OFF\n");
      printf("Red Light: OFF\n");
    } else if (yellowLight == 1) {
      printf("Green Light: OFF\n");
      printf("Yellow Light: ON\n");
      printf("Red Light: OFF\n");
    } else {
      printf("Green Light: OFF\n");
      printf("Yellow Light: OFF\n");
      printf("Red Light: ON\n");
    }

    // Check if the timer has reached the time for the next light change
    if ((clock() - start) / CLOCKS_PER_SEC >= 5 && greenLight == 1) { // Green to yellow
      greenLight = 0;
      yellowLight = 1;
      redLight = 0;
      start = clock(); // Reset the timer
    } else if ((clock() - start) / CLOCKS_PER_SEC >= 3 && yellowLight == 1) { // Yellow to red
      greenLight = 0;
      yellowLight = 0;
      redLight = 1;
      start = clock(); // Reset the timer
    } else if ((clock() - start) / CLOCKS_PER_SEC >= 7 && redLight == 1) { // Red to green
      greenLight = 1;
      yellowLight = 0;
      redLight = 0;
      start = clock(); // Reset the timer
    }

    // Wait for 1 second before looping again
    timer = (clock() - start) / CLOCKS_PER_SEC;
    sleep(1);
  }

  return 0;
}