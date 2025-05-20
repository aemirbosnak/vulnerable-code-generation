//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the command entered by user is valid or not
int isValidCommand(char command[]) {
    char validCommands[7][10] = {"takeoff", "land", "up", "down", "left", "right", "end"};

    // Loop through all the valid commands to check if the entered command matches with any of them
    for(int i = 0; i < 7; i++) {
        if(strcmp(validCommands[i], command) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("Entering post-apocalyptic mode...\n\n");

    // Initializing drone variables
    int altitude = 0;
    int x = 0, y = 0;
    int crashed = 0;

    // Loop till the drone is not crashed
    while(!crashed) {
        char command[10];

        printf("Enter command: ");
        scanf("%s", command);

        // Check if the entered command is valid or not
        if(!isValidCommand(command)) {
            printf("Invalid command entered. Please enter a valid command.\n");
            continue;
        }

        // If takeoff command is entered, set the altitude to 10
        if(strcmp(command, "takeoff") == 0) {
            printf("Drone taking off...\n");
            altitude = 10;
        }
        // If land command is entered, set the altitude to 0 and exit the program
        else if(strcmp(command, "land") == 0) {
            printf("Drone landing...\n");
            altitude = 0;
            break;
        }
        // If up command is entered, increase the altitude by 1
        else if(strcmp(command, "up") == 0) {
            if(altitude + 1 <= 100) {
                printf("Drone going up...\n");
                altitude += 1;
            }
            else {
                printf("ERROR: Drone has reached maximum altitude.\n");
            }
        }
        // If down command is entered, decrease the altitude by 1
        else if(strcmp(command, "down") == 0) {
            if(altitude - 1 >= 0) {
                printf("Drone going down...\n");
                altitude -= 1;
            }
            else {
                printf("ERROR: Drone has reached minimum altitude.\n");
            }
        }
        // If left command is entered, decrease the x-coordinate by 1
        else if(strcmp(command, "left") == 0) {
            if(x - 1 >= -100) {
                printf("Drone going left...\n");
                x -= 1;
            }
            else {
                printf("ERROR: Drone has reached left boundary.\n");
            }
        }
        // If right command is entered, increase the x-coordinate by 1
        else if(strcmp(command, "right") == 0) {
            if(x + 1 <= 100) {
                printf("Drone going right...\n");
                x += 1;
            }
            else {
                printf("ERROR: Drone has reached right boundary.\n");
            }
        }

        // Check if the drone has crashed due to altitude
        if(altitude == 0) {
            printf("ALERT: Drone has crashed due to low altitude.\n");
            crashed = 1;
        }
    }

    printf("Exiting post-apocalyptic mode...\n");
    printf("Thank you for using the C Drone Remote Control Program!\n");

    return 0;
}