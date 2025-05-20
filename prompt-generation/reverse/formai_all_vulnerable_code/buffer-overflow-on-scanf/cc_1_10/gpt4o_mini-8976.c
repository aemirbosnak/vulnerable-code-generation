//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_POSITION 100
#define MIN_POSITION 0
#define STEP_SIZE 5

typedef struct {
    int position;
    pthread_mutex_t lock;
} Robot;

void move_forward(Robot *robot) {
    pthread_mutex_lock(&robot->lock);
    if (robot->position + STEP_SIZE <= MAX_POSITION) {
        robot->position += STEP_SIZE;
        printf("Robot moved forward to position: %d\n", robot->position);
    } else {
        printf("Robot cannot move forward. Reached maximum position: %d\n", MAX_POSITION);
    }
    pthread_mutex_unlock(&robot->lock);
}

void move_backward(Robot *robot) {
    pthread_mutex_lock(&robot->lock);
    if (robot->position - STEP_SIZE >= MIN_POSITION) {
        robot->position -= STEP_SIZE;
        printf("Robot moved backward to position: %d\n", robot->position);
    } else {
        printf("Robot cannot move backward. Reached minimum position: %d\n", MIN_POSITION);
    }
    pthread_mutex_unlock(&robot->lock);
}

void *control_robot(void *arg) {
    Robot *robot = (Robot *)arg;
    char command;
    while (1) {
        printf("Enter command (w: forward, s: backward, q: quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'w':
                move_forward(robot);
                break;
            case 's':
                move_backward(robot);
                break;
            case 'q':
                printf("Exiting control loop.\n");
                return NULL;
            default:
                printf("Invalid command. Use 'w', 's', or 'q'.\n");
        }
    }
}

void *monitor_robot(void *arg) {
    Robot *robot = (Robot *)arg;
    while (1) {
        pthread_mutex_lock(&robot->lock);
        printf("Current position of the robot: %d\n", robot->position);
        pthread_mutex_unlock(&robot->lock);
        sleep(2);
    }
}

int main() {
    Robot robot;
    robot.position = 0;
    pthread_mutex_init(&robot.lock, NULL);

    pthread_t control_thread, monitor_thread;

    pthread_create(&control_thread, NULL, control_robot, &robot);
    pthread_create(&monitor_thread, NULL, monitor_robot, &robot);

    pthread_join(control_thread, NULL);
    
    // Cancel monitor thread before exiting
    pthread_cancel(monitor_thread);
    pthread_join(monitor_thread, NULL);

    pthread_mutex_destroy(&robot.lock);
    printf("Robot program has ended.\n");
    return 0;
}