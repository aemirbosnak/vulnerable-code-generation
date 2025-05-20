//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Let's define some constants for our time-traveling adventure.
#define TIME_TRAVEL_MIN_YEAR 1900
#define TIME_TRAVEL_MAX_YEAR 2100
#define TIME_TRAVEL_INCREMENT 10

// Now, let's create a function to generate a random year within our specified range.
int generate_random_year() {
  // We'll use the current time as a seed for our random number generator.
  srand(time(NULL));
  // Now, let's calculate a random year within our specified range.
  int year = rand() % (TIME_TRAVEL_MAX_YEAR - TIME_TRAVEL_MIN_YEAR) + TIME_TRAVEL_MIN_YEAR;
  // And let's round it to the nearest increment.
  year = (year / TIME_TRAVEL_INCREMENT) * TIME_TRAVEL_INCREMENT;
  return year;
}

// Great! Now, let's create a function to simulate our time travel experience.
void simulate_time_travel() {
  // First, let's ask the user for their name.
  char name[50];
  printf("Greetings, time traveler! What is thy name?\n");
  scanf("%s", name);

  // Now, let's ask the user for their destination year.
  int year;
  printf("Where wouldst thou like to travel, %s? (Enter a year between %d and %d)\n", name, TIME_TRAVEL_MIN_YEAR, TIME_TRAVEL_MAX_YEAR);
  scanf("%d", &year);

  // Let's check if the user entered a valid year.
  if (year < TIME_TRAVEL_MIN_YEAR || year > TIME_TRAVEL_MAX_YEAR) {
    printf("Invalid year! Please try again.\n");
    return;
  }

  // Okay, now let's generate a random year within our specified range.
  int random_year = generate_random_year();
  
  // Now, let's display a message to the user, indicating where they will be traveling.
  printf("Prepare thyself, %s! Thou art about to embark on a journey to the year %d.\n", name, random_year);
  
  // And let's simulate the time travel experience by pausing for a few seconds.
  printf("...");
  sleep(2);
  
  // Finally, let's display a message to the user, indicating that they have arrived at their destination.
  printf("Thou hast arrived in the year %d!\n", random_year);

}

// And now, let's create a main function to tie everything together.
int main() {
  // Let's seed the random number generator.
  srand(time(NULL));

  // Now, let's display a welcome message to the user.
  printf("Welcome to the Time Travel Simulator!\n");

  // And let's simulate the time travel experience.
  simulate_time_travel();

  return 0;
}