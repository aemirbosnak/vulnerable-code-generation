//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 10

int main()
{
    char cmd[MAX_CHAR];
    int drone_x = 0, drone_y = 0, drone_z = 0;
    int speed = 10;

    // Post-apocalyptic ambiance
    printf("Welcome to the ruins of the future, soldier.\n");
    printf("Your drone awaits your command. Enter a command below:\n");

    // Loop until the user enters a valid command
    while (1)
    {
        scanf("%s", cmd);

        // Check if the command is valid
        if (strcmp(cmd, "forward") == 0)
        {
            drone_x += speed;
            printf("Drone moving forward at speed %d.\n", speed);
        }
        else if (strcmp(cmd, "back") == 0)
        {
            drone_x -= speed;
            printf("Drone moving back at speed %d.\n", speed);
        }
        else if (strcmp(cmd, "left") == 0)
        {
            drone_y -= speed;
            printf("Drone moving left at speed %d.\n", speed);
        }
        else if (strcmp(cmd, "right") == 0)
        {
            drone_y += speed;
            printf("Drone moving right at speed %d.\n", speed);
        }
        else if (strcmp(cmd, "stop") == 0)
        {
            drone_x = drone_y = drone_z = 0;
            printf("Drone stopped.\n");
        }
        else
        {
            printf("Invalid command. Please try again.\n");
        }

        // Display the drone's current position
        printf("Drone position: (%d, %d, %d)\n", drone_x, drone_y, drone_z);
    }

    return 0;
}