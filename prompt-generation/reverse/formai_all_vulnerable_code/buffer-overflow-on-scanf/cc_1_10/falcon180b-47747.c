//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

// forward and backward movement functions
void forward(double speed) {
    printf("Moving forward at %.2f m/s\n", speed);
}

void backward(double speed) {
    printf("Moving backward at %.2f m/s\n", speed);
}

// left and right movement functions
void left(double speed) {
    printf("Turning left at %.2f rad/s\n", speed);
}

void right(double speed) {
    printf("Turning right at %.2f rad/s\n", speed);
}

// stop movement function
void stop() {
    printf("Stopping movement\n");
}

// main control loop
int main() {
    double speed = 0.5;
    char command[20];

    // get initial movement command from user
    printf("Enter initial movement command (forward/backward/left/right): ");
    scanf("%s", command);

    // execute initial movement command
    if (strcmp(command, "forward") == 0) {
        forward(speed);
    } else if (strcmp(command, "backward") == 0) {
        backward(speed);
    } else if (strcmp(command, "left") == 0) {
        left(speed);
    } else if (strcmp(command, "right") == 0) {
        right(speed);
    } else {
        printf("Invalid initial movement command\n");
        return 1;
    }

    // get subsequent movement commands from user
    while (1) {
        printf("Enter subsequent movement command (forward/backward/left/right/stop): ");
        scanf("%s", command);

        // execute subsequent movement command
        if (strcmp(command, "forward") == 0) {
            forward(speed);
        } else if (strcmp(command, "backward") == 0) {
            backward(speed);
        } else if (strcmp(command, "left") == 0) {
            left(speed);
        } else if (strcmp(command, "right") == 0) {
            right(speed);
        } else if (strcmp(command, "stop") == 0) {
            stop();
        } else {
            printf("Invalid subsequent movement command\n");
            break;
        }
    }

    return 0;
}