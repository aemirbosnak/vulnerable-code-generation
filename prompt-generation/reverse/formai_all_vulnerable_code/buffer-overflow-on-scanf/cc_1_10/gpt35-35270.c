//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: imaginative
#include <stdio.h>
#include <time.h>

int main() {
  time_t now = time(NULL);
  
  printf("Welcome to the Time Travel Simulator!\n\n");
  printf("Current date and time: %s", ctime(&now));
  
  printf("Please enter the year you would like to travel to: ");
  int year;
  scanf("%d", &year);
  
  printf("Please enter the month you would like to travel to (1-12): ");
  int month;
  scanf("%d", &month);
  
  printf("Please enter the day you would like to travel to (1-31): ");
  int day;
  scanf("%d", &day);
  
  printf("Please enter the hour you would like to travel to (0-23): ");
  int hour;
  scanf("%d", &hour);
  
  printf("Please enter the minute you would like to travel to (0-59): ");
  int minute;
  scanf("%d", &minute);
  
  struct tm travel_time;
  travel_time.tm_year = year - 1900;
  travel_time.tm_mon = month - 1;
  travel_time.tm_mday = day;
  travel_time.tm_hour = hour;
  travel_time.tm_min = minute;
  travel_time.tm_sec = 0;
  
  time_t travel_timestamp = mktime(&travel_time);
  
  printf("\n\nTraveling to %s...\n\n", ctime(&travel_timestamp));
  
  sleep(3); // pause for dramatic effect
  
  now = travel_timestamp;
  printf("Welcome to %s!\n\n", ctime(&now));
  
  printf("Would you like to travel again? (y/n): ");
  char ans;
  scanf(" %c", &ans);
  
  if (ans == 'y' || ans == 'Y') {
    main();
  }
  
  printf("Thank you for using the Time Travel Simulator. Goodbye!\n");
  
  return 0;
}