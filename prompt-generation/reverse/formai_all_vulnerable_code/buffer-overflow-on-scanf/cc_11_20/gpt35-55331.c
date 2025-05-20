//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to simulate the remote control vehicle */
void simulate_vehicle(int x, int y, int direction)
{
    printf("Starting vehicle at position (%d, %d) facing direction: ", x, y);
    if(direction == 0) printf("North\n");
    else if(direction == 1) printf("East\n");
    else if(direction == 2) printf("South\n");
    else printf("West\n");
    
    char input;
    while(1)
    {
        printf("\nEnter command (F for forward, L for turn left, R for turn right): ");
        scanf(" %c", &input);
        
        if(input == 'F')
        {
            if(direction == 0) y++;
            else if(direction == 1) x++;
            else if(direction == 2) y--;
            else x--;
            printf("Vehicle moved to position (%d, %d) facing direction: ", x, y);
            if(direction == 0) printf("North\n");
            else if(direction == 1) printf("East\n");
            else if(direction == 2) printf("South\n");
            else printf("West\n");
        }
        else if(input == 'L')
        {
            direction = (direction + 3) % 4;
            printf("Vehicle turned left. Now facing direction: ");
            if(direction == 0) printf("North\n");
            else if(direction == 1) printf("East\n");
            else if(direction == 2) printf("South\n");
            else printf("West\n");
        }
        else if(input == 'R')
        {
            direction = (direction + 1) % 4;
            printf("Vehicle turned right. Now facing direction: ");
            if(direction == 0) printf("North\n");
            else if(direction == 1) printf("East\n");
            else if(direction == 2) printf("South\n");
            else printf("West\n");
        }
        else printf("Invalid input. Please try again.\n");
        
        /* Randomly end simulation */
        if(rand() % 10 == 0)
        {
            printf("Simulation ended due to remote control malfunction.\n");
            break;
        }
    }
}

int main()
{
    srand(time(NULL)); // Initialize random seed
    int x = rand() % 10;
    int y = rand() % 10;
    int direction = rand() % 4;
    simulate_vehicle(x, y, direction);
    return 0;
}