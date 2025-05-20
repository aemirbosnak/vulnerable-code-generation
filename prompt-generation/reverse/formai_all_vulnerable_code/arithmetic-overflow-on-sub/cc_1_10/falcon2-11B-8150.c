//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <termios.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <signal.h>

struct timeval start, end;
double elapsed;

int main() {
    // Initialize the robot's starting position
    char robot_position = 'X';

    // Read the joystick values
    int joystick_x, joystick_y;
    while (1) {
        // Read the joystick values from the computer's input
        joystick_x = getchar();
        joystick_y = getchar();

        // Convert the joystick values to robot movement
        int robot_x = (joystick_x - 48) / 10;
        int robot_y = (joystick_y - 48) / 10;

        // Update the robot's position based on the movement
        if (robot_x == 1) {
            robot_position = 'R';
        } else if (robot_x == -1) {
            robot_position = 'L';
        } else if (robot_y == 1) {
            robot_position = 'U';
        } else if (robot_y == -1) {
            robot_position = 'D';
        } else {
            // Invalid movement, stay in place
            robot_position = 'X';
        }

        // Print the robot's current position
        printf("%c\n", robot_position);
    }

    return 0;
}