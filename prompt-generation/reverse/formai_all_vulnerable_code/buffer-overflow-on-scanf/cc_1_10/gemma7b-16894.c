//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: peaceful
#include <stdlib.h>
#include <time.h>

int main()
{

    int floor;
    int currentFloor = 1;
    int destinationFloor;
    char direction;

    // Create a timer to simulate the elevator movement
    time_t startTimer = time(NULL);
    time_t endTimer;

    // Display the current floor
    printf("Current floor: %d\n", currentFloor);

    // Get the destination floor
    printf("Enter your destination floor: ");
    scanf("%d", &destinationFloor);

    // Calculate the direction of travel
    if (destinationFloor > currentFloor)
    {
        direction = 'U';
    }
    else
    {
        direction = 'D';
    }

    // Simulate the elevator movement
    endTimer = time(NULL) + 3;
    while (time(NULL) < endTimer)
    {
        // Update the current floor
        currentFloor++;

        // Display the current floor
        printf("Current floor: %d\n", currentFloor);

        // Sleep for a while
        sleep(1);
    }

    // Stop the elevator
    currentFloor = destinationFloor;

    // Display the destination floor
    printf("Destination floor: %d\n", currentFloor);

    // Display a message
    printf("Thank you for riding the elevator.\n");

    return 0;
}