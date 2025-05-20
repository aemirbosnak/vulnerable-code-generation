//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

int x = 0, y = 0;

void move(int direction) {
    switch(direction) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y++;
            break;
        case DOWN:
            y--;
            break;
    }
    printf("Moved to x:%d y:%d\n", x, y);
}

void *remote_control(void *arg) {
    while(1) {
        char command;
        scanf(" %c", &command);
        switch(command) {
            case 'a':
                move(LEFT);
                break;
            case 'd':
                move(RIGHT);
                break;
            case 'w':
                move(UP);
                break;
            case 's':
                move(DOWN);
                break;
            default:
                printf("Invalid command!\n");
        }
    }
    return NULL;
}

int main() {
    pthread_t thread;
    int result = pthread_create(&thread, NULL, remote_control, NULL);
    if(result != 0) {
        printf("Failed to create thread.\n");
        exit(1);
    }

    while(1) {
        printf("Current position: x:%d y:%d\n", x, y);
        sleep(1);
    }

    return 0;
}