//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGGAGE 1000   // Maximum number of bags that can be handled
#define MAX_TERMINALS 10   // Maximum number of terminals at the airport

/* Baggage struct */
typedef struct {
   int weight;             // Weight of the bag
   int terminal;           // Terminal for the destination
} Baggage;

int main() {
   int num_bags, num_terminals, i, j, k;
   int total_weight[MAX_TERMINALS] = {0};  // Total weight of baggage for each terminal
   Baggage baggage[MAX_BAGGAGE];           // Array to store all the bags

   printf("Enter the number of bags: ");
   scanf("%d", &num_bags);

   // Input data for each bag
   for (i = 0; i < num_bags; ++i) {
      printf("\nBag %d details:\n", i+1);
      printf("Enter the weight of the bag in kgs: ");
      scanf("%d", &baggage[i].weight);
      printf("Enter the terminal number for the bag: ");
      scanf("%d", &baggage[i].terminal);
      if (baggage[i].terminal > MAX_TERMINALS) {
         printf("Invalid terminal number. Please enter a number from 1 to %d only.\n", MAX_TERMINALS);
         --i;
      }
   }

   num_terminals = MAX_TERMINALS; // Assume all terminals are operational
   
   // Display the input data for each bag
   printf("\nInput data for each baggage:\n");
   printf("Bag        Weight(kgs)         Terminal\n");
   printf("------------------------------------------------\n");
   for (i = 0; i < num_bags; ++i) {
      printf("%4d%15d%18d\n", i+1, baggage[i].weight, baggage[i].terminal);
   }

   // Calculate the total weight for each terminal
   for (i = 0; i < num_bags; ++i) {
      total_weight[baggage[i].terminal-1] += baggage[i].weight;
   }

   // Display the total weight for each terminal
   printf("\nTotal weight for each terminal:\n");
   printf("Terminal     Total weight(kgs)\n");
   printf("-------------------------------------\n");
   for (i = 0; i < num_terminals; ++i) {
      printf("%3d%17d\n", i+1, total_weight[i]);
   }

   // Sort the bags based on their weight
   for (i = 0; i < num_bags-1; ++i) {
      for (j = i+1; j < num_bags; ++j) {
         if (baggage[i].weight > baggage[j].weight) {
            // Swap the bags
            Baggage temp = baggage[i];
            baggage[i] = baggage[j];
            baggage[j] = temp;
         }
      }
   }

   // Display the sorted bags
   printf("\nSorted baggage based on weight:\n");
   printf("Bag        Weight(kgs)         Terminal\n");
   printf("------------------------------------------------\n");
   for (i = 0; i < num_bags; ++i) {
      printf("%4d%15d%18d\n", i+1, baggage[i].weight, baggage[i].terminal);
   }

   // Allocate baggage to each terminal in a fair manner
   printf("\nAllocation of baggage to each terminal:\n");
   printf("Terminal         Baggage\n");
   printf("----------------------------------\n");
   for (i = 0; i < num_terminals; ++i) {
      printf("%3d:", i+1);
      int total = 0;
      for (j = 0; j < num_bags; ++j) {
         if (baggage[j].terminal == i+1) {
            printf("%4d", j+1);
            total += baggage[j].weight;
         }
      }
      // Check if the total weight for the terminal is within limits
      if (total > 1000) {
         printf("\nTotal weight for terminal %d exceeds 1000 kgs. Please redistribute the baggage.\n", i+1);
      }
      printf("\n");
   }

   return 0;
}