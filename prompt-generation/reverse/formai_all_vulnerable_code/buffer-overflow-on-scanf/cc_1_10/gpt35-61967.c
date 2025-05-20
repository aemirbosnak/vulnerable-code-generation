//FormAI DATASET v1.0 Category: System boot optimizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  // Prompt the user to enter the number of boot optimizer steps
  int steps;
  printf("Welcome to the C System boot optimizer program.\n\n");
  printf("How many optimization steps do you want to perform?\n");
  scanf("%d", &steps);
  
  // Initialize random system boot data
  int boot_time = rand() % 60 + 1; // Random boot time between 1 - 60 seconds
  int startup_apps = rand() % 20; // Random number of startup apps between 0 - 19
  
  // Display initial system boot data
  printf("\nInitial boot time: %d seconds\n", boot_time);
  printf("Initial number of startup apps: %d\n\n", startup_apps);
  
  // Run optimizer steps
  int step;
  for (step = 1; step <= steps; step++) {
    
    // Generate random optimization action
    int action = rand() % 3; // Random selection between 0 - 2
    bool boot_time_updated = false;
    bool startup_apps_updated = false;
    
    // Perform optimization action
    if (action == 0) { // Decrease boot time by 10%
      boot_time = boot_time * 0.9;
      boot_time_updated = true;
    }
    else if (action == 1) { // Increase number of startup apps by 1
      startup_apps++;
      startup_apps_updated = true;
    }
    else { // Decrease number of startup apps by 1
      startup_apps--;
      startup_apps_updated = true;
    }
    
    // Display optimization results
    printf("Optimization step %d\n", step);
    if (boot_time_updated) {
      printf("Boot time decreased by 10%%. New boot time: %d seconds\n", boot_time);
    }
    if (startup_apps_updated) {
      printf("Startup apps updated. New number of startup apps: %d\n", startup_apps);
    }
    printf("\n");
  }
  
  // Display final system boot data
  printf("Final boot time: %d seconds\n", boot_time);
  printf("Final number of startup apps: %d\n", startup_apps);
  
  return 0;
}