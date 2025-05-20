//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep function
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define TURN_LEFT -1
#define TURN_RIGHT 1
#define FORWARD 1
#define BACKWARD -1

typedef struct {
    int speed;
    int direction; // 0: Stationary, 1: Forward, -1: Backward
    int turn; // -1: Left, 1: Right
} RC_Vehicle;

void initializeVehicle(RC_Vehicle *vehicle) {
    vehicle->speed = 0;
    vehicle->direction = 0;
    vehicle->turn = 0;
}

void setSpeed(RC_Vehicle *vehicle, int speed) {
    if (speed < MIN_SPEED || speed > MAX_SPEED) {
        printf("Invalid speed! Must be between %d and %d.\n", MIN_SPEED, MAX_SPEED);
        return;
    }
    vehicle->speed = speed;
    printf("Speed set to %d.\n", vehicle->speed);
}

void displayStatus(RC_Vehicle *vehicle) {
    printf("Vehicle Status: \n");
    printf("Speed: %d\n", vehicle->speed);
    printf("Direction: %s\n", vehicle->direction == 1 ? "Forward" : (vehicle->direction == -1 ? "Backward" : "Stationary"));
    printf("Turn: %s\n", vehicle->turn == TURN_LEFT ? "Left" : (vehicle->turn == TURN_RIGHT ? "Right" : "None"));
    printf("=========================================\n");
}

void moveVehicle(RC_Vehicle *vehicle) {
    if (vehicle->speed == 0) {
        printf("Vehicle is stationary. Please set speed to move!\n");
        return;
    }
    
    vehicle->direction = (vehicle->turn == TURN_LEFT || vehicle->turn == TURN_RIGHT) ? vehicle->direction : vehicle->direction;
    if (vehicle->turn == TURN_LEFT) {
        printf("Turning left while moving %s at speed %d...\n", vehicle->direction == 1 ? "forward" : "backward", vehicle->speed);
    } else if (vehicle->turn == TURN_RIGHT) {
        printf("Turning right while moving %s at speed %d...\n", vehicle->direction == 1 ? "forward" : "backward", vehicle->speed);
    } else {
        printf("Moving %s at speed %d...\n", vehicle->direction == 1 ? "forward" : "backward", vehicle->speed);
    }
    
    // Simulate movement for a while
    sleep(2);
    printf("The vehicle has completed the move\n");
}

void changeDirection(RC_Vehicle *vehicle, int turnDirection) {
    vehicle->turn = turnDirection;
    if (turnDirection == TURN_LEFT) {
        printf("Turning left!\n");
    } else if (turnDirection == TURN_RIGHT) {
        printf("Turning right!\n");
    } else {
        printf("No turn specified.\n");
    }
}

void updateInput(RC_Vehicle *vehicle) {
    int speed, turn, action;

    printf("Enter speed (0 to %d): ", MAX_SPEED);
    scanf("%d", &speed);
    setSpeed(vehicle, speed);

    if (speed > 0) {
        printf("Enter direction (1: Forward, -1: Backward, 0: Stop): ");
        scanf("%d", &vehicle->direction);
        if (vehicle->direction != 1 && vehicle->direction != -1) {
            vehicle->direction = 0; // No movement
        }
    }

    printf("Enter turning direction (-1: Left, 1: Right, 0: None): ");
    scanf("%d", &turn);
    changeDirection(vehicle, turn);

    // Move the vehicle based on user inputs
    moveVehicle(vehicle);
}

int main() {
    RC_Vehicle vehicle;
    initializeVehicle(&vehicle);
    
    srand(time(NULL)); // Seed for random speed

    while (1) {
        printf("=========================================\n");
        printf("RC Vehicle Controller\n");
        printf("1. Set Speed\n");
        printf("2. Display Status\n");
        printf("3. Move Vehicle\n");
        printf("4. Update Input\n");
        printf("5. Exit\n");
        printf("Choose an action: ");
        
        int action;
        scanf("%d", &action);

        switch (action) {
            case 1:
                printf("Randomizing speed...\n");
                setSpeed(&vehicle, rand() % (MAX_SPEED + 1)); // Random speed
                break;
            case 2:
                displayStatus(&vehicle);
                break;
            case 3:
                moveVehicle(&vehicle);
                break;
            case 4:
                updateInput(&vehicle);
                break;
            case 5:
                printf("Exiting simulation...\n");
                exit(0);
            default:
                printf("Invalid action! Please try again.\n");
        }
    }

    return 0;
}