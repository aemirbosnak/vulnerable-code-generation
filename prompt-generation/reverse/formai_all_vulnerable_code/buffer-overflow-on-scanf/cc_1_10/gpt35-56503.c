//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND_SIZE 50

struct drone_controller {
    int pitch;
    int roll;
    int yaw;
    int elevation;
};

void print_drone_stats(struct drone_controller c) {
    printf("Drone Stats:\n");
    printf("Pitch: %d\n", c.pitch);
    printf("Roll: %d\n", c.roll);
    printf("Yaw: %d\n", c.yaw);
    printf("Elevation: %d\n", c.elevation);
}

int main() {
    struct drone_controller controller = {0, 0, 0, 0};
    char command[MAX_COMMAND_SIZE];
    int value;
    
    while (1) {
        printf("Enter a command (pitch, roll, yaw, elevation, or exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        }
        
        printf("Enter a value: ");
        scanf("%d", &value);
        
        if (strcmp(command, "pitch") == 0) {
            controller.pitch = value;
        } else if (strcmp(command, "roll") == 0) {
            controller.roll = value;
        } else if (strcmp(command, "yaw") == 0) {
            controller.yaw = value;
        } else if (strcmp(command, "elevation") == 0) {
            controller.elevation = value;
        } else {
            printf("Invalid command.\n");
            continue;
        }
        
        print_drone_stats(controller);
    }
    
    return 0;
}