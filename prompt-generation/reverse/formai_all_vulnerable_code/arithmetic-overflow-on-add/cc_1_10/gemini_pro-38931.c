//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Watson, I believe we have stumbled upon a most peculiar contraption. It seems capable of manipulating the very fabric of time itself!

// Let us embark on a grand adventure, Watson, and unravel the mysteries of this enigmatic device.

// Declare a structure to represent the time traveler
typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} TimeTraveler;

// Declare a function to initialize the time traveler to a specific date and time
void initializeTimeTraveler(TimeTraveler *timeTraveler, int year, int month, int day, int hour, int minute, int second) {
  timeTraveler->year = year;
  timeTraveler->month = month;
  timeTraveler->day = day;
  timeTraveler->hour = hour;
  timeTraveler->minute = minute;
  timeTraveler->second = second;
}

// Declare a function to print the current time and date of the time traveler
void printTimeTraveler(TimeTraveler *timeTraveler) {
  printf("The current time and date is: %d-%02d-%02d %02d:%02d:%02d\n", timeTraveler->year, timeTraveler->month, timeTraveler->day, timeTraveler->hour, timeTraveler->minute, timeTraveler->second);
}

// Declare a function to travel forward in time by a specified number of years, months, days, hours, minutes, and seconds
void travelForwardInTime(TimeTraveler *timeTraveler, int years, int months, int days, int hours, int minutes, int seconds) {
  // Add the specified amount of time to the time traveler's current time and date
  timeTraveler->year += years;
  timeTraveler->month += months;
  timeTraveler->day += days;
  timeTraveler->hour += hours;
  timeTraveler->minute += minutes;
  timeTraveler->second += seconds;

  // Adjust for any overflow or underflow
  if (timeTraveler->second >= 60) {
    timeTraveler->second -= 60;
    timeTraveler->minute++;
  }
  if (timeTraveler->minute >= 60) {
    timeTraveler->minute -= 60;
    timeTraveler->hour++;
  }
  if (timeTraveler->hour >= 24) {
    timeTraveler->hour -= 24;
    timeTraveler->day++;
  }
  if (timeTraveler->day >= 31) {
    timeTraveler->day -= 31;
    timeTraveler->month++;
  }
  if (timeTraveler->month >= 12) {
    timeTraveler->month -= 12;
    timeTraveler->year++;
  }
}

// Declare a function to travel backward in time by a specified number of years, months, days, hours, minutes, and seconds
void travelBackwardInTime(TimeTraveler *timeTraveler, int years, int months, int days, int hours, int minutes, int seconds) {
  // Subtract the specified amount of time from the time traveler's current time and date
  timeTraveler->year -= years;
  timeTraveler->month -= months;
  timeTraveler->day -= days;
  timeTraveler->hour -= hours;
  timeTraveler->minute -= minutes;
  timeTraveler->second -= seconds;

  // Adjust for any overflow or underflow
  if (timeTraveler->second < 0) {
    timeTraveler->second += 60;
    timeTraveler->minute--;
  }
  if (timeTraveler->minute < 0) {
    timeTraveler->minute += 60;
    timeTraveler->hour--;
  }
  if (timeTraveler->hour < 0) {
    timeTraveler->hour += 24;
    timeTraveler->day--;
  }
  if (timeTraveler->day < 0) {
    timeTraveler->day += 31;
    timeTraveler->month--;
  }
  if (timeTraveler->month < 0) {
    timeTraveler->month += 12;
    timeTraveler->year--;
  }
}

// Declare a function to simulate the time travel experience
void simulateTimeTravel(TimeTraveler *timeTraveler) {
  // Prompt the user to enter a command
  printf("Enter a command (forward, backward, print, or quit): ");
  char command[10];
  scanf("%s", command);

  // Handle the user's command
  if (strcmp(command, "forward") == 0) {
    // Prompt the user to enter the amount of time to travel forward
    int years, months, days, hours, minutes, seconds;
    printf("Enter the amount of time to travel forward (years, months, days, hours, minutes, seconds): ");
    scanf("%d %d %d %d %d %d", &years, &months, &days, &hours, &minutes, &seconds);

    // Travel forward in time
    travelForwardInTime(timeTraveler, years, months, days, hours, minutes, seconds);

    // Print the new time and date
    printTimeTraveler(timeTraveler);
  } else if (strcmp(command, "backward") == 0) {
    // Prompt the user to enter the amount of time to travel backward
    int years, months, days, hours, minutes, seconds;
    printf("Enter the amount of time to travel backward (years, months, days, hours, minutes, seconds): ");
    scanf("%d %d %d %d %d %d", &years, &months, &days, &hours, &minutes, &seconds);

    // Travel backward in time
    travelBackwardInTime(timeTraveler, years, months, days, hours, minutes, seconds);

    // Print the new time and date
    printTimeTraveler(timeTraveler);
  } else if (strcmp(command, "print") == 0) {
    // Print the current time and date
    printTimeTraveler(timeTraveler);
  } else if (strcmp(command, "quit") == 0) {
    // Exit the program
    exit(0);
  } else {
    // Print an error message
    printf("Invalid command\n");
  }
}

int main() {
  // Initialize the time traveler to the current time and date
  TimeTraveler timeTraveler;
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  initializeTimeTraveler(&timeTraveler, tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

  // Print the initial time and date
  printTimeTraveler(&timeTraveler);

  // Simulate the time travel experience
  while (1) {
    simulateTimeTravel(&timeTraveler);
  }

  return 0;
}