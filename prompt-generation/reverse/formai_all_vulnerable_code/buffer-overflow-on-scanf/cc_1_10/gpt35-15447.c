//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 20

// Function to print the contents of an array of integers
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int baggageQueue[MAX_CAPACITY];
  int conveyorBelt[MAX_CAPACITY];
  int exitGate[MAX_CAPACITY];
  
  int baggageCount = 0;
  int conveyorCount = 0;
  int exitCount = 0;
  
  int numPassengers;
  printf("Enter the number of passengers: ");
  scanf("%d", &numPassengers);

  // Start the simulation
  for (int i = 1; i <= numPassengers; i++) {
    printf("Passenger %d has arrived at the baggage check-in area.\n", i);
    
    // Check if the baggage queue is full
    if (baggageCount >= MAX_CAPACITY) {
      printf("Baggage queue is full. Passenger %d has left the airport.\n", i);
      continue;
    }
    
    // Add the passenger's baggage to the baggage queue
    baggageQueue[baggageCount] = i;
    baggageCount++;
    
    printf("Passenger %d has checked-in their baggage.\n", i);
    
    // Move one baggage from the baggage queue to the conveyor belt
    conveyorBelt[conveyorCount] = baggageQueue[0];
    conveyorCount++;
    baggageCount--;
    
    printf("A baggage has moved from the baggage queue to the conveyor belt.\n");
    
    // Check if the conveyor belt is full
    if (conveyorCount >= MAX_CAPACITY) {
      printf("Conveyor belt is full. Moving baggage to the exit gate.\n");
      for (int j = 0; j < conveyorCount; j++) {
        exitGate[exitCount] = conveyorBelt[j];
        exitCount++;
      }
      conveyorCount = 0;
    }
    
    // Print the contents of the baggage queue, conveyor belt, and exit gate
    printf("Baggage queue: ");
    printArray(baggageQueue, baggageCount);
    printf("Conveyor belt: ");
    printArray(conveyorBelt, conveyorCount);
    printf("Exit gate: ");
    printArray(exitGate, exitCount);
  }

  // Move all remaining baggage to the exit gate
  for (int i = 0; i < baggageCount; i++) {
    exitGate[exitCount] = baggageQueue[i];
    exitCount++;
  }
  for (int i = 0; i < conveyorCount; i++) {
    exitGate[exitCount] = conveyorBelt[i];
    exitCount++;
  }
  
  // Print the final contents of the exit gate
  printf("Final exit gate contents: ");
  printArray(exitGate, exitCount);

  return 0;
}