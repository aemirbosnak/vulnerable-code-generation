//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Remote Control Vehicle Simulation Program!\n");
    printf("Initializing simulation...\n");

    //Initialize variables
    int x = 0; //horizontal position
    int y = 0; //vertical position
    int heading = 0; //0 = North, 1 = East, 2 = South, 3 = West
    int fuel = 100; //fuel level
    char controls; //user input for controls
    int obstacle_x = rand() % 10; //random horizontal position for obstacle
    int obstacle_y = rand() % 10; //random vertical position for obstacle

    //Print starting position and fuel level
    printf("Your vehicle is currently at position (%d,%d) facing North.\n", x, y);
    printf("You have %d units of fuel remaining.\n", fuel);

    //Simulation loop
    while(fuel > 0){
        printf("Enter your control command (F to move forward, R to turn right, L to turn left):");
        scanf("%c", &controls);

        //Check for valid control input
        while(controls != 'F' && controls != 'R' && controls != 'L'){
            printf("Invalid control command. Please enter F, R, or L:");
            scanf(" %c", &controls);
        }

        //Act on user input
        if(controls == 'F'){
            //Calculate new position based on heading
            switch(heading){
                case 0:
                    y++;
                    break;
                case 1:
                    x++;
                    break;
                case 2:
                    y--;
                    break;
                case 3:
                    x--;
                    break;
            }
            fuel--;
        }
        else if(controls == 'R'){
            heading = (heading + 1) % 4;
        }
        else if(controls == 'L'){
            heading = (heading + 3) % 4;
        }

        //Check if vehicle has collided with obstacle
        if(x == obstacle_x && y == obstacle_y){
            printf("You crashed into an obstacle!\n");
            break;
        }

        //Print updated position and fuel level
        printf("Your vehicle is currently at position (%d,%d) facing ", x, y);
        switch(heading){
            case 0:
                printf("North.\n");
                break;
            case 1:
                printf("East.\n");
                break;
            case 2:
                printf("South.\n");
                break;
            case 3:
                printf("West.\n");
                break;
        }
        printf("You have %d units of fuel remaining.\n", fuel);
    }

    //Print final position and fuel level
    printf("Your vehicle has run out of fuel and is stranded at position (%d,%d).\n", x, y);
    printf("Thank you for using the Remote Control Vehicle Simulation Program!\n");

    return 0;
}