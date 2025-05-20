//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Time Travel Simulator!\n");

  // getting the current time
  time_t t = time(NULL);
  struct tm *now = localtime(&t);

  printf("You are currently in year %d.\n", now->tm_year + 1900);

  // asking user where they want to go
  printf("What year would you like to travel to? ");
  int year;
  scanf("%d", &year);

  // calculating the difference and printing it
  int diff = year - (now->tm_year + 1900);
  printf("You will be travelling %d years into the ", abs(diff));

  if (diff < 0) {
    printf("past.\n");
  } else {
    printf("future.\n");
  }

  // randomly generating a time travel experience
  srand(time(NULL));
  int experience = rand() % 6;

  switch (experience) {
    case 0:
      printf("You feel a sudden gust of wind and black out.\n");
      break;
    case 1:
      printf("A bright light surrounds you and you feel weightless.\n");
      break;
    case 2:
      printf("You hear a loud noise and your vision blurs.\n");
      break;
    case 3:
      printf("You suddenly feel like everything is moving in slow motion.\n");
      break;
    case 4:
      printf("You feel a jarring sensation as if someone has grabbed you by the collar.\n");
      break;
    case 5:
      printf("You feel a sudden drop in temperature and everything around you turns blue.\n");
      break;
    default:
      printf("Something went wrong in the time travel experience.\n");
      break;
  }

  // calculating the new year and printing it
  int new_year = now->tm_year + diff;
  printf("You have arrived in year %d.\n", new_year + 1900);

  printf("Thank you for using the Time Travel Simulator!\n");

  return 0;
}