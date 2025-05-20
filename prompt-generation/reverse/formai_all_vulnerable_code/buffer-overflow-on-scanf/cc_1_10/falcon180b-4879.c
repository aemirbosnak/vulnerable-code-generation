//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <termios.h>

#define PI 3.14159265358979323846

// Drone control functions
void takeoff() {
    printf("Taking off...\n");
}

void land() {
    printf("Landing...\n");
}

void forward() {
    printf("Moving forward...\n");
}

void backward() {
    printf("Moving backward...\n");
}

void left() {
    printf("Turning left...\n");
}

void right() {
    printf("Turning right...\n");
}

void up() {
    printf("Moving up...\n");
}

void down() {
    printf("Moving down...\n");
}

int main() {
    // Initialize drone
    takeoff();

    // Main control loop
    while (1) {
        // Get user input
        char input[100];
        printf("Enter command: ");
        scanf("%s", input);

        // Convert input to uppercase
        for (int i = 0; i < strlen(input); i++) {
            input[i] = toupper(input[i]);
        }

        // Process command
        if (strcmp(input, "TAKEOFF") == 0) {
            takeoff();
        } else if (strcmp(input, "LAND") == 0) {
            land();
        } else if (strcmp(input, "FORWARD") == 0) {
            forward();
        } else if (strcmp(input, "BACKWARD") == 0) {
            backward();
        } else if (strcmp(input, "LEFT") == 0) {
            left();
        } else if (strcmp(input, "RIGHT") == 0) {
            right();
        } else if (strcmp(input, "UP") == 0) {
            up();
        } else if (strcmp(input, "DOWN") == 0) {
            down();
        } else {
            printf("Invalid command.\n");
        }

        // Delay for smooth movement
        usleep(100000);
    }

    return 0;
}