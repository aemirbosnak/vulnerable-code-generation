//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Dennis Ritchie
//Program to control a drone using C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void takeoff()
{
    printf("Drone taking off.\n");
}

void land()
{
    printf("Drone landing.\n");
}

void move_forward(int distance)
{
    printf("The drone is moving forward %d meters.\n", distance);
}

void move_backward(int distance)
{
    printf("The drone is moving backward %d meters.\n", distance);
}

void move_left(int distance)
{
    printf("The drone is moving left %d meters.\n", distance);
}

void move_right(int distance)
{
    printf("The drone is moving right %d meters.\n", distance);
}

void turn_left(int degrees)
{
    printf("The drone is turning left %d degrees.\n", degrees);
}

void turn_right(int degrees)
{
    printf("The drone is turning right %d degrees.\n", degrees);
}

int main()
{
    char command[20];
    int distance, degrees;

    printf("Welcome to Drone Remote Control.\n");

    while (1)
    {
        printf("Enter a command (takeoff, land, forward, backward, left, right, turnleft, turnright, exit): ");
        scanf("%s", command);

        if (strcmp(command, "takeoff") == 0)
        {
            takeoff();
        }
        else if (strcmp(command, "land") == 0)
        {
            land();
        }
        else if (strcmp(command, "forward") == 0)
        {
            printf("Enter a distance in meters: ");
            scanf("%d", &distance);
            move_forward(distance);
        }
        else if (strcmp(command, "backward") == 0)
        {
            printf("Enter a distance in meters: ");
            scanf("%d", &distance);
            move_backward(distance);
        }
        else if (strcmp(command, "left") == 0)
        {
            printf("Enter a distance in meters: ");
            scanf("%d", &distance);
            move_left(distance);
        }
        else if (strcmp(command, "right") == 0)
        {
            printf("Enter a distance in meters: ");
            scanf("%d", &distance);
            move_right(distance);
        }
        else if (strcmp(command, "turnleft") == 0)
        {
            printf("Enter an angle in degrees: ");
            scanf("%d", &degrees);
            turn_left(degrees);
        }
        else if (strcmp(command, "turnright") == 0)
        {
            printf("Enter an angle in degrees: ");
            scanf("%d", &degrees);
            turn_right(degrees);
        }
        else if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    printf("Shutting down Drone Remote Control.\n");

    return 0;
}