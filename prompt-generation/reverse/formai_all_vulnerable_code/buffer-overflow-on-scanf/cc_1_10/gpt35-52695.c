//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BAGGAGE 100 //maximum number of bags allowed in the system
#define MAX_FLIGHTS 10 //maximum number of flights allowed in the system
#define MAX_BAGS_PER_FLIGHT 20 //maximum number of bags allowed per flight

typedef struct Baggage {
   int id;
   int flight;
} Baggage;

//array of Baggage that represent all the bags in the system
Baggage baggage[MAX_BAGGAGE];
//arrays of integers that keep track of how many bags each flight has and the next available slot for each flight
int bags_per_flight[MAX_FLIGHTS] = {0};
int available_slot[MAX_FLIGHTS] = {0};

void add_baggage(int flight, int id) {
   //check if there is room for the bag in the system and the flight it belongs to
   if(bags_per_flight[flight] < MAX_BAGS_PER_FLIGHT) {
      if(available_slot[flight] < MAX_BAGS_PER_FLIGHT) {
         Baggage b = {id, flight};
         baggage[available_slot[flight]] = b;
         bags_per_flight[flight]++;
         available_slot[flight]++;
         printf("Added baggage ID %d to Flight %d.\n", id, flight);
      }
   }
   else {
      printf("Error: Flight %d is full, cannot add baggage ID %d.\n", flight, id);
   }
}

void remove_baggage(int id) {
   //find the bag with the matching ID and remove it from the system and the flight it belongs to
   for(int i = 0; i < MAX_BAGGAGE; i++) {
      if(baggage[i].id == id) {
         int flight = baggage[i].flight;
         for(int j = i; j < MAX_BAGGAGE - 1; j++) {
            baggage[j] = baggage[j+1];
         }
         bags_per_flight[flight]--;
         available_slot[flight]--;
         printf("Removed baggage ID %d from Flight %d.\n", id, flight);
         return;
      }
   }
   //if ID is not found
   printf("Error: Baggage with ID %d not found.\n", id);
}

void print_flight_bags(int flight) {
   printf("Flight %d Baggage:\n", flight);
   for(int i = 0; i < MAX_BAGS_PER_FLIGHT; i++) {
      for(int j = 0; j < MAX_BAGGAGE; j++) {
         if(baggage[j].id != 0 && baggage[j].flight == flight) {
            printf("ID: %d\n", baggage[j].id);
         }
      }
   }
}

int main() {
   int choice = 0;
   int id = 0;
   int flight = 0;

   while(true) {
      printf("\nAirport Baggage Handling\n");
      printf("=======================\n");
      printf("1. Add Baggage\n");
      printf("2. Remove Baggage\n");
      printf("3. Print Flight Baggage\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            printf("Enter Flight #: ");
            scanf("%d", &flight);
            printf("Enter Baggage ID: ");
            scanf("%d", &id);
            add_baggage(flight, id);
            break;
         case 2:
            printf("Enter Baggage ID: ");
            scanf("%d", &id);
            remove_baggage(id);
            break;
         case 3:
            printf("Enter Flight #: ");
            scanf("%d", &flight);
            print_flight_bags(flight);
            break;
         case 4:
            printf("Exiting the program.\n");
            exit(0);
            break;
         default:
            printf("Invalid choice, please try again.\n");
      }
   }

   return 0;
}