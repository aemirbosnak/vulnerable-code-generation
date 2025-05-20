//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>

#define MAX_DRONES 100   // Maximum number of drones that can be controlled by the remote control.
#define MAX_COMMANDS 20  // Maximum number of commands the remote control can store.

struct drone {           // Structure to define a drone
    int id;
    int x;
    int y;
    int z;
};

struct command {         // Structure to define a command for the drone to execute
    int type;
    int value;
};

void init_drones(struct drone *drones, int num_drones);                              // Function to initialize the drones
void execute_command(struct drone *drones, int num_drones, int drone_id, int command); // Function to execute a command on the drone

int main() {
    struct drone drones[MAX_DRONES];                                   // Array of drones
    struct command commands[MAX_DRONES][MAX_COMMANDS];                  // 2D array of commands for each drone
    int num_drones, num_commands, i, j;
    int drone_id, cmd_type, cmd_value, cmd_index;

    printf("Enter the number of drones: ");
    scanf("%d", &num_drones);
    init_drones(drones, num_drones);

    printf("Enter the number of commands: ");
    scanf("%d", &num_commands);

    for(i=0;i<num_drones;i++) {                // For each drone
        printf("\nEnter commands for drone %d:\n", drones[i].id);
        for(j=0;j<num_commands;j++) {           // Store commands for the drone
            printf("\nEnter command type (1 for move, 2 for hover): ");
            scanf("%d", &cmd_type);
            commands[i][j].type = cmd_type;

            if(cmd_type == 1) {                // Move command
                printf("\nEnter move value: ");
                scanf("%d", &cmd_value);
                commands[i][j].value = cmd_value;
            }
        }
    }

    while(1) {                                 // Infinite loop until program termination
        printf("\nEnter drone id and command index: (-1 to exit): ");
        scanf("%d %d", &drone_id, &cmd_index);

        if(drone_id == -1 || cmd_index == -1)   // Terminate program
            break;

        if(drone_id >= num_drones || cmd_index >= num_commands) {  // Check for valid input
            printf("\nInvalid input. Try again.\n");
            continue;
        }

        cmd_type = commands[drone_id][cmd_index].type;
        cmd_value = commands[drone_id][cmd_index].value;

        if(cmd_type == 1)                        // Execute move command
            execute_command(drones, num_drones, drone_id, cmd_value);
        else
            printf("\nDrone %d Hovering...\n", drones[drone_id].id);
    }

    return 0;
}

void init_drones(struct drone *drones, int num_drones) {   // Initialize the drones
    int i;
    for(i=0;i<num_drones;i++) {
        drones[i].id = i;
        drones[i].x = 0;
        drones[i].y = 0;
        drones[i].z = 0;
    }
}

void execute_command(struct drone *drones, int num_drones, int drone_id, int command) {
    drones[drone_id].z += command;             // Move the drone in the z-axis by the command value
    printf("\nDrone %d Moved Up by %d Units. \nNew Position: x=%d, y=%d, z=%d\n", drones[drone_id].id, command, drones[drone_id].x, drones[drone_id].y, drones[drone_id].z);
}