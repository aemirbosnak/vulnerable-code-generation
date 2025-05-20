//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // Seed random number generator

   // Set initial fitness levels for user
   int cardio = 50;
   int strength = 50;
   int flexibility = 50;

   // Print initial fitness levels
   printf("Your current fitness levels:\n");
   printf("Cardio: %d\nStrength: %d\nFlexibility: %d\n\n", cardio, strength, flexibility);

   // Track user's progress throughout the week
   for (int day = 1; day <= 7; day++) {
      printf("Day %d\n", day);

      // Generate random workout type for the day
      int workoutType = rand() % 3;
      if (workoutType == 0) {
         // Cardio workout
         printf("Today is a cardio day!\n");
         printf("How many minutes did you run today? ");
         int minutes;
         scanf("%d", &minutes);

         // Increase cardio level based on minutes run
         cardio += minutes / 5;

      } else if (workoutType == 1) {
         // Strength workout
         printf("Today is a strength day!\n");
         printf("How many pushups did you do today? ");
         int pushups;
         scanf("%d", &pushups);

         // Increase strength level based on pushups done
         strength += pushups / 10;

      } else {
         // Flexibility workout
         printf("Today is a flexibility day!\n");
         printf("How many minutes did you stretch today? ");
         int minutes;
         scanf("%d", &minutes);

         // Increase flexibility level based on minutes stretched
         flexibility += minutes / 5;
      }

      // Print updated fitness levels for the day
      printf("\nYour updated fitness levels for the day:\n");
      printf("Cardio: %d (+%d)\nStrength: %d (+%d)\nFlexibility: %d (+%d)\n\n", 
             cardio, cardio - 50, strength, strength - 50, flexibility, flexibility - 50);
   }

   // Print final fitness levels
   printf("Your final fitness levels:\n");
   printf("Cardio: %d (+%d)\nStrength: %d (+%d)\nFlexibility: %d (+%d)\n\n", 
          cardio, cardio - 50, strength, strength - 50, flexibility, flexibility - 50);

   // Check user's overall progress and provide feedback
   printf("Great job this week!\n");
   if (cardio >= 75 && strength >= 75 && flexibility >= 75) {
      printf("You have achieved a well-rounded level of fitness!\n");
   } else if (cardio >= 75) { 
      printf("You have made great progress in your cardio workouts!\n");
   } else if (strength >= 75) {
      printf("You have made great progress in your strength workouts!\n");
   } else if (flexibility >= 75) {
      printf("You have made great progress in your flexibility workouts!\n");
   } else {
      printf("Keep working hard! You are making progress towards your fitness goals.\n");
   }

   return 0;
}