//FormAI DATASET v1.0 Category: Smart home automation ; Style: energetic
#include <stdio.h>

int main() {
  /* Starting Smart Home Automation Program */

  // Initializing variables
  int temperature = 25; // in Celsius
  int lights = 0; // 0 for off, 1 for on
  int securityEnabled = 0; // 0 for off, 1 for on
  int windowsOpen = 0; // 0 for closed, 1 for open

  // Welcome message
  printf("Welcome Home! ");

  // Main loop
  while(1) {

    // Read temperature
    printf("The current temperature is %dC. ", temperature);

    // Check if it's too hot or too cold
    if(temperature > 30) {
      printf("It's too hot in here! Turning on the air conditioner. ");
    } else if(temperature < 20) {
      printf("It's too cold in here! Turning on the heater. ");
    }

    // Read lights status
    if(lights) {
      printf("The lights are currently on. ");
    } else {
      printf("The lights are currently off. ");
    }

    // Check if lights should be turned on/off
    if(temperature < 18 && !lights) {
      lights = 1;
      printf("It's getting dark in here! Turning on the lights. ");
    } else if (temperature >= 20 && lights) {
      lights = 0;
      printf("It's getting bright in here! Turning off the lights. ");
    }

    // Read security status
    if(securityEnabled) {
      printf("The security system is currently on. ");
    } else {
      printf("The security system is currently off. ");
    }

    // Check if security system should be turned on/off
    if(windowsOpen) {
      securityEnabled = 1;
      printf("The windows are open! Turning on the security system. ");
    } else {
      securityEnabled = 0;
      printf("All windows are closed. Turning off the security system. ");
    }

    // Read user input
    char userInput;
    printf("Enter 'C' to close the windows, 'O' to open the windows, or 'Q' to quit: ");
    scanf(" %c", &userInput);

    // Process user input
    if(userInput == 'C') {
      windowsOpen = 0;
    } else if(userInput == 'O') {
      windowsOpen = 1;
    } else if(userInput == 'Q') {
      break; // Exit program
    }
  }

  // Exit message
  printf("Goodbye! See you soon.");
  return 0;
}