//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: scientific
#include <stdio.h>

//define constants
#define MAX_DISTANCE 1000    //max distance in meters
#define MAX_SPEED 20         //max speed in m/s
#define MAX_FLOAT_TIME 30    //max float time in min
#define DEFAULT_HEIGHT 5     //default drone height in meters

int main()
{
    //define variables
    int distance = 0;
    int speed = 0;
    int float_time = 0;
    int height = DEFAULT_HEIGHT;
    char command = ' ';
    
    printf("Welcome to the C Drone Remote Control Program!\n");
    
    //take user input for distance, speed, and float time
    printf("Please enter the distance in meters: ");
    scanf("%d", &distance);
    
    while(distance > MAX_DISTANCE || distance <= 0)
    {
        printf("Invalid distance. Please enter a distance between 1 and %d meters: ", MAX_DISTANCE);
        scanf("%d", &distance);
    }
    
    printf("Please enter the speed in m/s: ");
    scanf("%d", &speed);
    
    while(speed > MAX_SPEED || speed <= 0)
    {
        printf("Invalid speed. Please enter a speed between 1 and %d m/s: ", MAX_SPEED);
        scanf("%d", &speed);
    }
    
    printf("Please enter the float time in minutes: ");
    scanf("%d", &float_time);
    
    while(float_time > MAX_FLOAT_TIME || float_time <= 0)
    {
        printf("Invalid float time. Please enter a float time between 1 and %d minutes: ", MAX_FLOAT_TIME);
        scanf("%d", &float_time);
    }
    
    //display drone information
    printf("\nDrone Specifications: \n");
    printf("Distance: %d meters \n", distance);
    printf("Speed: %d m/s \n", speed);
    printf("Float Time: %d minutes \n", float_time);
    printf("Height: %d meters \n\n", height);
    
    //simulate drone movement with for loop
    for(int i = 0; i < float_time; i++)
    {
        //check if drone has reached its destination
        if(distance <= 0)
        {
            printf("Drone has reached its destination and will now land.\n");
            break;
        }
        
        //display remaining time and distance
        printf("Time remaining: %d minutes\n", float_time - i);
        printf("Distance remaining: %d meters\n\n", distance);
        
        //take user input for drone movement
        printf("Please enter a command (f=forward, b=backward, u=up, d=down): ");
        scanf(" %c", &command);
        
        //move drone based on user input
        switch(command)
        {
            case 'f':
                distance -= speed;
                printf("Drone moved forward %d meters.\n", speed);
                break;
                
            case 'b':
                distance += speed;
                printf("Drone moved backward %d meters.\n", speed);
                break;
                
            case 'u':
                height += 1;
                printf("Drone moved up to %d meters.\n", height);
                break;
                
            case 'd':
                height -= 1;
                printf("Drone moved down to %d meters.\n", height);
                break;
                
            default:
                printf("Invalid command. Please enter f, b, u, or d.\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}