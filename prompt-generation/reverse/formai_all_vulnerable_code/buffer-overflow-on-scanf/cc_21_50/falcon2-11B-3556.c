//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    //Declaring variables
    int choice;
    int drone_status;
    int move_direction;
    int move_distance;
    int throttle;
    int time_delay;

    //Initializing variables
    choice = 0;
    drone_status = 0;
    move_direction = 0;
    move_distance = 0;
    throttle = 0;
    time_delay = 0;

    //Prompt user for input
    printf("Welcome to the Drone Remote Control!\n");
    printf("Enter the following details to control the drone:\n");
    printf("1. Choice of action\n");
    printf("2. Drone status\n");
    printf("3. Move direction\n");
    printf("4. Move distance\n");
    printf("5. Throttle level\n");
    printf("6. Time delay\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    //Handle user input
    switch(choice)
    {
        case 1: printf("You have chosen action 1\n");
            break;
        case 2: printf("You have chosen drone status 2\n");
            break;
        case 3: printf("You have chosen move direction 3\n");
            break;
        case 4: printf("You have chosen move distance 4\n");
            break;
        case 5: printf("You have chosen throttle level 5\n");
            break;
        case 6: printf("You have chosen time delay 6\n");
            break;
        default: printf("Invalid input!\n");
            break;
    }

    //Handle drone status
    if(drone_status == 1)
    {
        printf("Drone is taking off...\n");
        //delay
        sleep(time_delay);
        printf("Drone is in the air!\n");
    }
    else if(drone_status == 0)
    {
        printf("Drone is not in the air!\n");
    }

    //Handle move direction
    if(move_direction == 1)
    {
        printf("Drone is moving forward!\n");
        //delay
        sleep(time_delay);
        printf("Drone is moving forward!\n");
    }
    else if(move_direction == 0)
    {
        printf("Drone is not moving forward!\n");
    }

    //Handle move distance
    if(move_distance == 1)
    {
        printf("Drone is moving backwards!\n");
        //delay
        sleep(time_delay);
        printf("Drone is moving backwards!\n");
    }
    else if(move_distance == 0)
    {
        printf("Drone is not moving backwards!\n");
    }

    //Handle throttle level
    if(throttle == 1)
    {
        printf("Drone is ascending!\n");
        //delay
        sleep(time_delay);
        printf("Drone is ascending!\n");
    }
    else if(throttle == 0)
    {
        printf("Drone is not ascending!\n");
    }

    //Handle time delay
    if(time_delay == 1)
    {
        printf("Drone is hovering!\n");
        //delay
        sleep(time_delay);
        printf("Drone is hovering!\n");
    }
    else if(time_delay == 0)
    {
        printf("Drone is not hovering!\n");
    }

    //Handle action choice
    switch(choice)
    {
        case 1:
            if(drone_status == 1)
            {
                printf("You have chosen action 1 with drone status 1\n");
                //delay
                sleep(time_delay);
                printf("You have chosen action 1 with drone status 1\n");
            }
            else if(drone_status == 0)
            {
                printf("You have chosen action 1 with drone status 0\n");
                //delay
                sleep(time_delay);
                printf("You have chosen action 1 with drone status 0\n");
            }
            break;
        case 2:
            if(drone_status == 1)
            {
                printf("You have chosen action 2 with drone status 1\n");
                //delay
                sleep(time_delay);
                printf("You have chosen action 2 with drone status 1\n");
            }
            else if(drone_status == 0)
            {
                printf("You have chosen action 2 with drone status 0\n");
                //delay
                sleep(time_delay);
                printf("You have chosen action 2 with drone status 0\n");
            }
            break;
        case 3:
            if(move_direction == 1)
            {
                printf("You have chosen action 3 with move direction 1\n");
                //delay
                sleep(time_delay);
                printf("You have chosen action 3 with move direction 1\n");
            }
            else if(move_direction == 0)
            {
                printf("You have chosen action 3 with move direction 0\n");
                //delay
                sleep(time_delay);
                printf("You have chosen action 3 with move direction 0\n");
            }
            break;
        case 4:
            if(move_distance == 1)
            {
                printf("You have chosen action 4 with move distance 1\n");
                //delay
                sleep(time_delay);
                printf("You have chosen action 4 with move distance 1\n");
            }
            else if(move_distance == 0)
            {
                printf("You have chosen action 4 with move distance 0\n");
                //delay
                sleep(time_delay);
                printf("You have chosen action 4 with move distance 0\n");
            }
            break;
        case 5:
            if(throttle == 1)
            {
                printf("You have chosen action 5 with throttle level 1\n");
                //delay
                sleep(time_delay);
                printf("You have chosen action 5 with throttle level 1\n");
            }
            else if(throttle == 0)
            {
                printf("You have chosen action 5 with throttle level 0\n");
                //delay
                sleep(time_delay);
                printf("You have chosen action 5 with throttle level 0\n");
            }
            break;
        case 6:
            if(time_delay == 1)
            {
                printf("You have chosen action 6 with time delay 1\n");
                //delay
                sleep(time_delay);
                printf("You have chosen action 6 with time delay 1\n");
            }
            else if(time_delay == 0)
            {
                printf("You have chosen action 6 with time delay 0\n");
                //delay
                sleep(time_delay);
                printf("You have chosen action 6 with time delay 0\n");
            }
            break;
        default:
            printf("Invalid action!\n");
            break;
    }

    return 0;
}