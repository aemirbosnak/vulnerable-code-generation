//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>

volatile sig_atomic_t keep_running = 1;

void int_handler(int signum) {
    keep_running = 0;
}

struct Drone {
    int altitude;
    int speed;
    int direction;
    int cameraOn;
};

void* control_drone(void* arg) {
    struct Drone* drone = (struct Drone*)arg;

    while (keep_running) {
        int command;
        printf("Enter command: 1-Ascend, 2-Descend, 3-Speed Up, 4-Slow Down, 5-Camera On/Off, 6-Fly Left, 7-Fly Right, 0-Exit: ");
        scanf("%d", &command);
        
        switch (command) {
            case 1:
                drone->altitude += 100;
                printf("Ascending... New Altitude: %d\n", drone->altitude);
                break;
            case 2:
                if (drone->altitude >= 100) {
                    drone->altitude -= 100;
                } else {
                    printf("Cannot descend. Current Altitude: %d\n", drone->altitude);
                }
                printf("Descending... New Altitude: %d\n", drone->altitude);
                break;
            case 3:
                drone->speed += 10;
                printf("Speeding Up... New Speed: %d\n", drone->speed);
                break;
            case 4:
                if (drone->speed >= 10) {
                    drone->speed -= 10;
                } else {
                    printf("Cannot slow down further. Current Speed: %d\n", drone->speed);
                }
                printf("Slowing Down... New Speed: %d\n", drone->speed);
                break;
            case 5:
                drone->cameraOn = !drone->cameraOn;
                printf("Camera is now %s\n", drone->cameraOn ? "On" : "Off");
                break;
            case 6:
                drone->direction -= 15;
                printf("Flying Left... New Direction: %d\n", drone->direction);
                break;
            case 7:
                drone->direction += 15;
                printf("Flying Right... New Direction: %d\n", drone->direction);
                break;
            case 0:
                keep_running = 0;
                printf("Shutting down the drone...\n");
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
    }
    return NULL;
}

void display_status(struct Drone* drone) {
    printf("\nDrone Status:\n");
    printf("Altitude: %d, Speed: %d, Direction: %d, Camera: %s\n",
        drone->altitude, drone->speed, drone->direction,
        drone->cameraOn ? "On" : "Off");
}

int main() {
    struct Drone drone = {0, 0, 0, 0};

    signal(SIGINT, int_handler);
    
    pthread_t control_thread;
    if (pthread_create(&control_thread, NULL, control_drone, (void*)&drone)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    while (keep_running) {
        display_status(&drone);
        sleep(2);
    }

    pthread_join(control_thread, NULL);
    
    printf("Drone completely powered down.\n");
    return 0;
}