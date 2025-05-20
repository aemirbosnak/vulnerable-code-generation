//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

void move_forward(double speed, double distance) {
    double time = distance / speed;
    printf("Moving forward for %f seconds\n", time);
}

void turn_left(double speed, double angle) {
    double time = angle / speed;
    printf("Turning left for %f seconds\n", time);
}

void turn_right(double speed, double angle) {
    double time = angle / speed;
    printf("Turning right for %f seconds\n", time);
}

void move_backward(double speed, double distance) {
    double time = distance / speed;
    printf("Moving backward for %f seconds\n", time);
}

void spin_left(double speed, double angle) {
    double time = angle / speed;
    printf("Spinning left for %f seconds\n", time);
}

void spin_right(double speed, double angle) {
    double time = angle / speed;
    printf("Spinning right for %f seconds\n", time);
}

int main() {
    double speed, distance, angle;
    int choice;

    printf("Enter the speed of the robot (in meters/second): ");
    scanf("%lf", &speed);

    while(1) {
        printf("\nEnter your choice:\n");
        printf("1. Move forward\n2. Turn left\n3. Turn right\n4. Move backward\n5. Spin left\n6. Spin right\n7. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the distance to move forward (in meters): ");
                scanf("%lf", &distance);
                move_forward(speed, distance);
                break;
            case 2:
                printf("Enter the angle to turn left (in degrees): ");
                scanf("%lf", &angle);
                turn_left(speed, angle);
                break;
            case 3:
                printf("Enter the angle to turn right (in degrees): ");
                scanf("%lf", &angle);
                turn_right(speed, angle);
                break;
            case 4:
                printf("Enter the distance to move backward (in meters): ");
                scanf("%lf", &distance);
                move_backward(speed, distance);
                break;
            case 5:
                printf("Enter the angle to spin left (in degrees): ");
                scanf("%lf", &angle);
                spin_left(speed, angle);
                break;
            case 6:
                printf("Enter the angle to spin right (in degrees): ");
                scanf("%lf", &angle);
                spin_right(speed, angle);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}