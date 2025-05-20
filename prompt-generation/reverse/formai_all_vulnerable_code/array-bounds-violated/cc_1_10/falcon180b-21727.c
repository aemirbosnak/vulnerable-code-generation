//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

// Function prototypes
void process_command(char* command);
void send_command(char* command);

int main() {
    char command[MAX_COMMAND_LENGTH];

    while(1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        int len = strlen(command);
        if(command[len-1] == '\n') {
            command[len-1] = '\0';
        }

        process_command(command);
    }

    return 0;
}

void process_command(char* command) {
    if(strcmp(command, "takeoff") == 0) {
        send_command("takeoff");
    } else if(strcmp(command, "land") == 0) {
        send_command("land");
    } else if(strcmp(command, "move_forward") == 0) {
        send_command("move_forward");
    } else if(strcmp(command, "move_backward") == 0) {
        send_command("move_backward");
    } else if(strcmp(command, "move_left") == 0) {
        send_command("move_left");
    } else if(strcmp(command, "move_right") == 0) {
        send_command("move_right");
    } else if(strcmp(command, "rotate_left") == 0) {
        send_command("rotate_left");
    } else if(strcmp(command, "rotate_right") == 0) {
        send_command("rotate_right");
    } else {
        printf("Invalid command.\n");
    }
}

void send_command(char* command) {
    printf("Sending command: %s\n", command);
}