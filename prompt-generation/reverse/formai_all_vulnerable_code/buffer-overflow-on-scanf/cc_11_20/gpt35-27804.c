//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int droneMove[50];
    char command;
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("Please input your drone commands:\n");
    for(i = 0; i < 50; i++)
    {
        scanf("%c", &command);
        switch(command)
        {
            case 'U':
                printf("The drone moves up!\n");
                droneMove[i] = 1;
                break;
            case 'D':
                printf("The drone moves down!\n");
                droneMove[i] = 2;
                break;
            case 'L':
                printf("The drone moves left!\n");
                droneMove[i] = 3;
                break;
            case 'R':
                printf("The drone moves right!\n");
                droneMove[i] = 4;
                break;
            case 'F':
                printf("The drone moves forward!\n");
                droneMove[i] = 5;
                break;
            case 'B':
                printf("The drone moves backward!\n");
                droneMove[i] = 6;
                break;
            default:
                printf("Invalid command input!\n");
                droneMove[i] = 0;
                break;
        }
        if(command == '\n')
        {
            break;
        }
    }
    printf("Your drone commands are:\n");
    for(i = 0; i < 50; i++)
    {
        if(droneMove[i] == 1)
        {
            printf("%d: Up\n", i + 1);
        }
        else if(droneMove[i] == 2)
        {
            printf("%d: Down\n", i + 1);
        }
        else if(droneMove[i] == 3)
        {
            printf("%d: Left\n", i + 1);
        }
        else if(droneMove[i] == 4)
        {
            printf("%d: Right\n", i + 1);
        }
        else if(droneMove[i] == 5)
        {
            printf("%d: Forward\n", i + 1);
        }
        else if(droneMove[i] == 6)
        {
            printf("%d: Backward\n", i + 1);
        }
        else
        {
            printf("%d: Invalid command\n", i + 1);
        }
        if(droneMove[i] == 0)
        {
            break;
        }
    }
    return 0;
}