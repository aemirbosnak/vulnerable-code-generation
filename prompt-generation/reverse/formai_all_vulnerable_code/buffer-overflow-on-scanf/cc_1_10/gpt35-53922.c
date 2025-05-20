//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0)); // Making sure that the random number generator initializes with a different seed every time we run the program
    int battery_level = 100;
    int distance_travelled = 0;
    int signal_strength = 100;
    int car_direction = 0; // 0 means forward, 1 means backward
    int car_speed = 0;

    while(1) // loop indefinitely until the user decides to quit the program
    {
        printf("=========================\n");
        printf("Remote Control Car Program\n");
        printf("=========================\n");
        printf("Battery Level: %d%%\n", battery_level);
        printf("Distance Travelled: %d meters\n", distance_travelled);
        printf("Signal Strength: %d%%\n", signal_strength);
        printf("Car Direction: %s\n", car_direction==0?"Forward":"Backward");
        printf("Car Speed: %d meters/second\n", car_speed);
        printf("=========================\n");
        printf("Choose an action:\n");
        printf("1. Move Car Forward\n");
        printf("2. Move Car Backward\n");
        printf("3. Turn Off Car\n");
        printf("Your choice: ");

        int choice;
        scanf("%d", &choice);

        if(choice == 1) // move car forward
        {
            if(battery_level <= 10)
            {
                printf("Battery Level Too Low to Move Car Forward!\n");
            }
            else
            {
                car_direction = 0;
                car_speed = rand()%5 + 1; // Set car speed to a random value between 1 and 5 meters/second
                distance_travelled += car_speed;
                battery_level -= 2*car_speed;
                signal_strength -= rand()%10 + 1; // Reduce signal strength by a random value between 1 and 10%
                printf("Car Moved Forward %d meters at %d meters/second!\n", car_speed, car_speed);
            }
        }
        else if(choice == 2) // move car backward
        {
            if(battery_level <= 10)
            {
                printf("Battery Level Too Low to Move Car Backward!\n");
            }
            else
            {
                car_direction = 1;
                car_speed = rand()%3 + 1; // Set car speed to a random value between 1 and 3 meters/second
                distance_travelled -= car_speed;
                battery_level -= 3*car_speed;
                signal_strength -= rand()%5 + 1; // Reduce signal strength by a random value between 1 and 5%
                printf("Car Moved Backward %d meters at %d meters/second!\n", car_speed, car_speed);
            }
        }
        else if(choice == 3) // quit program
        {
            printf("Turning Off Car!\n");
            break;
        }
        else // invalid input
        {
            printf("Invalid Choice!\n");
        }

        if(battery_level <= 0) // battery ran out
        {
            printf("Battery Level Exhausted! Turning Off Car!\n");
            break;
        }
        if(signal_strength <= 0) // signal lost
        {
            printf("Signal Lost! Turning Off Car!\n");
            break;
        }

        printf("\n"); // add a blank line between outputs for clarity
    }

    return 0;
}