//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: light-weight
#include <stdio.h>

// Drone command constants
#define TAKE_OFF 1
#define LAND 2
#define FORWARD 3
#define BACKWARD 4
#define LEFT 5
#define RIGHT 6
#define UP 7
#define DOWN 8
#define STOP 0

/**
 * Function to send command to drone
 * @param cmd int The command to send to the drone
 */
void send_command(int cmd) {
    printf("Sending command: %d\n", cmd);
}

/**
 * Main function to control the drone with a remote
 */
int main() {
    int cmd = -1;
    printf("Welcome to drone remote control\n");

    // Loop until the user quits the program
    while (cmd != 0) {
        printf("Enter a command (1=take off, 2=land, 3=forward, 4=backward, 5=left, 6=right, 7=up, 8=down, 0=stop):");
        scanf("%d", &cmd);

        switch (cmd) {
            case TAKE_OFF:
                send_command(TAKE_OFF);
                break;
            case LAND:
                send_command(LAND);
                break;
            case FORWARD:
                send_command(FORWARD);
                break;
            case BACKWARD:
                send_command(BACKWARD);
                break;
            case LEFT:
                send_command(LEFT);
                break;
            case RIGHT:
                send_command(RIGHT);
                break;
            case UP:
                send_command(UP);
                break;
            case DOWN:
                send_command(DOWN);
                break;
            case STOP:
                send_command(STOP);
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }

    return 0;
}