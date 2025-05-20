//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number from a given range
int generateRandom(int lower, int upper) {
   int num = (rand() % (upper - lower + 1)) + lower;
   return num;
}

int main() {
  srand(time(0)); // Seed the random number generator

  int year, month, day, hour, minute, second;

  // Prompt the user to enter the desired date and time
  printf("Enter the year: ");
  scanf("%d", &year);

  printf("Enter the month (1-12): ");
  scanf("%d", &month);

  printf("Enter the day of the month: ");
  scanf("%d", &day);

  printf("Enter the hour (0-23): ");
  scanf("%d", &hour);

  printf("Enter the minute (0-59): ");
  scanf("%d", &minute);

  printf("Enter the second (0-59): ");
  scanf("%d", &second);

  // Determine the current date and time
  time_t now = time(NULL);
  struct tm *currentTime = localtime(&now);
  int currentYear = currentTime->tm_year + 1900;
  int currentMonth = currentTime->tm_mon + 1;
  int currentDay = currentTime->tm_mday;
  int currentHour = currentTime->tm_hour;
  int currentMinute = currentTime->tm_min;
  int currentSecond = currentTime->tm_sec;

  // Calculate the difference between the current date and the desired date
  int yearDifference = year - currentYear;
  int monthDifference = month - currentMonth;
  int dayDifference = day - currentDay;
  int hourDifference = hour - currentHour;
  int minuteDifference = minute - currentMinute;
  int secondDifference = second - currentSecond;

  // Use the difference to calculate the final date and time
  int finalYear = currentYear + yearDifference;
  int finalMonth = currentMonth + monthDifference;
  int finalDay = currentDay + dayDifference;
  int finalHour = currentHour + hourDifference;
  int finalMinute = currentMinute + minuteDifference;
  int finalSecond = currentSecond + secondDifference;

  // Handle cases where the final date and time go beyond the limits
  if (finalSecond > 59) {
    finalSecond -= 60;
    finalMinute++;
  }
  if (finalMinute > 59) {
    finalMinute -= 60;
    finalHour++;
  }
  if (finalHour > 23) {
    finalHour -= 24;
    finalDay++;
  }
  int daysInMonth;
  if (finalMonth == 2) {
    if ((finalYear % 4 == 0 && finalYear % 100 != 0) || finalYear % 400 == 0) {
      daysInMonth = 29;
    } else {
      daysInMonth = 28;
    }
  } else if (finalMonth == 4 || finalMonth == 6 || finalMonth == 9 || finalMonth == 11) {
    daysInMonth = 30;
  } else {
    daysInMonth = 31;
  }
  if (finalDay > daysInMonth) {
    finalDay -= daysInMonth;
    finalMonth++;
  }
  if (finalMonth > 12) {
    finalMonth -= 12;
    finalYear++;
  }

  // Print the final date and time
  printf("\nYour time machine is ready to take you to the following date and time:\n");
  printf("Year: %d\n", finalYear);
  printf("Month: %d\n", finalMonth);
  printf("Day: %d\n", finalDay);
  printf("Hour: %d\n", finalHour);
  printf("Minute: %d\n", finalMinute);
  printf("Second: %d\n\n", finalSecond);

  // Step into the time machine and travel to the final date and time
  printf("Preparing your time machine for travel....\n");

  for(int i = 0; i < 10; i++){
      printf("...");
      sleep(1);
  }
  printf("Wonderful! You have arrived successfully at your destination. Pick a point on this timeline and have some fun!");

  return 0;
}