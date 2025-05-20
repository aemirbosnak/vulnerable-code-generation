//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed the random number generator using the current system time
  srand(time(NULL));

  // Prompt the user to enter a year
  printf("Enter a year to travel to: ");
  int year;
  scanf("%d", &year);

  // Check if the user entered a valid year
  if (year < 0 || year > 9999) {
    printf("Invalid year. Please enter a year between 0 and 9999.\n");
    return 0;
  }

  // Travel to the specified year
  printf("Traveling to %d...\n\n", year);

  // Simulate the passage of time
  for (int i = 0; i < 10; i++) {
    printf("Year %d\n", year + i);

    // Generate a random event
    int event = rand() % 3;

    switch (event) {
      case 0:
        printf("Nothing of note happened.\n\n");
        break;
      case 1:
        printf("A major war broke out.\n\n");
        break;
      case 2:
        printf("A new technology was invented.\n\n");
        break;
    }

    // Sleep for one second to simulate the passage of time
    sleep(1);
  }

  // Return to the present day
  printf("Returning to the present day...\n");

  return 0;
}