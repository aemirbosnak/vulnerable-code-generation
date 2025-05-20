//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Retro style ASCII art
void print_ascii_art() {
  printf("\n");
  printf(" _____    __ __ __ __ __ \n");
  printf("|_   _|  |  |  |  |  |  |\n");
  printf("  | |    |  |  |  |  |  |\n");
  printf("  | | ___|  |__|  |  |  |\n");
  printf("  | |/ _ \\    __|  |  |  |\n");
  printf("  | |  __/ |  |  |  |  |\n");
  printf("  |_|\\___| |__|  |__|  |\n");
  printf("\n");
}

// Function to get current time
void get_current_time(struct tm *time_info) {
  time_t now = time(NULL);
  localtime_r(&now, time_info);
}

// Function to format time as HH:MM:SS
void format_time(struct tm *time_info, char *formatted_time) {
  sprintf(formatted_time, "%02d:%02d:%02d",
          time_info->tm_hour,
          time_info->tm_min,
          time_info->tm_sec);
}

// Function to print fitness data
void print_fitness_data(int steps, int distance, int calories) {
  printf("Fitness Data:\n");
  printf("Steps: %d\n", steps);
  printf("Distance: %d meters\n", distance);
  printf("Calories burned: %d\n", calories);
}

// Main function
int main() {
  int steps = 0;
  int distance = 0;
  int calories = 0;
  char formatted_time[9]; // HH:MM:SS

  struct tm time_info;
  get_current_time(&time_info);
  format_time(&time_info, formatted_time);

  printf("Welcome to the Retro Fitness Tracker!\n");
  printf("Current time: %s\n", formatted_time);

  while(1) {
    printf("Enter number of steps taken: ");
    scanf("%d", &steps);
    distance = steps * 0.8; // Assume each step is 0.8 meters
    calories = steps * 0.05; // Assume 5 calories burned per 100 steps

    print_fitness_data(steps, distance, calories);
    print_ascii_art();
  }

  return 0;
}