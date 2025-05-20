//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int probability, aliens, ships, weapons, year, population;
   srand(time(NULL)); //Set seed for random function

   //Gather data from user
   printf("Enter the current year (YYYY): ");
   scanf("%d", &year);
   printf("Enter the current world population: ");
   scanf("%d", &population);
   printf("Enter the total number of alien species known to exist: ");
   scanf("%d", &aliens);
   printf("Enter the total number of alien ships known to exist: ");
   scanf("%d", &ships);
   printf("Enter the total number of advanced weapons owned by humans: ");
   scanf("%d", &weapons);

   //Calculate probability of alien invasion
   probability = 100 - ((year/2) + (population/1000000000) + (aliens*10) + (ships*5) - (weapons*2));
   if (probability < 0) {
      probability = 0;
   }
   else if (probability > 100) {
      probability = 100;
   }

   //Print results to user
   printf("\nBased on the data provided, the probability of an alien invasion is %d%%.", probability);

   //Provide additional analysis of probability
   if (probability == 0) {
      printf("\nIt is highly unlikely that an alien invasion will occur.");
   }
   else if (probability <= 25) {
      printf("\nAn alien invasion is possible, but unlikely.");
   }
   else if (probability <= 50) {
      printf("\nAn alien invasion is moderately likely.");
   }
   else if (probability <= 75) {
      printf("\nAn alien invasion is very likely.");
   }
   else {
      printf("\nAn alien invasion is imminent. Take action to defend Earth!");
   }

   return 0;
}