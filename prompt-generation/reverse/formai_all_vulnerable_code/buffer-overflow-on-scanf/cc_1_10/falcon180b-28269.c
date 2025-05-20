//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 100
#define MAX_TURN 100
#define MAX_DISTANCE 100

typedef struct {
    char name[20];
    int speed;
    int turn;
    int distance;
} Vehicle;

void move_vehicle(Vehicle* v) {
    printf("Vehicle %s is moving at %d units per second.\n", v->name, v->speed);
}

void turn_vehicle(Vehicle* v) {
    printf("Vehicle %s is turning at %d degrees per second.\n", v->name, v->turn);
}

void measure_distance(Vehicle* v) {
    printf("Vehicle %s has traveled %d units.\n", v->name, v->distance);
}

int main() {
    Vehicle car1 = {"Car 1", 50, 20, 0};
    Vehicle car2 = {"Car 2", 70, 30, 0};
    Vehicle car3 = {"Car 3", 90, 40, 0};

    printf("Welcome to the remote control vehicle simulation!\n");
    printf("You have three cars at your disposal:\n");
    printf("- Car 1 (speed: %d, turn: %d)\n", car1.speed, car1.turn);
    printf("- Car 2 (speed: %d, turn: %d)\n", car2.speed, car2.turn);
    printf("- Car 3 (speed: %d, turn: %d)\n", car3.speed, car3.turn);

    int choice;
    do {
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                move_vehicle(&car1);
                break;
            case 2:
                move_vehicle(&car2);
                break;
            case 3:
                move_vehicle(&car3);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(1);

    return 0;
}