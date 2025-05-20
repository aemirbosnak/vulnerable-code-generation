//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: all-encompassing
#include <stdio.h>

int main(void) {
  int currentYear, travelYear;
  
  printf("Welcome to the Time Travel Simulator!\n\n");
  
  printf("Enter the current year: ");
  scanf("%d", &currentYear);
  
  printf("Please enter the year you would like to travel to: ");
  scanf("%d", &travelYear);
  
  if (travelYear < currentYear) {
    printf("\nWarning: You cannot travel back in time!\n");
    return 1;
  }
  
  printf("\nCalculating time travel...\n");
  printf("You have successfully traveled to the year %d from %d!\n", travelYear, currentYear);
  
  int numYearsTraveled = travelYear - currentYear;
  
  printf("\nYou have traveled %d years into the future!\n", numYearsTraveled);
  
  // Simulate time travel effects
  
  printf("\nSimulation starting in 3 seconds...\n");
  printf("3...\n");
  sleep(1);
  printf("2...\n");
  sleep(1);
  printf("1...\n");
  sleep(1);
  printf("Simulation started!\n");
  
  printf("\nPlease observe the changes in the world around you!\n");
  
  // Simulate some changes in the world
  
  printf("\nThe year is now %d. Here are some differences from the year %d:\n", travelYear, currentYear);
  
  if (numYearsTraveled >= 10) {
    printf("- Cars run on electricity instead of gas.\n");
  }
  
  if (numYearsTraveled >= 20) {
    printf("- Teleportation is now possible.\n");
  }
  
  if (numYearsTraveled >= 30) {
    printf("- Artificial intelligence has surpassed human intelligence.\n");
  }
  
  return 0;
}