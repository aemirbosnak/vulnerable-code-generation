//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t curr_time;
  time(&curr_time);
  struct tm *local_time = localtime(&curr_time);

  int current_year = local_time->tm_year + 1900;
  int current_month = local_time->tm_mon + 1;
  int current_day = local_time->tm_mday;

  printf("Welcome to the Time Travel Simulator!\n");

  // Get user input for year to travel to
  printf("Enter a year to travel to (between 1800 and %d): ", current_year);
  int year_choice;
  scanf("%d", &year_choice);

  if (year_choice < 1800 || year_choice > current_year) {
    printf("Invalid year choice. Please try again.\n");
    return 0;
  }

  // Calculate number of years to travel
  int years_to_travel = year_choice - current_year;

  // Calculate random day and month to travel to
  srand(time(NULL));
  int random_month = rand() % 12 + 1;
  int random_day;
  switch (random_month) {
    case 2:
      // Leap year calculation
      if (year_choice % 4 == 0 && (year_choice % 100 != 0 || year_choice % 400 == 0)) {
        random_day = rand() % 29 + 1;
      } else {
        random_day = rand() % 28 + 1;
      }
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      random_day = rand() % 30 + 1;
      break;
    default:
      random_day = rand() % 31 + 1;
  }

  // Calculate new date
  int new_year = current_year + years_to_travel;
  int new_month = random_month;
  int new_day = random_day;

  printf("\nTraveling to %d/%d/%d...\n", new_month, new_day, new_year);

  // Travel animation
  for (int i = 0; i < 5; i++) {
    printf(".");
    fflush(stdout);
    sleep(1);
  }

  printf("\nYou have arrived at %d/%d/%d!\n", new_month, new_day, new_year);

  return 0;
}