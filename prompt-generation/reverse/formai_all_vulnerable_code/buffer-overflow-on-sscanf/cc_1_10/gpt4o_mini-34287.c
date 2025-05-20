//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_MOTORS 4
#define COMMAND_LENGTH 20
#define BAUD_RATE B9600

// Structure for drone control
typedef struct {
    int motors[MAX_MOTORS];
} Drone;

// Function to initialize terminal settings
void initTerminal() {
    struct termios newt;

    tcgetattr(STDIN_FILENO, &newt);
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

// Function to restore terminal settings
void restoreTerminal() {
    struct termios newt;
    tcgetattr(STDIN_FILENO, &newt);
    newt.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

// Function to handle termination of the program
void signalHandler(int signal) {
    restoreTerminal();
    printf("\nExiting Drone Control...\n");
    exit(0);
}

// Function to initialize the drone
void initDrone(Drone* drone) {
    for (int i = 0; i < MAX_MOTORS; i++) {
        drone->motors[i] = 0; // Motors are initially off
    }
}

// Function to set motor speed
void setMotorSpeed(Drone* drone, int motorIndex, int speed) {
    if (motorIndex >= 0 && motorIndex < MAX_MOTORS) {
        drone->motors[motorIndex] = speed;
        printf("Motor %d set to speed %d\n", motorIndex, speed);
    } else {
        printf("Invalid motor index: %d\n", motorIndex);
    }
}

// Function to print motor statuses
void printMotorStatuses(Drone* drone) {
    printf("Current Motor Speeds:\n");
    for (int i = 0; i < MAX_MOTORS; i++) {
        printf("Motor %d: %d\n", i, drone->motors[i]);
    }
}

// Function to execute a command on the drone
void executeCommand(Drone* drone, const char* command) {
    if (strcmp(command, "takeoff") == 0) {
        for (int i = 0; i < MAX_MOTORS; i++) {
            setMotorSpeed(drone, i, 50); // Set all motors to an initial takeoff speed
        }
    } else if (strcmp(command, "land") == 0) {
        for (int i = 0; i < MAX_MOTORS; i++) {
            setMotorSpeed(drone, i, 0); // Land by stopping all motors
        }
    } else if (strncmp(command, "setmotor", 8) == 0) {
        int motorIndex, speed;
        sscanf(command + 9, "%d %d", &motorIndex, &speed);
        setMotorSpeed(drone, motorIndex, speed);
    } else if (strcmp(command, "status") == 0) {
        printMotorStatuses(drone);
    } else {
        printf("Unknown command: %s\n", command);
    }
}

int main() {
    Drone drone;
    char command[COMMAND_LENGTH];

    // Register signal handler for clean exit
    signal(SIGINT, signalHandler);
    
    // Initialize terminal
    initTerminal();

    // Initialize drone
    initDrone(&drone);

    printf("Welcome to the Drone Remote Control!\n");
    printf("Available commands: takeoff, land, setmotor [index] [speed], status\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character
        executeCommand(&drone, command);
    }

    return 0;
}