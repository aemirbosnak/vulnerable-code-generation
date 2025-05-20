//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    float latitude = 0, longitude = 0;
    char direction[4][6] = {"North", "South", "East", "West"};
    char currentDirection[6];

    printf("Welcome to the GPS Navigation Simulation!\n");
    printf("Enter your starting latitude (between -90 and 90): ");
    scanf("%f", &latitude);
    printf("Enter your starting longitude (between -180 and 180): ");
    scanf("%f", &longitude);

    printf("You are currently at %f N, %f W\n", latitude, longitude);

    while(1)
    {
        int move = rand() % 3 + 1;
        int dir = rand() % 4;

        if(dir == 0)
        {
            latitude += move;
            strcpy(currentDirection, direction[dir]);
        }
        else if(dir == 1)
        {
            latitude -= move;
            strcpy(currentDirection, direction[dir]);
        }
        else if(dir == 2)
        {
            longitude += move;
            strcpy(currentDirection, direction[dir]);
        }
        else
        {
            longitude -= move;
            strcpy(currentDirection, direction[dir]);
        }

        if(latitude > 90 || latitude < -90 || longitude > 180 || longitude < -180)
        {
            printf("You have gone off the map! Try again.\n");
            break;
        }

        printf("You moved %d units to the %s, your new location is %f N, %f W\n", move, currentDirection, latitude, longitude);

        printf("Would you like to continue? (Y/N) ");
        char choice;
        scanf(" %c", &choice);

        if(choice == 'N' || choice == 'n')
        {
            printf("Exiting the program, see you later!\n");
            break;
        }
    }

    return 0;
}