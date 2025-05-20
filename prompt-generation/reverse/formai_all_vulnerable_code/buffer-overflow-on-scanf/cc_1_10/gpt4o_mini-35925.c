//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#define MAX_X 10
#define MAX_Y 10

typedef struct {
    int x;
    int y;
} Position;

Position robotPos = {0, 0};
pthread_mutex_t posMutex;
volatile sig_atomic_t stopFlag = 0;

void handleSignal(int signum) {
    stopFlag = 1;
}

void *movementControl(void *arg) {
    char command;
    while (!stopFlag) {
        printf("Enter command (W/A/S/D to move, Q to quit): ");
        scanf(" %c", &command);
        
        pthread_mutex_lock(&posMutex);
        switch (command) {
            case 'W':
            case 'w':
                if (robotPos.y < MAX_Y - 1) {
                    robotPos.y++;
                }
                break;
            case 'A':
            case 'a':
                if (robotPos.x > 0) {
                    robotPos.x--;
                }
                break;
            case 'S':
            case 's':
                if (robotPos.y > 0) {
                    robotPos.y--;
                }
                break;
            case 'D':
            case 'd':
                if (robotPos.x < MAX_X - 1) {
                    robotPos.x++;
                }
                break;
            case 'Q':
            case 'q':
                stopFlag = 1; // To break the loop
                break;
            default:
                printf("Unknown command.\n");
        }
        printf("Current Position: (%d, %d)\n", robotPos.x, robotPos.y);
        pthread_mutex_unlock(&posMutex);
    }
    return NULL;
}

void *statusMonitor(void *arg) {
    while (!stopFlag) {
        pthread_mutex_lock(&posMutex);
        printf("Monitoring: Robot is at (%d, %d)\n", robotPos.x, robotPos.y);
        pthread_mutex_unlock(&posMutex);
        sleep(2); // Monitor every 2 seconds
    }
    return NULL;
}

int main() {
    signal(SIGINT, handleSignal); // Handle Ctrl+C to stop the robot
    pthread_t movementThread, monitoringThread;

    pthread_mutex_init(&posMutex, NULL);

    if (pthread_create(&movementThread, NULL, movementControl, NULL) != 0) {
        fprintf(stderr, "Error creating movement thread\n");
        return 1;
    }

    if (pthread_create(&monitoringThread, NULL, statusMonitor, NULL) != 0) {
        fprintf(stderr, "Error creating monitoring thread\n");
        return 1;
    }

    pthread_join(movementThread, NULL);
    pthread_join(monitoringThread, NULL);

    pthread_mutex_destroy(&posMutex);
    printf("Robot movement program stopped safely.\n");

    return 0;
}