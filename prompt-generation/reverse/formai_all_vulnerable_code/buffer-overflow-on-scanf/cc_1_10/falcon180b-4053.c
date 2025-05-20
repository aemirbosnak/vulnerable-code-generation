//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 50
#define MAX_TURN 100
#define MIN_TURN 50
#define MAX_ACCELERATION 10
#define MIN_ACCELERATION 1
#define MAX_BRAKE 10
#define MIN_BRAKE 1

struct vehicle {
    int speed;
    int turn;
    int acceleration;
    int brake;
};

void init_vehicle(struct vehicle *vehicle) {
    vehicle->speed = 0;
    vehicle->turn = 0;
    vehicle->acceleration = 0;
    vehicle->brake = 0;
}

void handle_input(struct vehicle *vehicle, int input) {
    switch(input) {
        case 1:
            vehicle->acceleration = MAX_ACCELERATION;
            vehicle->brake = MIN_BRAKE;
            break;
        case 2:
            vehicle->acceleration = MAX_ACCELERATION;
            vehicle->brake = MAX_BRAKE;
            break;
        case 3:
            vehicle->acceleration = MIN_ACCELERATION;
            vehicle->brake = MIN_BRAKE;
            break;
        case 4:
            vehicle->acceleration = MIN_ACCELERATION;
            vehicle->brake = MAX_BRAKE;
            break;
        default:
            vehicle->acceleration = 0;
            vehicle->brake = 0;
            break;
    }
}

void update_vehicle(struct vehicle *vehicle) {
    vehicle->speed += vehicle->acceleration;
    vehicle->speed -= vehicle->brake;
    vehicle->speed = (vehicle->speed > MAX_SPEED)? MAX_SPEED : (vehicle->speed < MIN_SPEED)? MIN_SPEED : vehicle->speed;
    
    vehicle->turn += vehicle->acceleration - vehicle->brake;
    vehicle->turn = (vehicle->turn > MAX_TURN)? MAX_TURN : (vehicle->turn < MIN_TURN)? MIN_TURN : vehicle->turn;
}

void print_vehicle_status(struct vehicle *vehicle) {
    printf("Speed: %d\n", vehicle->speed);
    printf("Turn: %d\n", vehicle->turn);
}

int main() {
    struct vehicle vehicle;
    init_vehicle(&vehicle);
    
    int choice;
    do {
        printf("Choose an input:\n1: Accelerate\n2: Brake\n3: Left turn\n4: Right turn\n");
        scanf("%d", &choice);
        handle_input(&vehicle, choice);
        update_vehicle(&vehicle);
        print_vehicle_status(&vehicle);
    } while(choice!= 0);

    return 0;
}