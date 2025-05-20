//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t current_time;
  time_t future_time;
  struct tm * time_info;
  char time_string[80];

  // Get current time
  time(&current_time);
  time_info = localtime(&current_time);
  strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
  printf("Current time: %s\n", time_string);

  // Set future time
  time_info->tm_year += 10;
  future_time = mktime(time_info);
  time_info = localtime(&future_time);
  strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
  printf("Future time: %s\n", time_string);

  // Set past time
  time_info->tm_year -= 20;
  time_t past_time = mktime(time_info);
  time_info = localtime(&past_time);
  strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
  printf("Past time: %s\n", time_string);

  // Travel to future and back to past
  printf("Initializing time travel sequence...\n");
  printf("Traveling to future...\n");
  for (int i = 1; i <= 10; i++) {
    sleep(1);
    printf("%d...\n", i);
  }
  time(&current_time);
  time_info = localtime(&current_time);
  strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
  printf("Current time: %s\n", time_string);
  printf("Traveling back to past...\n");
  for (int i = 20; i >= 11; i--) {
    sleep(1);
    printf("%d...\n", i);
  }
  time(&current_time);
  time_info = localtime(&current_time);
  strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
  printf("Current time: %s\n", time_string);

  printf("Time travel sequence complete.\n");

  return 0;
}