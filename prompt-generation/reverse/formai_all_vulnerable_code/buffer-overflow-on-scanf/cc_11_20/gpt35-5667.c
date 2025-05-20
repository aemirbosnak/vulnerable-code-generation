//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 1000
#define MAX_WEIGHT 100
#define MAX_FLIGHTS 10
#define MAX_TERMINALS 5
#define MAX_CONVEYORS 10

typedef struct {
   int flight_number;
   int terminal_number;
   double weight;
} baggage;

int main() {
   srand(time(0)); // Seed the random number generator
   int num_flights, num_terminals, num_conveyors, time_limit;
   
   // Get user inputs
   printf("Enter the number of flights: ");
   scanf("%d", &num_flights);
   printf("Enter the number of terminals: ");
   scanf("%d", &num_terminals);
   printf("Enter the number of conveyors: ");
   scanf("%d", &num_conveyors);
   printf("Enter the simulation time limit (in seconds): ");
   scanf("%d", &time_limit);
   
   // Initialize arrays to store baggage, flights, terminals, and conveyors
   baggage baggage_list[MAX_BAGGAGE];
   int flight_list[MAX_FLIGHTS];
   int terminal_list[MAX_TERMINALS];
   int conveyor_list[MAX_CONVEYORS];
   int num_bags = 0;
   
   // Generate random flight and terminal numbers
   for (int i = 0; i < num_flights; i++) {
      flight_list[i] = rand() % 100 + 1;
   }
   for (int i = 0; i < num_terminals; i++) {
      terminal_list[i] = rand() % 5 + 1;
   }
   
   // Generate random baggage with flight numbers, terminal numbers, and weights
   while (num_bags < MAX_BAGGAGE) {
      baggage_list[num_bags].flight_number = flight_list[rand() % num_flights];
      baggage_list[num_bags].terminal_number = terminal_list[rand() % num_terminals];
      baggage_list[num_bags].weight = (double)((rand() % MAX_WEIGHT) + 1)/10;
      num_bags++;
   }
   
   // Initialize conveyors to empty
   for (int i = 0; i < num_conveyors; i++) {
      conveyor_list[i] = 0;
   }
   
   // Simulate airport baggage handling
   int time = 0;
   while (time < time_limit) {
      // Check if baggage needs to be added to conveyor
      if (num_bags > 0) {
         int conveyor_index = rand() % num_conveyors;
         if (conveyor_list[conveyor_index] == 0) {
            conveyor_list[conveyor_index] = num_bags;
            num_bags--;
         }
      }
      
      // Output current conveyor contents
      printf("\nTime: %d\nConveyor contents: [ ", time);
      for (int i = 0; i < num_conveyors; i++) {
         if (conveyor_list[i] != 0) {
            printf("%d ", conveyor_list[i]);
         }
      }
      printf("]\n");
      
      // Check if baggage needs to be removed from conveyor
      for (int i = 0; i < num_conveyors; i++) {
         if (conveyor_list[i] != 0) {
            int conveyor_bags = conveyor_list[i];
            int num_removed = rand() % conveyor_bags + 1;
            conveyor_list[i] -= num_removed;
            printf("%d bags removed from conveyor %d\n", num_removed, i+1);
         }
      }
      
      // Wait 1 second before next iteration
      sleep(1);
      time++;
   }
   
   return 0;
}