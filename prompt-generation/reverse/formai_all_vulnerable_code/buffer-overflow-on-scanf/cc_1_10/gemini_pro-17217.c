//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the light switch states
#define OFF 0
#define ON 1

// Create a global variable to store the current light switch state
int lightState = OFF;

// Define the function to turn the light on
void turnOn() {
  // Set the light switch state to ON
  lightState = ON;

  // Print a funny message to the console
  printf("The light is now on! Time to party like it's 1999!\n");
}

// Define the function to turn the light off
void turnOff() {
  // Set the light switch state to OFF
  lightState = OFF;

  // Print a funny message to the console
  printf("The light is now off. Good night, sweet prince.\n");
}

// Define the main function
int main() {
  // Get the user's input
  printf("What do you want to do?\n");
  printf("1. Turn the light on\n");
  printf("2. Turn the light off\n");

  int choice;
  scanf("%d", &choice);

  // Call the appropriate function based on the user's input
  switch (choice) {
    case 1:
      turnOn();
      break;
    case 2:
      turnOff();
      break;
    default:
      printf("Invalid choice. Please try again.\n");
  }

  return 0;
}