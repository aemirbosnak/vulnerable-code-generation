//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50 // maximum length of input strings

int main() {
  char input[MAX_LEN]; // variable to store user input

  int current_speed = 0; // current speed of the vehicle
  int current_direction = 0; // current direction of the vehicle
  int max_speed = 100; // maximum speed of the vehicle

  while (1) {
    printf("Enter a command: ");
    fgets(input, MAX_LEN, stdin); // get user input

    // remove newline character
    if (input[strlen(input)-1] == '\n') {
      input[strlen(input)-1] = '\0';
    }

    if (strcmp(input, "stop") == 0) { // stop the vehicle
      current_speed = 0;
      current_direction = 0;
      printf("Vehicle stopped.\n");
    }
    else if (strcmp(input, "forward") == 0) { // move the vehicle forward
      if (current_speed < max_speed) {
        current_speed += 10;
      }
      current_direction = 0;
      printf("Vehicle moving forward at %d mph.\n", current_speed);
    }
    else if (strcmp(input, "backward") == 0) { // move the vehicle backward
      if (current_speed < max_speed) {
        current_speed += 10;
      }
      current_direction = 180;
      printf("Vehicle moving backward at %d mph.\n", current_speed);
    }
    else if (strcmp(input, "left") == 0) { // turn the vehicle left
      if (current_direction > -90) {
        current_direction -= 10;
      }
      printf("Vehicle turning left to face %d degrees.\n", current_direction);
    }
    else if (strcmp(input, "right") == 0) { // turn the vehicle right
      if (current_direction < 90) {
        current_direction += 10;
      }
      printf("Vehicle turning right to face %d degrees.\n", current_direction);
    }
    else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}