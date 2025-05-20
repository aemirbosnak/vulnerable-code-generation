//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define MIN_TURN 1
#define MAX_TURN 10
#define MAX_DISTANCE 100

// Struct to hold vehicle data
typedef struct {
    int speed;
    int turn;
    int distance;
} Vehicle;

// Function prototypes
void move(Vehicle *v);
int random_number(int min, int max);

int main() {
    srand(time(NULL)); // Seed the random number generator
    Vehicle v = {0, 0, 0}; // Initialize the vehicle
    int choice;

    while(1) {
        printf("Current speed: %d, turn: %d, distance: %d\n", v.speed, v.turn, v.distance);
        printf("Enter choice:\n1. Move forward\n2. Turn left\n3. Turn right\n4. Stop\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                v.speed += random_number(1, MAX_SPEED);
                if(v.speed > MAX_SPEED)
                    v.speed = MAX_SPEED;
                break;
            case 2:
                v.turn -= random_number(1, MAX_TURN);
                if(v.turn < MIN_TURN)
                    v.turn = MIN_TURN;
                break;
            case 3:
                v.turn += random_number(1, MAX_TURN);
                if(v.turn > MAX_TURN)
                    v.turn = MAX_TURN;
                break;
            case 4:
                v.speed = 0;
                v.turn = 0;
                break;
            default:
                printf("Invalid choice\n");
        }

        move(&v);
    }

    return 0;
}

void move(Vehicle *v) {
    int distance = v->speed * v->turn;
    v->distance += distance;

    if(v->distance > MAX_DISTANCE) {
        printf("Vehicle has reached maximum distance.\n");
        exit(0);
    }
}

int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}