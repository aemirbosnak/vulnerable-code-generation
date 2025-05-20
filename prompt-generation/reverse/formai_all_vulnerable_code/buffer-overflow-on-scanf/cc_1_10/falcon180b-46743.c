//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

double get_current_time() {
    struct timespec ts;
    if (clock_gettime(CLOCK_MONOTONIC, &ts) == -1) {
        perror("clock_gettime");
        return 0;
    }
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}

void motor_control(int motor_speed) {
    printf("Motor speed set to %d\n", motor_speed);
}

void camera_control(int camera_angle) {
    printf("Camera angle set to %d degrees\n", camera_angle);
}

void main() {
    int choice;
    double time_elapsed = 0;

    while(1) {
        printf("\nDrone Remote Control\n");
        printf("1. Motor Speed Control\n");
        printf("2. Camera Angle Control\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter motor speed (0-100): ");
                int motor_speed = getchar() - '0';
                motor_control(motor_speed);
                break;

            case 2:
                printf("Enter camera angle (0-360): ");
                int camera_angle = getchar() - '0';
                camera_control(camera_angle);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }

        time_elapsed += 0.1;
        if(time_elapsed >= 1) {
            printf("\nTime elapsed: %lf seconds\n", time_elapsed);
            time_elapsed = 0;
        }
    }
}