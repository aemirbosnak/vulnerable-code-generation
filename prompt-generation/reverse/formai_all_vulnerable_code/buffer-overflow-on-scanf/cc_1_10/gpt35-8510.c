//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int alienCount, successfulInvasions, totalAttempts;
  double invasionProbability;
  char response;
  
  srand(time(NULL)); // Seed for random number generator
  
  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  
  do {
    // Get user input
    printf("Please enter the number of aliens: ");
    scanf("%d", &alienCount);
    
    // Calculate invasion probability
    invasionProbability = (double) alienCount / RAND_MAX;
    
    // Set successful invasions and total attempts to 0
    successfulInvasions = 0;
    totalAttempts = 0;
    
    // Simulate 100 invasion attempts
    for (int i = 0; i < 100; i++) {
      // Generate a random number between 0 and 1
      double randNum = (double) rand() / RAND_MAX;
      
      // Increment total attempts
      totalAttempts++;
      
      if (randNum <= invasionProbability) {
        // The invasion was successful
        successfulInvasions++;
      }
    }
    
    // Calculate success rate
    double successRate = (double) successfulInvasions / totalAttempts;
    
    printf("Based on our calculations, the chances of a successful alien invasion with %d aliens is %f\n", alienCount, invasionProbability);
    printf("In our simulation, out of %d invasion attempts, %d were successful, resulting in a success rate of %f.\n", totalAttempts, successfulInvasions, successRate);
    
    // Ask user if they want to run the program again
    printf("Do you want to calculate another invasion probability? (Y/N): ");
    scanf(" %c", &response);
  } while (response == 'Y' || response == 'y');
  
  printf("Thank you for using the Alien Invasion Probability Calculator!\n");
  
  return 0;
}