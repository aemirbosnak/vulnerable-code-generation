//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char command[20] = "";
    int i = 0;

    while (i < 10)
    {
        printf("Enter a command: ");
        scanf("%s", command);

        if (strcmp(command, "forward") == 0)
        {
            // Drone moves forward
            printf("Drone is moving forward.\n");
        }
        else if (strcmp(command, "backward") == 0)
        {
            // Drone moves backward
            printf("Drone is moving backward.\n");
        }
        else if (strcmp(command, "left") == 0)
        {
            // Drone moves left
            printf("Drone is moving left.\n");
        }
        else if (strcmp(command, "right") == 0)
        {
            // Drone moves right
            printf("Drone is moving right.\n");
        }
        else if (strcmp(command, "stop") == 0)
        {
            // Drone stops
            printf("Drone is stopped.\n");
        }
        else
        {
            // Invalid command
            printf("Invalid command.\n");
        }

        i++;
    }

    return 0;
}