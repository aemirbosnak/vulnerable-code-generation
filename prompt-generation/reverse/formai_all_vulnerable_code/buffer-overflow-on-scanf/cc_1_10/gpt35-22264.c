//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 10
#define MIN_SPEED 0
#define MAX_ALTITUDE 100
#define MIN_ALTITUDE 0

typedef struct drone
{
    int speed;
    int altitude;
} Drone;

void print_drone_state(Drone drone)
{
    printf("Drone state: speed = %d, altitude = %d\n", drone.speed, drone.altitude);
}

void increase_speed(Drone* drone)
{
    if (drone->speed < MAX_SPEED)
    {
        drone->speed++;
        printf("Speed increased to %d\n", drone->speed);
    }
    else
    {
        printf("Cannot increase speed. Already at maximum speed.\n");
    }
}

void decrease_speed(Drone* drone)
{
    if (drone->speed > MIN_SPEED)
    {
        drone->speed--;
        printf("Speed decreased to %d\n", drone->speed);
    }
    else
    {
        printf("Cannot decrease speed. Already at minimum speed.\n");
    }
}

void increase_altitude(Drone* drone)
{
    if (drone->altitude < MAX_ALTITUDE)
    {
        drone->altitude++;
        printf("Altitude increased to %d\n", drone->altitude);
    }
    else
    {
        printf("Cannot increase altitude. Already at maximum altitude.\n");
    }
}

void decrease_altitude(Drone* drone)
{
    if (drone->altitude > MIN_ALTITUDE)
    {
        drone->altitude--;
        printf("Altitude decreased to %d\n", drone->altitude);
    }
    else
    {
        printf("Cannot decrease altitude. Already at minimum altitude.\n");
    }
}

int main()
{
    Drone my_drone = {5, 50}; // start at speed 5, altitude 50
    char user_input;

    do
    {
        print_drone_state(my_drone);
        printf("What would you like to do? (i)increase speed, (d)decrease speed, (u)increase altitude, (h)decrease altitude, or (q)uit: ");
        scanf(" %c", &user_input);

        switch (user_input)
        {
        case 'i':
            increase_speed(&my_drone);
            break;
        case 'd':
            decrease_speed(&my_drone);
            break;
        case 'u':
            increase_altitude(&my_drone);
            break;
        case 'h':
            decrease_altitude(&my_drone);
            break;
        case 'q':
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid input, try again\n");
        }

    } while (user_input != 'q');

    return 0;
}