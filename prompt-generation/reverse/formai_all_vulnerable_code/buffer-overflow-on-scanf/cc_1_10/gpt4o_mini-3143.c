//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define robot movement commands
typedef enum {
    MOVE_FORWARD,
    MOVE_BACKWARD,
    TURN_LEFT,
    TURN_RIGHT,
    STOP,
} Command;

// Function to simulate robot movements
void execute_command(Command cmd) {
    switch (cmd) {
        case MOVE_FORWARD:
            printf("Robot is moving forward.\n");
            break;
        case MOVE_BACKWARD:
            printf("Robot is moving backward.\n");
            break;
        case TURN_LEFT:
            printf("Robot is turning left.\n");
            break;
        case TURN_RIGHT:
            printf("Robot is turning right.\n");
            break;
        case STOP:
            printf("Robot has stopped.\n");
            break;
        default:
            printf("Invalid command!\n");
            break;
    }
}

// Function to safely obtain user input for commands
Command get_user_command() {
    int command;
    printf("Enter command (0: Forward, 1: Backward, 2: Left, 3: Right, 4: Stop, -1: Exit): ");
    scanf("%d", &command);
    
    if (command >= 0 && command <= 4) {
        return (Command)command;
    } else if (command == -1) {
        printf("Exiting the program. Goodbye!\n");
        exit(0);
    } else {
        printf("Invalid input! Try again.\n");
        return get_user_command(); // Recursion to ask for input again
    }
}

// Main function
int main() {
    printf("Robot Movement Control Program\n");
    printf("Control the robot using commands:\n");
    printf("0: Move Forward\n");
    printf("1: Move Backward\n");
    printf("2: Turn Left\n");
    printf("3: Turn Right\n");
    printf("4: Stop\n");
    printf("-1: Exit Program\n");

    while (1) {
        Command cmd = get_user_command();
        execute_command(cmd);
        usleep(1000000); // Simulate time taken by robot to execute command (1 second)
    }
    
    return 0; // Return success
}