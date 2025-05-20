//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

// Define the movement commands
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

// Robot structure to hold its position and movement status
typedef struct {
    int x;
    int y;
    int direction; // 0: stopped, 1: moving
    pthread_mutex_t lock;
} Robot;

Robot robot;

// Function for the robot to move
void *move_robot(void *arg) {
    while (1) {
        pthread_mutex_lock(&robot.lock);
        if (robot.direction == FORWARD) {
            robot.y += 1;
            printf("Moving Forward to position (%d, %d)\n", robot.x, robot.y);
        } else if (robot.direction == BACKWARD) {
            robot.y -= 1;
            printf("Moving Backward to position (%d, %d)\n", robot.x, robot.y);
        } else if (robot.direction == LEFT) {
            robot.x -= 1;
            printf("Turning Left to position (%d, %d)\n", robot.x, robot.y);
        } else if (robot.direction == RIGHT) {
            robot.x += 1;
            printf("Turning Right to position (%d, %d)\n", robot.x, robot.y);
        }
        pthread_mutex_unlock(&robot.lock);
        usleep(500000); // Delay to simulate movement time
    }
}

// Function to control robot commands
void *control_robot(void *arg) {
    char command[10];
    while (1) {
        printf("Enter command (forward, backward, left, right, stop): ");
        scanf("%s", command);
        
        pthread_mutex_lock(&robot.lock);
        if (strcmp(command, "forward") == 0) {
            robot.direction = FORWARD;
        } else if (strcmp(command, "backward") == 0) {
            robot.direction = BACKWARD;
        } else if (strcmp(command, "left") == 0) {
            robot.direction = LEFT;
        } else if (strcmp(command, "right") == 0) {
            robot.direction = RIGHT;
        } else if (strcmp(command, "stop") == 0) {
            robot.direction = STOP;
            printf("Robot stopped at position (%d, %d)\n", robot.x, robot.y);
            continue; // Skip the unlock step to prevent motion after stop
        } else {
            printf("Invalid command! Please try again.\n");
        }
        pthread_mutex_unlock(&robot.lock);
    }
}

int main() {
    pthread_t move_thread, control_thread;
    
    // Initialize robot
    robot.x = 0;
    robot.y = 0;
    robot.direction = STOP;
    pthread_mutex_init(&robot.lock, NULL);

    // Create threads for moving the robot and controlling the robot
    pthread_create(&move_thread, NULL, move_robot, NULL);
    pthread_create(&control_thread, NULL, control_robot, NULL);

    // Wait for threads to finish (which they won't in this case)
    pthread_join(move_thread, NULL);
    pthread_join(control_thread, NULL);

    pthread_mutex_destroy(&robot.lock);
    return 0;
}