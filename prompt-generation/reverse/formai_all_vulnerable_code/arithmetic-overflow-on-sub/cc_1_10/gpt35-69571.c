//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int year;
  int time_travel_years;
  int current_time;
  int future_time;

  srand(time(0)); // Initializes random number generator based on current time

  printf("Enter the current year: ");
  scanf("%d", &year);

  printf("Enter the number of years you want to time travel: ");
  scanf("%d", &time_travel_years);

  current_time = year - 1900; // Calculates number of years since 1900
  future_time = current_time + time_travel_years; // Calculates the future year

  // Generates a random number representing the likelihood of encountering paradoxes
  int paradox_chance = rand() % 101;

  printf("\nYou have successfully time traveled %d years into the future!\n", time_travel_years);
  printf("Current year: %d\n", year);
  printf("Future year: %d\n", future_time + 1900);

  if (paradox_chance >= 50) { // If the likelihood of encountering paradoxes is greater than or equal to 50%
    printf("Warning: There is a high likelihood of encountering paradoxes!\n");

    // Generates a random number representing the severity of paradoxes
    int paradox_severity = rand() % 101;

    if (paradox_severity >= 75) { // If the severity of paradoxes is greater than or equal to 75%
      printf("Paradoxes encountered!\n");

      // Generates a random number representing the number of paradoxes encountered
      int num_paradoxes = rand() % 4 + 1;

      switch (num_paradoxes) {
        case 1:
          printf("You have encountered a paradox: a T-Rex is now loose in modern day New York City!\n");
          break;
        case 2:
          printf("You have encountered two paradoxes: World War III has broken out and Earth is a wasteland!\n");
          break;
        case 3:
          printf("You have encountered three paradoxes: You are now Emperor of the World!\n");
          break;
        case 4:
          printf("You have encountered four paradoxes: You have become your own grandfather!\n");
          break;
      }
    } else {
      printf("Minor paradoxes encountered. Please proceed with caution.\n");
    }
  } else {
    printf("No paradoxes encountered. Enjoy your stay!\n");
  }

  return 0;
}