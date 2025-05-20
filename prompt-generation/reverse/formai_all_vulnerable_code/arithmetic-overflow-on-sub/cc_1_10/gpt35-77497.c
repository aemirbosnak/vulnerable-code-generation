//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //initialize random seed
    srand(time(0));

    //initialize current position and target position
    int current_x = 0;
    int current_y = 0;
    int target_x = rand()%100;
    int target_y = rand()%100;

    printf("Your current position is (%d,%d).\n", current_x, current_y);
    printf("Your target position is (%d,%d).\n\n", target_x, target_y);

    //start navigation
    char direction;
    int distance;
    int remaining_distance = abs(target_x-current_x) + abs(target_y-current_y);

    while(remaining_distance > 0)
    {
        //ask for input
        printf("Enter direction (N,S,E,W): ");
        scanf(" %c", &direction);
        printf("Enter distance: ");
        scanf("%d", &distance);

        //update current position based on input
        switch(direction)
        {
            case 'N':
                current_y += distance;
                break;
            case 'S':
                current_y -= distance;
                break;
            case 'E':
                current_x += distance;
                break;
            case 'W':
                current_x -= distance;
                break;
            default:
                printf("Invalid direction entered. Please try again.\n");
        }

        //calculate remaining distance and print new position
        remaining_distance = abs(target_x-current_x) + abs(target_y-current_y);
        printf("Your new position is (%d,%d).\n", current_x, current_y);

        //inform if getting closer or farther from target
        if(remaining_distance < abs(abs(target_x-current_x) + abs(target_y-current_y)))
            printf("Getting closer to target.\n\n");
        else
            printf("Getting farther from target.\n\n");
    }

    printf("Congratulations! You have reached your target position at (%d,%d).\n", target_x, target_y);

    return 0;
}