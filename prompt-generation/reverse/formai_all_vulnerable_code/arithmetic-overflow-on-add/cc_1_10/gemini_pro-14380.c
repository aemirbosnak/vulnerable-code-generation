//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of years the user can travel
#define MAX_YEARS 100

// Define the minimum year the user can travel to
#define MIN_YEAR 1900

// Get the current year
int get_current_year() {
  time_t now = time(NULL);
  struct tm *tm = localtime(&now);
  return tm->tm_year + 1900;
}

// Get the user's desired year of travel
int get_desired_year() {
  int year;
  printf("Enter the year you want to travel to (between %d and %d): ", MIN_YEAR, MAX_YEARS + get_current_year());
  scanf("%d", &year);
  return year;
}

// Calculate the time difference between the current year and the desired year
int calculate_time_difference(int current_year, int desired_year) {
  return desired_year - current_year;
}

// Print the time travel results
void print_results(int time_difference, int desired_year) {
  printf("You have travelled %d years ", time_difference);
  if (time_difference > 0) {
    printf("into the future");
  } else if (time_difference < 0) {
    printf("into the past");
  } else {
    printf("to the present");
  }
  printf(" to the year %d.\n", desired_year);
}

// Main function
int main() {
  // Get the current year
  int current_year = get_current_year();

  // Get the user's desired year of travel
  int desired_year = get_desired_year();

  // Calculate the time difference between the current year and the desired year
  int time_difference = calculate_time_difference(current_year, desired_year);

  // Print the time travel results
  print_results(time_difference, desired_year);

  return 0;
}