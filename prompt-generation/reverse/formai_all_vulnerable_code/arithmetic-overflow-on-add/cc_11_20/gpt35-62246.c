//FormAI DATASET v1.0 Category: Robot movement control ; Style: imaginative
#include <stdio.h>
int main()
{
    int posX = 0; // X position of the robot
    int posY = 0; // Y position of the robot
    int direction = 0; // 0 - facing East, 1 - facing North, 2 - facing West, 3 - facing South
        
    printf("Enter the number of movements: ");
    int movements;
    scanf("%d", &movements);

    char movementType[movements + 1]; // String to store all the movements
    printf("Enter the movements (F - forward, L - turn left, R - turn right):\n");
    scanf("%s", movementType);

    for (int i = 0; i < movements; i++)
    {
        if (movementType[i] == 'F')
        {
            // Move the robot one unit forward based on its direction
            switch (direction)
            {
                case 0: posX++; break; // facing East
                case 1: posY++; break; // facing North
                case 2: posX--; break; // facing West
                case 3: posY--; break; // facing South
            }
        }
        else if (movementType[i] == 'L')
        {
            // Turn the robot 90 degrees left
            direction--;
            if (direction < 0)
                direction = 3;
        }
        else if (movementType[i] == 'R')
        {
            // Turn the robot 90 degrees right
            direction++;
            if (direction > 3)
                direction = 0;
        }
    }

    printf("Final position: (%d, %d)\n", posX, posY);
    printf("Final direction: ");
    switch (direction)
    {
        case 0: printf("East"); break;
        case 1: printf("North"); break;
        case 2: printf("West"); break;
        case 3: printf("South"); break;
    }
        
    return 0;
}