//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>

// This program is a simple fitness tracker that allows the user to input various data related to their daily exercise routine. 

int main() {
   int numDays, i, j;
   float avgTime, totalTime, totalMiles, avgMiles, pace;
   char response;
   
   printf("Welcome to the fitness tracker program!\n");
   printf("How many days would you like to track your exercise for?\n");
   scanf("%d", &numDays);
   
   float time[numDays], miles[numDays];
   
   for (i = 0; i < numDays; i++) {
      printf("Enter the amount of time you exercised today (in minutes):\n");
      scanf("%f", &time[i]);
      
      printf("Enter the distance you covered today (in miles):\n");
      scanf("%f", &miles[i]);
   }
   
   // Calculate overall stats for the tracked days:
   
   for (j = 0; j < numDays; j++) {
      totalTime += time[j];
      totalMiles += miles[j];
   } 
   
   avgTime = totalTime / numDays;
   avgMiles = totalMiles / numDays;
   pace = totalTime / totalMiles;
   
   printf("Here are your overall statistics:\n");
   printf("Total time spent exercising in %d days: %.2f minutes\n", numDays, totalTime);
   printf("Average time spent exercising per day: %.2f minutes\n", avgTime);
   printf("Total distance covered in %d days: %.2f miles\n", numDays, totalMiles);
   printf("Average distance covered per day: %.2f miles\n", avgMiles);
   printf("Overall pace: %.2f minutes per mile\n", pace);
   
   // Prompt the user for their exercise goal for the current day:
   
   printf("What is your exercise goal for today? Enter 'T' for time or 'D' for distance:\n");
   scanf(" %c", &response);
   
   if (response == 'T') {
      float goalTime;
      printf("How many minutes would you like to exercise for today?\n");
      scanf("%f", &goalTime);
      
      if (goalTime <= avgTime) {
         printf("Great job! You have already surpassed your average exercise time for this week.\n");
      } else {
         printf("You need to exercise for %.2f more minutes to reach your goal for the day.\n", goalTime - avgTime);
      }
      
   } else if (response == 'D') {
      float goalDistance;
      printf("How many miles would you like to cover today?\n");
      scanf("%f", &goalDistance);
      
      if (goalDistance <= avgMiles) {
         printf("Awesome! You have already surpassed your average distance covered for this week.\n");
      } else {
         printf("You need to cover %.2f more miles to reach your goal for the day.\n", goalDistance - avgMiles);
      }
      
   } else {
      printf("Invalid option.\n");
   }
   
   return 0;
}