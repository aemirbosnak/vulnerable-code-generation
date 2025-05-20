//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MAX_X 10
#define MAX_Y 10

typedef struct {
    int x;
    int y;
    char direction; // N, E, S, W
} Robot;

void initialize_robot(Robot *robot, int start_x, int start_y, char start_direction) {
    robot->x = start_x;
    robot->y = start_y;
    robot->direction = start_direction;
}

void print_robot_position(Robot *robot) {
    printf("Robot is at (%d, %d) facing %c\n", robot->x, robot->y, robot->direction);
}

void move_forward(Robot *robot) {
    switch (robot->direction) {
        case 'N':
            if (robot->y < MAX_Y - 1) robot->y++;
            break;
        case 'E':
            if (robot->x < MAX_X - 1) robot->x++;
            break;
        case 'S':
            if (robot->y > 0) robot->y--;
            break;
        case 'W':
            if (robot->x > 0) robot->x--;
            break;
    }
}

void turn_left(Robot *robot) {
    switch (robot->direction) {
        case 'N':
            robot->direction = 'W';
            break;
        case 'W':
            robot->direction = 'S';
            break;
        case 'S':
            robot->direction = 'E';
            break;
        case 'E':
            robot->direction = 'N';
            break;
    }
}

void turn_right(Robot *robot) {
    switch (robot->direction) {
        case 'N':
            robot->direction = 'E';
            break;
        case 'E':
            robot->direction = 'S';
            break;
        case 'S':
            robot->direction = 'W';
            break;
        case 'W':
            robot->direction = 'N';
            break;
    }
}

void signal_handler(int signum) {
    printf("Emergency stop activated! Program terminating...\n");
    exit(0);
}

int main() {
    // Setup signal handler for emergency stop
    signal(SIGINT, signal_handler);
    
    Robot my_robot;
    initialize_robot(&my_robot, 0, 0, 'N');

    print_robot_position(&my_robot);
    
    char command;
    
    while (1) {
        printf("Enter command (F: Forward, L: Left, R: Right, Q: Quit): ");
        scanf(" %c", &command);
        
        if (command == 'Q' || command == 'q') {
            printf("Exiting the program.\n");
            break;
        }
        
        switch (command) {
            case 'F':
            case 'f':
                move_forward(&my_robot);
                break;
            case 'L':
            case 'l':
                turn_left(&my_robot);
                break;
            case 'R':
            case 'r':
                turn_right(&my_robot);
                break;
            default:
                printf("Invalid command. Please try again.\n");
                continue;
        }

        print_robot_position(&my_robot);
        usleep(500000); // Pause for half a second
    }

    return 0;
}