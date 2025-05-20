//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Smart home automation system variables
int lights_on = 0;
int fans_on = 0;
int ac_on = 0;

// Function to turn on the lights
void turn_on_lights() {
  if (lights_on == 0) {
    printf("Turning on the lights!\n");
    lights_on = 1;
  } else {
    printf("Lights are already on!\n");
  }
}

// Function to turn off the lights
void turn_off_lights() {
  if (lights_on == 1) {
    printf("Turning off the lights!\n");
    lights_on = 0;
  } else {
    printf("Lights are already off!\n");
  }
}

// Function to turn on the fans
void turn_on_fans() {
  if (fans_on == 0) {
    printf("Turning on the fans!\n");
    fans_on = 1;
  } else {
    printf("Fans are already on!\n");
  }
}

// Function to turn off the fans
void turn_off_fans() {
  if (fans_on == 1) {
    printf("Turning off the fans!\n");
    fans_on = 0;
  } else {
    printf("Fans are already off!\n");
  }
}

// Function to turn on the AC
void turn_on_ac() {
  if (ac_on == 0) {
    printf("Turning on the AC!\n");
    ac_on = 1;
  } else {
    printf("AC is already on!\n");
  }
}

// Function to turn off the AC
void turn_off_ac() {
  if (ac_on == 1) {
    printf("Turning off the AC!\n");
    ac_on = 0;
  } else {
    printf("AC is already off!\n");
  }
}

// Main function
int main() {
  // Get the user input
  char input[100];
  printf("Enter a command: ");
  gets(input);

  // Process the user input
  if (strcmp(input, "turn on lights") == 0) {
    turn_on_lights();
  } else if (strcmp(input, "turn off lights") == 0) {
    turn_off_lights();
  } else if (strcmp(input, "turn on fans") == 0) {
    turn_on_fans();
  } else if (strcmp(input, "turn off fans") == 0) {
    turn_off_fans();
  } else if (strcmp(input, "turn on ac") == 0) {
    turn_on_ac();
  } else if (strcmp(input, "turn off ac") == 0) {
    turn_off_ac();
  } else {
    printf("Invalid command!\n");
  }

  return 0;
}