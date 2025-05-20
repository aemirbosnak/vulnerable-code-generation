//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int num_bags, conveyor_speed, bag_count=0, wait_time=0, processed=0, sacks_of_grain=0;

   srand(time(NULL));

   printf("Welcome to the Medieval Baggage Handling Simulation\n\n");
   printf("Enter number of bags to process (max 100): ");
   scanf("%d", &num_bags);
   printf("Enter conveyor belt speed (1-10): ");
   scanf("%d", &conveyor_speed);

   if(num_bags > 100) {
      printf("Error: max number of bags is 100\n");
      return 1;
   }
   if(conveyor_speed < 1 || conveyor_speed > 10) {
      printf("Error: conveyor speed must be between 1 and 10\n");
      return 1;
   }

   printf("\nProcessing %d bags at conveyor speed %d...\n\n", num_bags, conveyor_speed);

   while(processed < num_bags) {
      printf("Processing bag #%d...\n", bag_count);
      wait_time = rand() % 10;
      printf("Waiting for bag to arrive (%d seconds)...\n", wait_time);
      sacks_of_grain += wait_time; // add wait time to sacks of grain count
      bag_count++;
      processed++;

      if(conveyor_speed < 5) { // slow conveyor speed
         wait_time = rand() % 10;
         printf("Sending bag to storage room for inspection (%d seconds)...\n", wait_time);
         sacks_of_grain += wait_time; // add inspection time to sacks of grain count
      }
      else { // fast conveyor speed
         wait_time = rand() % 5;
         printf("Loading bag onto cart for transport (%d seconds)...\n", wait_time);
      }
      
      printf("Bag processing complete!\n\n");
   }

   printf("All bags have been processed. Total number of sacks of grain handled: %d\n", sacks_of_grain);

   return 0;
}