//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>

int main() {
   // Data variables
   int age;
   float height_m;
   float weight_kg;
   int num_workouts;
   
   // Prompt users for input
   printf("Enter your age: ");
   scanf("%d", &age);
   printf("Enter your height in meters: ");
   scanf("%f", &height_m);
   printf("Enter your weight in kilograms: ");
   scanf("%f", &weight_kg);
   printf("Enter the number of workouts you performed this week: ");
   scanf("%d", &num_workouts);
   
   // Calculate body mass index
   float bmi = weight_kg / (height_m * height_m); 
   
   // Output results
   printf("Age:\t\t%d years\n", age);
   printf("Height:\t\t%.2f meters\n", height_m);
   printf("Weight:\t\t%.2f kilograms\n", weight_kg);
   printf("BMI:\t\t%.2f\n", bmi);
   printf("Workouts:\t%d\n", num_workouts);
   
   // Determine workout frequency goal based on age
   int workout_goal;
   if (age <= 30) {
      workout_goal = 5;
   } else if (age > 30 && age <= 50) {
      workout_goal = 4;
   } else {
      workout_goal = 3;
   }
   
   // Output workout frequency goal
   printf("Workout goal:\t%d per week\n", workout_goal);
   
   // Determine if user met workout goal
   if (num_workouts >= workout_goal) {
      printf("Congratulations! You met your weekly workout goal!\n");
   } else {
      printf("You need to perform %d more workouts this week to meet your goal.\n", workout_goal-num_workouts);
   }
   
   return 0;
}