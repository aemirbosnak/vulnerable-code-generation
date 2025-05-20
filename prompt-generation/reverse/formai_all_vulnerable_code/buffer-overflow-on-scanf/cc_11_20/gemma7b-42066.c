//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: Sherlock Holmes
// The Adventure Begins...

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // The dim lights cast long shadows...

    int x = 0, y = 0; // Position of the robot
    int direction = 0; // Direction of movement (0 = north, 1 = east, 2 = south, 3 = west)

    // The clock strikes 12...

    printf("Hear ye, hear ye, my dear Watson! The clock strikes twelve... The mystery unfolds...\n");

    // The robot sets off...

    while (1)
    {
        // The robot moves forward...

        switch (direction)
        {
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

        // The robot has reached the end of the trail...

        if (x == 5 && y == 5)
        {
            printf("Congratulations, my dear Watson! You have found the hidden treasure!\n");
            break;
        }

        // The robot prints its current position...

        printf("Current position: (%d, %d)\n", x, y);

        // The robot listens for instructions...

        char instruction;
        printf("Enter an instruction (n/e/s/w): ");
        scanf("%c", &instruction);

        // The robot changes direction...

        switch (instruction)
        {
            case 'n':
                direction = 0;
                break;
            case 'e':
                direction = 1;
                break;
            case 's':
                direction = 2;
                break;
            case 'w':
                direction = 3;
                break;
        }
    }

    return 0;
}