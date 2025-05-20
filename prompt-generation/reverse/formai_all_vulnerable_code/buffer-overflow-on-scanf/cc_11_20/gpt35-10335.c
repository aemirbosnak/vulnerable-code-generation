//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: synchronous
#include<stdio.h>

int main()
{
    int elevator_floor = 1;
    int requested_floor;
    int num_floors = 10;
    char direction = 'u'; // 'u' for up, 'd' for down
    int stop_floors[10] = {0}; // stops required for each floor
    
    while(1)
    {
        printf("You are currently on floor %d. Please enter the floor number you want to go to (-1 to exit): ", elevator_floor);
        
        scanf("%d", &requested_floor);
        
        if(requested_floor == -1)
        {
            printf("\nThank you for using the elevator simulator!\n");
            break;
        }
        
        if(requested_floor < 1 || requested_floor > num_floors)
        {
            printf("\nError: Please enter a valid floor number between 1 and %d.\n\n", num_floors);
            continue;
        }
        
        stop_floors[requested_floor - 1] = 1;
        
        if(requested_floor > elevator_floor)
        {
            direction = 'u';
        }
        else if(requested_floor < elevator_floor)
        {
            direction = 'd';
        }
        
        printf("\nDoor closing...\n");
        printf("Elevator moving %c...\n", direction);
        
        while(1)
        {
            if(direction == 'u') // moving up
            {
                elevator_floor++;
                printf("Elevator on floor %d\n", elevator_floor);
            }
            else // moving down
            {
                elevator_floor--;
                printf("Elevator on floor %d\n", elevator_floor);
            }
            
            if(stop_floors[elevator_floor - 1] == 1)
            {
                printf("Stopping at floor %d...\n", elevator_floor);
                stop_floors[elevator_floor - 1] = 0;
            }
            
            if(elevator_floor == requested_floor)
            {
                printf("Door opening...\n");
                break;
            }
        }
    }
    
    return 0;
}