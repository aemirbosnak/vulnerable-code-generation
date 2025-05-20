//Code Llama-13B DATASET v1.0 Category: Smart home light control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to control the light
void light_control(int state) {
  if (state == 1) {
    printf("Light is on.\n");
  } else if (state == 0) {
    printf("Light is off.\n");
  } else {
    printf("Invalid light state.\n");
  }
}

// Recursive function to turn on the light
void turn_on_light(int state) {
  if (state == 1) {
    light_control(1);
  } else if (state == 0) {
    light_control(1);
    turn_on_light(1);
  } else {
    printf("Invalid light state.\n");
  }
}

// Recursive function to turn off the light
void turn_off_light(int state) {
  if (state == 1) {
    light_control(0);
  } else if (state == 0) {
    light_control(0);
  } else {
    printf("Invalid light state.\n");
  }
}

int main() {
  int state = 0;
  printf("Enter the light state (0 or 1): ");
  scanf("%d", &state);

  if (state == 1) {
    turn_on_light(state);
  } else if (state == 0) {
    turn_off_light(state);
  } else {
    printf("Invalid light state.\n");
  }

  return 0;
}