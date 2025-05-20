//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize random seed
  srand(time(NULL));

  // Declare variables
  int distance = 0;
  int fuel = 100;
  int score = 0;
  int choice;
  int event;

  // Introduction
  printf("Welcome to Procedural Space Adventure!\n");
  printf("You are the captain of a spaceship traveling through the galaxy.\n");
  printf("Your objective is to reach the end of the galaxy without running out of fuel.\n\n");

  // Main game loop
  while (distance < 1000 && fuel > 0) {

    // Print status
    printf("Distance traveled: %d light years\n", distance);
    printf("Fuel remaining: %d units\n\n", fuel);

    // Ask for player choice
    printf("Enter 1 to travel to a nearby planet\n");
    printf("Enter 2 to fly through an asteroid field\n");
    printf("Enter 3 to dock at a space station\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Calculate event
    event = rand() % 3;

    // Update based on player choice
    if (choice == 1) {
      distance += 10;
      fuel -= 5;
      score += 50;
      printf("You traveled to a nearby planet.\n");

      // Check for event
      if (event == 0) {
        fuel += 10;
        printf("You found a fuel deposit!\n");
      }
      else if (event == 1) {
        fuel -= 10;
        printf("You encountered space pirates!\n");
      }
    }
    else if (choice == 2) {
      distance += 20;
      fuel -= 10;
      score += 100;
      printf("You flew through an asteroid field.\n");

      // Check for event
      if (event == 0) {
        fuel += 10;
        printf("You found a fuel deposit!\n");
      }
      else if (event == 1) {
        fuel -= 10;
        printf("You encountered space pirates!\n");
      }
    }
    else if (choice == 3) {
      fuel += 30;
      printf("You docked at a space station.\n");

      // Check for event
      if (event == 0) {
        score += 100;
        printf("You were given a mission to save a planet!\n");
      }
      else if (event == 1) {
        score -= 50;
        printf("You were fined for disrupting space traffic!\n");
      }
    }
    else {
      printf("Invalid choice, try again.\n");
    }
  }

  // Check for game over
  if (distance >= 1000) {
    printf("\nCongratulations, you reached the end of the galaxy!\n");
  }
  else {
    printf("\nGame over, you ran out of fuel.\n");
  }

  // Display final score
  printf("Final score: %d\n", score);

  return 0;
}