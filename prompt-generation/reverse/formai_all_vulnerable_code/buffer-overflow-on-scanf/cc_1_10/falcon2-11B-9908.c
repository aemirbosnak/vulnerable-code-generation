//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: protected
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

struct Elevator
{
    int id;
    char name[20];
    int floors;
    int currentFloor;
    bool isRunning;
    bool isStopped;
};

int main()
{
    struct Elevator el;
    int floors = 10;
    el.id = 1;
    strcpy(el.name, "Elevator 1");
    el.floors = floors;
    el.currentFloor = 1;
    el.isRunning = true;
    el.isStopped = false;

    while(el.isRunning)
    {
        printf("Current Floor: %d\n", el.currentFloor);
        printf("Floor 1 - %s\n", el.name);
        printf("Floor 2 - %s\n", el.name);
        //...
        printf("Floor %d - %s\n", el.currentFloor, el.name);
        printf("Enter destination floor (1-%d): ", el.floors);
        int destinationFloor;
        scanf("%d", &destinationFloor);
        if(destinationFloor < 1 || destinationFloor > el.floors)
        {
            printf("Invalid floor number. Please try again.\n");
        }
        else
        {
            if(el.currentFloor == destinationFloor)
            {
                printf("Reached destination floor %d.\n", destinationFloor);
            }
            else
            {
                int direction = 0;
                printf("Direction: ");
                scanf("%d", &direction);
                if(direction == 1)
                {
                    if(el.currentFloor!= el.floors)
                    {
                        el.currentFloor++;
                    }
                }
                else if(direction == 2)
                {
                    if(el.currentFloor!= 1)
                    {
                        el.currentFloor--;
                    }
                }
                else
                {
                    printf("Invalid direction. Please try again.\n");
                }
                if(el.currentFloor == destinationFloor)
                {
                    printf("Reached destination floor %d.\n", destinationFloor);
                }
                else
                {
                    printf("Reached floor %d.\n", el.currentFloor);
                }
            }
        }
    }
    return 0;
}