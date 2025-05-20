//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 10 // maximum number of floors in the building

int main()
{
    int num_floors;
    int current_floor = 1;
    int requested_floor;
    bool moving_up = true;
    bool doors_open = false;
    
    // get number of floors in the building from user
    printf("Enter the number of floors in the building (max %d): ", MAX_FLOORS);
    scanf("%d", &num_floors);
    
    // check if number of floors is within limits
    if (num_floors < 1 || num_floors > MAX_FLOORS)
    {
        printf("Invalid number of floors.\n");
        return 1; // exit program with error code
    }
    
    // simulate elevator operation
    while (true)
    {
        // print current status of elevator
        printf("Current floor: %d\n", current_floor);
        printf("Doors %s\n", doors_open ? "open" : "closed");
        
        // prompt user for requested floor
        printf("Enter requested floor: ");
        scanf("%d", &requested_floor);
        
        // check if requested floor is within limits
        if (requested_floor < 1 || requested_floor > num_floors)
        {
            printf("Invalid floor number.\n");
            continue; // go to the beginning of the while loop and prompt user again
        }
        
        // check if requested floor is the same as current floor
        if (requested_floor == current_floor)
        {
            printf("You are already on that floor.\n");
            continue; // go to the beginning of the while loop and prompt user again
        }
        
        // check if elevator is moving in the right direction
        if ((requested_floor > current_floor && !moving_up) ||
            (requested_floor < current_floor && moving_up))
        {
            printf("Elevator is going in the wrong direction.\n");
            continue; // go to the beginning of the while loop and prompt user again
        }
        
        // calculate the number of floors to travel
        int num_floors_to_travel = abs(requested_floor - current_floor);
        
        // simulate elevator movement
        for (int i = 0; i < num_floors_to_travel; i++)
        {
            // print current status of elevator
            printf("Current floor: %d\n", current_floor);
            printf("Doors %s\n", doors_open ? "open" : "closed");
            
            // move elevator one floor up or down depending on direction
            if (moving_up)
            {
                current_floor++;
            }
            else
            {
                current_floor--;
            }
            
            // check if elevator has reached requested floor
            if (current_floor == requested_floor)
            {
                // open doors and print message
                doors_open = true;
                printf("Doors opening on floor %d.\n", current_floor);
                
                // wait for user to enter or leave elevator
                printf("Press any key to close doors.\n");
                getchar(); // clear input buffer
                getchar(); // wait for user input
                
                // close doors and print message
                doors_open = false;
                printf("Doors closing.\n");
            }
        }
        
        // change direction of elevator
        moving_up = !moving_up;
    }
    
    return 0;
}