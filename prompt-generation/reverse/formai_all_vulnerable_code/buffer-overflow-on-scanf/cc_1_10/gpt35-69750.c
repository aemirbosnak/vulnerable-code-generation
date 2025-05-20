//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random year
int generateRandomYear() {
  int startYear = 1900;
  int endYear = 2100;
  return (rand() % (endYear - startYear + 1)) + startYear;
}

int main() {
  // Seed the random number generator with the current time
  srand(time(NULL));
  
  // Get the user's desired year to travel to
  int desiredYear;
  printf("Welcome to the Happy Time Travel Simulator! What year do you want to travel to? ");
  scanf("%d", &desiredYear);

  // Check if the desired year is valid
  if (desiredYear < 1900 || desiredYear > 2100) {
    printf("Sorry, that's an invalid year. Please try again.\n");
    return 0;
  }

  // Calculate the number of years between the current year and the desired year
  int currentYear = 2021;
  int yearsToTravel = desiredYear - currentYear;

  // Print a message to the user
  printf("Great choice! You're traveling %d years into the %s.\n", abs(yearsToTravel), yearsToTravel < 0 ? "past" : "future");

  // Loop through each year to simulate time travel
  for (int i = 0; i < abs(yearsToTravel); i++) {
    // Generate a random year to travel to
    int randomYear = generateRandomYear();
    
    // Update the current year
    currentYear += yearsToTravel < 0 ? -1 : 1;

    // Print a message to the user
    printf("You have arrived in %d. Let's see what's happening...\n", currentYear);

    // Simulate some events
    if (currentYear == randomYear) {
      printf("Wow, it's your lucky year! You just won the lottery!\n");
    } else if (currentYear % 4 == 0) {
      printf("Happy Leap Year! Enjoy an extra day this year!\n");
    } else if (currentYear % 10 == 0) {
      printf("It's a milestone year! Celebrate with cake and balloons!\n");
    } else {
      printf("Nothing exciting seems to be happening this year...\n");
    }
  }

  // Print a final message to the user
  printf("Congratulations! You have successfully traveled through time and arrived in %d!\n", currentYear);

  // Exit the program
  return 0;
}