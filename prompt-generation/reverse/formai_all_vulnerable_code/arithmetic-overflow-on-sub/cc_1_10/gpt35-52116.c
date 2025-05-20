//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Setup random
  srand(time(NULL));

  // Variables
  int year = 2021;
  int timeMachineHealth = 100;
  int timeTravelYear;
  int i;

  // Introduction
  printf("Welcome to the Time Travel Simulator\n");
  printf("Your mission is to travel to the past and save the future\n");
  printf("Your time machine currently has 100 health\n");
  printf("You will be sent to a random year between 1900 and 2100\n");
  
  // Main game loop
  while (timeMachineHealth > 0) {
    // Get user input
    printf("\nEnter the year you want to travel to: ");
    scanf("%d", &timeTravelYear);

    // Calculate travel time
    int travelTime = abs(year - timeTravelYear);

    // Check if time travel is possible
    if (travelTime <= 100) {
      // Calculate time machine damage
      int damage = rand() % travelTime;

      // Update time machine health
      timeMachineHealth -= damage;

      // Update current year
      year = timeTravelYear;

      // Display result
      printf("\nYou successfully traveled to %d\n", year);
      printf("Your time machine took %d damage\n", damage);
      printf("Your time machine has %d health remaining\n", timeMachineHealth);
    } else {
      printf("\nTime travel to that year is not possible\n");
      printf("The time difference is too great\n");
    }

    // Check if game is over
    if (year == 2020 && timeMachineHealth > 0) {
      printf("\nCongratulations! You saved the future!\n");
      break;
    } else if (timeMachineHealth <= 0) {
      printf("\nYour time machine has been destroyed\n");
      printf("Game Over\n");
      break;
    }
  }

  return 0;
}