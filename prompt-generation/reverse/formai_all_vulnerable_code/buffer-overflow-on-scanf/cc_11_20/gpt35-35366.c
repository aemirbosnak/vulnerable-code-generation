//FormAI DATASET v1.0 Category: Smart home automation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Welcome to Smart Home Automation
  printf("Welcome to Smart Home Automation!\n");

  // Declaring variables
  int temp, motion, light;
  int temp_up = 0, temp_down = 0;
  int motion_detected = 0;
  int light_off_time = 0;
  int ac_on = 0;
  int light_on = 0;

  // Set initial values
  temp = 25;
  motion = 0;
  light = 0;

  // Start the loop
  while (1) {
    // Read temperature sensor
    printf("Temperature: ");
    scanf("%d", &temp);

    // Check if temperature needs adjustment
    if (temp > 26) {
      temp_down = 0;
      temp_up++;
    } else if (temp < 24) {
      temp_up = 0;
      temp_down++;
    } else {
      temp_up = 0;
      temp_down = 0;
    }

    // Adjust temperature
    if (temp_up >= 3 && !ac_on) {
      printf("Turning on the AC.\n");
      ac_on = 1;
    } else if (temp_down >= 3 && ac_on) {
      printf("Turning off the AC.\n");
      ac_on = 0;
    }

    // Read motion sensor
    printf("Motion: ");
    scanf("%d", &motion);

    // Check if motion detected
    if (motion && !motion_detected) {
      printf("Motion detected.\n");
      motion_detected = 1;
    } else if (!motion && motion_detected) {
      printf("Motion stopped.\n");
      motion_detected = 0;
    }

    // Adjust light
    if (motion_detected) {
      light_on = 1;
      light_off_time = 0;
    } else if (light_on && light_off_time >= 10) {
      printf("Turning off the light.\n");
      light_on = 0;
    } else {
      light_off_time++;
    }

    // Print status
    printf("AC: %s, Light: %s\n", ac_on ? "on" : "off", light_on ? "on" : "off");
  }

  return 0;
}