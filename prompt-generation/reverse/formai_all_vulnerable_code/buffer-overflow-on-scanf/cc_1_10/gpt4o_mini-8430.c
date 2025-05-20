//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#define GRID_SIZE 10

typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    Direction dir;
    pthread_mutex_t lock;
} Robot;

Robot robot;

void* move_robot(void* arg) {
    while (1) {
        pthread_mutex_lock(&robot.lock);
        
        switch (robot.dir) {
            case UP:
                if (robot.pos.y > 0) {
                    robot.pos.y--;
                }
                break;
            case DOWN:
                if (robot.pos.y < GRID_SIZE - 1) {
                    robot.pos.y++;
                }
                break;
            case LEFT:
                if (robot.pos.x > 0) {
                    robot.pos.x--;
                }
                break;
            case RIGHT:
                if (robot.pos.x < GRID_SIZE - 1) {
                    robot.pos.x++;
                }
                break;
        }

        printf("Robot is at (%d, %d)\n", robot.pos.x, robot.pos.y);
        pthread_mutex_unlock(&robot.lock);
        sleep(1);
    }
    return NULL;
}

void update_direction(Direction new_dir) {
    pthread_mutex_lock(&robot.lock);
    robot.dir = new_dir;
    pthread_mutex_unlock(&robot.lock);
}

void signal_handler(int signum) {
    if (signum == SIGINT) {
        printf("\nExiting robot control gracefully.\n");
        pthread_mutex_destroy(&robot.lock);
        exit(0);
    }
}

int main() {
    robot.pos.x = GRID_SIZE / 2;
    robot.pos.y = GRID_SIZE / 2;
    robot.dir = UP;
    pthread_mutex_init(&robot.lock, NULL);

    signal(SIGINT, signal_handler);

    pthread_t robot_thread;
    if (pthread_create(&robot_thread, NULL, move_robot, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    char command;
    while (1) {
        printf("Enter command (w: up, s: down, a: left, d: right, q: quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'w':
                update_direction(UP);
                break;
            case 's':
                update_direction(DOWN);
                break;
            case 'a':
                update_direction(LEFT);
                break;
            case 'd':
                update_direction(RIGHT);
                break;
            case 'q':
                printf("Robot is shutting down...\n");
                pthread_cancel(robot_thread);
                pthread_join(robot_thread, NULL);
                pthread_mutex_destroy(&robot.lock);
                return 0;
            default:
                printf("Invalid command. Use 'w', 's', 'a', 'd', or 'q'.\n");
                break;
        }
    }

    pthread_join(robot_thread, NULL);
    pthread_mutex_destroy(&robot.lock);
    return 0;
}