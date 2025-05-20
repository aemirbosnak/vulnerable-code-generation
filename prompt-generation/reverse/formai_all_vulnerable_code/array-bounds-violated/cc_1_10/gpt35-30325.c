//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 10

void set_drone_position(int x, int y, int z) {
    printf("Drone position set to (%d,%d,%d)\n", x, y, z);
}

void send_drone_command(char* command) {
    printf("Sending command to drone: %s\n", command);
}

int main() {
    int drone_x = 0, drone_y = 0, drone_z = 0;
    char command[MAX_COMMAND_LENGTH];
    char view[MAX_COMMAND_LENGTH];
    int i;

    printf("Welcome to the CyberDrone Remote Control Program\n");
    printf("Enter 'help' for a list of commands\n");

    while(1) {
        printf(">> ");

        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strlen(command) - 1] = '\0'; // remove newline character

        if(strcmp(command, "help") == 0) {
            printf("> help\n");
            printf("  Commands:\n");
            printf("    set_pos x y z - Sets the drone position to (x,y,z)\n");
            printf("    view          - Displays the current drone position\n");
            printf("    move x y z    - Moves the drone to the position (x,y,z)\n");
            printf("    takeoff       - Makes the drone take off\n");
            printf("    land          - Makes the drone land\n");
            printf("    explode       - Makes the drone explode\n");
            printf("    exit          - Exits the program\n");
        }
        else if(strcmp(command, "set_pos") == 0) {
            printf("> set_pos\n");
            printf("  Enter x y z: ");
            scanf("%d %d %d", &drone_x, &drone_y, &drone_z);
            getchar(); // remove newline character
            set_drone_position(drone_x, drone_y, drone_z);
        }
        else if(strcmp(command, "view") == 0) {
            printf("> view\n");
            printf("  Drone position: (%d,%d,%d)\n", drone_x, drone_y, drone_z);
        }
        else if(strcmp(command, "move") == 0) {
            printf("> move\n");
            printf("  Enter x y z: ");
            scanf("%d %d %d", &drone_x, &drone_y, &drone_z);
            getchar(); // remove newline character
            send_drone_command("MOVE");
        }
        else if(strcmp(command, "takeoff") == 0) {
            printf("> takeoff\n");
            send_drone_command("TAKEOFF");
        }
        else if(strcmp(command, "land") == 0) {
            printf("> land\n");
            send_drone_command("LAND");
        }
        else if(strcmp(command, "explode") == 0) {
            printf("> explode\n");
            send_drone_command("EXPLODE");
        }
        else if(strcmp(command, "exit") == 0) {
            printf("> exit\n");
            printf("Thank you for using the CyberDrone Remote Control Program\n");
            exit(0);
        }
        else {
            printf("Invalid command\n");
        }
    }

    return 0;
}