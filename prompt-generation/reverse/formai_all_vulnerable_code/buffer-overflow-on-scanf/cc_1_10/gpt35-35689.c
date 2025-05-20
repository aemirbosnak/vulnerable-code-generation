//FormAI DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Declare global variables
int lights = 0;
int ac = 0;
int heater = 0;

// function declarations
void toggleLights();
void toggleAC();
void toggleHeater();

// Main function
int main () {
  // Welcome message
  printf("Welcome to Smart Home Automation!\n");

  // Loop until user exits
  while(1) {
    // Options menu
    printf("Please select an option:\n");
    printf("1. Toggle Lights\n");
    printf("2. Toggle AC\n");
    printf("3. Toggle Heater\n");
    printf("4. Exit\n");

    // User input
    int option;
    scanf("%d", &option);

    // Toggle lights
    if (option == 1) {
      toggleLights();
    }
    // Toggle AC
    else if (option == 2) {
      toggleAC();
    }
    // Toggle heater
    else if (option == 3) {
      toggleHeater();
    }
    // Exit program
    else if (option == 4) {
      printf("Goodbye! Thanks for using Smart Home Automation.\n");
      exit(0);
    }
    // Invalid input
    else {
      printf("Invalid option! Please try again.\n");
    }
  }
  return 0;
}

// Function to toggle lights
void toggleLights() {
  if(lights == 0) {
    printf("Turning on lights...\n");
    lights = 1;
  }else {
    printf("Turning off lights...\n");
    lights = 0;
  }
}

// Function to toggle AC
void toggleAC() {
  if(ac == 0) {
    printf("Turning on AC...\n");
    ac = 1;
  }else {
    printf("Turning off AC...\n");
    ac = 0;
  }
}

// Function to toggle heater
void toggleHeater() {
  if(heater == 0) {
    printf("Turning on heater...\n");
    heater = 1;
  }else {
    printf("Turning off heater...\n");
    heater = 0;
  }
}