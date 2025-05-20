//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>

#define MOVE_FORWARD 1
#define MOVE_BACKWARD 2
#define TURN_LEFT 3
#define TURN_RIGHT 4
#define STOP 0
#define COMMAND_DELAY 500000 // delay in microseconds

typedef struct {
    int command;
    int duration; // in seconds
} RobotCommand;

typedef struct {
    int position; // Simulated position index
    pthread_mutex_t lock;
} Robot;

Robot robot;

void *current_command_thread(void *arg) {
    RobotCommand *cmd = (RobotCommand *)arg;

    for (int i = 0; i < cmd->duration; i++) {
        usleep(COMMAND_DELAY);

        pthread_mutex_lock(&robot.lock);
        switch (cmd->command) {
            case MOVE_FORWARD:
                robot.position++;
                printf("Robot moving forward. Current position: %d\n", robot.position);
                break;
            case MOVE_BACKWARD:
                robot.position--;
                printf("Robot moving backward. Current position: %d\n", robot.position);
                break;
            case TURN_LEFT:
                printf("Robot turning left.\n");
                break;
            case TURN_RIGHT:
                printf("Robot turning right.\n");
                break;
            case STOP:
                printf("Robot stopped. Current position: %d\n", robot.position);
                pthread_mutex_unlock(&robot.lock);
                return NULL;
        }
        pthread_mutex_unlock(&robot.lock);
    }
    return NULL;
}

void execute_command(RobotCommand cmd) {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, current_command_thread, (void *)&cmd);
    pthread_join(thread_id, NULL);
}

void signal_handler(int signal) {
    if (signal == SIGINT) {
        printf("Interrupt received. Stopping the robot.\n");
        RobotCommand stop_cmd = {STOP, 1};
        execute_command(stop_cmd);
        exit(0);
    }
}

int main() {
    // Initialize the robot
    robot.position = 0;
    pthread_mutex_init(&robot.lock, NULL);

    // Set signal handler for graceful exit
    signal(SIGINT, signal_handler);

    printf("Welcome to the Robot Movement Control System!\n");

    while (1) {
        int command;
        int duration;

        printf("Enter command (1: Forward, 2: Backward, 3: Left, 4: Right, 0: Stop): ");
        scanf("%d", &command);
        
        if (command == STOP) {
            RobotCommand stop_cmd = {STOP, 1};
            execute_command(stop_cmd);
        } else {
            printf("Enter duration in seconds: ");
            scanf("%d", &duration);

            RobotCommand cmd = {command, duration};
            execute_command(cmd);
        }

        printf("------------------------------------------\n");
    }

    pthread_mutex_destroy(&robot.lock);
    return 0;
}