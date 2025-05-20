//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   float alienProb = 0.0;
   int playerLevel, numAliens, timeOfDay;
   char playerResponse;

   srand(time(0));

   printf("Welcome to the Alien Invasion Probability Calculator. Let's get started!\n");

   printf("What is your current level?");
   scanf("%d", &playerLevel);

   if (playerLevel <= 10) {
      alienProb += 0.2;
   }
   else if (playerLevel > 10 && playerLevel <= 20) {
      alienProb += 0.35;
   }
   else {
      alienProb += 0.5;
   }

   printf("How many aliens do you think will invade?");
   scanf("%d", &numAliens);

   if (numAliens == 0) {
      printf("Are you sure? The probability of a zero invasion is extremely low. Y/N \n");
      scanf(" %c", &playerResponse);
      if (playerResponse == 'N' || playerResponse == 'n') {
         printf("Good choice. Let's try again. \n");
         main();
         return 0;
      }
   }
   
   alienProb += numAliens * 0.1;

   printf("What time of day do you think the aliens will come?");
   printf("1. Morning\n2. Afternoon\n3. Evening\n");
   scanf("%d", &timeOfDay);

   switch (timeOfDay) {
      case 1:
         alienProb += 0.05;
         break;

      case 2:
         alienProb += 0.1;
         break;

      case 3:
         alienProb += 0.15;
         break;

      default:
         printf("Invalid option.\n");
         main();
         return 0;
   }

   if (rand() % 2 == 0) {
      alienProb += 0.25;
   }

   printf("Your estimated probability of an alien invasion is: %.2f percent\n", alienProb * 100);
   printf("Remember to always stay alert and prepared.\n");
   
   return 0;
}