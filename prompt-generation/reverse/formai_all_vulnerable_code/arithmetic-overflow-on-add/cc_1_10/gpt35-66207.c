//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define ELEVATOR_SPEED 3

// Function to simulate time delay
void delay(int sec)
{
    clock_t start_time = clock();
    while (clock() < start_time + sec * CLOCKS_PER_SEC);
}

// Function to randomly generate floor numbers
int randomFloor()
{
    return rand() % NUM_FLOORS + 1;
}

// Main function
int main()
{
    srand(time(NULL));
    
    // Initialize elevator state variables
    int currentFloor = 1;
    int destinationFloor = 0;
    int passengers = 0;
    
    printf("Welcome to the Elevator Simulation Program!");
    
    // Main loop
    while(1)
    {
        printf("Current floor: %d\n", currentFloor);
        
        // Check if there are any passengers inside the elevator
        if (passengers == 0)
        {
            destinationFloor = randomFloor();
            printf("Elevator is currently empty. Heading to floor %d...\n", destinationFloor);
            delay(destinationFloor/ELEVATOR_SPEED);
            currentFloor = destinationFloor;
        }
        else
        {
            printf("Elevator has %d passengers.\n", passengers);
            int choice = 0;
            
            while (choice < 1 || choice > passengers)
            {
                printf("Which passenger would you like to drop off? Enter a number from 1 to %d: ", passengers);
                scanf("%d", &choice);
            }
            
            printf("Passenger %d has been dropped off on floor %d.\n", choice, currentFloor);
            passengers--;
            
            if (passengers == 0)
            {
                printf("Elevator is now empty. Heading to a new floor...\n");
                destinationFloor = randomFloor();
                delay(abs(destinationFloor - currentFloor)/ELEVATOR_SPEED);
                currentFloor = destinationFloor;
            }
        }
        
        printf("Enter 1 to add a passenger, or 0 to exit: ");
        int addPassenger = 0;
        scanf("%d", &addPassenger);
        
        if (addPassenger == 1)
        {
            printf("New passenger has been added.\n");
            passengers++;
        }
        else
        {
            printf("Thank you for using the Elevator Simulation Program!");
            break;
        }
    }
    
    return 0;
}