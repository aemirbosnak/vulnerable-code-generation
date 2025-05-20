//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000  // Maximum number of commands that can be stored

int main()
{
    int commands[MAX];
    int i = 0;  // Number of commands entered by user
    int x = 0;  // Current position of the drone
    int y = 0; 

    printf("Welcome to the C Drone Remote Control");
    printf("\n");

    // Prompt user to enter commands
    printf("Please enter the commands:\n");
    printf("1: Move up\n");
    printf("2: Move down\n");
    printf("3: Move left\n");
    printf("4: Move right\n");
    printf("5: Exit\n");

    // Store commands entered by user
    while (i < MAX)
    {
        int cmd;
        scanf("%d", &cmd);
        if (cmd >= 1 && cmd <= 5)
        {
            commands[i] = cmd;
            i++;
        }
        if (cmd == 5)
        {
            break;
        }
    }

    // Execute commands
    for (int j = 0; j < i; j++)
    {
        int cmd = commands[j];
        switch (cmd)
        {
            case 1:
                y++;
                printf("Drone moved up\n");
                break;

            case 2:
                y--;
                printf("Drone moved down\n");
                break;

            case 3:
                x--;
                printf("Drone moved left\n");
                break;

            case 4:
                x++;
                printf("Drone moved right\n");
                break;

            case 5:
                printf("Exiting drone remote control program\n");
                exit(0);
                break;

            default:
                printf("Invalid command entered\n");
                break;
        }

        // Display current position of drone
        printf("Current position of drone: (%d,%d)\n", x, y);
    }


    return 0;
}