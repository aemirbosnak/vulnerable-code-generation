//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Dice rolling function
int roll_dice(int sides) {
  srand(time(NULL));  // Seed the random number generator
  return rand() % sides + 1;  // Generate a random number between 1 and the number of sides
}

// Main function
int main() {
  // Variables
  int sides = 0;        // Number of sides on the dice
  int rolls = 0;        // Number of rolls to perform
  char command[100];  // Input command

  // Get input from the user
  printf("Welcome to the dice roller!\n");
  printf("Enter the number of sides on the dice: ");
  scanf("%d", &sides);
  printf("Enter the number of rolls to perform: ");
  scanf("%d", &rolls);

  // Check if the input is valid
  if (sides < 1 || rolls < 1) {
    printf("Invalid input. Please enter a positive integer for both the number of sides and the number of rolls.\n");
    return 1;
  }

  // Roll the dice the specified number of times
  for (int i = 0; i < rolls; i++) {
    int result = roll_dice(sides);
    printf("Roll %d: %d\n", i + 1, result);
  }

  // Calculate statistics
  float average = 0;
  float stdev = 0;
  for (int i = 0; i < rolls; i++) {
    int result = roll_dice(sides);
    average += result;
    stdev += result * result;
  }
  average /= rolls;
  stdev = sqrt(stdev / rolls - average * average);

  // Print statistics
  printf("\nStatistics:\n");
  printf("Average: %.2f\n", average);
  printf("Standard deviation: %.2f\n", stdev);

  // Get another command from the user
  printf("\nEnter another command (roll, quit, or help): ");
  scanf("%s", command);

  // Handle the command
  while (strcmp(command, "quit") != 0) {
    if (strcmp(command, "roll") == 0) {
      // Roll the dice again
      int result = roll_dice(sides);
      printf("Roll: %d\n", result);
    } else if (strcmp(command, "help") == 0) {
      // Display help message
      printf("Commands:\n");
      printf("roll: Roll the dice\n");
      printf("quit: Quit the program\n");
      printf("help: Display this help message\n");
    } else {
      // Invalid command
      printf("Invalid command. Please enter a valid command (roll, quit, or help).\n");
    }

    // Get another command from the user
    printf("\nEnter another command (roll, quit, or help): ");
    scanf("%s", command);
  }

  // Quit the program
  printf("Goodbye!\n");
  return 0;
}