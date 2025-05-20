//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: beginner-friendly
#include <stdio.h>

int main() {
   int currentFloor = 1, destinationFloor, numFloors = 10, numPassengers;
   int elevatorWeightLimit = 1000, currentElevatorWeight = 0, passengerWeight;
   int numPassengersGoingUp = 0, numPassengersGoingDown = 0;
   int i, j;
   char direction[10];

   // Initializing the elevator with 0 passengers
   printf("Initializing elevator...\n");
   
   // Looping until the user enters an invalid number of passengers
   do {
      printf("Enter the number of passengers (max %d): ", (elevatorWeightLimit-currentElevatorWeight)/50);
      scanf("%d", &numPassengers);
   } while((numPassengers*50 + currentElevatorWeight) > elevatorWeightLimit);

   // Getting the destination floor for each passenger and their weight
   for(i = 1; i <= numPassengers; i++) {
      printf("\nPassenger %d details:\n", i);
      printf("Enter the destination floor (1 to %d): ", numFloors);
      scanf("%d", &destinationFloor);
      printf("Enter the passenger weight: ");
      scanf("%d", &passengerWeight);

      // Calculating the passenger count in up and down direction
      if(destinationFloor > currentFloor) {
         numPassengersGoingUp++;
      } 
      else if(destinationFloor < currentFloor) {
         numPassengersGoingDown++;
      }

      // Updating the elevator weight after adding the passenger
      currentElevatorWeight += passengerWeight;
   }

   // Determining the direction in which the elevator should go
   if(numPassengersGoingUp > numPassengersGoingDown) {
      sprintf(direction, "up");
   } 
   else if(numPassengersGoingUp < numPassengersGoingDown) {
      sprintf(direction, "down");
   } 
   else {
      printf("\nThere are equal number of passengers going up and down.\n");
      printf("The elevator will go up.\n\n");
      sprintf(direction, "up");
   }

   // Updating the current floor as per the direction of the elevator
   if(strcmp(direction, "up") == 0) currentFloor = 1;
   else currentFloor = numFloors;

   // Elevator simulation
   printf("\nElevator simulation:\n");
   for(i = currentFloor; (strcmp(direction, "up") == 0) ? i <= numFloors : i >= 1; (strcmp(direction, "up") == 0) ? i++ : i--) {
      printf("\nCurrent floor: %d\n", i);
      for(j = 1; j <= numPassengers; j++) {
         if(currentFloor == destinationFloor) {
            printf("\nPassenger %d has reached their destination.\n", j);
            currentElevatorWeight -= passengerWeight;
         }
      }
   }
   printf("\nThe elevator simulation is complete.\n");

   return 0;
}