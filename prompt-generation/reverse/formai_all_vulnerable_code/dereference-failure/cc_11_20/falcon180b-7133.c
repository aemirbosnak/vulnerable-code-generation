//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000

int main()
{
    char line[MAX_LINE];
    char *token;
    int i;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Please enter your name: ");
    fgets(line, MAX_LINE, stdin);

    token = strtok(line, "\n");
    printf("Hello, %s! You are now in control of a remote control vehicle.\n", token);

    while (1)
    {
        printf("Enter a command (forward, backward, left, right, stop): ");
        fgets(line, MAX_LINE, stdin);

        token = strtok(line, " ");
        if (strcmp(token, "forward") == 0)
        {
            for (i = 0; i < 10; i++)
            {
                printf("The remote control vehicle is moving forward...\n");
                sleep(1);
            }
        }
        else if (strcmp(token, "backward") == 0)
        {
            for (i = 0; i < 10; i++)
            {
                printf("The remote control vehicle is moving backward...\n");
                sleep(1);
            }
        }
        else if (strcmp(token, "left") == 0)
        {
            for (i = 0; i < 10; i++)
            {
                printf("The remote control vehicle is turning left...\n");
                sleep(1);
            }
        }
        else if (strcmp(token, "right") == 0)
        {
            for (i = 0; i < 10; i++)
            {
                printf("The remote control vehicle is turning right...\n");
                sleep(1);
            }
        }
        else if (strcmp(token, "stop") == 0)
        {
            printf("The remote control vehicle has stopped.\n");
        }
        else
        {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}