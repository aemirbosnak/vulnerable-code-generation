//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define vehicle states for our comedy of errors
typedef enum {
    PARKED,
    MOVING,
    CRASHED,
    REVERSED,
    SPINNING
} VehicleState;

// The remote-controlled vehicle structure
typedef struct {
    VehicleState state;
    int speed;
    char *name;
} RC_Vehicle;

// Function declarations
void displayState(RC_Vehicle *vehicle);
void moveForward(RC_Vehicle *vehicle);
void reverse(RC_Vehicle *vehicle);
void spin(RC_Vehicle *vehicle);
void crash(RC_Vehicle *vehicle);
void park(RC_Vehicle *vehicle);
void randomEvent(RC_Vehicle *vehicle);

int main() {
    // Create our silly vehicle
    RC_Vehicle myCar;
    myCar.state = PARKED;
    myCar.speed = 0;
    myCar.name = "The Sluggish Slug";

    printf("Welcome to the RC Vehicle Simulation with %s!\n", myCar.name);

    while(1) {
        displayState(&myCar);
        printf("Choose an action (1: Move Forward, 2: Reverse, 3: Spin, 4: Crash, 5: Park, 6: Exit): ");
        int action;
        scanf("%d", &action);

        switch (action) {
            case 1:
                moveForward(&myCar);
                break;
            case 2:
                reverse(&myCar);
                break;
            case 3:
                spin(&myCar);
                break;
            case 4:
                crash(&myCar);
                break;
            case 5:
                park(&myCar);
                break;
            case 6:
                printf("Exiting the simulation... Don't cry, it's just a game!\n");
                exit(0);
                break;
            default:
                printf("That's not a choice, silly!\n");
                break;
        }

        // Check for a random event every action
        randomEvent(&myCar);
        sleep(1);  // Wait a second before the next action
    }

    return 0;
}

void displayState(RC_Vehicle *vehicle) {
    printf("\nCurrent state of %s:\n", vehicle->name);
    switch (vehicle->state) {
        case PARKED:
            printf("The vehicle is parked like it's on an endless vacation!\n");
            break;
        case MOVING:
            printf("The vehicle is moving forward... like a confused snail!\n");
            break;
        case CRASHED:
            printf("Oops! The vehicle just crashed... now it's debating its life choices!\n");
            break;
        case REVERSED:
            printf("The vehicle is reversing... I hope it's not going to hit its own tail!\n");
            break;
        case SPINNING:
            printf("Wheeeee! The vehicle is spinning like it’s auditioning for a dance-off!\n");
            break;
    }
}

void moveForward(RC_Vehicle *vehicle) {
    if (vehicle->state == PARKED || vehicle->state == REVERSED) {
        vehicle->state = MOVING;
        vehicle->speed += 10;  // Increase speed for humor!
        printf("Vroom! The vehicle speeds up to %d km/h, but it's still a slug!\n", vehicle->speed);
    } else {
        printf("The vehicle is already on the move, calm down Sluggish Slug!\n");
    }
}

void reverse(RC_Vehicle *vehicle) {
    if (vehicle->state != CRASHED) {
        vehicle->state = REVERSED;
        vehicle->speed = 5; // Why not reverse at a laughable speed?
        printf("Beep beep! You're reversing at a breakneck speed of %d km/h...\n", vehicle->speed);
    } else {
        printf("Crisis alert! The vehicle can't reverse while it’s taking a nap after crashing!\n");
    }
}

void spin(RC_Vehicle *vehicle) {
    vehicle->state = SPINNING;
    vehicle->speed = 0; // Because spinning isn't going anywhere!
    printf("The vehicle is spinning like it's at a party! Just no dancing, please!\n");
}

void crash(RC_Vehicle *vehicle) {
    vehicle->state = CRASHED;
    vehicle->speed = 0; // Suddenly, things aren’t moving anymore!
    printf("Oh no! The vehicle crashed! Well, it'll break for a cup of coffee now!\n");
}

void park(RC_Vehicle *vehicle) {
    vehicle->state = PARKED;
    vehicle->speed = 0;
    printf("The vehicle is back to its lazy roots and parked!\n");
}

void randomEvent(RC_Vehicle *vehicle) {
    int event = rand() % 5;
    switch (event) {
        case 0:
            printf("A cat just crossed your path! Good luck with that!\n");
            break;
        case 1:
            printf("A squirrel demanded snacks! You're in the wrong business!\n");
            break;
        case 2:
            printf("The vehicle said 'I need to sleep!' Time for a pit stop!\n");
            park(vehicle);
            break;
        case 3:
            printf("Wind blew by and somehow the vehicle got inspired! It's thinking of becoming a ballet dancer!\n");
            spin(vehicle);
            break;
        case 4:
            printf("Suddenly, a pizza delivery guy raced past! Was that actually on time?\n");
            break;
        default:
            break;
    }
}