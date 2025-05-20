//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main() {
   int days, i;
   float weight, height;
   float bmi;
   float total_calories = 0;

   printf("Welcome to the C Fitness Tracker\n");
   printf("Enter your weight in kg: ");
   scanf("%f", &weight);

   printf("Enter your height in meters: ");
   scanf("%f", &height);

   bmi = weight / (height * height);
   printf("Your BMI is: %.2f\n\n", bmi);

   printf("How many days would you like to track: ");
   scanf("%d", &days);

   float calories[days];
   float water[days];

   for (i = 0; i < days; i++) {
      printf("\nDAY %d\n", i + 1);
      printf("Enter the number of calories you ate today: ");
      scanf("%f", &calories[i]);
      total_calories += calories[i];
      printf("Enter the amount of water you drank today (in liters): ");
      scanf("%f", &water[i]);
   }

   printf("\nCALORIES:\n");

   for (i = 0; i < days; i++) {
      printf("Day %d: %.2f calories\n", i + 1, calories[i]);
   }

   printf("Total calories consumed over %d days: %.2f calories\n", days, total_calories);
   printf("Average calories consumed per day: %.2f calories\n", total_calories / days);

   printf("\nWATER:\n");

   for (i = 0; i < days; i++) {
      printf("Day %d: %.2f liters\n", i + 1, water[i]);
   }

   return 0;
}