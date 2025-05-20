//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: random
#include <stdio.h>
#include <time.h>

int main() {
  time_t now = time(NULL);
  struct tm *time_info = localtime(&now);
  int current_year = time_info->tm_year + 1900;
  int birth_year, travel_year;

  printf("Welcome to the Time Travel Simulator!\n");
  printf("Enter your birth year: ");
  scanf("%d", &birth_year);

  if (birth_year > current_year) {
    printf("Invalid year. Try again.\n");
    return 0;
  }

  printf("Enter the year you want to time travel to: ");
  scanf("%d", &travel_year);

  if (travel_year > current_year) {
    printf("You're traveling to the future!\n");
  } else {
    printf("You're traveling to the past!\n");
  }

  if (travel_year < birth_year) {
    printf("Sorry, you haven't been born yet in that year.\n");
    return 0;
  } else if (travel_year == birth_year) {
    printf("You're back to the year of your birth!\n");
  }

  int age = travel_year - birth_year;
  printf("You would be %d years old in the year %d.\n", age, travel_year);

  if (travel_year < 1900 || travel_year > current_year + 100) {
    printf("Time travel not possible.\n");
    return 0;
  }

  int month, day;

  printf("Enter the month you want to time travel to: ");
  scanf("%d", &month);

  if (month < 1 || month > 12) {
    printf("Invalid month. Try again.\n");
    return 0;
  }

  printf("Enter the day you want to time travel to: ");
  scanf("%d", &day);

  if (day < 1 || day > 31) {
    printf("Invalid day. Try again.\n");
    return 0;
  }

  struct tm travel_time = {0};
  travel_time.tm_year = travel_year - 1900;
  travel_time.tm_mon = month - 1;
  travel_time.tm_mday = day;

  time_t travel_timestamp = mktime(&travel_time);
  struct tm *travel_info = localtime(&travel_timestamp);

  printf("\nYou arrive on %s", asctime(travel_info));
  printf("You have successfully time traveled! Have fun!\n");

  return 0;
}