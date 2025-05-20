//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    char command[100];
    char response[100];
    int drone_id = 0;

    printf("Welcome to the Drone Remote Control! Please enter your drone's ID: ");
    scanf("%d", &drone_id);

    while (1) {
        printf("Enter a command: ");
        fgets(command, 100, stdin);
        int command_length = strlen(command);

        if (command[command_length - 1] == '\n') {
            command[command_length - 1] = '\0';
        }

        if (strcmp(command, "takeoff") == 0) {
            if (drone_id == 0) {
                printf("Drone 0: Taking off!\n");
            } else if (drone_id == 1) {
                printf("Drone 1: Taking off!\n");
            } else {
                printf("Invalid drone ID.\n");
            }
        } else if (strcmp(command, "land") == 0) {
            if (drone_id == 0) {
                printf("Drone 0: Landing!\n");
            } else if (drone_id == 1) {
                printf("Drone 1: Landing!\n");
            } else {
                printf("Invalid drone ID.\n");
            }
        } else if (strcmp(command, "hover") == 0) {
            if (drone_id == 0) {
                printf("Drone 0: Hovering!\n");
            } else if (drone_id == 1) {
                printf("Drone 1: Hovering!\n");
            } else {
                printf("Invalid drone ID.\n");
            }
        } else if (strcmp(command, "up") == 0) {
            if (drone_id == 0) {
                printf("Drone 0: Ascending!\n");
            } else if (drone_id == 1) {
                printf("Drone 1: Ascending!\n");
            } else {
                printf("Invalid drone ID.\n");
            }
        } else if (strcmp(command, "down") == 0) {
            if (drone_id == 0) {
                printf("Drone 0: Descending!\n");
            } else if (drone_id == 1) {
                printf("Drone 1: Descending!\n");
            } else {
                printf("Invalid drone ID.\n");
            }
        } else if (strcmp(command, "left") == 0) {
            if (drone_id == 0) {
                printf("Drone 0: Rotating left!\n");
            } else if (drone_id == 1) {
                printf("Drone 1: Rotating left!\n");
            } else {
                printf("Invalid drone ID.\n");
            }
        } else if (strcmp(command, "right") == 0) {
            if (drone_id == 0) {
                printf("Drone 0: Rotating right!\n");
            } else if (drone_id == 1) {
                printf("Drone 1: Rotating right!\n");
            } else {
                printf("Invalid drone ID.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}