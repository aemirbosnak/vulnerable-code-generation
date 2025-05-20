//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define the number of floors and elevators
#define NUM_OF_FLOORS 10
#define NUM_OF_ELEVATORS 4

//Define constants for the direction of movement
#define UP 1
#define DOWN -1

//Structure for an elevator
typedef struct
{
    int id;
    int currentFloor;
    int direction;
} Elevator;

//Function to generate a random number between min and max
int getRandomNum(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    int i, j, k;
    int elevatorChoice = 0;
    int destinationFloor = 0;
    int temp = 0;

    //Seed the random number generator
    srand(time(NULL));

    //Create an array of elevators
    Elevator elevators[NUM_OF_ELEVATORS];

    //Initialize the elevators
    for (i = 0; i < NUM_OF_ELEVATORS; i++)
    {
        elevators[i].id = i + 1;
        elevators[i].currentFloor = getRandomNum(1, NUM_OF_FLOORS);
        elevators[i].direction = getRandomNum(UP, DOWN);
    }

    //Main loop
    while (1)
    {
        //Print the current status of each elevator
        printf("\nElevator Status:\n");
        for (i = 0; i < NUM_OF_ELEVATORS; i++)
        {
            printf("Elevator %d is on floor %d and moving %s\n", elevators[i].id, elevators[i].currentFloor, (elevators[i].direction == UP) ? "up" : "down");
        }

        //Prompt the user to choose an elevator and destination floor
        printf("\nEnter the number of the elevator you would like to use: ");
        scanf("%d", &elevatorChoice);
        printf("Enter the desired floor: ");
        scanf("%d", &destinationFloor);

        //Calculate the distance between the elevator and the destination floor
        int distance[NUM_OF_ELEVATORS];
        for (j = 0; j < NUM_OF_ELEVATORS; j++)
        {
            distance[j] = abs(elevators[j].currentFloor - destinationFloor);
        }

        //Find the closest elevator to the destination floor
        int closestElevator = 0;
        for (k = 1; k < NUM_OF_ELEVATORS; k++)
        {
            if (distance[k] < distance[closestElevator])
            {
                closestElevator = k;
            }
        }

        //Calculate the direction the elevator needs to move
        int direction = (destinationFloor > elevators[closestElevator].currentFloor) ? UP : DOWN;

        //Move the elevator to the destination floor
        while (elevators[closestElevator].currentFloor != destinationFloor)
        {
            printf("\nElevator %d is on floor %d\n", elevators[closestElevator].id, elevators[closestElevator].currentFloor);
            elevators[closestElevator].currentFloor += direction;
        }

        //Open the elevator doors
        printf("\nElevator %d has arrived on floor %d\n", elevators[closestElevator].id, elevators[closestElevator].currentFloor);
        printf("Doors are opening...\n");
        printf("Doors are open\n");

        //Close the elevator doors
        temp = elevators[closestElevator].currentFloor;
        while (temp != destinationFloor)
        {
            printf("\nElevator %d is on floor %d\n", elevators[closestElevator].id, temp);
            temp += direction;
        }
        printf("\nDoors are closing...\n");
        printf("Doors are closed\n");

        //Set the elevator direction based on the destination floor
        elevators[closestElevator].direction = (destinationFloor > elevators[closestElevator].currentFloor) ? UP : DOWN;

        //Print the current status of each elevator
        printf("\nElevator Status:\n");
        for (i = 0; i < NUM_OF_ELEVATORS; i++)
        {
            printf("Elevator %d is on floor %d and moving %s\n", elevators[i].id, elevators[i].currentFloor, (elevators[i].direction == UP) ? "up" : "down");
        }
    }

    return 0;
}