//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* C Fitness Tracker Example Program */

typedef struct {
   int age;
   float height;  // in meters
   float weight;  // in kg
   char gender[10];
} userProfile;

typedef struct {
   char activity[30];
   int duration;  // in minutes
   int calories;  // in kcal
} fitnessActivity;

int main() {

   // User profile creation
   userProfile user1;
   printf("Please enter your age: ");
   scanf("%d", &user1.age);
   printf("Please enter your height in meters (ex: 1.85): ");
   scanf("%f", &user1.height);
   printf("Please enter your weight in kg: ");
   scanf("%f", &user1.weight);
   printf("Please enter your gender (male/female/non-binary): ");
   scanf("%s", user1.gender);
   printf("\nYour profile has been created!\n\n");

   // Fitness activity log
   int numActivities = 0;
   fitnessActivity activities[50];

   // Display menu
   int choice = 0;
   while (choice != 4) {
      printf("*********************\n");
      printf("    FITNESS TRACKER\n");
      printf("*********************\n");
      printf("1. Add activity\n");
      printf("2. View log\n");
      printf("3. Update profile\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {

         // Add activity
         case 1: {
            if (numActivities == 50) {
               printf("Maximum number of activities have been logged.\n\n");
            } else {
               printf("Enter activity name: ");
               scanf("%s", activities[numActivities].activity);
               printf("Enter duration in minutes: ");
               scanf("%d", &activities[numActivities].duration);

               // Calculate calories burned based on user profile
               if (strcmp(user1.gender, "male") == 0) {
                  activities[numActivities].calories = (int)(((0.2017 * user1.age) + (0.6309 * user1.weight) + (0.09036 * user1.height) + 55.0969) / 4.184 * activities[numActivities].duration);
               } else if (strcmp(user1.gender, "female") == 0) {
                  activities[numActivities].calories = (int)(((0.074 * user1.age) - (0.1263 * user1.weight) + (0.4472 * user1.height) + 20.4022) / 4.184 * activities[numActivities].duration);
               } else if (strcmp(user1.gender, "non-binary") == 0) {
                  activities[numActivities].calories = (int)(((0.074 * user1.age) - (0.1263 * user1.weight) + (0.4472 * user1.height) + 20.4022) / 4.184 * activities[numActivities].duration);
               }

               // Display calculated calories burned
               printf("You burned %d kcal doing %s.\n\n", activities[numActivities].calories, activities[numActivities].activity);
               numActivities++;
            }
            break;
         }

         // View log
         case 2: {
            if (numActivities == 0) {
               printf("You have not logged any activities yet.\n\n");
            } else {
               printf("Activity\tDuration (min)\tCalories Burned\n");
               for (int i = 0; i < numActivities; i++) {
                  printf("%s\t\t%d\t\t%d\n", activities[i].activity, activities[i].duration, activities[i].calories);
               }
               printf("\n");
            }
            break;
         }

         // Update profile
         case 3: {
            printf("Please enter your age: ");
            scanf("%d", &user1.age);
            printf("Please enter your height in meters (ex: 1.85): ");
            scanf("%f", &user1.height);
            printf("Please enter your weight in kg: ");
            scanf("%f", &user1.weight);
            printf("Please enter your gender (male/female/non-binary): ");
            scanf("%s", user1.gender);
            printf("\nYour profile has been updated!\n\n");
            break;
         }

         // Exit program
         case 4: {
            printf("Goodbye!\n");
            break;
         }

         // Invalid input, prompt user to try again
         default: {
            printf("Invalid input! Please try again.\n\n");
            break;
         }
      }
   }

   return 0;
}