//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// struct for the remote control vehicle
typedef struct {
    int x_pos;
    int y_pos;
    int facing_direction;
    bool is_on;
} RCVehicle;

// function to move the vehicle forward
void move_forward(RCVehicle* vehicle) {
    switch (vehicle->facing_direction) {
        case 0: // North
            (vehicle->y_pos)++;
            break;
        case 1: // East
            (vehicle->x_pos)++;
            break;
        case 2: // South
            (vehicle->y_pos)--;
            break;
        case 3: // West
            (vehicle->x_pos)--;
            break;
    }
}

// function to turn the vehicle to the left
void turn_left(RCVehicle* vehicle) {
    (vehicle->facing_direction)--;
    if (vehicle->facing_direction < 0) {
        vehicle->facing_direction = 3;
    }
}

// function to turn the vehicle to the right
void turn_right(RCVehicle* vehicle) {
    (vehicle->facing_direction)++;
    if (vehicle->facing_direction > 3) {
        vehicle->facing_direction = 0;
    }
}

int main() {
    // initialize the vehicle at position (0,0), facing North and turned off
    RCVehicle vehicle = {0, 0, 0, false};
    
    // menu for user to interact with the vehicle
    int option;
    printf("Welcome to the Futuristic Remote Control Vehicle Simulation.\n");
    printf("What would you like to do?\n");
    do {
        printf("\n1. Turn on the vehicle.\n");
        printf("2. Turn off the vehicle.\n");
        printf("3. Move the vehicle forward.\n");
        printf("4. Turn the vehicle left.\n");
        printf("5. Turn the vehicle right.\n");
        printf("6. Check the vehicle's position and facing direction.\n");
        printf("7. Quit the simulation.\n");
        printf("\nEnter your option (1-7): ");
        
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                vehicle.is_on = true;
                printf("Vehicle is now turned on.\n");
                break;
            case 2:
                vehicle.is_on = false;
                printf("Vehicle is now turned off.\n");
                break;
            case 3:
                if (!vehicle.is_on) {
                    printf("Vehicle is currently turned off.\n");
                    break;
                }
                move_forward(&vehicle);
                printf("Vehicle moved forward.\n");
                break;
            case 4:
                if (!vehicle.is_on) {
                    printf("Vehicle is currently turned off.\n");
                    break;
                }
                turn_left(&vehicle);
                printf("Vehicle turned left.\n");
                break;
            case 5:
                if (!vehicle.is_on) {
                    printf("Vehicle is currently turned off.\n");
                    break;
                }
                turn_right(&vehicle);
                printf("Vehicle turned right.\n");
                break;
            case 6:
                printf("Current Vehicle Position: (%d,%d)\n", vehicle.x_pos, vehicle.y_pos);
                
                switch (vehicle.facing_direction) {
                    case 0:
                        printf("Vehicle is facing: North\n");
                        break;
                    case 1:
                        printf("Vehicle is facing: East\n");
                        break;
                    case 2:
                        printf("Vehicle is facing: South\n");
                        break;
                    case 3:
                        printf("Vehicle is facing: West\n");
                        break;
                }
                break;
            case 7:
                printf("Thank you for trying the Futuristic Remote Control Vehicle Simulation.\n");
                break;
            default:
                printf("Invalid option. Please enter a valid option (1-7).\n");
        }
    } while (option != 7);
    
    return 0;
}