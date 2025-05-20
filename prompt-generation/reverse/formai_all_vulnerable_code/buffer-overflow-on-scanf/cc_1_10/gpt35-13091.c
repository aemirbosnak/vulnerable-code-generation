//FormAI DATASET v1.0 Category: Robot movement control ; Style: satisfied
/* This program controls the movement of a Robot using C language */
#include<stdio.h>

// function to move the Robot Forward
void moveForward(int distance)
{
    printf("Moving the Robot Forward by %d units.\n", distance);
}

// function to move the Robot Backward
void moveBackward(int distance)
{
    printf("Moving the Robot Backward by %d units.\n", distance);
}

// function to turn the Robot Right
void turnRight()
{
    printf("Turning the Robot Right.\n");
}

// function to turn the Robot Left
void turnLeft()
{
    printf("Turning the Robot Left.\n");
}

// function to stop the Robot
void stopRobot()
{
    printf("Stopping the Robot.\n");
}

int main()
{
    int choice, distance;
    
    // loop to repeatedly take input until user stops
    while(1)
    {
        printf("Enter your choice:\n1. Move Forward.\n2. Move Backward.\n3. Turn Right.\n4. Turn Left.\n5. Stop Robot.\n6. Exit.\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter the distance to move forward: ");
                scanf("%d", &distance);
                moveForward(distance);
                break;
            
            case 2:
                printf("Enter the distance to move backward: ");
                scanf("%d", &distance);
                moveBackward(distance);
                break;
            
            case 3:
                turnRight();
                break;
            
            case 4:
                turnLeft();
                break;
                
            case 5:
                stopRobot();
                break;
                
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            
            default:
                printf("Invalid choice, please enter again.\n");
                break;
        }
    }
    return 0;
}