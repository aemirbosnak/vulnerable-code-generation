//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_BAGS 500
#define MAX_WEIGHT 50

typedef struct _baggage {
   int bagID;
   float weight;
   char destination[10];
   int flightNo;
} Baggage;

typedef struct _conveyor {
   int capacity;
   int bagsInCount;
   Baggage bags[MAX_BAGS];
} Conveyor;

int main() {
   Conveyor conveyor;
   memset(&conveyor, 0, sizeof(conveyor)); // Initialize all conveyor values to 0

   int menuChoice;
   while (1) {
      printf("1. Add baggage to conveyor\n2. Remove baggage from conveyor\n3. Print the conveyor status\n4. Quit\n");
      printf("Enter your choice: ");
      scanf("%d", &menuChoice);

      switch (menuChoice) {
         case 1: {
            Baggage bag;
            printf("Enter the bag ID: ");
            scanf("%d", &bag.bagID);

            printf("Enter the weight of the bag: ");
            scanf("%f", &bag.weight);
            while (bag.weight > MAX_WEIGHT) { // Check if the bag weight is within limit
               printf("The maximum allowed weight is %d kg. Please enter a valid weight: ", MAX_WEIGHT);
               scanf("%f", &bag.weight);
            }

            printf("Enter the destination airport code (3-letter code): ");
            scanf("%s", bag.destination);

            printf("Enter the flight number: ");
            scanf("%d", &bag.flightNo);

            if (conveyor.bagsInCount == conveyor.capacity) { // Check if the conveyor is full
               printf("Sorry, the conveyor is full.\n");
            } else {
               conveyor.bags[conveyor.bagsInCount++] = bag; // Add the bag to the conveyor
               printf("The bag has been added to the conveyor.\n");
            }
            break;
         }
         case 2: {
            int bagID;
            printf("Enter the bag ID: ");
            scanf("%d", &bagID);

            int i;
            for (i = 0; i < conveyor.bagsInCount; i++) {
               if (conveyor.bags[i].bagID == bagID) {
                  // Remove the bag from the conveyor
                  conveyor.bagsInCount--;
                  printf("The bag has been removed from the conveyor.\n");
                  break;
               }
            }

            // Check if the bag was found in the conveyor
            if (i == conveyor.bagsInCount) {
               printf("The bag with ID %d was not found in the conveyor.\n", bagID);
            }
            break;
         }
         case 3: {
            // Print the status of the conveyor
            printf("Number of bags in conveyor: %d\n", conveyor.bagsInCount);
            printf("Bag ID | Weight | Destination | Flight No.\n");
            printf("---------------------------------------------\n");

            int i;
            for (i = 0; i < conveyor.bagsInCount; i++) {
               printf("%-6d | %-6.2f | %-10s | %-9d\n", 
                  conveyor.bags[i].bagID, conveyor.bags[i].weight, 
                  conveyor.bags[i].destination, conveyor.bags[i].flightNo);
            }
            break;
         }
         case 4: {
            return 0;
         }
         default: {
            printf("Invalid choice. Please enter a valid choice.\n");
            break;
         }
      }
   }
}