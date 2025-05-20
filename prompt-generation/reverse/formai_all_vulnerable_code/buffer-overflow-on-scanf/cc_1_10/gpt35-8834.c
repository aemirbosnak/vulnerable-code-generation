//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int year;
  printf("Welcome to Time Travel Simulator\n");
  printf("Please enter the year you want to travel to (1000 - 9999): ");
  scanf("%d", &year);

  if(year < 1000 || year > 9999) {
    printf("Invalid year entered.");
    return 1;
  }

  printf("You have selected the year %d.\n", year);
  printf("Are you ready to begin your journey? (Y/N): ");
  char answer;
  scanf(" %c", &answer);

  if(answer == 'Y' || answer == 'y') {
    printf("Starting Time Travel Engine...\n");
    printf("Initializing Time Coordinates...\n");
    printf("Adjusting Time Flux Capacitor...\n");
    printf("Engaging Temporal Displacement...\n");
    printf("Success! You have arrived in the year %d!\n", year);
  } else {
    printf("Time travel aborted. Goodbye!");
    return 0;
  }

  // Here you can add more code to simulate life in the chosen year.

  printf("You have successfully traveled to the year %d.\n", year);

  // Complete the time travel loop
  printf("Do you want to travel back to the present time? (Y/N): ");
  scanf(" %c", &answer);

  if(answer == 'Y' || answer == 'y') {
    printf("Starting Time Travel Engine...\n");
    printf("Initializing Time Coordinates...\n");
    printf("Adjusting Time Flux Capacitor...\n");
    printf("Engaging Temporal Displacement...\n");
    printf("Success! You have arrived back to the present time!\n");
  } else {
    printf("Thank you for using Time Travel Simulator!\n");
  }

  return 0;
}