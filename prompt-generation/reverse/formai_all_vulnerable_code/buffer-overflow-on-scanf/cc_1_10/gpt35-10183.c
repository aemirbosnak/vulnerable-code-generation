//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void takeoff()
{
    printf("Drone is taking-off!\n");
}

void land()
{
    printf("Drone is landing!\n");
}

int main()
{
    int x, y, z;
    bool flying = false;
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("Press 1 to takeoff, 0 to land and 2 to exit the program.\n");

    while (true)
    {
        printf("Enter your command: ");
        scanf("%d", &x);

        switch(x)
        {
            case 0:
                if (flying)
                {
                    land();
                    flying = false;
                }
                else
                {
                    printf("Drone is already on the ground!\n");
                }
                break;

            case 1:
                if (flying)
                {
                    printf("Drone is already flying!\n");
                }
                else
                {
                    takeoff();
                    flying = true;
                }
                break;

            case 2:
                printf("Exiting the program. Goodbye!");
                exit(0);

            default:
                printf("Invalid command! Press 1 to takeoff, 0 to land and 2 to exit the program.\n");
        }
    }

    return 0;
}