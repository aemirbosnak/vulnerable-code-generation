//FormAI DATASET v1.0 Category: Robot movement control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void moveForward(int speed);
void moveBackward(int speed);
void turnLeft(int speed);
void turnRight(int speed);
void stopMovement();

int main()
{
    int speed = 50; // Set default speed to 50%
    int choice; // User's selection

    do
    {
        printf("1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Turn Left\n");
        printf("4. Turn Right\n");
        printf("5. Stop Movement\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: // Move Forward
                moveForward(speed);
                break;

            case 2: // Move Backward
                moveBackward(speed);
                break;

            case 3: // Turn Left
                turnLeft(speed);
                break;

            case 4: // Turn Right
                turnRight(speed);
                break;

            case 5: // Stop Movement
                stopMovement();
                break;

            case 6: // Exit
                printf("Goodbye!\n");
                exit(0);

            default: // Invalid option
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void moveForward(int speed)
{
    printf("Moving Forward at %d%% Speed...\n", speed);
    // Code to move robot forward at specified speed
}

void moveBackward(int speed)
{
    printf("Moving Backward at %d%% Speed...\n", speed);
    // Code to move robot backward at specified speed
}

void turnLeft(int speed)
{
    printf("Turning Left at %d%% Speed...\n", speed);
    // Code to turn robot left at specified speed
}

void turnRight(int speed)
{
    printf("Turning Right at %d%% Speed...\n", speed);
    // Code to turn robot right at specified speed
}

void stopMovement()
{
    printf("Stopping Movement...\n");
    // Code to stop robot's movement
}