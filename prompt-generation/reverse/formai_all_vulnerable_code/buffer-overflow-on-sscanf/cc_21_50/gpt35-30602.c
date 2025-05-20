//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DRONES 10
#define MAX_COMMAND_LENGTH 100

int main()
{
    char commands[MAX_DRONES][MAX_COMMAND_LENGTH];
    bool isFlying[MAX_DRONES] = {false};
    int battery[MAX_DRONES] = {100};
    int droneCount = 0;

    printf("Welcome to the C Drone Remote Control Program!\n");

    while (true)
    {
        printf("\nEnter 'add' to add a new drone, or enter the command for a drone (e.g. 'takeoff 1')\n");
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        
        char command[MAX_COMMAND_LENGTH];
        int droneNum = -1;
        sscanf(input, "%s %d", command, &droneNum);

        if (strcmp(command, "add") == 0)
        {
            if (droneCount >= MAX_DRONES)
            {
                printf("Sorry, you have reached the maximum number of drones (%d)\n", MAX_DRONES);
            }
            else
            {
                printf("New drone added! Its number is %d\n", droneCount+1);
                droneCount++;
            }
        }
        else if (strcmp(command, "takeoff") == 0)
        {
            if (droneNum < 1 || droneNum > droneCount)
            {
                printf("Sorry, invalid drone number\n");
            }
            else if (isFlying[droneNum-1])
            {
                printf("Sorry, drone %d is already flying\n", droneNum);
            }
            else if (battery[droneNum-1] < 20)
            {
                printf("Sorry, drone %d does not have enough battery to take off\n", droneNum);
            }
            else
            {
                strcpy(commands[droneNum-1], "takeoff");
                isFlying[droneNum-1] = true;
                battery[droneNum-1] -= 20;
                printf("Drone %d is taking off!\n", droneNum);
            }
        }
        else if (strcmp(command, "land") == 0)
        {
            if (droneNum < 1 || droneNum > droneCount)
            {
                printf("Sorry, invalid drone number\n");
            }
            else if (!isFlying[droneNum-1])
            {
                printf("Sorry, drone %d is not flying\n", droneNum);
            }
            else
            {
                strcpy(commands[droneNum-1], "land");
                isFlying[droneNum-1] = false;
                battery[droneNum-1] -= 10;
                printf("Drone %d is landing!\n", droneNum);
            }
        }
        else if (strcmp(command, "up") == 0 || strcmp(command, "down") == 0 ||
                 strcmp(command, "left") == 0 || strcmp(command, "right") == 0)
        {
            if (droneNum < 1 || droneNum > droneCount)
            {
                printf("Sorry, invalid drone number\n");
            }
            else if (!isFlying[droneNum-1])
            {
                printf("Sorry, drone %d is not flying\n", droneNum);
            }
            else
            {
                sprintf(commands[droneNum-1], "%s %d", command, abs(rand() % 100));
                battery[droneNum-1] -= 5;
                printf("Drone %d is moving %s!\n", droneNum, command);
            }
        }
        else if (strcmp(command, "status") == 0)
        {
            printf("Currently there are %d drones:\n", droneCount);
            for (int i = 0; i < droneCount; i++)
            {
                printf("Drone %d: ", i+1);
                if (isFlying[i])
                {
                    printf("flying, ");
                }
                else
                {
                    printf("landed, ");
                }
                printf("battery: %d%%, command: %s\n", battery[i], commands[i]);
            }
        }
        else if (strcmp(command, "exit") == 0)
        {
            printf("Exiting the C Drone Remote Control Program. Goodbye!\n");
            break;
        }
        else
        {
            printf("Sorry, invalid command\n");
        }
    }
    
    return 0;
}