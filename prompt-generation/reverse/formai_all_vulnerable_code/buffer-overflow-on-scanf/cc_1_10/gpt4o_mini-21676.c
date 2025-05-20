//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int altitude; // height in meters
    int position_x; // x-axis position
    int position_y; // y-axis position
} Drone;

void takeoff(Drone *drone) {
    if (drone->altitude == 0) {
        drone->altitude = 10; // Set to 10 meters on takeoff
        printf("Drone has taken off. Altitude: %d meters\n", drone->altitude);
    } else {
        printf("Drone is already in the air at %d meters.\n", drone->altitude);
    }
}

void land(Drone *drone) {
    if (drone->altitude > 0) {
        drone->altitude = 0;
        printf("Drone has landed.\n");
    } else {
        printf("Drone is already on the ground.\n");
    }
}

void move_forward(Drone *drone) {
    if (drone->altitude > 0) {
        drone->position_y += 1; // Move forward in the y-axis
        printf("Drone moved forward. Current position: (%d, %d)\n", drone->position_x, drone->position_y);
    } else {
        printf("Drone must be in the air to move.\n");
    }
}

void move_backward(Drone *drone) {
    if (drone->altitude > 0) {
        drone->position_y -= 1; // Move backward in the y-axis
        printf("Drone moved backward. Current position: (%d, %d)\n", drone->position_x, drone->position_y);
    } else {
        printf("Drone must be in the air to move.\n");
    }
}

void turn_left(Drone *drone) {
    if (drone->altitude > 0) {
        drone->position_x -= 1; // Turn left on the x-axis
        printf("Drone turned left. Current position: (%d, %d)\n", drone->position_x, drone->position_y);
    } else {
        printf("Drone must be in the air to turn.\n");
    }
}

void turn_right(Drone *drone) {
    if (drone->altitude > 0) {
        drone->position_x += 1; // Turn right on the x-axis
        printf("Drone turned right. Current position: (%d, %d)\n", drone->position_x, drone->position_y);
    } else {
        printf("Drone must be in the air to turn.\n");
    }
}

void display_status(const Drone *drone) {
    printf("Drone Status:\n");
    printf("Altitude: %d meters\n", drone->altitude);
    printf("Position: (%d, %d)\n", drone->position_x, drone->position_y);
}

int main() {
    Drone drone = {0, 0, 0}; // Initialize drone
    int command;

    while (1) {
        printf("\nDrone Control Menu:\n");
        printf("1. Take Off\n");
        printf("2. Land\n");
        printf("3. Move Forward\n");
        printf("4. Move Backward\n");
        printf("5. Turn Left\n");
        printf("6. Turn Right\n");
        printf("7. Display Status\n");
        printf("8. Exit\n");
        printf("Enter your command: ");
        scanf("%d", &command);

        switch (command) {
            case 1:
                takeoff(&drone);
                break;
            case 2:
                land(&drone);
                break;
            case 3:
                move_forward(&drone);
                break;
            case 4:
                move_backward(&drone);
                break;
            case 5:
                turn_left(&drone);
                break;
            case 6:
                turn_right(&drone);
                break;
            case 7:
                display_status(&drone);
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid command. Please try again.\n");
        }
    }
    
    return 0;
}