//FormAI DATASET v1.0 Category: Robot movement control ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Oh Romeo, my love, please help me guide the robot across the floor.\n");
    printf("Fear not my dear Juliet, for I have just the code for that.\n");

    int robot_x = 0;
    int robot_y = 0;

    while(1)
    {
        char direction;
        printf("Which way should the robot move? [f]orward, [b]ackward, [l]eft, or [r]ight: ");
        scanf("%c", &direction);

        if(direction == 'f')
        {
            robot_y += 1;
            printf("The robot moves forward. Its position is now (%d,%d).\n", robot_x, robot_y);
        }
        else if(direction == 'b')
        {
            robot_y -= 1;
            printf("The robot moves backward. Its position is now (%d,%d).\n", robot_x, robot_y);
        }
        else if(direction == 'l')
        {
            robot_x -= 1;
            printf("The robot moves left. Its position is now (%d,%d).\n", robot_x, robot_y);
        }
        else if(direction == 'r')
        {
            robot_x += 1;
            printf("The robot moves right. Its position is now (%d,%d).\n", robot_x, robot_y);
        }
        else
        {
            printf("Oh Juliet, forgive me. I made an error in my code. Please try again.\n");
            continue;
        }

        if(robot_x == 2 && robot_y == 1)
        {
            printf("Oh Romeo, my love, the robot has reached the target position. You are my hero!\n");
            break;
        }
    }

    return 0;
}