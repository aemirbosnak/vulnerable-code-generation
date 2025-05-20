//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void move_forward(double speed, double time) {
    printf("Moving forward at %lf m/s for %lf s\n", speed, time);
}

void turn_left(double speed, double time) {
    printf("Turning left at %lf rad/s for %lf s\n", speed, time);
}

void turn_right(double speed, double time) {
    printf("Turning right at %lf rad/s for %lf s\n", speed, time);
}

void main() {
    double distance = 0, angle = 0;
    int choice;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter distance to move forward (in meters): ");
                scanf("%lf", &distance);
                move_forward(distance, distance/5.0);
                break;

            case 2:
                printf("Enter angle to turn left (in radians): ");
                scanf("%lf", &angle);
                turn_left(angle, angle/5.0);
                break;

            case 3:
                printf("Enter angle to turn right (in radians): ");
                scanf("%lf", &angle);
                turn_right(angle, angle/5.0);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);
}