//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

void time_travel(int years) {
  // Go back in time (years is negative), or forward in time (years is positive)
  struct tm *ptm;
  time_t now;
  
  // Get the current time
  now = time(NULL);
  
  // Adjust the current time based on the years parameter
  now = now + (years * 31536000);
  
  // Convert the adjusted time into a struct tm
  ptm = gmtime(&now);

  // Print out the new time
  printf("You have time traveled to %s", asctime(ptm));
}

void print_menu() {
  printf("\n\n");
  printf("=============================================\n");
  printf("     Welcome to the Time Travel Simulator    \n");
  printf("=============================================\n");
  printf("Choose an option:                             \n");
  printf("1. Travel back in time        3. Exit program \n");
  printf("2. Travel forward in time                     \n");
  printf("=============================================\n");
}

int get_choice() {
  // Prompt the user to input a choice
  printf("Enter your choice (1-3): ");
  int choice;
  scanf("%d", &choice);
  return choice;
}

int get_years() {
  // Prompt the user to input the number of years to travel
  printf("Enter the number of years to time travel: ");
  int years;
  scanf("%d", &years);
  return years;
}

void execute_choice(int choice) {
  // Execute the user's chosen option
  bool exit_program = false;
  switch (choice) {
    case 1:
      time_travel(-1 * get_years());
      break;
    case 2:
      time_travel(get_years());
      break;
    case 3:
      exit_program = true;
      break;
    default:
      printf("Invalid choice! Please try again.\n");
      break;
  }
  
  if (exit_program) {
    printf("Goodbye!\n");
    exit(0);
  }
}

int main() {
  while (true) {
    print_menu();
    execute_choice(get_choice());
  }
  
  return 0;
}