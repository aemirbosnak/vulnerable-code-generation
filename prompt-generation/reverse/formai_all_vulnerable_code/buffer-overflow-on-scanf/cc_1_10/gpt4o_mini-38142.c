//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP,
    EXIT
} Command;

typedef struct {
    Command current_command;
    pthread_mutex_t mutex;
} Robot;

void* move_robot(void* arg) {
    Robot* robot = (Robot*)arg;
    
    while (1) {
        pthread_mutex_lock(&robot->mutex);
        Command cmd = robot->current_command;
        pthread_mutex_unlock(&robot->mutex);
        
        switch (cmd) {
            case FORWARD:
                printf("Robot is moving forward...\n");
                break;
            case BACKWARD:
                printf("Robot is moving backward...\n");
                break;
            case LEFT:
                printf("Robot is turning left...\n");
                break;
            case RIGHT:
                printf("Robot is turning right...\n");
                break;
            case STOP:
                printf("Robot has stopped.\n");
                break;
            case EXIT:
                printf("Exiting the robot control program.\n");
                return NULL;
            default:
                printf("No valid command.\n");
                break;
        }
        sleep(1);  // Simulate time taken for movement
    }
}

void* user_input(void* arg) {
    Robot* robot = (Robot*)arg;
    char input[10];
    
    while (1) {
        printf("Enter command (FORWARD, BACKWARD, LEFT, RIGHT, STOP, EXIT): ");
        scanf("%s", input);
        
        pthread_mutex_lock(&robot->mutex);
        if (strcmp(input, "FORWARD") == 0) {
            robot->current_command = FORWARD;
        } else if (strcmp(input, "BACKWARD") == 0) {
            robot->current_command = BACKWARD;
        } else if (strcmp(input, "LEFT") == 0) {
            robot->current_command = LEFT;
        } else if (strcmp(input, "RIGHT") == 0) {
            robot->current_command = RIGHT;
        } else if (strcmp(input, "STOP") == 0) {
            robot->current_command = STOP;
        } else if (strcmp(input, "EXIT") == 0) {
            robot->current_command = EXIT;
        } else {
            printf("Invalid command. Try again.\n");
        }
        pthread_mutex_unlock(&robot->mutex);
        
        if (robot->current_command == EXIT) {
            break;
        }
    }
    return NULL;
}

int main() {
    Robot robot;
    robot.current_command = STOP;
    pthread_mutex_init(&robot.mutex, NULL);
    
    pthread_t move_thread, input_thread;
    
    pthread_create(&move_thread, NULL, move_robot, &robot);
    pthread_create(&input_thread, NULL, user_input, &robot);
    
    pthread_join(input_thread, NULL);
    
    // Clean up and stop the robot
    pthread_cancel(move_thread);
    pthread_join(move_thread, NULL);
    
    pthread_mutex_destroy(&robot.mutex);
    return 0;
}