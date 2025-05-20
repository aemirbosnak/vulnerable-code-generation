//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: sophisticated
#include <stdio.h>

// Define the structure of the remote control vehicle
struct RCVehicle {
    int x_pos; // X-coordinate of the vehicle
    int y_pos; // Y-coordinate of the vehicle
    float battery_level; // Battery level of the vehicle
};

// Define the possible actions of the vehicle
enum Action {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    STOP
};

// Define a function to execute an action on the vehicle
void execute_action(struct RCVehicle* vehicle, enum Action action) {
    switch(action) {
        case MOVE_UP:
            vehicle->y_pos++;
            break;
        case MOVE_DOWN:
            vehicle->y_pos--;
            break;
        case MOVE_LEFT:
            vehicle->x_pos--;
            break;
        case MOVE_RIGHT:
            vehicle->x_pos++;
            break;
        case STOP:
            printf("Vehicle has stopped.\n");
            break;
        default:
            printf("Invalid action.\n");
            break;
    }
}

// Define the main function
int main() {
    // Initialize the vehicle
    struct RCVehicle vehicle = {0, 0, 100};

    // Take input from the user to execute actions on the vehicle
    char input;
    printf("Enter actions to execute on the vehicle (u/d/l/r/s): ");
    while(scanf("%c", &input) != EOF) {
        switch(input) {
            case 'u':
                execute_action(&vehicle, MOVE_UP);
                printf("Vehicle moved up.\n");
                break;
            case 'd':
                execute_action(&vehicle, MOVE_DOWN);
                printf("Vehicle moved down.\n");
                break;
            case 'l':
                execute_action(&vehicle, MOVE_LEFT);
                printf("Vehicle moved left.\n");
                break;
            case 'r':
                execute_action(&vehicle, MOVE_RIGHT);
                printf("Vehicle moved right.\n");
                break;
            case 's':
                execute_action(&vehicle, STOP);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        printf("Vehicle location: (%d, %d)\n", vehicle.x_pos, vehicle.y_pos);
        printf("Battery level: %.1f\n", vehicle.battery_level);
    }

    return 0;
}