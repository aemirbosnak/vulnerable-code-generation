//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Donald Knuth
#include <stdio.h>

// Define constants for commands
#define MOVE_UP 1
#define MOVE_DOWN 2
#define MOVE_LEFT 3
#define MOVE_RIGHT 4
#define TAKE_OFF 5
#define LAND 6
#define EMERGENCY_STOP 7

// Main function
int main() {

    // Initialize drone position and flight status
    int droneX = 0;
    int droneY = 0;
    int droneZ = 0;
    int droneFlying = 0; // 0-Not Flying, 1-Flying

    // Print initial message
    printf("** DRONE REMOTE CONTROL **\n");
    printf("Use commands TAKE_OFF, LAND, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, EMERGENCY_STOP to control the drone.\n");

    // Loop to accept user commands
    while(1) {

        // Accept user command
        printf("\nEnter command: ");
        char command[20];
        scanf("%s", command);

        // Handle command
        if(strcmp(command, "MOVE_UP") == 0) {
            if(droneFlying) { // Move drone up only if it is flying
                droneZ++;
                printf("Drone moved up to height %d\n", droneZ);
            }
            else {
                printf("ERROR: Drone not flying\n");
            }
        }
        else if(strcmp(command, "MOVE_DOWN") == 0) {
            if(droneFlying && droneZ > 0) { // Move drone down only if it is flying and not on ground
                droneZ--;
                printf("Drone moved down to height %d\n", droneZ);
            }
            else {
                printf("ERROR: Drone not flying or on ground\n");
            }
        }
        else if(strcmp(command, "MOVE_LEFT") == 0) {
            if(droneFlying) { // Move drone left only if it is flying
                droneX--;
                printf("Drone moved left to position (%d,%d,%d)\n", droneX, droneY, droneZ);
            }
            else {
                printf("ERROR: Drone not flying\n");
            }
        }
        else if(strcmp(command, "MOVE_RIGHT") == 0) {
            if(droneFlying) { // Move drone right only if it is flying
                droneX++;
                printf("Drone moved right to position (%d,%d,%d)\n", droneX, droneY, droneZ);
            }
            else {
                printf("ERROR: Drone not flying\n");
            }
        }
        else if(strcmp(command, "TAKE_OFF") == 0) {
            if(!droneFlying) { // Take off only if the drone is not flying
                droneFlying = 1; // Set drone flying status
                droneZ = 10; // Increase drone height
                printf("Drone took off to height %d\n", droneZ);
            }
            else {
                printf("ERROR: Drone already flying\n");
            }
        }
        else if(strcmp(command, "LAND") == 0) {
            if(droneFlying) { // Land only if the drone is flying
                droneFlying = 0; // Set drone not flying status
                droneZ = 0; // Decrease drone height
                droneX = 0; // Reset drone position
                droneY = 0;
                printf("Drone landed at position (%d,%d,%d)\n", droneX, droneY, droneZ);
            }
            else {
                printf("ERROR: Drone already on ground\n");
            }
        }
        else if(strcmp(command, "EMERGENCY_STOP") == 0) {
            printf("EMERGENCY STOP: Drone stopped immediately\n");
            droneFlying = 0; // Set drone not flying status
            droneZ = 0; // Decrease drone height
            droneX = 0; // Reset drone position
            droneY = 0;
        }
        else {
            printf("ERROR: Invalid command\n"); // If user enters invalid command
        }
    }

    return 0;
}