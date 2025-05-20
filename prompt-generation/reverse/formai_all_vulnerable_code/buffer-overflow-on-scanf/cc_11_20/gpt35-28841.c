//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

enum DIR {UP, DOWN}; // Enumeration for the elevator direction

int main()
{
    int currentfloor = 0;
    int targetfloor = 0;
    enum DIR direction = UP;
    int floors[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Array of floors
    int numfloors = sizeof(floors) / sizeof(floors[0]); // Number of floors
    
    printf("Welcome to Elevator Simulation\n\n");
    
    while(1)
    {
        // Prompt user to enter current floor
        printf("Enter current floor (0-9): ");
        scanf("%d", &currentfloor);
        
        // Validate current floor
        if(currentfloor < 0 || currentfloor > 9)
        {
            printf("Invalid floor number. Please enter a number from 0 to 9.\n");
            continue;
        }

        while(1)
        {
            // Prompt user to enter target floor
            printf("Enter target floor (0-9): ");
            scanf("%d", &targetfloor);
            
            // Validate target floor
            if(targetfloor < 0 || targetfloor > 9)
            {
                printf("Invalid floor number. Please enter a number from 0 to 9.\n");
                continue;
            }
            
            // Set direction of elevator
            if(targetfloor > currentfloor)
                direction = UP;
            else if(targetfloor < currentfloor)
                direction = DOWN;
                
            // Prompt user to confirm target floor
            printf("You have selected floor %d. Is this correct? (Y/N): ", targetfloor);
            char answer;
            scanf(" %c", &answer);
            
            // Process user confirmation
            if(answer == 'Y' || answer == 'y')
                break;
            else if(answer == 'N' || answer == 'n')
                continue;
            else
            {
                printf("Invalid input. Please enter Y or N.\n");
                continue;
            }
        }
        
        // Move elevator to target floor
        while(currentfloor != targetfloor)
        {
            if(direction == UP)
                currentfloor++;
            else
                currentfloor--;
                
            printf("Elevator at floor %d\n", currentfloor);
        }
        
        // Open elevator doors
        printf("Doors opening...\n");
        printf("Doors closed.\n");
    }
    
    return 0;
}