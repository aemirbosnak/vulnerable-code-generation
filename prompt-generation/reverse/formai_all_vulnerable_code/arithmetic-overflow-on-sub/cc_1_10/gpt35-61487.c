//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // initialize random seed
  srand(time(NULL));

  // set up time variables
  int presentYear = 2022;
  int presentMonth = 7;
  int presentDay = 14;
  int presentDayOfWeek = 3; // Wednesday
  int presentHour = 12;
  int presentMinute = 0;

  int travelYear;
  int travelMonth;
  int travelDay;
  int travelDayOfWeek;
  int travelHour;
  int travelMinute;

  // ask the user for a year to travel to
  printf("Enter the year you want to travel to: ");
  scanf("%d", &travelYear);

  // check if the year entered is in the past or future
  if (travelYear < presentYear) {
    printf("You can't travel back in time!\n");
    return 0;
  } else if (travelYear == presentYear) {
    // if the year is the same, ask for the month and day
    printf("Enter the month you want to travel to: ");
    scanf("%d", &travelMonth);

    printf("Enter the day you want to travel to: ");
    scanf("%d", &travelDay);

    // check if the date entered is in the past or future
    if (travelMonth < presentMonth || (travelMonth == presentMonth && travelDay < presentDay)) {
      printf("You can't travel back in time!\n");
      return 0;
    }

    // set the travel date and time
    travelDayOfWeek = (presentDayOfWeek + (travelDay - presentDay)) % 7;
    travelHour = rand() % 24;
    travelMinute = rand() % 60;

    printf("You have traveled to %d/%d/%d, %02d:%02d.\n", travelMonth, travelDay, travelYear, travelHour, travelMinute);
  } else {
    // if the year is in the future, set the travel date and time to the same day
    travelMonth = presentMonth;
    travelDay = presentDay;
    travelDayOfWeek = presentDayOfWeek;
    travelHour = rand() % 24;
    travelMinute = rand() % 60;

    printf("You have traveled to %d/%d/%d, %02d:%02d.\n", travelMonth, travelDay, travelYear, travelHour, travelMinute);
  }

  return 0;
}