//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>
#include <string.h>

// Declare a struct called Exercise to hold exercise data
struct Exercise {
   char name[50];
   int sets;
   int reps;
   int weight;
};

// Declare a struct called Workout to hold workout data
struct Workout {
   char date[20];
   struct Exercise exercises[10];
};

int main() {
   int num_workouts;

   // Prompt user for number of workouts to input
   printf("How many workouts would you like to track? ");
   scanf("%d", &num_workouts);

   struct Workout workouts[num_workouts];

   // Loop through each workout and prompt user for data
   for (int i = 0; i < num_workouts; i++) {
      printf("\nWORKOUT %d\n", i + 1);
      printf("Enter the date (MM/DD/YYYY): ");
      scanf("%s", &workouts[i].date);

      for (int j = 0; j < 10; j++) {
         printf("\nEXERCISE %d\n", j + 1);
         printf("Enter the exercise name: ");
         scanf("%s", &workouts[i].exercises[j].name);
         printf("Enter the number of sets: ");
         scanf("%d", &workouts[i].exercises[j].sets);
         printf("Enter the number of reps: ");
         scanf("%d", &workouts[i].exercises[j].reps);
         printf("Enter the weight in pounds: ");
         scanf("%d", &workouts[i].exercises[j].weight);
      }
   }

   // Print out all inputted workout data
   printf("------------------\n");
   for (int i = 0; i < num_workouts; i++) {
      printf("WORKOUT %d\n", i + 1);
      printf("Date: %s\n", workouts[i].date);

      for (int j = 0; j < 10; j++) {
         printf("Exercise %d: %s\n", j + 1, workouts[i].exercises[j].name);
         printf("Sets: %d\n", workouts[i].exercises[j].sets);
         printf("Reps: %d\n", workouts[i].exercises[j].reps);
         printf("Weight: %d lbs\n", workouts[i].exercises[j].weight);
      }
      printf("------------------\n");
   }

   return 0;
}