//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>

#define COMMAND_BUFFER_SIZE 100

// Drone state variables
typedef struct {
    int altitude;
    int speed;
    int direction; // 0=North, 1=East, 2=South, 3=West
} DroneState;

DroneState drone;

// Function to initialize drone state
void initializeDrone() {
    drone.altitude = 0;
    drone.speed = 0;
    drone.direction = 0;
}

// Function to change drone altitude
void changeAltitude(int change) {
    drone.altitude += change;
    printf("Drone altitude: %d meters\n", drone.altitude);
}

// Function to set drone speed
void setSpeed(int speed) {
    drone.speed = speed;
    printf("Drone speed: %d m/s\n", drone.speed);
}

// Function to change drone direction
void changeDirection(int dir) {
    drone.direction = dir % 4;  // ensure direction is within range
    const char *directions[] = { "North", "East", "South", "West" };
    printf("Drone direction: %s\n", directions[drone.direction]);
}

// Function to display current drone status
void displayDroneStatus() {
    printf("Current Drone Status:\n");
    printf("  Altitude: %d meters\n", drone.altitude);
    printf("  Speed: %d m/s\n", drone.speed);
    printf("  Direction: %d\n", drone.direction);
}

// Function to read a character from input without waiting for Enter
char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// Function to execute drone commands
void executeCommand(char command) {
    switch (command) {
        case 'w': // Increase altitude
            changeAltitude(10);
            break;
        case 's': // Decrease altitude
            changeAltitude(-10);
            break;
        case 'a': // Increase speed
            setSpeed(drone.speed + 5);
            break;
        case 'd': // Decrease speed
            setSpeed(drone.speed - 5);
            break;
        case 'j': // Turn left
            changeDirection(drone.direction - 1);
            break;
        case 'l': // Turn right
            changeDirection(drone.direction + 1);
            break;
        case 'p': // Print status
            displayDroneStatus();
            break;
        case 'q': // Quit program
            printf("Exiting drone control...\n");
            exit(0);
            break;
        default:
            printf("Invalid command! Use: w/s/a/d for altitude/speed, j/l for direction, p for status, q to exit.\n");
            break;
    }
}

// Main function to run the drone control loop
int main() {
    initializeDrone();
    printf("Drone Remote Control Initialized!\n");
    printf("Use commands:\n");
    printf("  w: Increase altitude\n");
    printf("  s: Decrease altitude\n");
    printf("  a: Increase speed\n");
    printf("  d: Decrease speed\n");
    printf("  j: Turn left\n");
    printf("  l: Turn right\n");
    printf("  p: Print status\n");
    printf("  q: Quit program\n");

    while (1) {
        char command = getch(); // Get command without pressing Enter
        executeCommand(command);
    }

    return 0;
}