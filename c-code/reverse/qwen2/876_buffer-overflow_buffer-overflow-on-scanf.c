#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_COMMAND_LENGTH 10

int main() {
    char command[MAX_COMMAND_LENGTH];
    printf("Enter command: ");
    scanf("%s", command);
    if (strcmp(command, "takeoff") == 0) {
        printf("Drone taking off.\n");
    } else if (strcmp(command, "land") == 0) {
        printf("Drone landing.\n");
    } else if (strcmp(command, "moveup") == 0) {
        printf("Drone moving up.\n");
    } else if (strcmp(command, "movedown") == 0) {
        printf("Drone moving down.\n");
    } else if (strcmp(command, "turnleft") == 0) {
        printf("Drone turning left.\n");
    } else if (strcmp(command, "turnright") == 0) {
        printf("Drone turning right.\n");
    } else if (strcmp(command, "forward") == 0) {
        printf("Drone moving forward.\n");
    } else if (strcmp(command, "backward") == 0) {
        printf("Drone moving backward.\n");
    } else {
        printf("Unknown command.\n");
    }
    return 0;
}
