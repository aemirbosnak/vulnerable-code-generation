//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The main function is the entry point of the program.
int main() {
  // Seed the random number generator.
  srand(time(NULL));
  
  // Create a FitnessTracker struct to store the user's data.
  typedef struct {
    int steps;
    int caloriesBurned;
    int distanceTraveled;
    int activeMinutes;
    int sleepHours;
    int sleepQuality;
  } FitnessTracker;
  FitnessTracker user;
  
  // Initialize the user's data.
  user.steps = 0;
  user.caloriesBurned = 0;
  user.distanceTraveled = 0;
  user.activeMinutes = 0;
  user.sleepHours = 0;
  user.sleepQuality = 0;
  
  // Get the current time.
  time_t now = time(NULL);
  
  // Loop until the user quits the program.
  while (1) {
    // Get the user's input.
    printf("What would you like to do?\n");
    printf("1. Start a workout\n");
    printf("2. End a workout\n");
    printf("3. View your progress\n");
    printf("4. Quit\n");
    int choice;
    scanf("%d", &choice);
    
    // Start a workout.
    if (choice == 1) {
      // Get the workout type.
      printf("What type of workout are you doing?\n");
      printf("1. Walking\n");
      printf("2. Running\n");
      printf("3. Cycling\n");
      printf("4. Other\n");
      int workoutType;
      scanf("%d", &workoutType);
      
      // Get the workout duration.
      printf("How long do you want to work out for?\n");
      int duration;
      scanf("%d", &duration);
      
      // Start the workout.
      printf("Starting workout...\n");
      
      // Simulate the workout.
      for (int i = 0; i < duration; i++) {
        // Increment the user's steps.
        user.steps++;
        
        // Increment the user's calories burned.
        user.caloriesBurned += rand() % 10;
        
        // Increment the user's distance traveled.
        user.distanceTraveled += rand() % 10;
        
        // Increment the user's active minutes.
        user.activeMinutes++;
      }
      
      // End the workout.
      printf("Workout ended.\n");
    }
    
    // End a workout.
    else if (choice == 2) {
      // Get the workout type.
      printf("What type of workout did you do?\n");
      printf("1. Walking\n");
      printf("2. Running\n");
      printf("3. Cycling\n");
      printf("4. Other\n");
      int workoutType;
      scanf("%d", &workoutType);
      
      // Get the workout duration.
      printf("How long did you work out for?\n");
      int duration;
      scanf("%d", &duration);
      
      // End the workout.
      printf("Ending workout...\n");
      
      // Simulate the workout.
      for (int i = 0; i < duration; i++) {
        // Increment the user's steps.
        user.steps++;
        
        // Increment the user's calories burned.
        user.caloriesBurned += rand() % 10;
        
        // Increment the user's distance traveled.
        user.distanceTraveled += rand() % 10;
        
        // Increment the user's active minutes.
        user.activeMinutes++;
      }
      
      // End the workout.
      printf("Workout ended.\n");
    }
    
    // View the user's progress.
    else if (choice == 3) {
      // Print the user's progress.
      printf("Steps: %d\n", user.steps);
      printf("Calories Burned: %d\n", user.caloriesBurned);
      printf("Distance Traveled: %d\n", user.distanceTraveled);
      printf("Active Minutes: %d\n", user.activeMinutes);
      printf("Sleep Hours: %d\n", user.sleepHours);
      printf("Sleep Quality: %d\n", user.sleepQuality);
    }
    
    // Quit the program.
    else if (choice == 4) {
      break;
    }
    
    // Invalid input.
    else {
      printf("Invalid input.\n");
    }
  }
  
  return 0;
}