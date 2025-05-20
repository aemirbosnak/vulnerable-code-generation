//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: paranoid
#include <stdio.h>
#include <time.h>

int main() {
  time_t currentTime;
  struct tm * timeInfo;
  int year, month, day, hour, minute, second;

  time(&currentTime);
  timeInfo = localtime(&currentTime);

  year = timeInfo->tm_year + 1900;
  month = timeInfo->tm_mon + 1;
  day = timeInfo->tm_mday;
  hour = timeInfo->tm_hour;
  minute = timeInfo->tm_min;
  second = timeInfo->tm_sec;

  printf("Current Date and Time: %d-%d-%d %d:%d:%d\n", year, month, day, hour, minute, second);
  
  printf("Enter a future year: ");
  scanf("%d", &year);

  while (year < timeInfo->tm_year + 1900) {
    printf("You cannot travel back in time! Enter a future year: ");
    scanf("%d", &year);
  }

  printf("Enter a future month (1-12): ");
  scanf("%d", &month);
  while(month < 1 || month > 12) {
    printf("Invalid month! Enter a future month (1-12): ");
    scanf("%d", &month);
  }

  printf("Enter a future day: ");
  scanf("%d", &day);
  while (day < 1 || day > 31) {
    printf("Invalid day! Enter a future day: ");
    scanf("%d", &day);
  }

  printf("Enter a future hour: ");
  scanf("%d", &hour);
  while (hour < 0 || hour > 23) {
    printf("Invalid hour! Enter a future hour: ");
    scanf("%d", &hour);
  }

  printf("Enter a future minute: ");
  scanf("%d", &minute);
  while (minute < 0 || minute > 59) {
    printf("Invalid minute! Enter a future minute: ");
    scanf("%d", &minute);
  }

  printf("Enter a future second: ");
  scanf("%d", &second);
  while (second < 0 || second > 59) {
    printf("Invalid second! Enter a future second: ");
    scanf("%d", &second);
  }

  printf("Traveling to %d-%d-%d %d:%d:%d...\n", year, month, day, hour, minute, second);

  // Just for fun, generate a random number to simulate the possibility that something goes wrong during time travel.
  srand(time(NULL));
  int randomNum = rand() % 100 + 1;

  if (randomNum <= 25) {
    printf("Paranoia sets in as you start to notice small changes in the timeline...\n");
    printf("Error: Time travel failed. Anomaly detected.\n");
    return 1;
  } else {
    printf("Time travel successful. Welcome to %d-%d-%d %d:%d:%d!\n", year, month, day, hour, minute, second);
    return 0;
  }
}