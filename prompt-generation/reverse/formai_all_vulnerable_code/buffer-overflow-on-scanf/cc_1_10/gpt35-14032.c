//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complex
#include <stdio.h>

#define MAX_COMMANDS 10

void printCurrentPosition(int x, int y, int z);

void takeOff()
{
    printf("Drone is taking off!\n");
}

void land()
{
    printf("Drone is landing!\n");
}

void moveUp(int meters)
{
    printf("Drone is moving up %d meters!\n", meters);
}

void moveDown(int meters)
{
    printf("Drone is moving down %d meters!\n", meters);
}

void moveForward(int meters)
{
    printf("Drone is moving forward %d meters!\n", meters);
}

void moveBackward(int meters)
{
    printf("Drone is moving backward %d meters!\n", meters);
}

void moveLeft(int meters)
{
    printf("Drone is moving left %d meters!\n", meters);
}

void moveRight(int meters)
{
    printf("Drone is moving right %d meters!\n", meters);
}

void turnLeft(int degrees)
{
    printf("Drone is turning left %d degrees!\n", degrees);
}

void turnRight(int degrees)
{
    printf("Drone is turning right %d degrees!\n", degrees);
}

int main(void)
{
    int x = 0, y = 0, z = 0;
    int command[MAX_COMMANDS];
    int command_count = 0;

    printf("Welcome to Drone Remote Control Program!\n");

    while (1)
    {
        printf("Enter your command (0:takeOff, 1:land, 2:moveUp, 3:moveDown, 4:moveForward, 5:moveBackward, 6:moveLeft, 7:moveRight, 8:turnLeft, 9:turnRight, -1:quit):\n");

        int c;
        scanf("%d", &c);

        if (c < -1 || c > 9)
        {
            printf("Invalid command!\n");
            continue;
        }
        else if (c == -1)
        {
            break;
        }

        switch (c)
        {
            case 0:
                takeOff();
                break;

            case 1:
                land();
                break;

            case 2:
            {
                int meters;
                printf("Enter distance in meters:\n");
                scanf("%d", &meters);
                moveUp(meters);
                z += meters;
                break;
            }

            case 3:
            {
                int meters;
                printf("Enter distance in meters:\n");
                scanf("%d", &meters);
                moveDown(meters);
                z -= meters;
                break;
            }

            case 4:
            {
                int meters;
                printf("Enter distance in meters:\n");
                scanf("%d", &meters);
                moveForward(meters);
                x += meters;
                break;
            }

            case 5:
            {
                int meters;
                printf("Enter distance in meters:\n");
                scanf("%d", &meters);
                moveBackward(meters);
                x -= meters;
                break;
            }

            case 6:
            {
                int meters;
                printf("Enter distance in meters:\n");
                scanf("%d", &meters);
                moveLeft(meters);
                y -= meters;
                break;
            }

            case 7:
            {
                int meters;
                printf("Enter distance in meters:\n");
                scanf("%d", &meters);
                moveRight(meters);
                y += meters;
                break;
            }

            case 8:
            {
                int degrees;
                printf("Enter angle in degrees:\n");
                scanf("%d", &degrees);
                turnLeft(degrees);
                break;
            }

            case 9:
            {
                int degrees;
                printf("Enter angle in degrees:\n");
                scanf("%d", &degrees);
                turnRight(degrees);
                break;
            }

            default:
                break;
        }

        if (command_count < MAX_COMMANDS)
        {
            command[command_count++] = c;
        }
    }

    printf("\nCommand history:\n");
    for (int i = 0; i < command_count; i++)
    {
        printf("%d ", command[i]);
    }

    printCurrentPosition(x, y, z);

    printf("Program exiting...\n");

    return 0;
}

void printCurrentPosition(int x, int y, int z)
{
    printf("\nCurrent position: (%d, %d, %d)\n", x, y, z);
}