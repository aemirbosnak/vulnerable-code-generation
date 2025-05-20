//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: complex
#include <stdio.h>
#include <time.h>

int main() {
  time_t currentTime = time(NULL);
  struct tm *timeDetails = localtime(&currentTime);

  int currentYear = timeDetails->tm_year + 1900;
  int currentMonth = timeDetails->tm_mon + 1;
  int currentDay = timeDetails->tm_mday;

  printf("Welcome to Time Travel Simulator\n");
  printf("Today's Date: %d/%d/%d\n", currentDay, currentMonth, currentYear);

  printf("Enter a year between 1900 and %d: ", currentYear);
  int travelYear;
  scanf("%d", &travelYear);

  if (travelYear < 1900 || travelYear > currentYear) {
    printf("Invalid year entered\n");
    return 0;
  }

  printf("Enter a month (1-12): ");
  int travelMonth;
  scanf("%d", &travelMonth);

  if (travelMonth < 1 || travelMonth > 12) {
    printf("Invalid month entered\n");
    return 0;
  }

  printf("Enter a day (1-31): ");
  int travelDay;
  scanf("%d", &travelDay);

  if (travelDay < 1 || travelDay > 31) {
    printf("Invalid day entered\n");
    return 0;
  }

  int travelSeconds = 0;
  int currentSeconds = timeDetails->tm_sec + (timeDetails->tm_min * 60) + (timeDetails->tm_hour * 3600);

  for (int i = currentYear; i < travelYear; i++) {
    if (i % 4 == 0 || (i % 100 == 0 && i % 400 == 0)) {
      travelSeconds += 31622400; // leap year has 31622400 seconds
    } else {
      travelSeconds += 31536000; // normal year has 31536000 seconds
    }
  }

  int travelMonthSeconds[12] = {2678400, 2419200, 2678400, 2592000, 2678400, 2592000, 2678400, 2678400, 2592000, 2678400, 2592000, 2678400};
  for (int i = 0; i < travelMonth - 1; i++) {
    travelSeconds += travelMonthSeconds[i];
  }

  travelSeconds += (travelDay - 1) * 86400; // each day has 86400 seconds

  if (travelSeconds < currentSeconds) {
    printf("You cannot travel back in time\n");
    return 0;
  }

  printf("Date set to: %d/%d/%d\n", travelDay, travelMonth, travelYear);

  time_t travelTime = currentTime + (travelSeconds - currentSeconds);
  struct tm *travelDetails = localtime(&travelTime);

  printf("Time machine activated...\n");
  printf("Traveling to %d/%d/%d at %d:%02d:%02d\n", travelDay, travelMonth, travelYear, travelDetails->tm_hour, travelDetails->tm_min, travelDetails->tm_sec);

  for (int i = 10; i > 0; i--) {
    printf("%d\n", i);
    sleep(1);
  }

  printf("Welcome to %d/%d/%d at %d:%02d:%02d\n", travelDay, travelMonth, travelYear, travelDetails->tm_hour, travelDetails->tm_min, travelDetails->tm_sec);

  return 0;
}