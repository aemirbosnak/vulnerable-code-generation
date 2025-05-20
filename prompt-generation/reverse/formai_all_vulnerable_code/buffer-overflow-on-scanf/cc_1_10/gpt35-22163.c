//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: statistical
#include<stdio.h>

int main() {
   int days;
   double total_cals = 0.0;
   double avg_cals;
   double cals_array[7];
   int i;

   printf("Welcome to your weekly fitness tracker!\n");

   // Gather calorie data for each day of the week
   for(i=0; i<7; i++) {
      printf("How many calories did you burn on day %d? ", i+1);
      scanf("%lf", &cals_array[i]);
   }

   // Calculate total calories burned for the week
   for(i=0; i<7; i++) {
      total_cals += cals_array[i];
   }

   // Calculate average calories burned per day
   avg_cals = total_cals/7.0;

   // Calculate standard deviation of calories burned per day
   double variance = 0.0;
   for(i=0; i<7; i++) {
      variance += pow((cals_array[i] - avg_cals), 2);
   }
   variance /= 7.0;
   double std_dev = sqrt(variance);

   // Output statistics
   printf("\nHere are your statistics for the week:\n");
   printf("Total calories burned: %.2lf\n", total_cals);
   printf("Average calories burned per day: %.2lf\n", avg_cals);
   printf("Standard deviation of calories burned per day: %.2lf\n", std_dev);

   // Determine if overall fitness goal was achieved
   printf("\nDid you achieve your fitness goal this week? (y/n) ");
   char answer;
   scanf(" %c", &answer);
   if(answer == 'y' || answer == 'Y'){
      printf("Congratulations! Keep up the good work!\n");
   }
   else {
      printf("Don't worry, there's always next week!\n");
   }

   return 0;
}