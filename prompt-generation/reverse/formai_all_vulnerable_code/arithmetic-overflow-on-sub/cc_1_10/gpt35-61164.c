//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // Set the seed for random number generator.
   srand(time(NULL));
   
   // Ask user to input the year they wish to travel to.
   int year;
   printf("Which year would you like to travel to? ");
   scanf("%d", &year);
   
   // Calculate the years of travel.
   int years_to_travel = abs(year - 2021);
   
   // Print out the travel year and the years of travel.
   printf("Traveling to %d... (%d years to travel)\n", year, years_to_travel);
   printf("> Initializing time travel sequence...");

   // Simulate time travel sequence.
   for (int i = 5; i >= 1; i--) {
      printf("\n%d...\n", i);
      sleep(1);
   }

   // Print out arrival message.
   printf("\n> Arrival confirmed: %d\n", year);

   // Print out a random historical fact about the year traveled to.
   switch(year) {
      case 1066:
         printf("In 1066, William, Duke of Normandy, conquered England in the Battle of Hastings.\n");
         break;
      case 1776:
         printf("In 1776, the United States declared its independence from Great Britain.\n");
         break;
      case 1969:
         printf("In 1969, the United States successfully landed astronauts on the moon.\n");
         break;
      default:
         printf("Sorry, no historical events found for %d.\n", year);
         break;
   }

   printf("> Return sequence initiating...");
   
   // Simulate return sequence.
   for (int i = 5; i >= 1; i--) {
      printf("\n%d...\n", i);
      sleep(1);
   }

   // Print out return message.
   printf("\n> You have returned to 2021.\n");
   
   return 0;
}