//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLIGHTS 10
#define MAX_BAGS 20

int main() {
  srand(time(NULL)); // Seed the random number generator
  
  // Initialize variables
  int flights[MAX_FLIGHTS][MAX_BAGS] = {0};
  int numFlights, numBagsPerFlight, numSeconds;
  int numBagsLoaded = 0, totalBags = 0;
  bool isSystemIdle = true;
  
  // Get user input for number of flights, number of bags per flight, and simulation time
  printf("Enter number of flights: ");
  scanf("%d", &numFlights);
  printf("Enter number of bags per flight: ");
  scanf("%d", &numBagsPerFlight);
  printf("Enter simulation time in seconds: ");
  scanf("%d", &numSeconds);
  
  // Start simulation
  for (int i = 0; i < numSeconds; i++) {
    // Check if a flight has arrived
    if (rand() % 10 < 3 && numBagsLoaded < totalBags) {
      int randomFlight = rand() % numFlights;
      
      // Check if there is enough space for the bags
      if (totalBags + numBagsPerFlight <= MAX_FLIGHTS * MAX_BAGS) {
        printf("Flight %d has arrived at time %d\n", randomFlight, i);
        totalBags += numBagsPerFlight;
        
        // Load bags onto conveyor belt
        for (int j = 0; j < numBagsPerFlight; j++) {
          int randomSlot = rand() % MAX_BAGS;
          while (flights[randomFlight][randomSlot] != 0) {
            randomSlot = rand() % MAX_BAGS;
          }
          flights[randomFlight][randomSlot] = 1;
        }
      } else {
        printf("Flight %d has arrived but there is not enough space for bags at time %d\n", randomFlight, i);
      }
    }
    
    // Check if there is a bag on the conveyor belt
    int numBagsOnBelt = 0;
    for (int j = 0; j < numFlights; j++) {
      for (int k = 0; k < MAX_BAGS; k++) {
        if (flights[j][k] == 1) {
          numBagsOnBelt++;
          isSystemIdle = false;
        }
      }
    }
    
    if (numBagsOnBelt == 0) {
      isSystemIdle = true;
    }
    
    // Load bag onto plane
    if (!isSystemIdle) {
      int randomFlight = rand() % numFlights;
      int randomSlot = rand() % MAX_BAGS;
      for (int j = 0; j < MAX_BAGS; j++) {
        if (flights[randomFlight][randomSlot] == 1) {
          flights[randomFlight][randomSlot] = 2;
          numBagsLoaded++;
          printf("Bag loaded onto Flight %d at time %d\n", randomFlight, i);
          break;
        } else {
          randomSlot = (randomSlot + 1) % MAX_BAGS;
        }
      }
    }
  }
  printf("Simulation ended at time %d\n", numSeconds);

  return 0;
}