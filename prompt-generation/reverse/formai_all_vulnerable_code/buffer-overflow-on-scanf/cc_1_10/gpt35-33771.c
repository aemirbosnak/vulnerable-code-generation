//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define Drone struct
typedef struct drone {
    int batteryLevel;
    int altitude;
    int speed;
} Drone;

// Define Command Codes
#define COMMAND_UP 'W'
#define COMMAND_LEFT 'A'
#define COMMAND_DOWN 'S'
#define COMMAND_RIGHT 'D'
#define COMMAND_LAND 'L'
#define COMMAND_TAKEOFF 'T'
#define COMMAND_EXIT 'E'

// Function prototypes
void printMenu();
char readInput();
void executeCommand(Drone *d, char command);

int main() {
    // Initialize the drone
    Drone myDrone = {100, 0, 0};
    
    // Welcome message
    printf("Welcome to the Drone Remote Control Program!\n");
    
    // Print out current drone state
    printf("Current Battery: %d\n", myDrone.batteryLevel);
    printf("Current Altitude: %d\n", myDrone.altitude);
    printf("Current Speed: %d\n", myDrone.speed);
    
    // Print out menu options
    printMenu();
    
    // Begin main loop
    int shouldRun = 1;
    while (shouldRun) {
        char input = readInput();
        executeCommand(&myDrone, input);
        if (input == COMMAND_EXIT) {
            shouldRun = 0;
        }
    }
    
    return 0;
}

/*
 * Utility function to print out the menu options
 */
void printMenu() {
    printf("Command Menu:\n");
    printf("%c: Move Drone Up\n", COMMAND_UP);
    printf("%c: Move Drone Left\n", COMMAND_LEFT);
    printf("%c: Move Drone Down\n", COMMAND_DOWN);
    printf("%c: Move Drone Right\n", COMMAND_RIGHT);
    printf("%c: Land Drone\n", COMMAND_LAND);
    printf("%c: Take Off Drone\n", COMMAND_TAKEOFF);
    printf("%c: Exit Program\n", COMMAND_EXIT);
}

/*
 * Utility function to read in user inputs from the console
 */
char readInput() {
    char input;
    printf("Enter command: ");
    scanf("%c", &input);
    while (getchar() != '\n');
    return input;
}

/*
 * Function that executes a command on the drone
 *
 * @param d A pointer to the drone object that will be affected by the command
 * @param command A single character representing the command that the user entered
 */
void executeCommand(Drone *d, char command) {
    switch (command) {
        case COMMAND_UP:
            d->altitude += 10;
            d->speed += 5; 
            printf("Moving Drone Up\n");
            break;
        case COMMAND_LEFT:
            d->altitude += 2;
            d->speed -= 1; 
            printf("Moving Drone Left\n");
            break;
        case COMMAND_DOWN:
            d->altitude -= 10;
            d->speed -= 5; 
            printf("Moving Drone Down\n");
            break;
        case COMMAND_RIGHT:
            d->altitude += 2;
            d->speed += 1; 
            printf("Moving Drone Right\n");
            break;
        case COMMAND_LAND:
            d->altitude = 0;
            d->speed = 0;
            printf("Landing Drone\n");
            break;
        case COMMAND_TAKEOFF:
            d->altitude = 10;
            d->speed = 5; 
            printf("Taking Off Drone\n");
            break;
        case COMMAND_EXIT:
            printf("Exiting Drone Control Program...\n");
            break;
        default:
            printf("Invalid command entered.\n");
            break;
    }
    
    // Adjust the battery level depending on the command executed
    if (command != COMMAND_EXIT) {
        d->batteryLevel -= 1;
        if (d->batteryLevel <= 0) {
            printf("Drone battery has run out. Please recharge.\n");
            exit(0);
        }
        printf("Current Battery: %d\n", d->batteryLevel);
        printf("Current Altitude: %d\n", d->altitude);
        printf("Current Speed: %d\n", d->speed);
    }
}