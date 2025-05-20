//FormAI DATASET v1.0 Category: Robot movement control ; Style: brave
#include<stdio.h>

int main()
{
    int robot_x = 0, robot_y = 0;      //Initial position of the robot
    char command;                      //Variable to store user input command
    
    printf("Welcome to Robot Movement Control Program!\n\n");
    
    while(1)                           //Infinite loop until the user exits the program
    {
        printf("Current Position of Robot : (%d, %d)\n", robot_x, robot_y);
        printf("Enter the Command for Robot Movement (U/D/L/R) : ");
        scanf(" %c", &command);        //Reading user input
        
        switch(command)
        {
            case 'U':
            case 'u':
                robot_y++;             //Moving the robot up
                break;
                
            case 'D':
            case 'd':
                robot_y--;             //Moving the robot down
                break;
                
            case 'L':
            case 'l':
                robot_x--;             //Moving the robot left
                break;
                
            case 'R':
            case 'r':
                robot_x++;             //Moving the robot right
                break;
                
            case 'E':
            case 'e':
                printf("Exiting Robot Movement Control Program!\n");
                return 0;              //Exiting the program
                break;
                
            default:
                printf("Invalid Command! Please Enter Valid Command (U/D/L/R/E)\n\n");
                break;
        }
        printf("\n");
    }
    return 0;
}