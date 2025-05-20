//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int speed;
    int direction; // 0: forward, 1: backward, 2: left, 3: right
} RC_Vehicle;

void initialize_vehicle(RC_Vehicle* vehicle) {
    vehicle->speed = 0;
    vehicle->direction = 0;
    printf("RC Vehicle Initialized! Speed: %d, Direction: %d\n", vehicle->speed, vehicle->direction);
}

void set_speed(RC_Vehicle* vehicle, int speed) {
    if (speed < 0) {
        printf("Speed cannot be negative. Defaulting to 0.\n");
        vehicle->speed = 0;
    } else {
        vehicle->speed = speed;
    }
    printf("Speed set to: %d\n", vehicle->speed);
}

void set_direction(RC_Vehicle* vehicle, int direction) {
    if (direction < 0 || direction > 3) {
        printf("Invalid direction. Acceptable values are:\n0 - Forward\n1 - Backward\n2 - Left\n3 - Right\n");
        return;
    }
    vehicle->direction = direction;
    printf("Direction set to: %d\n", vehicle->direction);
}

void move_vehicle(RC_Vehicle* vehicle) {
    printf("Moving vehicle...\n");
    switch (vehicle->direction) {
        case 0:
            printf("Moving forward at speed %d\n", vehicle->speed);
            break;
        case 1:
            printf("Moving backward at speed %d\n", vehicle->speed);
            break;
        case 2:
            printf("Turning left at speed %d\n", vehicle->speed);
            break;
        case 3:
            printf("Turning right at speed %d\n", vehicle->speed);
            break;
        default:
            printf("Vehicle remains stationary.\n");
    }
    sleep(1);
}

void stop_vehicle(RC_Vehicle* vehicle) {
    vehicle->speed = 0;
    printf("Vehicle stopped. Speed is now %d.\n", vehicle->speed);
}

void display_status(RC_Vehicle* vehicle) {
    const char* directions[] = {"Forward", "Backward", "Left", "Right"};
    printf("\n---- Vehicle Status ----\n");
    printf("Current Speed: %d\n", vehicle->speed);
    printf("Current Direction: %s\n", directions[vehicle->direction]);
}

int main() {
    RC_Vehicle myVehicle;

    initialize_vehicle(&myVehicle);
    
    int choice;
    
    while (1) {
        printf("\nRC Vehicle Control Menu:\n");
        printf("1. Set Speed\n");
        printf("2. Set Direction\n");
        printf("3. Move Vehicle\n");
        printf("4. Stop Vehicle\n");
        printf("5. Display Status\n");
        printf("6. Exit\n");
        printf("Please select an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int speed;
                printf("Enter speed (0-100): ");
                scanf("%d", &speed);
                set_speed(&myVehicle, speed);
                break;
            }
            case 2: {
                int direction;
                printf("Enter direction (0-3): ");
                scanf("%d", &direction);
                set_direction(&myVehicle, direction);
                break;
            }
            case 3:
                move_vehicle(&myVehicle);
                break;
            case 4:
                stop_vehicle(&myVehicle);
                break;
            case 5:
                display_status(&myVehicle);
                break;
            case 6:
                printf("Exiting the program. Your vehicle is safe!\n");
                exit(0);
            default:
                printf("Please choose a valid option.\n");
        }
    }

    return 0;
}