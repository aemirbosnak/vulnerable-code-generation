#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void controlDrone(char command[10]) {
    if (strcmp(command, "takeoff") == 0) {
        printf("Drone taking off.\n");
    } else if (strcmp(command, "land") == 0) {
        printf("Drone landing.\n");
    } else if (strcmp(command, "forward") == 0) {
        printf("Drone moving forward.\n");
    } else if (strcmp(command, "backward") == 0) {
        printf("Drone moving backward.\n");
    } else if (strcmp(command, "left") == 0) {
        printf("Drone turning left.\n");
    } else if (strcmp(command, "right") == 0) {
        printf("Drone turning right.\n");
    } else if (strcmp(command, "up") == 0) {
        printf("Drone ascending.\n");
    } else if (strcmp(command, "down") == 0) {
        printf("Drone descending.\n");
    } else if (strcmp(command, "hover") == 0) {
        printf("Drone hovering.\n");
    } else if (strcmp(command, "shoot") == 0) {
        printf("Drone shooting.\n");
    } else {
        char buffer[100];
        strcpy(buffer, command);
        printf("Unknown command: %s\n", buffer);
    }
}

int main() {
    char command[10];
    printf("Enter command: ");
    scanf("%s", command);
    controlDrone(command);
    return 0;
}
