//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 50 //maximum speed of vehicle
#define MIN_RADIUS 5 //minimum turning radius of vehicle
#define PI 3.14159

int main() {
    int speed = 0, direction = 0, distance = 0, radius = 0;
    double time_elapsed = 0, angle = 0, x = 0, y = 0, speed_x = 0, speed_y = 0;
    time_t start_time, end_time;

    printf("Welcome to Remote Control Vehicle Simulation!\n");
    printf("Enter the speed of the vehicle (0-%d km/h): ", MAX_SPEED);
    scanf("%d", &speed);

    while(speed > MAX_SPEED || speed < 0) {
        printf("Invalid speed. Enter a speed between 0 and %d km/h: ", MAX_SPEED);
        scanf("%d", &speed);
    }

    printf("Enter the direction of the vehicle (0-359 degrees): ");
    scanf("%d", &direction);

    while(direction < 0 || direction > 359) {
        printf("Invalid direction. Enter a direction between 0 and 359 degrees: ");
        scanf("%d", &direction);
    }

    printf("Enter the distance to be covered by the vehicle (in meters): ");
    scanf("%d", &distance);

    printf("Enter the turning radius of the vehicle (in meters): ");
    scanf("%d", &radius);

    while(radius < MIN_RADIUS) {
        printf("Invalid radius. Enter a radius greater than %d meters: ", MIN_RADIUS);
        scanf("%d", &radius);
    }

    angle = (double) distance / radius; //calculate angle of turn
    time(&start_time); //start timer

    while(distance > 0) {
        //calculate new position of vehicle based on speed and direction
        x += speed_x * time_elapsed;
        y += speed_y * time_elapsed;

        double radians = direction * PI / 180;
        speed_x = speed * cos(radians);
        speed_y = speed * sin(radians);

        //check if vehicle needs to turn
        if(radius > 0) {
            double turn_radius = sqrt(pow(distance, 2) + pow(radius, 2) - 2 * distance * radius * cos(angle));

            double turn_angle = angle * radius / turn_radius;
            double arc_length = turn_angle * turn_radius;

            if(arc_length > distance) {
                turn_angle = angle * distance / arc_length;
                arc_length = distance;
            }

            double cx = x - radius * sin(radians);
            double cy = y + radius * cos(radians);

            //calculate new position of vehicle after turning
            x = cx + (cos(radians + turn_angle) * turn_radius);
            y = cy - (sin(radians + turn_angle) * turn_radius);

            direction += turn_angle * 180 / PI;
            distance -= arc_length; //decrement distance
        } else {
            distance -= speed * time_elapsed; //decrement distance
        }

        time(&end_time);
        time_elapsed = difftime(end_time, start_time); //calculate time elapsed
    }

    printf("Vehicle has reached its destination in %f seconds!\n", time_elapsed);

    return 0;
}