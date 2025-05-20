//FormAI DATASET v1.0 Category: Robot movement control ; Style: imaginative
#include<stdio.h>

int main()
{
    int x_pos = 0, y_pos = 0, direction = 0;
    printf("Enter the initial position of the robot (x,y): ");
    scanf("%d%d", &x_pos, &y_pos);
    printf("Enter the initial direction of the robot (0-North, 1-East, 2-South, 3-West): ");
    scanf("%d", &direction);
    printf("\n");

    int num_moves = 0;
    printf("Enter the number of moves the robot should make: ");
    scanf("%d", &num_moves);
    printf("\n");

    int moves[num_moves];
    printf("Enter the moves for the robot (0-Forward, 1-Right, 2-Backward, 3-Left): ");
    for(int i = 0; i < num_moves; i++)
    {
        scanf("%d", &moves[i]);
    }
    printf("\n");

    printf("Initial position and direction of robot: (%d,%d) facing ", x_pos, y_pos);
    if(direction == 0)
    {
        printf("North\n");
    }
    else if(direction == 1)
    {
        printf("East\n");
    }
    else if(direction == 2)
    {
        printf("South\n");
    }
    else if(direction == 3)
    {
        printf("West\n");
    }
    printf("\n");

    for(int i = 0; i < num_moves; i++)
    {
        if(moves[i] == 0) // Forward
        {
            if(direction == 0)
            {
                y_pos++;
            }
            else if(direction == 1)
            {
                x_pos++;
            }
            else if(direction == 2)
            {
                y_pos--;
            }
            else if(direction == 3)
            {
                x_pos--;
            }
        }
        else if(moves[i] == 1) // Right
        {
            direction = (direction + 1) % 4;
        }
        else if(moves[i] == 2) // Backward
        {
            if(direction == 0)
            {
                y_pos--;
            }
            else if(direction == 1)
            {
                x_pos--;
            }
            else if(direction == 2)
            {
                y_pos++;
            }
            else if(direction == 3)
            {
                x_pos++;
            }
        }
        else if(moves[i] == 3) // Left 
        {
            direction = (direction + 3) % 4;
        }
    }

    printf("Final position and direction of robot: (%d,%d) facing ", x_pos, y_pos);
    if(direction == 0)
    {
        printf("North\n");
    }
    else if(direction == 1)
    {
        printf("East\n");
    }
    else if(direction == 2)
    {
        printf("South\n");
    }
    else if(direction == 3)
    {
        printf("West\n");
    }

    return 0;
}