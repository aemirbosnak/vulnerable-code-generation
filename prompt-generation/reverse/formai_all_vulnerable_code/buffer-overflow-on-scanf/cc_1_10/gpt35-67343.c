//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include <stdio.h>

// Function to simulate the elevator movements
void simulateElevator(int currentFloor) {
	int destination, floorDifference;
	
	// Request for destination floor from current floor
	printf("\nYou are currently on floor %d.", currentFloor);
	printf("\nEnter your destination floor from 0 to 9: ");
	scanf("%d", &destination);
	
	// Calculate the difference between floors
	floorDifference = destination - currentFloor;
	
	// Check for invalid destination floor
	if(destination < 0 || destination > 9) {
		printf("\nInvalid destination floor entered. Please enter a floor between 0 to 9.");
		return;
	}
	
	// Move the elevator up or down based on the destination floor
	if(floorDifference > 0) {
		printf("\nThe elevator is moving up from floor %d to floor %d.", currentFloor, destination);
		while(currentFloor != destination) {
			currentFloor++;
			printf("\nArrived at floor %d.", currentFloor);
		}
		printf("\nYou have arrived at your destination floor %d.", destination);
	} else if(floorDifference < 0) {
		printf("\nThe elevator is moving down from floor %d to floor %d.", currentFloor, destination);
		while(currentFloor != destination) {
			currentFloor--;
			printf("\nArrived at floor %d.", currentFloor);
		}
		printf("\nYou have arrived at your destination floor %d.", destination);
	} else {
		printf("\nYou are already on floor %d.", currentFloor);
	}
}

int main() {
	int currentFloor = 0;
	char choice;
	
	do {
		// Display the elevator options and ask for user choice
		printf("\nWelcome to the shape shifting elevator. What would you like to do?\n");
		printf("1. Simulate elevator movement\n");
		printf("2. Exit\n");
		printf("\nEnter your choice: ");
		scanf(" %c", &choice);
		
		switch(choice) {
			case '1': // Simulate elevator movement
				simulateElevator(currentFloor);
				break;
			
			case '2': // Exit program
				printf("\nThank you for using the shape shifting elevator!");
				break;
			
			default: // Invalid choice
				printf("\nInvalid choice entered. Please enter 1 or 2.");
				break;
		}
		
	} while(choice != '2');
	
	return 0;
}