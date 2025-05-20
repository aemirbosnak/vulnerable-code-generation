//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>

#define ROBOT_UART_PATH "/dev/ttyS0"
#define MOVE_FORWARD 'F'
#define MOVE_BACKWARD 'B'
#define TURN_LEFT 'L'
#define TURN_RIGHT 'R'
#define STOP 'S'
#define MAX_MOVEMENTS 100

typedef struct {
    int x;
    int y;
    char direction; // 'N', 'E', 'S', 'W'
} Robot;

Robot* create_robot() {
    Robot* robot = (Robot*)malloc(sizeof(Robot));
    if (!robot) {
        perror("Failed to allocate memory for robot");
        exit(EXIT_FAILURE);
    }
    robot->x = 0;
    robot->y = 0;
    robot->direction = 'N';
    return robot;
}

void destroy_robot(Robot* robot) {
    free(robot);
}

char* to_string(Robot* robot) {
    static char position[50];
    snprintf(position, sizeof(position), "Position: (%d, %d), Direction: %c", 
             robot->x, robot->y, robot->direction);
    return position;
}

// Function to change robot's direction
void turn_robot(Robot* robot, char turn_direction) {
    if (turn_direction == TURN_LEFT) {
        switch (robot->direction) {
            case 'N': robot->direction = 'W'; break;
            case 'E': robot->direction = 'N'; break;
            case 'S': robot->direction = 'E'; break;
            case 'W': robot->direction = 'S'; break;
        }
    } else if (turn_direction == TURN_RIGHT) {
        switch (robot->direction) {
            case 'N': robot->direction = 'E'; break;
            case 'E': robot->direction = 'S'; break;
            case 'S': robot->direction = 'W'; break;
            case 'W': robot->direction = 'N'; break;
        }
    }
}

void move_robot(Robot* robot, char move_command) {
    switch (move_command) {
        case MOVE_FORWARD:
            switch (robot->direction) {
                case 'N': robot->y++; break;
                case 'E': robot->x++; break;
                case 'S': robot->y--; break;
                case 'W': robot->x--; break;
            }
            break;
        case MOVE_BACKWARD:
            switch (robot->direction) {
                case 'N': robot->y--; break;
                case 'E': robot->x--; break;
                case 'S': robot->y++; break;
                case 'W': robot->x++; break;
            }
            break;
        case STOP:
            printf("Robot has stopped.\n");
            break;
        default:
            printf("Invalid move command.\n");
            break;
    }
    printf("%s\n", to_string(robot));
}

int main() {
    Robot* my_robot = create_robot();
    char command;
    printf("Robot Movement Control\n");
    printf("Commands:\n");
    printf("F: Move Forward\n");
    printf("B: Move Backward\n");
    printf("L: Turn Left\n");
    printf("R: Turn Right\n");
    printf("S: Stop\n");
    printf("Q: Quit\n");

    while (1) {
        printf("Enter command: ");
        scanf(" %c", &command);

        if (command == 'Q') {
            break;
        } else if (command == MOVE_FORWARD || command == MOVE_BACKWARD || command == STOP) {
            move_robot(my_robot, command);
        } else if (command == TURN_LEFT || command == TURN_RIGHT) {
            turn_robot(my_robot, command);
            printf("%s\n", to_string(my_robot));
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    destroy_robot(my_robot);
    return 0;
}