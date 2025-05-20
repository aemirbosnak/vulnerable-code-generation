//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>

void move_forward(int distance)
{
    if (distance > 0)
    {
        printf("Moving forward...\n");
        distance--;
        move_forward(distance);
    }
    else
    {
        printf("Finished moving forward.\n");
    }
}

void move_backward(int distance)
{
    if (distance > 0)
    {
        printf("Moving backward...\n");
        distance--;
        move_backward(distance);
    }
    else
    {
        printf("Finished moving backward.\n");
    }
}

void turn_left(int angle)
{
    if (angle > 0)
    {
        printf("Turning left...\n");
        angle--;
        turn_left(angle);
    }
    else
    {
        printf("Finished turning left.\n");
    }
}

void turn_right(int angle)
{
    if (angle > 0)
    {
        printf("Turning right...\n");
        angle--;
        turn_right(angle);
    }
    else
    {
        printf("Finished turning right.\n");
    }
}

int main()
{
    int choice;
    int distance;
    int angle;
    
    while (1)
    {
        printf("Remote Control Options:\n");
        printf("1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Turn Left\n");
        printf("4. Turn Right\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("Enter distance to move forward: ");
                scanf("%d", &distance);
                move_forward(distance);
                break;
            case 2:
                printf("Enter distance to move backward: ");
                scanf("%d", &distance);
                move_backward(distance);
                break;
            case 3:
                printf("Enter angle to turn left: ");
                scanf("%d", &angle);
                turn_left(angle);
                break;
            case 4:
                printf("Enter angle to turn right: ");
                scanf("%d", &angle);
                turn_right(angle);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}