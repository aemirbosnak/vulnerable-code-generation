//FormAI DATASET v1.0 Category: Robot movement control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int direction; // variable to store the direction of movement
    int x = 0; // robot's starting position
    int y = 0;

    printf("Welcome to Robot Movement Control System!\n");
    printf("To move the robot, enter a number between 1 and 4.\n");
    printf("1 - Move North\n");
    printf("2 - Move South\n");
    printf("3 - Move East\n");
    printf("4 - Move West\n");
    printf("Enter 0 to exit.\n");

    while(1) {
        // get direction from user
        printf("\nEnter direction: ");
        scanf("%d", &direction);

        // process user input
        switch(direction) {
            case 0:
                printf("Exiting...\n");
                exit(0);
            case 1:
                y++;
                printf("Moved North!\n");
                break;
            case 2:
                y--;
                printf("Moved South!\n");
                break;
            case 3:
                x++;
                printf("Moved East!\n");
                break;
            case 4:
                x--;
                printf("Moved West!\n");
                break;
            default:
                printf("Invalid direction! Please try again.\n");
        }

        // print new position of the robot
        printf("New position: (%d, %d)\n", x, y);

        // add some energy to the robot
        printf("Adding some energy...\n");
        for(int i = 1; i <= 10; i++) {
            printf("%d...\n", i);
        }
        printf("Energy level is now full!\n");
    }

    return 0;
}