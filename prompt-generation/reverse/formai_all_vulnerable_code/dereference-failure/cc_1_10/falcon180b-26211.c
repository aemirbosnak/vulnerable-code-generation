//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 100

// Function to remove leading and trailing whitespace from a string
void trim(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    while (isspace(str[start])) {
        start++;
    }
    while (isspace(str[end])) {
        end--;
    }
    if (start > end) {
        str[0] = '\0';
    } else {
        memmove(str, str + start, end - start + 1);
        str[end - start + 1] = '\0';
    }
}

// Function to parse a command and execute the appropriate function
void execute_command(char *command) {
    if (strcmp(command, "takeoff") == 0) {
        printf("Drone taking off...\n");
    } else if (strcmp(command, "land") == 0) {
        printf("Drone landing...\n");
    } else if (strcmp(command, "move_forward") == 0) {
        printf("Drone moving forward...\n");
    } else if (strcmp(command, "move_backward") == 0) {
        printf("Drone moving backward...\n");
    } else if (strcmp(command, "move_left") == 0) {
        printf("Drone moving left...\n");
    } else if (strcmp(command, "move_right") == 0) {
        printf("Drone moving right...\n");
    } else if (strcmp(command, "rotate_left") == 0) {
        printf("Drone rotating left...\n");
    } else if (strcmp(command, "rotate_right") == 0) {
        printf("Drone rotating right...\n");
    } else {
        printf("Invalid command: %s\n", command);
    }
}

// Function to read a line of input from the user and execute the command
void read_command() {
    char input[MAX_COMMAND_LENGTH];
    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    trim(input);
    execute_command(input);
}

int main() {
    while (1) {
        read_command();
    }
    return 0;
}