//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t currentTime;
  struct tm *timeinfo;

  time(&currentTime);
  timeinfo = localtime(&currentTime);

  int year = timeinfo->tm_year + 1900;
  int month = timeinfo->tm_mon + 1;
  int day = timeinfo->tm_mday;
  int hour = timeinfo->tm_hour;

  printf("Welcome to the Time Travel Simulator!\n");
  printf("It is currently %02d/%02d/%d %02d:00\n", month, day, year, hour);

  int targetYear, targetMonth, targetDay, targetHour;

  printf("Enter the year you want to travel to (ex. 2030): ");
  scanf("%d", &targetYear);

  printf("Enter the month you want to travel to (ex. 07): ");
  scanf("%d", &targetMonth);

  printf("Enter the day you want to travel to (ex. 23): ");
  scanf("%d", &targetDay);

  printf("Enter the hour you want to travel to (ex. 16): ");
  scanf("%d", &targetHour);

  printf("\nYou are traveling to %02d/%02d/%d %02d:00...\n", targetMonth, targetDay, targetYear, targetHour);

  int travelDelay = 5;

  int yearDifference = targetYear - year;
  int monthDifference = targetMonth - month;
  int dayDifference = targetDay - day;
  int hourDifference = targetHour - hour;

  int totalSeconds = ((yearDifference * 365 * 24 * 60 * 60) + (monthDifference * 30 * 24 * 60 * 60) + (dayDifference * 24 * 60 * 60) + (hourDifference * 60 * 60));

  printf("\nTime traveling in ");
  for(int i = travelDelay; i > 0; i--) {
    printf("%d... ", i);
    sleep(1);
  }

  printf("\nYou have arrived in the year %d!\n", targetYear);

  printf("Here are some events that happened during your stay:\n");

  // Insert interesting historical events here

  return 0;
}