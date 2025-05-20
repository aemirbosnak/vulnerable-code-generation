//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Claude Shannon
#include <stdio.h>

//function to control drone movement
void droneMovement(int x, int y, char z)
{
    printf("Drone is moved to (%d, %d) and %c direction.\n", x, y, z);
}

//function to takeoff drone
void droneTakeoff()
{
    printf("Drone is taking off...\n");
}

//function to land drone
void droneLand()
{
    printf("Drone is landing...\n");
}

int main()
{
    int x, y; //coordinates
    char z; //direction
    
    printf("Welcome to the C Drone Remote Control Program!\n\n");
    
    while(1)
    {
        printf("Please enter a command (takeoff, land, move): ");
        char input[10];
        scanf("%s", input);
        
        if(strcmp(input, "takeoff") == 0) //if command is takeoff
        {
            droneTakeoff();
        }
        else if(strcmp(input, "land") == 0) //if command is land
        {
            droneLand();
        }
        else if(strcmp(input, "move") == 0) //if command is move
        {
            printf("Please enter x, y, and direction (N, S, E, W): ");
            scanf("%d %d %c", &x, &y, &z);
            droneMovement(x, y, z);
        }
        else //if command is not valid
        {
            printf("Invalid command. Please try again.\n");
        }
    }
    
    return 0;
}