//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 50

int main() {
    // Initialization
    srand(time(NULL));
    int battery_life = rand() % 50 + 50;
    int speed = rand() % (MAX_SPEED + 1);

    // User input
    printf("Enter the distance you want the remote control vehicle to travel: ");
    int distance;
    scanf("%d", &distance);

    // Battery check
    if (battery_life < distance * 2) {
        printf("Battery life is not sufficient for this distance. Aborting mission...\n");
        exit(1);
    }

    // Simulation start
    printf("Initiating remote control vehicle simulation...\n");

    for (int i = 0; i < distance; i++) {
        printf("Travelled %d meters. Battery life remaining: %d%%\n", i, battery_life * 100 / (distance * 2));

        // Random events
        int event = rand() % 10;
        switch (event) {
            case 0:
                printf("Obstacle detected. Slowing down...\n");
                speed /= 2;
                break;
            case 1:
                printf("System malfunction detected. Attempting repair...\n");
                int repair_time = rand() % 10 + 5;
                printf("Estimated repair time: %d seconds\n", repair_time);
                for (int j = 0; j < repair_time; j++) {
                    printf("Repairing... %d%%\n", j * 100 / repair_time);
                    sleep(1);
                }
                printf("Repair successful. Resuming mission...\n");
                break;
            case 2:
                printf("Signal lost. Attempting to reconnect...\n");
                int reconnect_time = rand() % 10 + 5;
                printf("Estimated reconnect time: %d seconds\n", reconnect_time);
                for (int j = 0; j < reconnect_time; j++) {
                    printf("Reconnecting... %d%%\n", j * 100 / reconnect_time);
                    sleep(1);
                }
                printf("Reconnect successful. Resuming mission...\n");
                break;
            default:
                printf("No events detected. Maintaining current speed...\n");
                break;
        }

        // Battery drain
        battery_life--;
    }

    // Simulation end
    printf("Simulation successful. Remote control vehicle has reached its destination.\n");
    printf("Battery life remaining: %d%%\n", battery_life * 100 / (distance * 2));
    return 0;
}