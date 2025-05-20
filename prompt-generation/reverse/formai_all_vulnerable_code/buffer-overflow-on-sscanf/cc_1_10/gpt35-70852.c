//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: retro
#include <stdio.h>
#include <time.h>

int main(void) {
  // Initialize time variables
  time_t present_time, future_time;
  
  // Prompt user for input date
  printf("Welcome to the Time Travel Simulator!\n");
  printf("Please enter a future date in the format: YYYY-MM-DD\n");
  
  // Read input date
  char input_date[11];
  scanf("%s", input_date);

  // Convert to struct tm
  struct tm future_tm = {0};
  sscanf(input_date, "%d-%d-%d", &future_tm.tm_year, &future_tm.tm_mon, &future_tm.tm_mday);
  future_tm.tm_year -= 1900;
  future_tm.tm_mon -= 1;

  // Convert to time_t
  future_time = mktime(&future_tm);

  // Get current time
  present_time = time(NULL);

  // Calculate time difference
  double seconds_difference = difftime(future_time, present_time);
  
  // Check if time travel is possible
  if (seconds_difference < 0) {
    printf("Sorry, time travel to the past is not possible in this simulator.\n");
    return 0;
  }

  // Time travel
  printf("Time travel successful! You have arrived at: %s\n", input_date);

  // Retro style delay
  for (int i = 3; i >= 1; i--) {
    printf("%d...\n", i);
    sleep(1);
  }
  
  // Print final message
  printf("Welcome to the future!\n");

  return 0;
}