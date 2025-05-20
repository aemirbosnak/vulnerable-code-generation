//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the C Drone Remote Control Program! \n");
    printf("Enter '1' to take off, '2' to land, '3' to move forward, '4' to move backward, '5' to turn left, '6' to turn right, '7' to increase altitude, '8' to decrease altitude, and '9' to exit the program. \n");

    int droneState = 0; // 0 = landed, 1 = in air
    int altitude = 0;
    int input;

    while(1) // infinite loop
    {
        printf("Enter command: ");
        scanf("%d", &input);

        if(input == 1) // take off
        {
            if(droneState == 0)
            {
                printf("Drone taking off... \n");
                droneState = 1;
                altitude += 10;
            }
            else
            {
                printf("Drone already in air! \n");
            }
        }
        else if(input == 2) // land
        {
            if(droneState == 1)
            {
                printf("Drone landing... \n");
                droneState = 0;
                altitude = 0;
            }
            else
            {
                printf("Drone already landed! \n");
            }
        }
        else if(input == 3) // move forward
        {
            if(droneState == 1)
            {
                printf("Drone moving forward... \n");
            }
            else
            {
                printf("Drone must be in air to move! \n");
            }
        }
        else if(input == 4) // move backward
        {
            if(droneState == 1)
            {
                printf("Drone moving backward... \n");
            }
            else
            {
                printf("Drone must be in air to move! \n");
            }
        }
        else if(input == 5) // turn left
        {
            if(droneState == 1)
            {
                printf("Drone turning left... \n");
            }
            else
            {
                printf("Drone must be in air to turn! \n");
            }
        }
        else if(input == 6) // turn right
        {
            if(droneState == 1)
            {
                printf("Drone turning right... \n");
            }
            else
            {
                printf("Drone must be in air to turn! \n");
            }
        }
        else if(input == 7) // increase altitude
        {
            if(droneState == 1)
            {
                printf("Drone increasing altitude... \n");
                altitude += 5;
            }
            else
            {
                printf("Drone must be in air to increase altitude! \n");
            }
        }
        else if(input == 8) // decrease altitude
        {
            if(droneState == 1)
            {
                if(altitude > 5)
                {
                    printf("Drone decreasing altitude... \n");
                    altitude -= 5;
                }
                else
                {
                    printf("Drone can't decrease altitude any further! \n");
                }
            }
            else
            {
                printf("Drone must be in air to decrease altitude! \n");
            }
        }
        else if(input == 9) // exit program
        {
            printf("Exiting drone control program... \n");
            exit(0);
        }
        else // invalid input
        {
            printf("Invalid command! \n");
        }

        printf("Drone state: %d | Altitude: %d \n", droneState, altitude); // print drone state and altitude
    }

    return 0;
}