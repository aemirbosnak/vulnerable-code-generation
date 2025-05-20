//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS 10
#define NUM_ELEVATOR 5

void main_menu();
void add_passenger();
void remove_passenger();
void print_elevators();
void print_passengers();

struct elevator {
    int capacity;
    int current_floor;
    int direction;
    int num_passengers;
    int passengers[MAX_PASS];
};

struct passenger {
    int start_floor;
    int dest_floor;
};

struct elevator elevators[NUM_ELEVATOR];
struct passenger passengers[MAX_PASS];
int num_passengers = 0;

int main(void) {
    int choice;

    // initialize elevators
    for (int i = 0; i < NUM_ELEVATOR; i++) {
        elevators[i].capacity = rand() % 6 + 5; // 5-10 person capacity
        elevators[i].current_floor = 0; // ground floor
        elevators[i].direction = 1; // up
        elevators[i].num_passengers = 0; // no passengers initially
    }

    while (1) {
        main_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_passenger();
                break;
            case 2:
                remove_passenger();
                break;
            case 3:
                print_elevators();
                break;
            case 4:
                print_passengers();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}

void main_menu() {
    printf("Elevators:\n");
    print_elevators();
    printf("\nWhat would you like to do?\n");
    printf("1. Add passenger\n");
    printf("2. Remove passenger\n");
    printf("3. Print elevators\n");
    printf("4. Print passengers\n");
    printf("5. Quit\n");
}

void add_passenger() {
    int start_floor, dest_floor, added = 0;

    if (num_passengers == MAX_PASS) {
        printf("Maximum number of passengers reached.\n");
        return;
    }

    printf("Enter start floor (0-9): ");
    scanf("%d", &start_floor);
    printf("Enter destination floor (0-9): ");
    scanf("%d", &dest_floor);

    // check if start and dest floors are valid
    if (start_floor < 0 || start_floor > 9 || dest_floor < 0 || dest_floor > 9) {
        printf("Invalid floor.\n");
        return;
    }

    // check if start and dest floors are the same
    if (start_floor == dest_floor) {
        printf("Start and destination floors are the same.\n");
        return;
    }

    // find elevator that is closest and has enough space
    int closest = 0, distance = 10;
    for (int i = 0; i < NUM_ELEVATOR; i++) {
        if (elevators[i].num_passengers < elevators[i].capacity) {
            int elevator_dist = abs(elevators[i].current_floor - start_floor);
            if (elevator_dist < distance) {
                closest = i;
                distance = elevator_dist;
            }
        }
    }

    // check if elevator is going in the right direction
    if ((elevators[closest].direction == 1 && start_floor < elevators[closest].current_floor) || (elevators[closest].direction == -1 && start_floor > elevators[closest].current_floor)) {
        printf("Elevator is going in the wrong direction.\n");
        return;
    }

    // add passenger to elevator
    elevators[closest].passengers[elevators[closest].num_passengers] = num_passengers;
    elevators[closest].num_passengers++;
    elevators[closest].direction = start_floor > elevators[closest].current_floor ? 1 : -1;
    passengers[num_passengers].start_floor = start_floor;
    passengers[num_passengers].dest_floor = dest_floor;
    num_passengers++;

    printf("Passenger successfully added to elevator %d.\n", closest+1);
}

void remove_passenger() {
    int elevator, passenger;

    printf("Enter elevator number (1-5): ");
    scanf("%d", &elevator);
    printf("Enter passenger number (1-10): ");
    scanf("%d", &passenger);

    // check if elevator number is valid
    if (elevator < 1 || elevator > NUM_ELEVATOR) {
        printf("Invalid elevator number.\n");
        return;
    }

    // check if passenger number is valid
    if (passenger < 1 || passenger > elevators[elevator-1].num_passengers) {
        printf("Invalid passenger number.\n");
        return;
    }

    // remove passenger from elevator
    elevators[elevator-1].passengers[passenger-1] = -1;
    elevators[elevator-1].num_passengers--;

    printf("Passenger successfully removed from elevator %d.\n", elevator);
}

void print_elevators() {
    for (int i = 0; i < NUM_ELEVATOR; i++) {
        printf("Elevator %d (Capacity: %d, Current Floor: %d, Direction: %s, Passengers: [ ", i+1, elevators[i].capacity, elevators[i].current_floor, elevators[i].direction == 1 ? "up" : "down");
        for (int j = 0; j < elevators[i].num_passengers; j++) {
            printf("%d ", elevators[i].passengers[j]+1);
        }
        printf("])\n");
    }
}

void print_passengers() {
    for (int i = 0; i < num_passengers; i++) {
        printf("Passenger %d (Start Floor: %d, Destination Floor: %d)\n", i+1, passengers[i].start_floor, passengers[i].dest_floor);
    }
}