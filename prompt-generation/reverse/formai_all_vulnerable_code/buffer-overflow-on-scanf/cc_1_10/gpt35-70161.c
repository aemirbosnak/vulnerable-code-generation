//FormAI DATASET v1.0 Category: Robot movement control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void moveForward(int steps);
void turnLeft();
void turnRight();
void moveBackward(int steps);

int main()
{
    printf("Welcome to the C Robot Movement Control Program!\n\n");

    int instruction;
    int steps;
    srand(time(NULL)); // initialize random seed

    while (1)
    {
        printf("Instructions:\n1 - Move Forward\n2 - Turn Left\n3 - Turn Right\n4 - Move Backward\n5 - Quit Program\n\n");
        printf("Enter instruction: ");
        scanf("%d", &instruction);

        switch (instruction)
        {
            case 1:
                printf("Enter number of steps: ");
                scanf("%d", &steps);
                moveForward(steps);
                break;
            case 2:
                turnLeft();
                break;
            case 3:
                turnRight();
                break;
            case 4:
                printf("Enter number of steps: ");
                scanf("%d", &steps);
                moveBackward(steps);
                break;
            case 5:
                printf("\nProgram terminated!");
                exit(0);
            default:
                printf("Invalid instruction! Please try again.\n");
                break;
        }
    }

    return 0;
}

void moveForward(int steps)
{
    printf("Moving Forward %d steps...\n", steps);

    // simulate robot movements
    for (int i = 0; i < steps; i++)
    {
        int random = rand() % 101 + 1; // generate random number from 1 to 101

        if (random <= 60) // robot moves forward
        {
            printf("*");
        }
        else if (random > 60 && random <= 80) // robot encounters obstacle
        {
            printf("X");
            printf("\nObstacle encountered! Robot stopped at step %d.\n", i+1);
            break;
        }
        else // robot drifts away
        {
            printf("~");
        }
    }
    printf("\n\n");
}

void turnLeft()
{
    printf("Turning Left...\n\n");
}

void turnRight()
{
    printf("Turning Right...\n\n");
}

void moveBackward(int steps)
{
    printf("Moving Backward %d steps...\n", steps);
    
    // simulate robot movements
    for (int i = 0; i < steps; i++)
    {
        int random = rand() % 101 + 1; // generate random number from 1 to 101

        if (random <= 60) // robot moves backward
        {
            printf("*");
        }
        else if (random > 60 && random <= 80) // robot encounters obstacle
        {
            printf("X");
            printf("\nObstacle encountered! Robot stopped at step -%d.\n", i+1);
            break;
        }
        else // robot drifts away
        {
            printf("~");
        }
    }
    printf("\n\n");
}