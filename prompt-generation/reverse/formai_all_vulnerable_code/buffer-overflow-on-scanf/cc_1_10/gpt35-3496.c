//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define ARMED 1
#define DISARMED 0

typedef struct {
    float roll;
    float pitch;
    float yaw;
    float throttle;
} drone_t;

void arm_drone(drone_t* drone) {
    printf("Arming drone...\n");
    drone->roll = 0;
    drone->pitch = 0;
    drone->yaw = 0;
    drone->throttle = 0;
}

void disarm_drone(drone_t* drone) {
    printf("Disarming drone...\n");
    drone->roll = 0;
    drone->pitch = 0;
    drone->yaw = 0;
    drone->throttle = 0;
}

void receive_input(drone_t* drone) {
    printf("Enter roll: ");
    scanf("%f", &drone->roll);
    printf("Enter pitch: ");
    scanf("%f", &drone->pitch);
    printf("Enter yaw: ");
    scanf("%f", &drone->yaw);
    printf("Enter throttle: ");
    scanf("%f", &drone->throttle);
}

int main(void) {
    drone_t my_drone;
    int state = DISARMED;
    char input[30];

    printf("Drone Remote Control\n");
    printf("--------------------\n");

    while(1) {
        printf("Enter command: ");
        scanf("%s", input);

        if (strcmp(input, "arm") == 0) {
            arm_drone(&my_drone);
            state = ARMED;
            printf("Drone armed.\n");
        }
        else if (strcmp(input, "disarm") == 0) {
            disarm_drone(&my_drone);
            state = DISARMED;
            printf("Drone disarmed.\n");
        }
        else if (strcmp(input, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
        else if (state == ARMED) {
            if (strcmp(input, "input") == 0) {
                receive_input(&my_drone);
                printf("Received input: (%.2f, %.2f, %.2f, %.2f).\n", my_drone.roll, my_drone.pitch, my_drone.yaw, my_drone.throttle);
            }
            else {
                printf("Unknown command. Please enter 'input' or 'exit'.\n");
            }
        }
        else {
            printf("Drone not armed. Please arm the drone to enter commands.\n");
        }
    }

    return 0;
}