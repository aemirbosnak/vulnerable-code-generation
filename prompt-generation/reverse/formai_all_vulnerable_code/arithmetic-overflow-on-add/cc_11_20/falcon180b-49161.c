//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize variables
  int redLightDuration = 30; // in seconds
  int greenLightDuration = 30; // in seconds
  int yellowLightDuration = 5; // in seconds
  int currentLight = 0; // 0 for red, 1 for green, 2 for yellow
  int currentState = 0; // 0 for stop, 1 for go
  int countdown = 0; // countdown timer for yellow light
  time_t startTime; // start time for countdown timer
  time_t endTime; // end time for countdown timer
  char *lightState[] = {"red", "green", "yellow"}; // array of light states
  printf("Traffic Light Controller\n");
  
  // Set initial light to red
  currentLight = 0;
  currentState = 0;
  
  // Start countdown timer for yellow light
  startTime = time(NULL);
  endTime = startTime + yellowLightDuration;
  
  // Main loop
  while(1) {
    printf("Current light: %s\n", lightState[currentLight]);
    if(currentState == 0) {
      printf("Current state: Stop\n");
    } else {
      printf("Current state: Go\n");
    }
    
    // Check if countdown timer has expired
    if(difftime(time(NULL), startTime) >= yellowLightDuration) {
      printf("Yellow light expired, switching to red\n");
      currentLight = 0;
      currentState = 0;
      countdown = 0;
      startTime = time(NULL);
      endTime = startTime + yellowLightDuration;
    } else if(countdown == 0) {
      printf("Starting countdown for yellow light\n");
      countdown = 1;
      startTime = time(NULL);
      endTime = startTime + yellowLightDuration;
    } else {
      printf("Countdown for yellow light: %d\n", yellowLightDuration - difftime(time(NULL), startTime));
    }
    
    // Switch to next light
    if(currentLight == 0) {
      currentLight = 1;
    } else if(currentLight == 1) {
      currentLight = 2;
    } else {
      currentLight = 0;
    }
    
    // Wait for duration of current light
    switch(currentLight) {
      case 0:
        sleep(redLightDuration);
        break;
      case 1:
        sleep(greenLightDuration);
        break;
      case 2:
        sleep(yellowLightDuration);
        break;
    }
    
    // Switch to next state
    if(currentState == 0) {
      currentState = 1;
    } else {
      currentState = 0;
    }
  }
  
  return 0;
}