//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void traffic(char *current_light); // Function prototype declaration

void main() {
   char light;
   printf("Traffic Light Controller Simulation\n");
   printf("-----------------------------------\n");

   // Generate random traffic light at startup
   srand(time(0)); // Seed the random number generator with the current time
   int random = rand() % 3; // Generate random number from 0 to 2
   if(random == 0) {
      light = 'R';
      printf("Initial light: Red\n");
   }
   else if(random == 1) {
      light = 'Y';
      printf("Initial light: Yellow\n");
   }
   else {
      light = 'G';
      printf("Initial light: Green\n");
   }

   traffic(&light); // Call the traffic function with the initial light
}

// Function definition
void traffic(char *current_light) {
   int time_remaining = 10; // Initialize timer to 10 seconds
   int switch_light = 0; // Used to determine if we need to switch the light

   while(1) { // Infinite loop
      if(time_remaining == 0) { // Timer has ran out
         switch_light = 1;
         time_remaining = 10;
      }

      if(switch_light == 1) { // Switch the light
         if(*current_light == 'R') {
            *current_light = 'G';
            printf("Light: Green\n");
         }
         else if(*current_light == 'G') {
            *current_light = 'Y';
            printf("Light: Yellow\n");
         }
         else { // Yellow
            *current_light = 'R';
            printf("Light: Red\n");
         }
         switch_light = 0;
      }

      printf("Time remaining: %d seconds\n", time_remaining);

      // Sleep for one second
      clock_t start_time = clock();
      while(clock() < start_time + 1000); // Wait for 1000 milliseconds (1 second)

      time_remaining--; // Decrement timer
   }
}