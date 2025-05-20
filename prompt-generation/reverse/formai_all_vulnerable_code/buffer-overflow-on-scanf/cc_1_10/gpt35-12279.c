//FormAI DATASET v1.0 Category: Robot movement control ; Style: active
// C Robot Movement Control Program
#include <stdio.h>

// function to move robot forward
void moveForward(int distance)
{
    printf("Moving robot forward %d units...\n", distance);
    // code to move robot forward
}

// function to move robot backward
void moveBackward(int distance)
{
    printf("Moving robot backward %d units...\n", distance);
    // code to move robot backward
}

// function to turn robot left
void turnLeft(int angle)
{
    printf("Turning robot left %d degrees...\n", angle);
    // code to turn robot left
}

// function to turn robot right
void turnRight(int angle)
{
    printf("Turning robot right %d degrees...\n", angle);
    // code to turn robot right
}

// function to stop robot
void stopRobot()
{
    printf("Stopping robot...\n");
    // code to stop robot
}

// main function
int main()
{
    int choice, distance, angle;

    do {
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Stop\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter distance to move forward: ");
                scanf("%d", &distance);
                moveForward(distance);
                break;

            case 2:
                printf("Enter distance to move backward: ");
                scanf("%d", &distance);
                moveBackward(distance);
                break;

            case 3:
                printf("Enter angle to turn left: ");
                scanf("%d", &angle);
                turnLeft(angle);
                break;

            case 4:
                printf("Enter angle to turn right: ");
                scanf("%d", &angle);
                turnRight(angle);
                break;

            case 5:
                stopRobot();
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice, try again...\n");
                break;
        }
    } while (choice != 6);

    return 0;
}