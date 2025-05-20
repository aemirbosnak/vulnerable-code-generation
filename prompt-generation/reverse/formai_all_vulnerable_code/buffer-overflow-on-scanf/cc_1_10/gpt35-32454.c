//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  time_t curr_time;
  struct tm *time_info;
  char time_string[9];

  time(&curr_time);
  time_info = localtime(&curr_time);

  strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);

  printf("Welcome to the Time Travel Simulator!\n");
  printf("It is currently %s in the present day.\n\n", time_string);

  printf("Enter a year to travel to: ");
  int year;
  scanf("%d", &year);

  if (year < 0)
  {
    printf("\nInvalid year. Please enter a positive integer.\n");
    return 0;
  }

  time_t travel_time = curr_time;
  time_info = localtime(&travel_time);

  time_info->tm_year = year - 1900;
  travel_time = mktime(time_info);

  if (travel_time < curr_time)
  {
    printf("\nOops! You can't travel back in time! Please enter a future year.\n");
    return 0;
  }

  printf("\nYou have arrived in the year %d!\n", year);

  time_info = localtime(&travel_time);
  strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);

  printf("The time is currently %s in your time machine.\n\n", time_string);

  printf("Enter 1 to go back to the present day, or any other number to exit the program: ");

  int choice;
  scanf("%d", &choice);

  if (choice == 1)
  {
    printf("\nReturning to the present day...\n");
    time(&curr_time);
    time_info = localtime(&curr_time);
    strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
    printf("Welcome back to the present day! It is currently %s.\n", time_string);
  }
  else
  {
    printf("\nThank you for using the Time Travel Simulator! Goodbye!\n");
  }

  return 0;
}