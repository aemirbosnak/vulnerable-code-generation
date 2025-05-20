//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 100

// Robot movement commands
typedef enum {
    MOVE_FORWARD,
    MOVE_BACKWARD,
    TURN_LEFT,
    TURN_RIGHT,
    STOP
} RobotCommand;

// Robot state
typedef struct {
    int x;
    int y;
    int angle;
} RobotState;

// Function to execute a robot command
void execute_command(RobotState *robot, RobotCommand command) {
    switch (command) {
        case MOVE_FORWARD:
            robot->x += 1;
            break;
        case MOVE_BACKWARD:
            robot->x -= 1;
            break;
        case TURN_LEFT:
            robot->angle -= 90;
            break;
        case TURN_RIGHT:
            robot->angle += 90;
            break;
        case STOP:
            break;
    }
}

// Function to parse a robot command string
RobotCommand parse_command(char *cmd) {
    if (strcmp(cmd, "move_forward") == 0) {
        return MOVE_FORWARD;
    } else if (strcmp(cmd, "move_backward") == 0) {
        return MOVE_BACKWARD;
    } else if (strcmp(cmd, "turn_left") == 0) {
        return TURN_LEFT;
    } else if (strcmp(cmd, "turn_right") == 0) {
        return TURN_RIGHT;
    } else if (strcmp(cmd, "stop") == 0) {
        return STOP;
    } else {
        return -1;
    }
}

// Main function
int main() {
    // Initialize the robot state
    RobotState robot = {0, 0, 0};

    // Get the robot movement commands from the user
    char cmd[MAX_CMD_LEN];
    while (1) {
        printf("Enter a robot movement command (move_forward, move_backward, turn_left, turn_right, stop): ");
        scanf("%s", cmd);

        // Parse the robot movement command
        RobotCommand command = parse_command(cmd);

        // If the command is valid, execute it
        if (command != -1) {
            execute_command(&robot, command);
        } else {
            printf("Invalid command! Please enter a valid command.\n");
        }

        // Print the robot state
        printf("Robot state: x = %d, y = %d, angle = %d\n", robot.x, robot.y, robot.angle);
    }

    return 0;
}