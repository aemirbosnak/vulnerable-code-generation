//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables to track the current time and user input
time_t current_time;
int user_input;

// Function to display the current time in a user-friendly format
void display_time() {
  struct tm *time_info = localtime(&current_time);
  printf("Current time: %s\n", asctime(time_info));
}

// Function to handle user input and update the current time accordingly
void handle_user_input() {
  printf("Enter a number to travel through time (positive for future, negative for past): ");
  scanf("%d", &user_input);

  // Adjust the current time based on the user's input
  current_time += user_input * 3600;  // Convert hours to seconds
}

// Function to simulate time travel and display the resulting time
void simulate_time_travel() {
  printf("Traveling through time...\n");

  // Update the current time using the user's input
  handle_user_input();

  // Display the resulting time
  display_time();
}

int main() {
  // Initialize the current time to the current system time
  current_time = time(NULL);

  // Display the initial time
  display_time();

  // Get the current time and the user's input
  while (1) {
    printf("\nWhat do you want to do?\n");
    printf("1. Travel through time\n");
    printf("2. Quit\n");
    scanf("%d", &user_input);

    switch (user_input) {
      case 1:
        simulate_time_travel();
        break;
      case 2:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid input. Please enter 1 or 2.\n");
    }
  }

  return 0;
}