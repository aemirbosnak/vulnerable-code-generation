//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
// C Fitness Tracker Example Program

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void print_menu();
void track_exercise(int exercise_type);
void calculate_calories_burned(int exercise_type);

// Global variables
int total_calories_burned = 0;

int main() {
  // Print the menu
  print_menu();

  // Get the exercise type from the user
  int exercise_type;
  printf("Enter the exercise type (1-5): ");
  scanf("%d", &exercise_type);

  // Track the exercise
  track_exercise(exercise_type);

  // Calculate the calories burned
  calculate_calories_burned(exercise_type);

  // Print the total calories burned
  printf("Total calories burned: %d\n", total_calories_burned);

  return 0;
}

// Print the menu
void print_menu() {
  printf("============================\n");
  printf(" 1. Cardio\n");
  printf(" 2. Strength Training\n");
  printf(" 3. Yoga\n");
  printf(" 4. Swimming\n");
  printf(" 5. Cycling\n");
  printf("============================\n");
}

// Track the exercise
void track_exercise(int exercise_type) {
  switch (exercise_type) {
    case 1:
      // Cardio exercise
      total_calories_burned += 500;
      break;
    case 2:
      // Strength training exercise
      total_calories_burned += 1000;
      break;
    case 3:
      // Yoga exercise
      total_calories_burned += 300;
      break;
    case 4:
      // Swimming exercise
      total_calories_burned += 700;
      break;
    case 5:
      // Cycling exercise
      total_calories_burned += 800;
      break;
    default:
      printf("Invalid exercise type\n");
      break;
  }
}

// Calculate the calories burned
void calculate_calories_burned(int exercise_type) {
  switch (exercise_type) {
    case 1:
      // Cardio exercise
      total_calories_burned += 500;
      break;
    case 2:
      // Strength training exercise
      total_calories_burned += 1000;
      break;
    case 3:
      // Yoga exercise
      total_calories_burned += 300;
      break;
    case 4:
      // Swimming exercise
      total_calories_burned += 700;
      break;
    case 5:
      // Cycling exercise
      total_calories_burned += 800;
      break;
    default:
      printf("Invalid exercise type\n");
      break;
  }
}