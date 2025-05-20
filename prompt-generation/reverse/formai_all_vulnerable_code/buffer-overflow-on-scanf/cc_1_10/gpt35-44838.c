//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int current_year, target_year, years_travelled;

  //Get current year
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  current_year = tm.tm_year + 1900;

  //Get target year from user input
  printf("Enter target year: ");
  scanf("%d", &target_year);

  //Calculate years travelled
  years_travelled = abs(target_year - current_year);

  //If user entered a year in the future
  if(target_year > current_year) {
    printf("Travelling %d years into the future...\n", years_travelled);
    for(int i = 1; i <= years_travelled; i++) {
      //Do time travelling things
      printf("Year %d\n", current_year+i);
      //Rest for a second to simulate time travel
      sleep(1);
    }
    printf("Welcome to year %d!\n", target_year);
  }

  //If user entered a year in the past
  else if(target_year < current_year) {
    printf("Travelling %d years into the past...\n", years_travelled);
    for(int i = 1; i <= years_travelled; i++) {
      //Do time travelling things
      printf("Year %d\n", current_year-i);
      //Rest for a second to simulate time travel
      sleep(1);
    }
    printf("Welcome to year %d!\n", target_year);
  }

  //If user entered current year
  else {
    printf("You are already in year %d.\n", current_year);
  }

  return 0;
}