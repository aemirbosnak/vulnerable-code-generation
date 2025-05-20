//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Time Travel Simulator!\n\n");

  // initialize random seed
  srand(time(NULL));

  // user input
  int start_year, end_year;
  printf("Enter the starting year: ");
  scanf("%d", &start_year);
  printf("Enter the ending year: ");
  scanf("%d", &end_year);
  printf("\n");

  // check input validity
  if (end_year < start_year) {
    printf("Error: Ending year cannot be before starting year.\n");
    return 1;
  }

  // variables for time travel simulation
  int current_year = start_year;
  int time_travel_count = 0;

  // time travel loop
  while (current_year <= end_year) {
    printf("Year: %d\n", current_year);

    // simulate a time jump
    int time_jump = rand() % 10 + 1;
    printf("Time jump: %d year(s)\n", time_jump);

    // update current year after time jump
    current_year += time_jump;

    // update time travel count
    time_travel_count++;

    // prompt user for input
    char user_input;
    printf("Do you want to continue time traveling? (y/n) ");
    scanf(" %c", &user_input);
    printf("\n");

    // check if user wants to continue time traveling
    if (user_input == 'n') {
      printf("You traveled through time %d time(s)!\n", time_travel_count);
      printf("You ended your time travel journey in year %d.\n", current_year);
      printf("Thanks for using the Time Travel Simulator!\n");

      return 0;
    }
  }

  // time travel completed successfully
  printf("You traveled through time %d time(s)!\n", time_travel_count);
  printf("You successfully completed your time travel journey in year %d.\n", current_year);
  printf("Thanks for using the Time Travel Simulator!\n");

  return 0;
}