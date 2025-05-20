//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: retro
// ╔═══════════════════════════╗
// ║ Retro Temperature Monitor ║
// ║   by Awesome Tech Inc.   ║
// ║╚═══════════════════════════╝╚

// Libraries needed by this program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayTitle();
void displayMenu();
void getTemperature();
void displayTemperature(float temp);

// Main function
int main() {
  // Display the title
  displayTitle();

  // Display the menu
  displayMenu();

  // Forever loop to keep the program running
  while (1) {
    // Get the user's choice
    char choice;
    scanf(" %c", &choice);

    // Switch on the user's choice
    switch (choice) {
      case '1':  // Get the temperature
        getTemperature();
        break;
      case '2':  // Quit the program
        exit(0);
      default:  // Invalid choice, display the menu again
        displayMenu();
    }
  }

  return 0;
}

// Display the title
void displayTitle() {
  printf("*************************************************\n");
  printf("*                                                 *\n");
  printf("*        Retro Temperature Monitor                *\n");
  printf("*                                                 *\n");
  printf("*************************************************\n\n");
}

// Display the menu
void displayMenu() {
  printf("Please select an option:\n");
  printf("1. Get the temperature\n");
  printf("2. Quit\n");
}

// Get the temperature
void getTemperature() {
  // Initialize the random number generator
  srand(time(NULL));

  // Get a random temperature between 0 and 100
  float temp = (float) (rand() % 101);

  // Display the temperature
  displayTemperature(temp);
}

// Display the temperature
void displayTemperature(float temp) {
  printf("\nThe current temperature is %.1f degrees Celsius.\n\n", temp);
}