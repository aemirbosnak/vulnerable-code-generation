//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  time_t t = time(NULL); // Get the current time
  struct tm *currTime = localtime(&t); // Get the current local time
  
  printf("Welcome to the Time Travel Simulator!\n\n");

  // Display the current time
  printf("Current Time: %d-%d-%d %d:%d:%d\n", 
           currTime->tm_year + 1900, currTime->tm_mon + 1, currTime->tm_mday,
           currTime->tm_hour, currTime->tm_min, currTime->tm_sec);

  // Ask the user for a year
  int year;
  printf("\n\nEnter a year to travel to (any integer greater than 0): ");
  scanf("%d", &year);

  if(year < 1){
    printf("Invalid year!\n");
    exit(1);
  }

  // Get the difference between current year and the input year
  int yearDelta = year - (currTime->tm_year + 1900);

  // Calculate the new time given the yearDelta
  // Assumes that there are no leap years between now and then
  int numYears = currTime->tm_year + 1900 + yearDelta;
  int numMonths = currTime->tm_mon + 1;
  int numDays = currTime->tm_mday;
  int numHours = currTime->tm_hour;
  int numMinutes = currTime->tm_min;
  int numSeconds = currTime->tm_sec;

  // Keep track of the time travel progress
  printf("\n\nTravelling through time to %d...\n\n", year);

  // Simulate time travel by counting down from 3
  for(int i=3; i>=1; i--){
    printf("%d...\n", i);
    sleep(1);
  }

  // Display the new time after time travel
  printf("\n\nTime travel successful! You have arrived at:\n");
  printf("New Time: %d-%d-%d %d:%d:%d\n", numYears, numMonths, numDays,
         numHours, numMinutes, numSeconds);

  // Play a sound effect to signal arrival
  printf("Sound effect: *Bloop!*\n\n");

  return 0;
}