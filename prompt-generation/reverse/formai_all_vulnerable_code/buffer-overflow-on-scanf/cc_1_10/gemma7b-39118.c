//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void drone_control(int state) {
    switch (state) {
        case 0:
            printf("Drone is in the home position.\n");
            break;
        case 1:
            printf("Drone is flying forward.\n");
            break;
        case 2:
            printf("Drone is flying right.\n");
            break;
        case 3:
            printf("Drone is flying left.\n");
            break;
        case 4:
            printf("Drone is flying backward.\n");
            break;
        case 5:
            printf("Drone is landing.\n");
            break;
    }

    printf("Enter the next command (0-5): ");
    int next_command;
    scanf("%d", &next_command);

    switch (next_command) {
        case 0:
            drone_control(0);
            break;
        case 1:
            drone_control(1);
            break;
        case 2:
            drone_control(2);
            break;
        case 3:
            drone_control(3);
            break;
        case 4:
            drone_control(4);
            break;
        case 5:
            drone_control(5);
            break;
    }
}

int main() {
    drone_control(0);
    return 0;
}