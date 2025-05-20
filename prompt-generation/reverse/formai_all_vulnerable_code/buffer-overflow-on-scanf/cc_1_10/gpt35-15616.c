//FormAI DATASET v1.0 Category: Smart home automation ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>

// Defining a struct to represent the state of different devices
typedef struct {
  bool lightOn;
  bool fanOn;
  bool tvOn;
  bool acOn;
} HomeState;

// Function to print the current state of the home
void printState(HomeState state) {
  printf("Current Home State:\n");
  printf("Light: %s\n", state.lightOn ? "ON" : "OFF");
  printf("Fan: %s\n", state.fanOn ? "ON" : "OFF");
  printf("TV: %s\n", state.tvOn ? "ON" : "OFF");
  printf("AC: %s\n", state.acOn ? "ON" : "OFF");
  printf("\n");
}

int main() {
  HomeState state = {false, false, false, false};  // Initial home state
  char input;  // Variable to store user input

  // Loop to keep asking for input and updating home state
  while(true) {
    printState(state);  // Print current state of home

    // Ask for user input
    printf("What would you like to do?\n");
    printf("L: Toggle Light\n");
    printf("F: Toggle Fan\n");
    printf("T: Toggle TV\n");
    printf("A: Toggle AC\n");
    printf("Q: Quit\n");
    scanf(" %c", &input);

    switch(input) {
      case 'L':
        state.lightOn = !state.lightOn;  // Toggle light state
        break;
      case 'F':
        state.fanOn = !state.fanOn;  // Toggle fan state
        break;
      case 'T':
        state.tvOn = !state.tvOn;  // Toggle TV state
        break;
      case 'A':
        state.acOn = !state.acOn;  // Toggle AC state
        break;
      case 'Q':
        printf("Goodbye!\n");
        return 0;
        break;
      default:
        printf("Invalid option. Please try again.\n");
        break;
    }
  }
}