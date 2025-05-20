//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the available commands */
#define TAKE_OFF_COMMAND "Take off!"
#define LAND_COMMAND "Land!"
#define HOVER_COMMAND "Hover!"
#define FORWARD_COMMAND "Forward!"
#define BACKWARD_COMMAND "Backward!"
#define LEFT_COMMAND "Left!"
#define RIGHT_COMMAND "Right!"
#define UP_COMMAND "Up!"
#define DOWN_COMMAND "Down!"

/* Define the maximum length of a command */
#define MAX_COMMAND_LENGTH 20

/* Define a function to process user inputs */
void process_command(char* command) {
    /* Check if the command is valid */
    if (strcmp(command, TAKE_OFF_COMMAND) == 0) {
        printf("Drone is taking off!\n");
    } else if (strcmp(command, LAND_COMMAND) == 0) {
        printf("Drone is landing!\n");
    } else if (strcmp(command, HOVER_COMMAND) == 0) {
        printf("Drone is hovering!\n");
    } else if (strcmp(command, FORWARD_COMMAND) == 0) {
        printf("Drone is moving forward!\n");
    } else if (strcmp(command, BACKWARD_COMMAND) == 0) {
        printf("Drone is moving backward!\n");
    } else if (strcmp(command, LEFT_COMMAND) == 0) {
        printf("Drone is moving left!\n");
    } else if (strcmp(command, RIGHT_COMMAND) == 0) {
        printf("Drone is moving right!\n");
    } else if (strcmp(command, UP_COMMAND) == 0) {
        printf("Drone is moving up!\n");
    } else if (strcmp(command, DOWN_COMMAND) == 0) {
        printf("Drone is moving down!\n");
    } else {
        printf("Invalid command!\n");
    }
}

int main() {
    /* Define variables */
    char command[MAX_COMMAND_LENGTH];

    /* Loop until the user enters "exit" */
    while (1) {
        /* Prompt the user to enter a command */
        printf("Enter a command: ");
        scanf("%s", command);

        /* Process the user command */
        process_command(command);

        /* Check if the user wants to exit */
        if (strcmp(command, "exit") == 0) {
            break;
        }
    }

    /* Exit the program */
    return 0;
}