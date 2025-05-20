//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SPEED 100
#define MIN_SPEED 0

int vehicle_speed = 0;
int steering_angle = 0;

void* speed_controller(void* arg)
{
    while(1)
    {
        int input_speed;
        printf("Enter speed: ");
        scanf("%d", &input_speed);

        if(input_speed > MAX_SPEED)
            vehicle_speed = MAX_SPEED;
        else if(input_speed < MIN_SPEED)
            vehicle_speed = MIN_SPEED;
        else
            vehicle_speed = input_speed;

        printf("Vehicle speed set to %d\n", vehicle_speed);
    }
}

void* steering_controller(void* arg)
{
    while(1)
    {
        int input_angle;
        printf("Enter steering angle: ");
        scanf("%d", &input_angle);

        if(input_angle > 180)
            steering_angle = 180;
        else if(input_angle < -180)
            steering_angle = -180;
        else
            steering_angle = input_angle;

        printf("Steering angle set to %d\n", steering_angle);
    }
}

void* velocity_controller(void* arg)
{
    while(1)
    {
        printf("Vehicle is moving at %d km/h with a steering angle of %d degrees\n", vehicle_speed, steering_angle);
        sleep(2);
    }
}

int main()
{
    pthread_t speed_thread, steering_thread, velocity_thread;

    pthread_create(&speed_thread, NULL, speed_controller, NULL);
    pthread_create(&steering_thread, NULL, steering_controller, NULL);
    pthread_create(&velocity_thread, NULL, velocity_controller, NULL);

    pthread_join(speed_thread, NULL);
    pthread_join(steering_thread, NULL);
    pthread_join(velocity_thread, NULL);

    return 0;
}