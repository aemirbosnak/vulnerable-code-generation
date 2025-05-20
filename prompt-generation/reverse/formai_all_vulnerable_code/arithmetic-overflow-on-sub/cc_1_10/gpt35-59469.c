//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// stores the current position of the car
int x, y;

// function to move the car
void moveCar(char direction, int distance)
{
    if(direction == 'U')
    {
        y += distance;
    }
    else if(direction == 'D')
    {
        y -= distance;
    }
    else if(direction == 'L')
    {
        x -= distance;
    }
    else if(direction == 'R')
    {
        x += distance;
    }
}

// function to print the current location of the car
void printLocation()
{
    printf("Current Location: (%d, %d)\n", x, y);
}

int main()
{
    char direction;
    int distance;
    bool exit = false;
    
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    
    // set the initial position of the car to (0, 0)
    x = 0;
    y = 0;
    
    while(!exit)
    {
        printf("Enter the direction you want to move the car in (U/D/L/R): ");
        scanf(" %c", &direction);
        
        printf("Enter the distance you want to move the car: ");
        scanf("%d", &distance);
        
        moveCar(direction, distance);
        
        printLocation();
        
        printf("Do you want to continue? (y/n): ");
        
        char response;
        scanf(" %c", &response);
        
        if(response == 'n')
        {
            exit = true;
        }
    }
    
    printf("Thank you for using the Remote Control Vehicle Simulation!\n");
    
    return 0;
}