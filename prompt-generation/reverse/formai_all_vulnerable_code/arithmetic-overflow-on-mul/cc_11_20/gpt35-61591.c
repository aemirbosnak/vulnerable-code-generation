//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int numFlights, numGates, numBags;

  // Get input from user
  printf("Enter the number of flights: ");
  scanf("%d", &numFlights);
  printf("Enter the number of gates: ");
  scanf("%d", &numGates);
  printf("Enter the number of bags per flight: ");
  scanf("%d", &numBags);

  // Create arrays to store information
  int flights[numFlights][numBags];
  int gates[numGates][numBags];
  int bags[numFlights*numBags];

  // Initialize flight and gate arrays
  for (int i = 0; i < numFlights; i++) {
    for (int j = 0; j < numBags; j++) {
      flights[i][j] = (rand() % 100) + 1; // randomly assign weight between 1-100
    }
  }
  for (int i = 0; i < numGates; i++) {
    for (int j = 0; j < numBags; j++) {
      gates[i][j] = -1; // initialize all to -1 (unassigned)
    }
  }

  // Assign bags to flights
  for (int i = 0; i < numFlights; i++) {
    for (int j = 0; j < numBags; j++) {
      bags[i*numBags+j] = flights[i][j]; // add bag weight to bags array
    }
  }

  // Sort bags array in descending order
  for (int i = 0; i < numFlights*numBags-1; i++) {
    for (int j = 0; j < numFlights*numBags-i-1; j++) {
      if (bags[j] < bags[j+1]) {
        int temp = bags[j];
        bags[j] = bags[j+1];
        bags[j+1] = temp;
      }
    }
  }

  // Assign bags to gates
  int bagIndex = 0;
  for (int i = 0; i < numGates; i++) {
    for (int j = 0; j < numBags; j++) {
      if (bagIndex == numFlights*numBags) break; // all bags assigned
      for (int k = 0; k < numFlights; k++) {
        if (flights[k][j] == bags[bagIndex] && gates[i][j] == -1) {
          gates[i][j] = k; // assign gate to flight
          bagIndex++; // move to next bag
          break;
        }
      }
    }
  }

  // Print assignment matrix
  printf("\nFlight\t\tGate\n");
  for (int i = 0; i < numFlights; i++) {
    printf("%d: ", i+1);
    for (int j = 0; j < numGates; j++) {
      for (int k = 0; k < numBags; k++) {
        if (gates[j][k] == i) {
          printf("%d ", j+1);
          break;
        }
      }
    }
    printf("\n");
  }
  return 0;
}