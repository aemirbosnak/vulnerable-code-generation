//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int present_year, future_year, past_year, choice, num_years;

  srand(time(NULL)); // for random year selection

  printf("Welcome to the Time Travel Simulator!\n");

  // get present year from computer
  time_t t = time(NULL);
  struct tm *local_time = localtime(&t);
  present_year = local_time->tm_year + 1900;

  printf("You are currently in the year %d.\n", present_year);

  // offer options for time travel
  printf("\nEnter 1 to travel to a future year.\nEnter 2 to travel to a past year.\nEnter 3 to exit.\n");

  scanf("%d", &choice);

  while (choice != 3) {
    switch (choice) {
      case 1: // travel to future
        printf("\nHow many years into the future would you like to go?\n");
        scanf("%d", &num_years);

        future_year = present_year + num_years;

        printf("\nYou have traveled to the year %d!\n", future_year);
        break;

      case 2: // travel to past
        printf("\nHow many years into the past would you like to go?\n");
        scanf("%d", &num_years);

        past_year = present_year - num_years;

        printf("\nYou have traveled to the year %d!\n", past_year);
        break;

      default:
        printf("\nInvalid input. Please try again.\n");
        break;
    }

    // offer options for time travel again
    printf("\nEnter 1 to travel to a future year.\nEnter 2 to travel to a past year.\nEnter 3 to exit.\n");
    scanf("%d", &choice);
  }

  printf("\nThank you for using the Time Travel Simulator!\n");

  return 0;
}